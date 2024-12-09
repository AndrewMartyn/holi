cmake_minimum_required(VERSION 3.8)
project(holi-chat-server LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g -ggdb3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Werror")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_ENABLE_EXPORTS ON)

message("-- Build: ${CMAKE_BUILD_TYPE}")
message("-- System: ${CMAKE_SYSTEM_NAME}")

find_package(SQLite3 REQUIRED)

add_subdirectory(holi)

