set(VERSION "2.8.4") # Create var "VERSION"
set(SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*) # Create var "SOURCE_FILES", I guess init.c is enough cus anything linked to it is compiled?

# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})
project(Robot CXX C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
# https://docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level?view=vs-2019
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

file(GLOB SOURCES "src/*.c" "src/*.h" "src/*.cpp" "src/*.hpp")

include_directories(Robot "${CMAKE_CURRENT_SOURCE_DIR}/../../include")
add_library(Robot ${SOURCES} ${INCLUDES} ${CMAKE_CURRENT_SOURCE_DIR})

# https://stackoverflow.com/questions/28597351/how-do-i-add-a-library-path-in-cmake
# https://stackoverflow.com/questions/38858275/how-to-import-a-file-to-cmake-in-c
# Add firmware/ libraries
target_link_libraries(Robot exec "${CMAKE_CURRENT_SOURCE_DIR}/../../firmware/libpros.a")
target_link_libraries(Robot exec "${CMAKE_CURRENT_SOURCE_DIR}/../../firmware/okapilib.a")
target_link_libraries(Robot exec "${CMAKE_CURRENT_SOURCE_DIR}/../../firmware/libm.a")
target_link_libraries(Robot exec "${CMAKE_CURRENT_SOURCE_DIR}/../../firmware/libc.a")


#add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR} COMMAND prosv5 mut)