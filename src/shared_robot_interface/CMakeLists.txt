set(VERSION "2.8.4") # Create var "VERSION"

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})
project(SharedRobotInterface CXX)

file(GLOB SOURCES "src/*.c" "src/*.h" "src/*.cpp" "src/*.hpp")

# Enable DLL build w/ option() and SHARED flag in add_library()
option(MyLib_SHARED_LIBS "" ON)
add_library(SharedRobotInterface SHARED ${SOURCES})
