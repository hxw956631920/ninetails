#ifndef __NT_LOADSHADERS_H__
#define __NT_LOADSHADERS_H__

#include <iostream>
#include <string.h>
#include <GL/glew.h>
#include "../data/Vec.h"
using namespace std;

NT_NAMESPACE_BEGIN

class Shader
{
public:
    // 通过文件创建shader
    void createShaderByFile(const char* fileName);
    // 通过字符串创建shader
    void createShaderByChars(const char* vert, const char* frag);
    // 使用程序段
    void use();
    // 设置uniform
    // bool
    void setUniformBool(const char* name, bool value);
    void setUniform3f(const char* name, Vec3 vec);
    void setUniform1f(const char* name, float value);
    // friend const GLchar* readShader(const char* filename);
private:
    // shader程序段id
    NT_PROPERTY_RDONLY(GLuint, _programID, Program);
};

NT_NAMESPACE_END

#endif