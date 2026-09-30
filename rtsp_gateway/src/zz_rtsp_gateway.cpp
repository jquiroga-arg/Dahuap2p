// zz-rtsp-gateway — Pasarela "registro activo" Dahua -> RTSP
//
// Las cámaras/NVR remotos se auto-registran (conexión saliente) contra este servicio.
// Por cada equipo aceptado se hace login con ZZNetSDK, se abre el video en vivo y se
// re-publica, sin recodificar, en un servidor RTSP (MediaMTX) mediante ffmpeg:
//
//   cámara --DVRIP--> ZZNetSDK --DHAV--> cola --stdin--> ffmpeg -f dhav -c copy --> MediaMTX
//
// Configuración: archivo .env (--env RUTA) + variables de entorno (tienen prioridad).
// Ver config/gateway.env.example e install.md.

#include <arpa/inet.h>
#include <fcntl.h>
#include <spawn.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#include <algorithm>
#include <atomic>
#include <cerrno>
#include <chrono>
#include <condition_variable>
#include <csignal>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <map>
#include <memory>
#include <mutex>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

#include "ZZNetSDK.h"

extern char** environ;

static const char* kVersion = "1.0.0";

// =====================================================================================
// Logging (journald entiende el prefijo <N> cuando la salida va a systemd)
// =====================================================================================
enum LogLevel { LOG_ERR = 3, LOG_WARN = 4, LOG_INFO = 6, LOG_DBG = 7 };
static std::atomic<int> g_logLevel{LOG_INFO};
static bool g_journal = false;
static std::mutex g_logMx;

static void logf(int lvl, const char* fmt, ...) {
    if (lvl > g_logLevel.load()) return;
    char msg[2048];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(msg, sizeof(msg), fmt, ap);
    va_end(ap);
    std::lock_guard<std::mutex> lk(g_logMx);
    if (g_journal) {
        fprintf(stderr, "<%d>%s\n", lvl, msg);
    } else {
        const char* tag = lvl <= LOG_ERR ? "ERROR" : lvl == LOG_WARN ? "WARN " : lvl == LOG_INFO ? "INFO " : "DEBUG";
        time_t t = time(nullptr);
        struct tm tm;
        localtime_r(&t, &tm);
        char ts[32];
        strftime(ts, sizeof(ts), "%Y-%m-%d %H:%M:%S", &tm);
        fprintf(stderr, "%s %s %s\n", ts, tag, msg);
    }
    fflush(stderr);
}
#define LOGE(...) logf(LOG_ERR, __VA_ARGS__)
#define LOGW(...) logf(LOG_WARN, __VA_ARGS__)
#define LOGI(...) logf(LOG_INFO, __VA_ARGS__)
#define LOGD(...) logf(LOG_DBG, __VA_ARGS__)

static int parseLogLevel(const std::string& s) {
    if (s == "error") return LOG_ERR;
    if (s == "warn" || s == "warning") return LOG_WARN;
    if (s == "debug") return LOG_DBG;
    return LOG_INFO;
}

