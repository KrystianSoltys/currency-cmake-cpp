cmake_minimum_required(VERSION 3.8)

include_directories("${PROJECT_SOURCE_DIR}/lib/curl/include")

add_executable (currency "main.cpp" "reader.hpp" "reader.cpp" "application.hpp" "application.cpp" "ui.hpp" "ui.cpp")

target_link_libraries(currency "${PROJECT_SOURCE_DIR}/lib/curl/MSVC/Debug/libcurl-d.lib" wldap32 crypt32 Ws2_32)

add_compile_definitions(CURL_STATICLIB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# TODO: Add tests and install targets if needed.
