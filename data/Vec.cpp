
#include "Vec.h"

NT_USING_NAMESPACE

Vec2::Vec2(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vec2::Vec2(Vec2 &other)
{
    this->x = other.x;
    this->y = other.y;
}

Vec2 Vec2::operator+(Vec2& other)
{
    Vec2 result;
    result.x = this->x += other.x;
    result.y = this->y += other.y;
    return result;
}

float Vec2::operator[](int index)
{
    if (index == 0)
        return this->x;
    else if (index == 1) 
        return this->y;
}



Vec3::Vec3(float x, float y)
{
    this->x = x;
    this->y = y;
}

Vec3::Vec3(Vec3 &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
}

Vec3::Vec3(Vec2 &other)
{
    this->x = other.x;
    this->y = other.y;
    this->z = 0.0;
}

Vec3 Vec3::operator+(Vec3& other)
{
    Vec3 result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    result.z = this->z + other.z;
    return result;
}

Vec3 Vec3::operator+(Vec2& other)
{
    Vec3 result;
    result.x = this->x + other.x;
    result.y = this->y + other.y;
    result.z = this->z + 0.0;
    return result;
}

Vec2 Vec3::operator=(Vec2& other)
{
    Vec2 result;
    result.x = other.x;
    result.y = other.y;
    return result;
}

float Vec3::operator[](int index)
{
    if (index == 0)
        return this->x;
    else if (index == 1) 
        return this->y;
    else if (index == 2)
        return this->z;
}