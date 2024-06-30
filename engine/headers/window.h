#pragma once
#include "external-headers/GLFW/glfw3.h"

class Window {
public:
    Window(int width, int height, const char* title, int swap, int major_version, int minor_version, int profile) {
        glfwInit();

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, major_version);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, minor_version);
        glfwWindowHint(GLFW_OPENGL_PROFILE, profile);

        window = glfwCreateWindow(width, height, title, NULL, NULL);

        glfwMakeContextCurrent(window);
        
        glfwSwapInterval(swap);
    }

    GLFWwindow* getWindow() {
        return window;
    }
private:
    GLFWwindow* window;
};