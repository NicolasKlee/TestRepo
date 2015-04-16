#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 uv;

out vec2 passUV;

void main(){

    gl_Position = position;
    passUV = uv;
}