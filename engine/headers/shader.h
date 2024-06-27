#pragma once
#include <iostream>
#include <fstream>
#include "string"
#include "external-headers/GL/glew.h"
#include "external-headers/GLFW/glfw3.h"

class Shader {
public:
    void compileShader(std::string name, unsigned int type, unsigned int &id) {
        std::string source;
        std::string shadersFolderPath = "shaders/";
        
        source = getContentFromFile(shadersFolderPath + name);
        
        const char* code = source.c_str();

        id = glCreateShader(type);
        glShaderSource(id, 1, &code, NULL);
        glCompileShader(id);

        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if(!success) {
            glGetShaderInfoLog(id, 512, NULL, infoLog);
            std::cout << "Shader " << type << " compilation failed. Info Log: " << infoLog << std::endl;
        }

        infoLog[0] = '\0';
        success = 0;
    }

    void compileProgram() {
        programID = glCreateProgram();
        glAttachShader(programID, vertexID);
        glAttachShader(programID, fragmentID);

        glLinkProgram(programID);

        glValidateProgram(programID);

        glGetProgramiv(programID, GL_LINK_STATUS, &success);

        if (!success) {
            glGetProgramInfoLog(programID, 512, NULL, infoLog);
            std::cout << "Program linking failed. Info Log: " <<infoLog << std::endl;  
        }
    }

    void useProgram() {
        glUseProgram(programID);
    }

    unsigned int getProgramID() {
        return programID;
    }

    unsigned int * getVertexShaderIDPointer() {
        return &vertexID;
    }

    unsigned int * getFragmentShaderIDPointer() {
        return &fragmentID;
    }

    ~Shader() {
        glDeleteProgram(programID);
        glDeleteShader(vertexID);
        glDeleteShader(fragmentID);
    }
    
private:
    std::string getContentFromFile(std::string filepath) {
        std::ifstream file(filepath);
        std::string line, source;
        while (getline(file, line)) {
            source.append(line + "\n");
        }
        return source;
    }   
    unsigned int programID, vertexID, fragmentID;
    char infoLog[512];
    int success;
};