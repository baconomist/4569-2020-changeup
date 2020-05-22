set(VERSION "2.8.4") # Create var "VERSION"
# Disable sh.exe mingw error
set(DCMAKE_SH="CMAKE_SH-NOTFOUND")

cmake_minimum_required(VERSION ${VERSION})

project(RobotCode CXX)

# Add sub projects
add_subdirectory("src/robot")
add_subdirectory("src/shared_robot_interface")
add_subdirectory("src/simulator")
