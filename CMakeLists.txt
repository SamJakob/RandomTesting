cmake_minimum_required(VERSION 3.23)
project(RandomTesting)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_TOOLCHAIN_FILE ./vcpkg/scripts/buildsystems/vcpkg.cmake)

find_package(xxHash CONFIG REQUIRED)

add_executable(RandomTesting src/main.cpp)
target_link_libraries(RandomTesting PRIVATE xxHash::xxhash)
