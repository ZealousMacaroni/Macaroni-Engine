#pragma once
#include "external-headers/GLFW/glfw3.h"

class Window {
public:
    Window(int wid, int hght, const char* name, int swap_rate) : width(wid), height(hght), title(name), swap(swap_rate) {};

    void setupWindow() {
        window = glfwCreateWindow(width, height, title, NULL, NULL);
        glfwMakeContextCurrent(window);
        glfwSwapInterval(swap);
    }

    void modifyWindowAttribute(unsigned int attribute, unsigned int value) {
        glfwWindowHint(attribute, value);
    }

    GLFWwindow* getWindow() {
        return window;
    }

    int getWidth() {
        return width;
    }

    int getHeight() {
        return height;
    }
private:
    GLFWwindow* window;
    int width, height, swap;
    const char* title;
};