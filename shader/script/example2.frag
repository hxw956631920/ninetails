#version 410 core 
in vec4 outColor;
in vec2 outTexCoor;
out vec4 fColor; 

uniform sampler2D texture1;
// uniform sampler2D texture2;

void main() 
{ 
    fColor = texture(texture1, outTexCoor);
    // fColor = outColor;
} 