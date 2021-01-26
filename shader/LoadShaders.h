#ifndef __LOADSHADERS_H__
#define __LOADSHADERS_H__

#include <GL/glew.h>
// #include <gl/freeglut.h>
#include <iostream>
using namespace std;
 
typedef struct {
    GLenum       type;
    const char*  filename;
    GLuint       shader;
} ShaderInfo;
 
GLuint LoadShaders(ShaderInfo*);

#endif