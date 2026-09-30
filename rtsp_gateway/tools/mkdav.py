# Genera un flujo DHAV sintético (formato privado Dahua) a partir de H.264 Annex B,
# para probar la cadena: callback SDK -> ffmpeg -f dhav -> RTSP.
import struct, sys, time
data = open(sys.argv[1], 'rb').read()
aud = b'\x00\x00\x00\x01\x09'
parts = [p for p in data.split(aud) if p]
out = sys.stdout.buffer
fps = 25
for n, p in enumerate(parts):
    au = aud + p
    # tipo: 0xFD si contiene IDR (nal type 5) o SPS (7), si no 0xFC
    i = au.find(b'\x00\x00\x01')
    key = False
    while i != -1:
        t = au[i+3] & 0x1f
        if t in (5, 7): key = True; break
        i = au.find(b'\x00\x00\x01', i+3)
    ext = bytes([0x80, 0, 640//8, 480//8, 0x81, 0, 0x08, fps])
    flen = 24 + len(ext) + len(au) + 8
    ts = (n * 1000 // fps) & 0xffff
    lt = time.localtime()
    date = (lt.tm_sec | lt.tm_min<<6 | lt.tm_hour<<12 | lt.tm_mday<<17 | lt.tm_mon<<22 | (lt.tm_year-2000)<<26)
    hdr = b'DHAV' + bytes([0xFD if key else 0xFC, 0, 0, 0]) + struct.pack('<IIIHBB', n, flen, date, ts, len(ext), 0)
    out.write(hdr + ext + au + b'dhav' + struct.pack('<I', flen))
    out.flush()
    if len(sys.argv) > 2: time.sleep(1/fps)   # tiempo real
