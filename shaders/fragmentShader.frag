#version 410 core

in vec3 vertColor;
in vec2 vertTexCoords;

uniform sampler2D u_texImg0;

out vec4 fragmentColor;

void main() {
    fragmentColor = texture(u_texImg0, vertTexCoords) * vec4(vertColor, 0.0);
}