#version 410 core 
in vec4 outColor;
// in vec2 outTexCoor;
out vec4 fColor; 

// uniform sampler2D texture1;
// uniform sampler2D texture2;

uniform float timeValue;
void main() 
{ 
    vec4 outColor1 = vec4(outColor.rgb + sin(timeValue), outColor.a);
    // vec4 outColor1 = vec4(outColor.r + sin(timeValue), outColor.g, outColor.b, outColor.a);
    fColor = outColor;//vec4(1.0, .5, .6, 1.0); 
    // fColor = mix(texture(texture1, outTexCoor), texture(texture2, outTexCoor), 0.8);
} 