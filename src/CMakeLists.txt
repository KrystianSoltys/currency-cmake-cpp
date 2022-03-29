cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("${PROJECT_SOURCE_DIR}/lib/curl/include")

add_executable (currency "main.cpp" "reader.hpp" "reader.cpp" "application.hpp" "application.cpp" "ui.hpp" "ui.cpp")

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(currency "${PROJECT_SOURCE_DIR}/lib/curl/GCC/${CMAKE_BUILD_TYPE}/libcurl.a" wldap32 crypt32 Ws2_32)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_link_libraries(currency "${PROJECT_SOURCE_DIR}/lib/curl/MSVC/${CMAKE_BUILD_TYPE}/libcurl.lib" wldap32 crypt32 Ws2_32)
endif()
add_compile_definitions(CURL_STATICLIB)



# TODO: Add tests and install targets if needed.
