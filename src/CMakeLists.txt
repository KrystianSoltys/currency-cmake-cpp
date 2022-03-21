cmake_minimum_required(VERSION 3.8)

include_directories("${PROJECT_SOURCE_DIR}/lib/curl/include")

add_executable (currency-cmake-cpp "currency-cmake-cpp.cpp"  "reader.hpp" "reader.cpp")

target_link_libraries(currency-cmake-cpp "${PROJECT_SOURCE_DIR}/lib/curl/MSVC/Debug/libcurl-d.lib" wldap32 crypt32 Ws2_32)

# TODO: Add tests and install targets if needed.
