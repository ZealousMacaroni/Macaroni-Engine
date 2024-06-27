#pragma once
#include "external-headers/GL/glew.h"
#include "external-headers/GLFW/glfw3.h"
#include "shader.h"
#include "texture.h"

class Vertex {
public:
    Vertex(float posv1, float posv2, float posv3, float colv1, float colv2, float colv3) : vertex{posv1, posv2, posv3, colv1, colv2, colv3} {};

    void setVector(bool targetPosition, float v1, float v2, float v3) {
        if (targetPosition) {
            vertex[0] = v1; vertex[1] = v2; vertex[2] = v3;
        } else {
            vertex[3] = v1; vertex[4] = v2; vertex[5] = v3;
        }
    }
private:
    float vertex[6];
};

class VertexArrayObject {
public:
    VertexArrayObject(unsigned int count) {
        glGenVertexArrays(count, &id);
    }

    void bind() {
        glBindVertexArray(id);
    }

    ~VertexArrayObject() {
        glDeleteVertexArrays(1, &id);
    }
private:
    unsigned int id;
};

class Buffer {
public:
    Buffer(unsigned int buffer_type, bool bind) {
        glGenBuffers(1, &id);
        if (bind) {
            bindBuffer();
        }
    }

    void bindBuffer() {
        glBindBuffer(type, id);
    }

    void unbindBuffer() {
        glBindBuffer(type, 0);
    }

    ~Buffer() {
        glDeleteBuffers(1, &id);
    }

private:
    unsigned int id, type;
};

class VertexBuffer : Buffer {
public:
    VertexBuffer(unsigned int buffer_type, bool bind, int vertices) : Buffer(buffer_type, bind), n_of_vertices(vertices) {
        data = new float[vertices]; 
    };

    float* get() {
        return data;
    }

    ~VertexBuffer() {
        delete[] data;
    }

private:
    float* data;
    int n_of_vertices;
};

class IndexBuffer : Buffer {
public:
    IndexBuffer(unsigned int buffer_type, bool bind, int vertices) : Buffer(buffer_type, bind), n_of_vertices(vertices) {
        data = new int[vertices]; 
    };

    int* get() {
        return data;
    }

    ~IndexBuffer() {
        delete[] data;
    }

private:
    int* data;
    int n_of_vertices;
};

class Object {
public:
    VertexArrayObject VAO;
    VertexBuffer Buffer;
    IndexBuffer IBO;
    Vertex v1, v2, v3;
    Texture tex;
    Shader shader;
    
private:
    bool useTexture;
};