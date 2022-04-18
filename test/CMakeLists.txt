#testing
cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories("${PROJECT_SOURCE_DIR}/lib/curl/include")
include_directories("${PROJECT_SOURCE_DIR}/src")


add_executable (test1 "test.cpp" "../src/reader.hpp" "../src/reader.cpp" "../src/application.hpp" "../src/application.cpp" "../src/ui.hpp" "../src/ui.cpp")
add_test(No_arguments_app_execute test1)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()
add_compile_definitions(CURL_STATICLIB)


if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	target_link_libraries(test1 "${PROJECT_SOURCE_DIR}/lib/curl/GCC/${CMAKE_BUILD_TYPE}/libcurl.a" wldap32 crypt32 Ws2_32)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	target_link_libraries(test1 "${PROJECT_SOURCE_DIR}/lib/curl/MSVC/${CMAKE_BUILD_TYPE}/libcurl.lib" wldap32 crypt32 Ws2_32)
endif()