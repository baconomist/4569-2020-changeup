set(VERSION "2.8.4") # Create var "VERSION"
# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})

project(RobotCode CXX C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS}")
# https://docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level?view=vs-2019
if(MSVC)
    add_compile_options(/W4 /WX /W2 /wd4514 /Od /ZI /Zi)
    MESSAGE("USING MSVC; Using Cmake Profile: ${CMAKE_PROFILE}")
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
    MESSAGE("USING GCC; Using Cmake Profile: ${CMAKE_PROFILE}")
endif()

# Add sub projects (order here matters!)
add_subdirectory("shared_api")
add_subdirectory("simulator_api")
add_subdirectory("robot_api")
add_subdirectory("robot")
