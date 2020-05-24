#    set(CMAKE_C_COMPILER_FORCED TRUE)
#    set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_EXE_LINKER_FLAGS "--specs=nosys.specs" CACHE INTERNAL "")

# Fixes undefined reference to `_exit'
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} --specs=nosys.specs")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --specs=nosys.specs")

#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

#    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -D_POSIX_THREADS -D_UNIX98_THREAD_MUTEX_ATTRIBUTES --target=arm-arm-none-eabi -marm")

MESSAGE("Loaded toolchain.cmake")