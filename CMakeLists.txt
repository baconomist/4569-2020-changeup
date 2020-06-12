set(VERSION "2.8.4") # Create var "VERSION"
# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})

if (${CMAKE_PROFILE} MATCHES "RobotCompile")
    include(toolchain.cmake)
endif ()

project(RobotCode CXX C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
# https://docs.microsoft.com/en-us/cpp/build/reference/compiler-option-warning-level?view=vs-2019
if (MSVC)
    # https://stackoverflow.com/questions/31639611/c-callstack-on-windows-access-violation /EHa tells compiler to handle SEH exceptions as standard try/catch
    add_compile_options(/W4 /W2 /wd4514 /Od /ZI /Zi)
    MESSAGE("USING MSVC; Using Cmake Profile: ${CMAKE_PROFILE}")
else ()
    add_compile_options(-pedantic -Werror -ffunction-sections -fdata-sections -fdiagnostics-color -funwind-tables)
    MESSAGE("USING GCC; Using Cmake Profile: ${CMAKE_PROFILE}")
endif ()

# # # # # # # # # # # # # # #
# # # Add sub projects # # #
# # # # # # # # # # # # # #

add_subdirectory("shared_api")

# Can only compile SimulatorAPI with MSVC(Visual Studio Microsoft Compiler)
if (MSVC)
    add_subdirectory("simulator_api")
# Can only compiler RobotAPI w/ ARM GCC Compiler
else ()
    add_subdirectory("robot_api")
endif ()
# Robot can be built with either since its an abstract API
add_subdirectory("robot")

