#include "Vec_Color.h"

NT_USING_NAMESPACE

Vec_Color::Vec_Color(Vec2 &vec, Color3f &color)
:_vec(vec), _color(color)
{
    
}

Vec_Color::Vec_Color(Vec3 &vec, Color3f &color)
:_vec(vec), _color(color)
{

}

Vec_Color::operator GLfloat**()
{
    GLfloat (*vec_color)[3] = new GLfloat[2][3];
    for (int i = 0; i < 3; i++)
    {
        vec_color[0][j] = _vec[j];
        vec_color[1][j] = _color[j];
    }
    return vec_color;
}