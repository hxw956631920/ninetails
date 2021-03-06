#version 410 core 
layout(location = 0) in vec3 vPosition; 
layout(location = 1) in vec3 vColor; 
layout(location = 2) in vec2 vTexCoord;
out vec4 outColor;
out vec2 outTexCoor;

uniform float timeValue;
void main() 
{ 
    gl_Position = vec4(vPosition, 1.0); 
    outColor    = vec4(vColor, 1.0);
    outTexCoor  = vTexCoord;
} 