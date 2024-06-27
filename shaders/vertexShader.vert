#version 410 core

layout (location = 0) in vec3 programPosition;
layout (location = 1) in vec3 programColor;
layout (location = 2) in vec2 programTexCoords;

out vec3 vertColor;
out vec2 vertTexCoords;

uniform mat4 transform;

void main() {
    gl_Position = transform * vec4(programPosition, 1.0);

    vertColor = programColor;
    vertTexCoords = programTexCoords;
}