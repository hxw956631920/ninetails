#ifndef __NT_VEC_COLOR_H__
#define __NT_VEC_COLOR_H__

#include "../NTMacro.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Vec.h"
#include "Color.h"

NT_NAMESPACE_BEGIN

class Vec_Color
{
public:
    Vec_Color(){};
    Vec_Color(Vec2 &vec, Color3f &color);
    Vec_Color(Vec3 &vec, Color3f &color);
    // operator GLfloat*[]();
private:
    Vec3 _vec;
    Color3f _color;
};

NT_NAMESPACE_END

#endif