#pragma once
#include <cmath>

class Matrix4x4 {
public:
    void setIdentity(float identity) {
        matrix[0] = identity;
        matrix[5] = identity;
        matrix[10] = identity;
    };

    float* get() {
        return matrix;
    }

    void setElement(int index, float value) {
        matrix[index] = value;
    }
private:
    float matrix[16] = {
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
};