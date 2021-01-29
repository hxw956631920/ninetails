#version 410 core 
in vec4 outColor;
out vec4 fColor; 

uniform float timeValue;
void main() 
{ 
    vec4 outColor1 = vec4(outColor.rgb + sin(timeValue), outColor.a);
    // vec4 outColor1 = vec4(outColor.r + sin(timeValue), outColor.g, outColor.b, outColor.a);
    fColor = outColor1;//vec4(1.0, .5, .6, 1.0); 
} 