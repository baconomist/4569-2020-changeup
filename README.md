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