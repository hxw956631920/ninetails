#ifndef __NT_COLOR3_H__
#define __NT_COLOR3_H__

#include "../NTMacro.h"
#include <iostream>

NT_NAMESPACE_BEGIN

class Color3f
{
public:
    Color3f(){};
    Color3f(float r, float g, float b);
    Color3f(Color3f& other);
    float operator[](int index);
public:
    float r;
    float g;  
    float b; 
};

NT_NAMESPACE_END

#endif