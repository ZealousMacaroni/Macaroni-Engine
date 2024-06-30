#pragma once
#include "external-headers/GL/glew.h"
#include "external-headers/GLFW/glfw3.h"
#include "shader.h"
#include "texture.h"

class Vertex {
public:
    Vertex(float posv1, float posv2, float posv3, float colv1, float colv2, float colv3) : vertex{posv1, posv2, posv3, colv1, colv2, colv3} {};

    float* get() {
        return vertex;
    }
private:
    float vertex[6];
};

class VertexArrayObject {
public:
    VertexArrayObject() {
        glGenVertexArrays(1, &id);
        bind();
    }

    void bind() {
        glBindVertexArray(id);
    }

    void unbind() {
        glBindVertexArray(0);
    }

    ~VertexArrayObject() {
        glDeleteVertexArrays(1, &id);
    }

private:
    unsigned int id;
};

class Buffer {
public:
    Buffer(unsigned int buffer_type): type(buffer_type) {
        glGenBuffers(1, &id);
    }

    void bind() {
        glBindBuffer(type, id);
    }

    void unbind() {
        glBindBuffer(type, 0);
    }

    ~Buffer() {
        glDeleteBuffers(1, &id);
    }

private:
    unsigned int id, type;
};

class VertexBuffer : public Buffer {
public:
    VertexBuffer(int vertices) : Buffer(GL_ARRAY_BUFFER), n_of_floats(vertices * 6) {
        data = new float[n_of_floats]; 
    };

    void intizalizeVertexElements(Vertex v1, Vertex v2, Vertex v3) {
        setElement(0, v1);
        setElement(1, v2);
        setElement(2, v3);
    }

    void initializeData() {
        bind();
        glBufferData(GL_ARRAY_BUFFER, n_of_floats * 4, data, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (void*)(sizeof(float) * 3));
        glEnableVertexAttribArray(1);
    }

    void setDataAsnullptr() {  
        data = nullptr;
    }

    ~VertexBuffer() {
        if (data != nullptr) {
            delete[] data;
        }
    }

private:
    void setElement(int this_dataIndex, Vertex v) {
        float* contents = v.get();

        this_dataIndex *= 6;
        
        int index = this_dataIndex + 6;
        
        for (int vert_index = 0; this_dataIndex < (index); this_dataIndex++) {
            data[this_dataIndex] = contents[vert_index]; vert_index++;
        }
    }

    float* data;
    int n_of_floats;
};