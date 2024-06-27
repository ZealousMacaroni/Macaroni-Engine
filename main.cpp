#include "engine/macaroni-engine.h"
#include <iostream>
#include "string"

int main() { 
    glfwInit();
    
    Window win(720, 720, "app", 10);

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
        //positions           //color coords      //tex coords
        -0.5f, -0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   0.0f, 0.0f,
        0.5f, -0.5f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f,
        0.5f, 0.5f, 0.0f,     0.0f, 0.0f, 1.0f,   1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f,    0.5f, 0.5f, 0.0f,   0.0f, 1.0f
    };

    unsigned int indices[6] = {
        0, 1, 2, 2, 3, 0
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

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, 0);
    glEnableVertexAttribArray(0); //this binds the vertex attrib pointer to the currently bound array buffer at index 0 of the VAO

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 8, (void*)(sizeof(float) * 6));
    glEnableVertexAttribArray(2);

    Texture tex0(GL_TEXTURE_2D, 0, GL_RGB, GL_RGBA, true);

    tex0.loadData("container.jpeg", true);
    tex0.createTexture();
    tex0.loadDataIntoTexture();
    tex0.setSamplerUniform(shader.getProgramID());

    Matrix4x4 scaleMatrix;
    scaleMatrix.setIdentity(2.0f);
    float* matrix =scaleMatrix.get();

    unsigned int transformLocation = glGetUniformLocation(shader.getProgramID(), "transform");
    glUniformMatrix4fv(transformLocation, 1, GL_TRUE, scaleMatrix.get());
    
    while (!glfwWindowShouldClose(win.getWindow())) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

        glfwSwapBuffers(win.getWindow());

        glfwPollEvents(); 
    };
    glfwTerminate();
    return 0;
}