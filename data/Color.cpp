#include "Color.h"

NT_USING_NAMESPACE

Color3f::Color3f(float r, float g, float b)
{
    this->r = r;
    this->g = g;
    this->b = b;
}

Color3f::Color3f(Color3f &other)
{
    this->r = other.r;
    this->g = other.g;
    this->b = other.b;
}

float Color3f::operator[](int index)
{
    if (index == 0)
        return this->r;
    else if (index == 1)
        return this->g;
    else if (index == 2)
        return this->b;
    return (float)NULL;
}