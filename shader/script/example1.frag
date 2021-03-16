#version 410 core 
in vec4 outColor;
out vec4 fColor; 

uniform float timeValue;
void main() 
{ 
    fColor = outColor;
} 