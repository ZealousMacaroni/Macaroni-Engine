#version 410 core

in vec3 vertColor;

out vec4 fragmentColor;

void main() {
    fragmentColor = vec4(vertColor, 0.0);
}