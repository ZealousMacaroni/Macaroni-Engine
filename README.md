Macaroni Engine is an OpenGL game engine that abstracts the raw OpenGL code and makes writing an OpenGL app much simpler.

Macaroni Engine uses GLEW, GLFW, and STBI.

To install all required libraries, run the install.sh script.

The install script uses the Homebrew package manager. If you would like to unsintall homebrew, the command is:
"/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/uninstall.sh)""

After you write your code in main.cpp, to compile, run the command: "./engine/build.sh" to run the shell script that will compile and run the code!.

If you get the error "permission denied", enter the command: "chmod +x engine/build.sh" to give executable permissions to the shell script.

If you have any questions please create an issue.
