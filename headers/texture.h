#define STB_IMAGE_IMPLEMENTATION

#pragma once
#include "string"
#include "external-headers/GL/glew.h"
#include "external-headers/GLFW/glfw3.h"
#include "STBI/stb_image.h"


class Texture {
public:
    Texture(unsigned int type, unsigned int texunit, unsigned int imgtype, unsigned int outtype, bool domipmap) : textureType(type), textureUnitID(texunit), imageColorFormat(imgtype), textureColorFormat(outtype), generateMipmap(domipmap) {}

    void createTexture() {
        glGenTextures(1, &textureID);
        glActiveTexture(GL_TEXTURE0 + textureUnitID);
        glBindTexture(textureType, textureID);
    }

    void loadData(std::string name, bool flipVerticaly) {
        std::string filepath = "assets/" + name;
        stbi_set_flip_vertically_on_load(flipVerticaly);
        data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);
    }

    void loadDataIntoTexture() {
        glTexImage2D(textureType, 0, textureColorFormat, width, height, 0, imageColorFormat, GL_UNSIGNED_BYTE, data);
        if(generateMipmap) {
            glGenerateMipmap(textureType);
        }
    }

    void setSamplerUniform(unsigned int program) {
        std::string res;
        res = std::string("u_texImg") + std::to_string(textureUnitID);
        u_location = glGetUniformLocation(program, res.c_str());
        glUniform1i(u_location, textureUnitID);
    }
    void texParameteri(int type) {

    }

    ~Texture() {
        stbi_image_free(data);
        glDeleteTextures(1, &textureID);
    }
private:
    unsigned int textureID, textureUnitID, textureType, imageColorFormat, textureColorFormat;
    int width, height, nrChannels, u_location;
    unsigned char * data;
    bool generateMipmap;
};