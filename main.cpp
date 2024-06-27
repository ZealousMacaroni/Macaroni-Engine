#include "engine/macaroni-engine.h"
#include <iostream>
#include "string"

int main() { 
    glfwInit();
    
    Window win(640, 480, "app", 1);

    win.modifyWindowAttribute(GLFW_CONTEXT_VERSION_MAJOR, 4);
    win.modifyWindowAttribute(GLFW_CONTEXT_VERSION_MINOR, 1);
    win.modifyWindowAttribute(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    win.setupWindow();

    glewInit();

    Shader shader;

    shader.compileShader("vertexShader.vert", GL_VERTEX_SHADER, *shader.getVertexShaderIDPointer());
    shader.compileShader("fragmentShader.frag", GL_FRAGMENT_SHADER, *shader.getFragmentShaderIDPointer());

    shader.compileProgram();

    shader.useProgram();
    
    float points[32] = {
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,
        0.0f, 0.5f, 0.0f,     0.0f, 0.0f, 1.0f,
    };

    unsigned int indices[3] = {
        0, 1, 2
    };

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    unsigned int buffer_points;
    glGenBuffers(1, &buffer_points);
    glBindBuffer(GL_ARRAY_BUFFER, buffer_points);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

    unsigned int buffer_indices;
    glGenBuffers(1, &buffer_indices);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer_indices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);
    
    while (!glfwWindowShouldClose(win.getWindow())) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(win.getWindow());

        glfwPollEvents(); 
    };
    glfwTerminate();
    return 0;
}