// =====================================================================================
// Utilidades
// =====================================================================================
static std::string trim(const std::string& s) {
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == std::string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

static std::vector<std::string> split(const std::string& s, const char* seps) {
    std::vector<std::string> out;
    std::string cur;
    for (char c : s) {
        if (strchr(seps, c)) {
            if (!cur.empty()) out.push_back(cur);
            cur.clear();
        } else {
            cur += c;
        }
    }
    if (!cur.empty()) out.push_back(cur);
    return out;
}

static bool toBool(const std::string& v) {
    std::string s = v;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s == "1" || s == "true" || s == "yes" || s == "si" || s == "on";
}

// IDs que llegan desde la red: sólo caracteres seguros para rutas RTSP y logs
static bool validId(const std::string& id) {
    if (id.empty() || id.size() > 64) return false;
    for (char c : id)
        if (!(isalnum((unsigned char)c) || c == '-' || c == '_' || c == '.')) return false;
    return true;
}

// =====================================================================================
// Archivo .env
// =====================================================================================
// Formato: CLAVE=valor | CLAVE="valor" | export CLAVE=valor | # comentario
static bool loadEnvFile(const std::string& path, std::map<std::string, std::string>& out, std::string& err) {
    std::ifstream f(path);
    if (!f) { err = "no se puede abrir " + path + ": " + strerror(errno); return false; }
    std::string line;
    int n = 0;
    while (std::getline(f, line)) {
        n++;
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        if (line.rfind("export ", 0) == 0) line = trim(line.substr(7));
        size_t eq = line.find('=');
        if (eq == std::string::npos) { err = path + ":" + std::to_string(n) + ": falta '='"; return false; }
        std::string k = trim(line.substr(0, eq));
        std::string v = trim(line.substr(eq + 1));
        if (v.size() >= 2 && ((v.front() == '"' && v.back() == '"') || (v.front() == '\'' && v.back() == '\''))) {
            v = v.substr(1, v.size() - 2);
        } else {
            size_t hash = v.find(" #");  // comentario al final de línea (sólo sin comillas)
            if (hash != std::string::npos) v = trim(v.substr(0, hash));
        }
        out[k] = v;
    }
    return true;
}

// =====================================================================================
// Lista de redes permitidas (IPv4 CIDR)
// =====================================================================================
struct Cidr { uint32_t net, mask; std::string text; };

static bool parseCidr(const std::string& s, Cidr& c) {
    std::string ip = s;
    int bits = 32;
    size_t slash = s.find('/');
    if (slash != std::string::npos) {
        ip = s.substr(0, slash);
        char* end = nullptr;
        long b = strtol(s.c_str() + slash + 1, &end, 10);
        if (*end || b < 0 || b > 32) return false;
        bits = (int)b;
    }
    in_addr a{};
    if (inet_pton(AF_INET, ip.c_str(), &a) != 1) return false;
    c.mask = bits == 0 ? 0 : htonl(0xFFFFFFFFu << (32 - bits));
    c.net = a.s_addr & c.mask;
    c.text = s;
    return true;
}

static bool ipAllowed(const std::vector<Cidr>& list, const std::string& ip) {
    in_addr a{};
    if (inet_pton(AF_INET, ip.c_str(), &a) != 1) return false;
    for (const auto& c : list)
        if ((a.s_addr & c.mask) == c.net) return true;
    return false;
}

// =====================================================================================
// Configuración
// =====================================================================================
struct CamCfg {
    std::string user, pass;
    std::string channels = "";   // "" = usar ZZGW_DEFAULT_CHANNELS; "0,1" ; "all"
    std::string stream = "";     // "" = usar ZZGW_STREAM; main | sub | sub2
};

struct Config {
    std::string envFile;
    // Registro activo
    std::string listenIp = "0.0.0.0";
    int listenPort = 9500;
    std::vector<Cidr> allowed;          // vacía = ninguna IP permitida
    int maxSessions = 64;
    // Credenciales
    std::string camerasFile;            // ID usuario clave [canales] [flujo]
    bool allowUnknownIds = false;
    std::string defaultUser = "admin", defaultPass;
    // Video
    std::string stream = "sub";         // main | sub | sub2
    std::string defaultChannels = "0";
    int bufferPolicy = 0;               // 0 defecto, 1 fluidez, 2 tiempo real
    // RTSP / ffmpeg
    std::string rtspUrl = "rtsp://127.0.0.1:8554";
    std::string pathTemplate = "{id}";  // {id} {ch} (1..N) {sn}
    std::string ffmpegBin = "/usr/bin/ffmpeg";
    std::string ffmpegLogLevel = "warning";
    std::string ffmpegInputArgs = "-probesize 1000000 -analyzeduration 1000000";
    std::string ffmpegOutputArgs = "-c copy -f rtsp -rtsp_transport tcp";
    size_t queueMaxBytes = 8u << 20;
    int restartDelaySec = 3;
    // Operación
    int statsIntervalSec = 60;
    int logLevel = LOG_INFO;

    std::map<std::string, CamCfg> cams;
};

static std::string getv(const std::map<std::string, std::string>& m, const char* k, const std::string& def) {
    const char* e = getenv(k);                 // el entorno tiene prioridad sobre el archivo
    if (e) return e;
    auto it = m.find(k);
    return it == m.end() ? def : it->second;
}

static bool loadCameras(const std::string& path, std::map<std::string, CamCfg>& out, std::string& err) {
    out.clear();
    if (path.empty()) return true;
    std::ifstream f(path);
    if (!f) { err = "no se puede abrir " + path + ": " + strerror(errno); return false; }
    std::string line;
    int n = 0;
    while (std::getline(f, line)) {
        n++;
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        auto t = split(line, " \t");
        if (t.size() < 3) { err = path + ":" + std::to_string(n) + ": se esperaba 'ID usuario clave [canales] [flujo]'"; return false; }
        if (!validId(t[0])) { err = path + ":" + std::to_string(n) + ": ID inválido '" + t[0] + "'"; return false; }
        CamCfg c;
        c.user = t[1];
        c.pass = t[2];
        if (t.size() > 3 && t[3] != "-") c.channels = t[3];
        if (t.size() > 4) c.stream = t[4];
        out[t[0]] = c;
    }
    return true;
}

static bool loadConfig(Config& c, std::string& err, bool reload = false) {
    std::map<std::string, std::string> m;
    if (!c.envFile.empty() && !loadEnvFile(c.envFile, m, err)) return false;

    if (!reload) {
        c.listenIp = getv(m, "ZZGW_LISTEN_IP", c.listenIp);
        c.listenPort = atoi(getv(m, "ZZGW_LISTEN_PORT", std::to_string(c.listenPort)).c_str());
        c.rtspUrl = getv(m, "ZZGW_RTSP_URL", c.rtspUrl);
        c.ffmpegBin = getv(m, "ZZGW_FFMPEG_BIN", c.ffmpegBin);
    }
    std::vector<Cidr> allowed;
    for (auto& s : split(getv(m, "ZZGW_ALLOWED_CIDRS", "0.0.0.0/0"), ", ;")) {
        Cidr ci;
        if (!parseCidr(s, ci)) { err = "ZZGW_ALLOWED_CIDRS: red inválida '" + s + "'"; return false; }
        allowed.push_back(ci);
    }
    c.allowed = allowed;
    c.maxSessions = atoi(getv(m, "ZZGW_MAX_SESSIONS", std::to_string(c.maxSessions)).c_str());
    c.camerasFile = getv(m, "ZZGW_CAMERAS_FILE", c.camerasFile);
    c.allowUnknownIds = toBool(getv(m, "ZZGW_ALLOW_UNKNOWN_IDS", c.allowUnknownIds ? "true" : "false"));
    c.defaultUser = getv(m, "ZZGW_DEFAULT_USER", c.defaultUser);
    c.defaultPass = getv(m, "ZZGW_DEFAULT_PASS", c.defaultPass);
    c.stream = getv(m, "ZZGW_STREAM", c.stream);
    c.defaultChannels = getv(m, "ZZGW_DEFAULT_CHANNELS", c.defaultChannels);
    c.bufferPolicy = atoi(getv(m, "ZZGW_BUFFER_POLICY", std::to_string(c.bufferPolicy)).c_str());
    c.pathTemplate = getv(m, "ZZGW_PATH_TEMPLATE", c.pathTemplate);
    c.ffmpegLogLevel = getv(m, "ZZGW_FFMPEG_LOGLEVEL", c.ffmpegLogLevel);
    c.ffmpegInputArgs = getv(m, "ZZGW_FFMPEG_INPUT_ARGS", c.ffmpegInputArgs);
    c.ffmpegOutputArgs = getv(m, "ZZGW_FFMPEG_OUTPUT_ARGS", c.ffmpegOutputArgs);
    c.queueMaxBytes = (size_t)atoi(getv(m, "ZZGW_QUEUE_MAX_MB", std::to_string(c.queueMaxBytes >> 20)).c_str()) << 20;
    c.restartDelaySec = atoi(getv(m, "ZZGW_RESTART_DELAY_SEC", std::to_string(c.restartDelaySec)).c_str());
    c.statsIntervalSec = atoi(getv(m, "ZZGW_STATS_INTERVAL_SEC", std::to_string(c.statsIntervalSec)).c_str());
    c.logLevel = parseLogLevel(getv(m, "ZZGW_LOG_LEVEL", "info"));

    // Validaciones
    if (c.listenPort < 1 || c.listenPort > 65535) { err = "ZZGW_LISTEN_PORT fuera de rango"; return false; }
    if (c.stream != "main" && c.stream != "sub" && c.stream != "sub2") { err = "ZZGW_STREAM debe ser main|sub|sub2"; return false; }
    if (c.bufferPolicy < 0 || c.bufferPolicy > 2) { err = "ZZGW_BUFFER_POLICY debe ser 0, 1 o 2"; return false; }
    if (c.pathTemplate.find("{id}") == std::string::npos) { err = "ZZGW_PATH_TEMPLATE debe contener {id}"; return false; }
    if (c.maxSessions < 1) c.maxSessions = 1;
    if (c.queueMaxBytes < (1u << 20)) c.queueMaxBytes = 1u << 20;
    if (c.restartDelaySec < 1) c.restartDelaySec = 1;
    if (c.allowUnknownIds && c.defaultPass.empty()) { err = "ZZGW_ALLOW_UNKNOWN_IDS=true requiere ZZGW_DEFAULT_PASS"; return false; }
    if (!c.camerasFile.empty()) {
        struct stat st{};
        if (stat(c.camerasFile.c_str(), &st) == 0 && (st.st_mode & S_IROTH))
            LOGW("%s es legible por cualquier usuario (contiene claves): chmod 640", c.camerasFile.c_str());
    }
    if (!loadCameras(c.camerasFile, c.cams, err)) return false;
    for (auto& a : c.allowed)
        if (a.mask == 0) LOGW("ZZGW_ALLOWED_CIDRS incluye %s: se aceptan registros desde cualquier IP", a.text.c_str());
    if (c.cams.empty() && !c.allowUnknownIds) LOGW("no hay cámaras configuradas y ZZGW_ALLOW_UNKNOWN_IDS=false: se rechazarán todos los registros");
    return true;
}

static ZZ_RealPlayType streamType(const std::string& s) {
    if (s == "main") return ZZ_RType_Realplay_0;
    if (s == "sub2") return ZZ_RType_Realplay_2;
    return ZZ_RType_Realplay_1;
}
static int streamIndex(const std::string& s) { return s == "main" ? 0 : s == "sub2" ? 2 : 1; }

static std::string buildPath(const std::string& tpl, const std::string& id, int ch1, const std::string& sn, bool multi) {
    std::string p = tpl;
    auto rep = [&](const std::string& k, const std::string& v) {
        for (size_t pos; (pos = p.find(k)) != std::string::npos;) p.replace(pos, k.size(), v);
    };
    if (multi && p.find("{ch}") == std::string::npos) p += "/ch{ch}";
    rep("{id}", id);
    rep("{ch}", std::to_string(ch1));
    rep("{sn}", sn);
    return p;
}

// =====================================================================================
// Publicador: cola acotada + hilo escritor hacia un proceso ffmpeg (sin shell)
// =====================================================================================
class Publisher {
public:
    Publisher(const Config& c, std::string path) : cfg_(c), path_(std::move(path)) {
        th_ = std::thread([this] { run(); });
    }
    ~Publisher() {
        {
            std::lock_guard<std::mutex> lk(m_);
            stop_ = true;
        }
        cv_.notify_all();
        if (th_.joinable()) th_.join();
    }
    // Desde el hilo del SDK: copiar y encolar, nunca bloquear
    void push(const BYTE* p, DWORD n) {
        rxBytes_ += n;
        std::lock_guard<std::mutex> lk(m_);
        if (bytes_ + n > cfg_.queueMaxBytes) { dropped_ += n; return; }
        q_.emplace_back(p, p + n);
        bytes_ += n;
        cv_.notify_one();
    }
    const std::string& path() const { return path_; }
    bool takeKeyFrameRequest() { return needKey_.exchange(false); }
    void stats(uint64_t& rx, uint64_t& drop, int& restarts) {
        rx = rxBytes_.exchange(0);
        drop = dropped_.exchange(0);
        restarts = restarts_.load();
    }

private:
    bool spawn() {
        std::vector<std::string> a = {cfg_.ffmpegBin, "-hide_banner", "-nostdin", "-loglevel", cfg_.ffmpegLogLevel, "-fflags", "+genpts"};
        for (auto& s : split(cfg_.ffmpegInputArgs, " \t")) a.push_back(s);
        a.insert(a.end(), {"-f", "dhav", "-i", "pipe:0"});
        for (auto& s : split(cfg_.ffmpegOutputArgs, " \t")) a.push_back(s);
        std::string url = cfg_.rtspUrl;
        if (!url.empty() && url.back() == '/') url.pop_back();
        a.push_back(url + "/" + path_);

        int fds[2];
        if (pipe2(fds, O_CLOEXEC) != 0) { LOGE("[%s] pipe: %s", path_.c_str(), strerror(errno)); return false; }
        posix_spawn_file_actions_t fa;
        posix_spawn_file_actions_init(&fa);
        posix_spawn_file_actions_adddup2(&fa, fds[0], 0);   // stdin del hijo = lado de lectura
        std::vector<char*> argv;
        for (auto& s : a) argv.push_back(const_cast<char*>(s.c_str()));
        argv.push_back(nullptr);
        int rc = posix_spawn(&pid_, a[0].c_str(), &fa, nullptr, argv.data(), environ);
        posix_spawn_file_actions_destroy(&fa);
        close(fds[0]);
        if (rc != 0) {
            close(fds[1]);
            LOGE("[%s] no se pudo ejecutar %s: %s", path_.c_str(), a[0].c_str(), strerror(rc));
            pid_ = -1;
            return false;
        }
        wfd_ = fds[1];
        LOGD("[%s] ffmpeg pid=%d", path_.c_str(), (int)pid_);
        return true;
    }
    void reap() {
        if (wfd_ >= 0) { close(wfd_); wfd_ = -1; }
        if (pid_ > 0) {
            int st = 0;
            for (int i = 0; i < 50 && waitpid(pid_, &st, WNOHANG) == 0; i++) usleep(100000);
            if (waitpid(pid_, &st, WNOHANG) == 0) { kill(pid_, SIGTERM); waitpid(pid_, &st, 0); }
            pid_ = -1;
        }
    }
    bool writeAll(const BYTE* p, size_t n) {
        while (n) {
            ssize_t w = write(wfd_, p, n);
            if (w < 0) { if (errno == EINTR) continue; return false; }
            p += w;
            n -= (size_t)w;
        }
        return true;
    }
    void run() {
        while (!isStopping()) {
            if (!spawn()) {
                waitRestart();
                continue;
            }
            needKey_ = true;               // un I-frame acelera el arranque de ffmpeg
            bool broken = false;
            for (;;) {
                std::vector<BYTE> b;
                {
                    std::unique_lock<std::mutex> lk(m_);
                    cv_.wait(lk, [this] { return stop_ || !q_.empty(); });
                    if (stop_) break;
                    b.swap(q_.front());
                    q_.pop_front();
                    bytes_ -= b.size();
                }
                if (!writeAll(b.data(), b.size())) { broken = true; break; }
            }
            reap();
            if (broken && !isStopping()) {
                restarts_++;
                LOGW("[%s] ffmpeg terminó; reinicio en %d s", path_.c_str(), cfg_.restartDelaySec);
                waitRestart();
            }
        }
    }
    bool isStopping() {
        std::lock_guard<std::mutex> lk(m_);
        return stop_;
    }
    void waitRestart() {
        std::unique_lock<std::mutex> lk(m_);
        cv_.wait_for(lk, std::chrono::seconds(cfg_.restartDelaySec), [this] { return stop_; });
        q_.clear();                        // descartar lo acumulado durante la caída
        bytes_ = 0;
    }

    const Config cfg_;          // copia: la recarga (SIGHUP) no afecta a hilos en curso
    std::string path_;
    std::thread th_;
    std::mutex m_;
    std::condition_variable cv_;
    std::deque<std::vector<BYTE>> q_;
    size_t bytes_ = 0;
    bool stop_ = false;
    pid_t pid_ = -1;
    int wfd_ = -1;
    std::atomic<bool> needKey_{false};
    std::atomic<uint64_t> rxBytes_{0}, dropped_{0};
    std::atomic<int> restarts_{0};
};

static void CALLBACK OnRealData(LLONG, DWORD type, BYTE* buf, DWORD len, LDWORD user) {
    if (type != 0 || !buf || !len) return;      // 0 = flujo original del equipo (DHAV)
    reinterpret_cast<Publisher*>(user)->push(buf, len);
}

// =====================================================================================
// Sesiones
// =====================================================================================
struct Canal { int ch = 0; LLONG real = 0; std::unique_ptr<Publisher> pub; };
struct Sesion {
    std::string id, origen, sn;
    LLONG login = 0;
    int subStream = 1;
    std::vector<std::unique_ptr<Canal>> canales;
};
struct Evento { enum Tipo { ALTA, BAJA_ORIGEN, BAJA_LOGIN } tipo; std::string ip; WORD port = 0; std::string id; LLONG login = 0; };

static Config g_cfg;
static std::mutex g_evMx;
static std::queue<Evento> g_eventos;
static std::map<std::string, std::unique_ptr<Sesion>> g_ses;   // ID -> sesión
static std::atomic<bool> g_run{true};
static std::atomic<bool> g_reload{false};

static void encolar(Evento e) {
    std::lock_guard<std::mutex> lk(g_evMx);
    g_eventos.push(std::move(e));
}

// Callbacks del SDK (hilos del SDK): sólo encolan
static int CALLBACK OnService(LLONG, char* ip, WORD port, LONG cmd, void* param, DWORD len, LDWORD) {
    Evento e;
    e.ip = ip ? ip : "";
    e.port = port;
    if (cmd == ZZ_DVR_SERIAL_RETURN) {
        e.tipo = Evento::ALTA;
        if (param) e.id.assign(static_cast<char*>(param), strnlen(static_cast<char*>(param), len));
    } else if (cmd == ZZ_DVR_DISCONNECT) {
        e.tipo = Evento::BAJA_ORIGEN;
    } else {
        return 0;
    }
    encolar(e);
    return 0;
}

static void CALLBACK OnDisconnect(LLONG login, char* ip, LONG port, LDWORD) {
    Evento e;
    e.tipo = Evento::BAJA_LOGIN;
    e.login = login;
    e.ip = ip ? ip : "";
    e.port = (WORD)port;
    encolar(e);
}

static void cerrarSesion(const std::string& id, const char* motivo) {
    auto it = g_ses.find(id);
    if (it == g_ses.end()) return;
    Sesion& s = *it->second;
    for (auto& c : s.canales)
        if (c->real) ZZNETSDK_StopRealPlay(c->real);   // tras esto no llegan más callbacks
    if (s.login) ZZNETSDK_Logout(s.login);
    LOGI("[%s] sesión cerrada (%s)", id.c_str(), motivo);
    g_ses.erase(it);                                    // destruye publicadores -> cierra ffmpeg
}

static std::vector<int> resolverCanales(const std::string& spec, int total) {
    std::vector<int> out;
    if (spec == "all") {
        for (int i = 0; i < std::max(1, total); i++) out.push_back(i);
        return out;
    }
    for (auto& t : split(spec, ", ")) {
        int ch = atoi(t.c_str());
        if (ch >= 0 && (total <= 0 || ch < total) && std::find(out.begin(), out.end(), ch) == out.end()) out.push_back(ch);
    }
    if (out.empty()) out.push_back(0);
    return out;
}

static void procesarAlta(const Evento& e) {
    if (!ipAllowed(g_cfg.allowed, e.ip)) {
        LOGW("[rechazo] %s:%u fuera de ZZGW_ALLOWED_CIDRS (ID '%s')", e.ip.c_str(), e.port, e.id.c_str());
        return;
    }
    if (!validId(e.id)) {
        LOGW("[rechazo] ID inválido desde %s:%u", e.ip.c_str(), e.port);
        return;
    }
    CamCfg cam;
    auto it = g_cfg.cams.find(e.id);
    if (it != g_cfg.cams.end()) {
        cam = it->second;
    } else if (g_cfg.allowUnknownIds) {
        cam.user = g_cfg.defaultUser;
        cam.pass = g_cfg.defaultPass;
    } else {
        LOGW("[rechazo] ID desconocido '%s' desde %s:%u", e.id.c_str(), e.ip.c_str(), e.port);
        return;
    }
    if (cam.channels.empty()) cam.channels = g_cfg.defaultChannels;
    if (cam.stream.empty()) cam.stream = g_cfg.stream;

    cerrarSesion(e.id, "re-registro");
    if ((int)g_ses.size() >= g_cfg.maxSessions) {
        LOGW("[rechazo] '%s': se alcanzó ZZGW_MAX_SESSIONS=%d", e.id.c_str(), g_cfg.maxSessions);
        return;
    }

    ZZNET_DEVICEINFO info{};
    int err = 0;
    std::string id = e.id;
    LLONG login = ZZNETSDK_LoginEx(e.ip.c_str(), e.port, cam.user.c_str(), cam.pass.c_str(),
                                   EM_ZZ_LOGIN_SPEC_CAP_SERVER_CONN, (void*)id.c_str(), &info, &err);
    if (!login) {
        LOGE("[%s] login falló desde %s:%u err=%d 0x%08X", id.c_str(), e.ip.c_str(), e.port, err, ZZNETSDK_GetLastError());
        return;
    }
    std::unique_ptr<Sesion> s(new Sesion);
    s->id = id;
    s->origen = e.ip + ":" + std::to_string(e.port);
    s->login = login;
    s->subStream = streamIndex(cam.stream);
    char sn[ZZ_SERIALNO_LEN + 1] = {0};
    memcpy(sn, info.sSerialNumber, ZZ_SERIALNO_LEN);
    s->sn = sn;
    LOGI("[%s] login OK desde %s SN=%s canales=%d", id.c_str(), s->origen.c_str(), s->sn.c_str(), info.byChanNum);

    auto chans = resolverCanales(cam.channels, info.byChanNum);
    bool multi = chans.size() > 1;
    for (int ch : chans) {
        std::unique_ptr<Canal> c(new Canal);
        c->ch = ch;
        std::string path = buildPath(g_cfg.pathTemplate, id, ch + 1, s->sn, multi);
        c->pub.reset(new Publisher(g_cfg, path));
        c->real = ZZNETSDK_RealPlayEx(login, ch, NULL, streamType(cam.stream));
        if (!c->real) {
            LOGE("[%s] RealPlayEx canal %d falló 0x%08X", id.c_str(), ch, ZZNETSDK_GetLastError());
            continue;
        }
        if (g_cfg.bufferPolicy) {
            ZZNET_IN_BUFFER_POLICY bp{};
            bp.dwSize = sizeof(bp);
            bp.emRealPlayType = streamType(cam.stream);
            bp.nPolicy = (unsigned)g_cfg.bufferPolicy;
            ZZNETSDK_SetRealplayBufferPolicy(c->real, &bp, 1000);
        }
        ZZNETSDK_SetRealDataCallBack(c->real, OnRealData, (LDWORD)c->pub.get());
        LOGI("[%s] canal %d (%s) -> %s/%s", id.c_str(), ch + 1, cam.stream.c_str(), g_cfg.rtspUrl.c_str(), path.c_str());
        s->canales.push_back(std::move(c));
    }
    if (s->canales.empty()) {
        ZZNETSDK_Logout(login);
        LOGE("[%s] ningún canal pudo abrirse", id.c_str());
        return;
    }
    g_ses[id] = std::move(s);
}

static void procesarBaja(const Evento& e) {
    std::string origen = e.ip + ":" + std::to_string(e.port);
    for (auto& kv : g_ses) {
        if ((e.tipo == Evento::BAJA_ORIGEN && kv.second->origen == origen) ||
            (e.tipo == Evento::BAJA_LOGIN && kv.second->login == e.login)) {
            std::string id = kv.first;
            cerrarSesion(id, e.tipo == Evento::BAJA_ORIGEN ? "el equipo cerró el registro" : "desconexión");
            return;
        }
    }
}

static void tareasPeriodicas(time_t& lastStats) {
    // Pedidos de I-frame (arranque o reinicio de ffmpeg)
    for (auto& kv : g_ses)
        for (auto& c : kv.second->canales)
            if (c->pub->takeKeyFrameRequest()) ZZNETSDK_MakeKeyFrame(kv.second->login, c->ch, kv.second->subStream);

    if (g_cfg.statsIntervalSec <= 0) return;
    time_t now = time(nullptr);
    if (now - lastStats < g_cfg.statsIntervalSec) return;
    double secs = (double)(now - lastStats);
    lastStats = now;
    LOGI("[estado] sesiones=%zu", g_ses.size());
    for (auto& kv : g_ses)
        for (auto& c : kv.second->canales) {
            uint64_t rx, drop;
            int rs;
            c->pub->stats(rx, drop, rs);
            LOGI("[estado] %s: %.0f kbit/s descartado=%llu B reinicios_ffmpeg=%d", c->pub->path().c_str(),
                 rx * 8 / 1000.0 / secs, (unsigned long long)drop, rs);
        }
}

// =====================================================================================
// Modos auxiliares
// =====================================================================================
static void imprimirConfig(const Config& c) {
    printf("zz-rtsp-gateway %s (ZZNetSDK %s)\n", kVersion, ZZNETSDK_GetVersion());
    printf("  archivo .env           : %s\n", c.envFile.empty() ? "(ninguno)" : c.envFile.c_str());
    printf("  escucha                : %s:%d/TCP\n", c.listenIp.c_str(), c.listenPort);
    printf("  redes permitidas       :");
    for (auto& a : c.allowed) printf(" %s", a.text.c_str());
    printf("\n  sesiones máximas       : %d\n", c.maxSessions);
    printf("  archivo de cámaras     : %s (%zu cámaras)\n", c.camerasFile.empty() ? "(ninguno)" : c.camerasFile.c_str(), c.cams.size());
    for (auto& kv : c.cams)
        printf("      %-24s usuario=%s clave=*** canales=%s flujo=%s\n", kv.first.c_str(), kv.second.user.c_str(),
               kv.second.channels.empty() ? c.defaultChannels.c_str() : kv.second.channels.c_str(),
               kv.second.stream.empty() ? c.stream.c_str() : kv.second.stream.c_str());
    printf("  IDs desconocidos       : %s\n", c.allowUnknownIds ? "aceptar (credenciales por defecto)" : "rechazar");
    printf("  flujo / canales        : %s / %s\n", c.stream.c_str(), c.defaultChannels.c_str());
    printf("  política de buffer     : %d\n", c.bufferPolicy);
    printf("  RTSP                   : %s/%s\n", c.rtspUrl.c_str(), c.pathTemplate.c_str());
    printf("  ffmpeg                 : %s (loglevel %s)\n", c.ffmpegBin.c_str(), c.ffmpegLogLevel.c_str());
    printf("  cola máx. por canal    : %zu MB\n", c.queueMaxBytes >> 20);
    printf("  reinicio ffmpeg        : %d s\n", c.restartDelaySec);
    printf("  estadísticas cada      : %d s\n", c.statsIntervalSec);
}

static int modoSimular(const char* archivo, const char* id) {
    FILE* f = strcmp(archivo, "-") ? fopen(archivo, "rb") : stdin;
    if (!f) { LOGE("%s: %s", archivo, strerror(errno)); return 1; }
    {
        Publisher pub(g_cfg, buildPath(g_cfg.pathTemplate, id, 1, "SIM", false));
        LOGI("[simulación] %s -> %s/%s", archivo, g_cfg.rtspUrl.c_str(), pub.path().c_str());
        std::vector<BYTE> buf(4096);
        size_t n;
        while (g_run && (n = fread(buf.data(), 1, buf.size(), f)) > 0) OnRealData(0, 0, buf.data(), (DWORD)n, (LDWORD)&pub);
        usleep(500000);
    }
    if (f != stdin) fclose(f);
    return 0;
}

static void uso(const char* p) {
    printf("uso: %s [--env ARCHIVO] [opción]\n"
           "  --env ARCHIVO          archivo de configuración (defecto: $ZZGW_ENV_FILE o /etc/zz-rtsp-gateway/gateway.env)\n"
           "  --check-config         valida la configuración, la muestra y termina\n"
           "  --test-ip IP           indica si IP está dentro de ZZGW_ALLOWED_CIDRS\n"
           "  --simulate ARCH|- ID   publica un flujo DHAV (archivo o stdin) sin cámara, para pruebas\n"
           "  --version\n"
           "Señales: SIGHUP recarga cámaras, redes permitidas y nivel de log; SIGTERM/SIGINT detiene.\n",
           p);
}

// =====================================================================================
// main
// =====================================================================================
int main(int argc, char** argv) {
    g_journal = getenv("JOURNAL_STREAM") != nullptr;
    const char* envDef = getenv("ZZGW_ENV_FILE");
    g_cfg.envFile = envDef ? envDef : "/etc/zz-rtsp-gateway/gateway.env";
    bool envExplicito = envDef != nullptr;

    enum { RUN, CHECK, TESTIP, SIM } modo = RUN;
    std::string arg1, arg2;
    for (int i = 1; i < argc; i++) {
        std::string a = argv[i];
        if (a == "--env" && i + 1 < argc) { g_cfg.envFile = argv[++i]; envExplicito = true; }
        else if (a == "--check-config") modo = CHECK;
        else if (a == "--test-ip" && i + 1 < argc) { modo = TESTIP; arg1 = argv[++i]; }
        else if (a == "--simulate" && i + 2 < argc) { modo = SIM; arg1 = argv[++i]; arg2 = argv[++i]; }
        else if (a == "--version") { printf("zz-rtsp-gateway %s\n", kVersion); return 0; }
        else { uso(argv[0]); return a == "--help" || a == "-h" ? 0 : 2; }
    }
    if (!envExplicito && access(g_cfg.envFile.c_str(), R_OK) != 0) {
        // sin archivo por defecto: sólo variables de entorno
        LOGW("no se encontró %s; se usan variables de entorno y valores por defecto", g_cfg.envFile.c_str());
        g_cfg.envFile.clear();
    }

    std::string err;
    if (!loadConfig(g_cfg, err)) { LOGE("configuración: %s", err.c_str()); return 78; }  // EX_CONFIG
    g_logLevel = g_cfg.logLevel;

    if (modo == CHECK) { imprimirConfig(g_cfg); printf("Configuración OK\n"); return 0; }
    if (modo == TESTIP) {
        bool ok = ipAllowed(g_cfg.allowed, arg1);
        printf("%s: %s\n", arg1.c_str(), ok ? "PERMITIDA" : "RECHAZADA");
        return ok ? 0 : 1;
    }

    signal(SIGPIPE, SIG_IGN);
    struct sigaction sa{};
    sa.sa_handler = [](int s) { if (s == SIGHUP) g_reload = true; else g_run = false; };
    sigaction(SIGINT, &sa, nullptr);
    sigaction(SIGTERM, &sa, nullptr);
    sigaction(SIGHUP, &sa, nullptr);

    if (modo == SIM) return modoSimular(arg1.c_str(), arg2.c_str());

    if (access(g_cfg.ffmpegBin.c_str(), X_OK) != 0) { LOGE("no se encuentra ffmpeg ejecutable en %s", g_cfg.ffmpegBin.c_str()); return 78; }

    if (!ZZNETSDK_Init(OnDisconnect, 0)) { LOGE("ZZNETSDK_Init falló 0x%08X", ZZNETSDK_GetLastError()); return 1; }
    std::vector<char> ip(g_cfg.listenIp.begin(), g_cfg.listenIp.end());
    ip.push_back('\0');
    LLONG srv = ZZNETSDK_ListenServer(ip.data(), (WORD)g_cfg.listenPort, 0, OnService, 0);
    if (!srv) {
        LOGE("ListenServer %s:%d falló 0x%08X", g_cfg.listenIp.c_str(), g_cfg.listenPort, ZZNETSDK_GetLastError());
        ZZNETSDK_Cleanup();
        return 1;
    }
    LOGI("zz-rtsp-gateway %s escuchando registro activo en %s:%d; RTSP en %s; %zu cámaras configuradas",
         kVersion, g_cfg.listenIp.c_str(), g_cfg.listenPort, g_cfg.rtspUrl.c_str(), g_cfg.cams.size());

    time_t lastStats = time(nullptr);
    while (g_run) {
        if (g_reload.exchange(false)) {
            Config nuevo = g_cfg;
            std::string e;
            if (loadConfig(nuevo, e, true)) {
                g_cfg.allowed = nuevo.allowed;
                g_cfg.cams = nuevo.cams;
                g_cfg.allowUnknownIds = nuevo.allowUnknownIds;
                g_cfg.defaultUser = nuevo.defaultUser;
                g_cfg.defaultPass = nuevo.defaultPass;
                g_cfg.logLevel = nuevo.logLevel;
                g_logLevel = nuevo.logLevel;
                LOGI("configuración recargada: %zu cámaras, %zu redes permitidas", g_cfg.cams.size(), g_cfg.allowed.size());
            } else {
                LOGE("recarga descartada: %s", e.c_str());
            }
        }
        std::queue<Evento> q;
        {
            std::lock_guard<std::mutex> lk(g_evMx);
            std::swap(q, g_eventos);
        }
        for (; !q.empty(); q.pop()) {
            if (q.front().tipo == Evento::ALTA) procesarAlta(q.front());
            else procesarBaja(q.front());
        }
        tareasPeriodicas(lastStats);
        usleep(200 * 1000);
    }

    LOGI("deteniendo...");
    while (!g_ses.empty()) cerrarSesion(g_ses.begin()->first, "servicio detenido");
    ZZNETSDK_StopListenServer(srv);
    ZZNETSDK_Cleanup();
    LOGI("detenido");
    return 0;
}
