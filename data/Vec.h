#ifndef __NT_VEC2_H__
#define __NT_VEC2_H__

#include "../NTMacro.h"
#include <iostream>

NT_NAMESPACE_BEGIN

class Vec2
{
public:
    Vec2(){};
    Vec2(float x, float y);
    Vec2(Vec2 &other);
    Vec2 operator+(Vec2& other);
    float operator[](int index);
public:
    float x;
    float y;
};

class Vec3
{
public:
    Vec3(){};
    Vec3(float x, float y);
    Vec3(Vec3 &other);
    Vec3(Vec2 &other);
    Vec3 operator+(Vec3& other);
    Vec3 operator+(Vec2& other);
    Vec2 operator=(Vec2& other);
    float operator[](int index);
public:
    float x;
    float y;  
    float z; 
};

NT_NAMESPACE_END

#endif