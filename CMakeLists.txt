set(VERSION "2.8.4") # Create var "VERSION"
# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})

project(RobotCode CXX)

# Add sub projects (order here matters!)
add_subdirectory("shared_api")
add_subdirectory("robot_api")
add_subdirectory("simulator_api")
add_subdirectory("robot")
