Macaroni Engine is an OpenGL game engine that abstracts all raw OpenGL code and makes writing an OpenGL app much simpler.

Macaroni Engine uses GLEW, GLFW, and STBI.
The install script uses the Homebrew package manager. If you would like to unsintall homebrew, as of 6/26/24, the command is:
"/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/uninstall.sh)""

After you write your code in main.cpp, to compile, run the command: "./engine/build.sh". This will compile and run your code!

If you get the error "permission denied", enter the command: "chmod +x engine/build.sh" to give executable permissions to the shell script.

6-27-24: object.h script is unfinished