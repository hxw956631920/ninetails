#version 410 core 
layout(location = 0) in vec3 vPosition; 
layout(location = 1) in vec3 vColor; 
layout(location = 2) in vec2 vTexCoord;
out vec3 outColor;
out vec2 outTexCoor;

uniform float timeValue;
void main() 
{ 
    gl_Position = vec4(vPosition, 1.0); 
    outColor    = vColor;
    outTexCoor  = vTexCoord;
} 