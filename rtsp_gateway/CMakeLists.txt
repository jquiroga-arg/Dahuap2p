cmake_minimum_required(VERSION 3.16)
project(zz_rtsp_gateway VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ZZNETSDK_ROOT "/opt/zznetsdk" CACHE PATH "Instalación de ZZNetSDK")

find_package(OpenSSL 3 REQUIRED)
find_package(Threads REQUIRED)
find_library(PSL_LIB psl REQUIRED)

add_executable(zz-rtsp-gateway src/zz_rtsp_gateway.cpp)
target_compile_options(zz-rtsp-gateway PRIVATE -Wall -Wextra)
target_include_directories(zz-rtsp-gateway PRIVATE ${ZZNETSDK_ROOT}/include)
target_link_libraries(zz-rtsp-gateway PRIVATE
    ${ZZNETSDK_ROOT}/lib_linux64/libZZNetSDK.so
    ${ZZNETSDK_ROOT}/lib_linux64/libgeneral_netsdk.so
    ${ZZNETSDK_ROOT}/lib_linux64/libgeneral_configsdk.so
    OpenSSL::SSL OpenSSL::Crypto ${PSL_LIB} Threads::Threads)

install(TARGETS zz-rtsp-gateway RUNTIME DESTINATION bin)
