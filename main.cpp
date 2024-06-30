#include "engine/macaroni-engine.h"

int main() {     
    Window win(640, 480, "app", 1, 4, 1, GLFW_OPENGL_CORE_PROFILE);

    glewInit();
    
    VertexArrayObject VAO;

    Vertex v1(-1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f);
    Vertex v2(1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    Vertex v3(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);

    VertexBuffer VBO(3);
    VBO.intizalizeVertexElements(v1, v2, v3);
    VBO.initializeData();

    Shader shader("vertex.glsl", "fragment.glsl");
    shader.useShader();
    
    while (!glfwWindowShouldClose(win.getWindow())) {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(win.getWindow());

        glfwPollEvents(); 
    };
    glfwTerminate();
    return 0;
}