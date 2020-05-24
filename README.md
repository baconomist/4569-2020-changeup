4569-2020-changeup

# Getting Clion Working:
- Use mingw
- This error message is ok: <b>c:/mingw/bin/../lib/gcc/mingw32/8.2.0/../../../../mingw32/bin/ld.exe: c:/mingw/bin/../lib/gcc/mingw32/8.2.0/../../../libmingw32.a(main.o):(.text.startup+0xb0): undefined reference to `WinMain@16'</b>
- Restart clion and refresh NOT rebuild cmake project



# PROS INSTALLATION
 ####DO NOT COMMIT PROS LIB FILES
 

# Simulator Setup (TODO)
1. Create a unity project
2. Install this Unity plugin: https://github.com/mcpiroman/UnityNativeTool

Setup a clean-slate robot repo for people to clone and build...

# CLion
Write down all the clion cmake setup instructions here like going into build->cmake and adding -G "visual studio..."
Maybe download cmake? Or using visual studio environment inside clion is probs good enough...

Have to set robot cmake->toolchain->gcc by using cygwin as toolchain or mingw...


# PROS
If you get an error like "No rule to make target 'path/foo.ccp', needed by 'foo.o'. Stop." Then you must have changed the
PROS src/ dir and need to for some reason do a project search for the path its complaining about "path/foo.cpp" and replace
it with the correct path


# Project Structure
* **robot/** --> Abstract Robot Code Via A SharedAPI. (Depends on sim/non-sim build in globals.h)
* **robot_api/** --> PROS Robot API Code
* **shared_api/** --> A Shared Api header Lib
* **simulator_api/** --> Unity Simulator Code

# COMPILING FOR ROBOT
1. COMPILE CMAKE ROBOT
2. COPY libRobot.a from build dir
3. MOVE libRobot.a into PROS firmware dir TODO: MAKE A SCRIPT FOR THIS
4. COMPILE/UPLOAD PROS

# ARM COMPILER STUFF
* Vex Brain Architecture "ARM 7": https://www.vexrobotics.com/276-4810.html#Product_Specs
* ARM COMPILER DOWNLOAD: https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm
* ******************** **USE MINGW** ******************** CYGWIN **DOES NOT** WORK DUE TO IT APPENDING /cygdrive/c/ to paths when calling the compiler
* INSIDE CLION, FOR MINGW TOOLCHAIN, SET COMPILER TO THE DOWNLOADED ARM COMPILER
* '--specs=nosys.specs' is used to prevent compiler errors related to undefined _exit. This is since on ARM platforms,
such standard methods don't exist as they do on computers or something like that... --> https://stackoverflow.com/questions/19419782/exit-c-text0x18-undefined-reference-to-exit-when-using-arm-none-eabi-gcc
