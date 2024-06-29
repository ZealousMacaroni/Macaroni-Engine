#version 410 core

layout (location = 0) in vec3 programPosition;
layout (location = 1) in vec3 programColor;

out vec3 vertColor;

void main() {
    gl_Position = vec4(programPosition, 1.0);

    vertColor = programColor;
}