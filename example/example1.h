#ifndef __NT_EXAMPLE1_H__
#define __NT_EXAMPLE1_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../shader/LoadShaders.h"
#include "NTMacro.h"
#include "NTConstant.h"

namespace NT_EXAMPLE1{

enum VAO_IDs { PosVAO, ColorVAO, NumVAOs};

enum Buffer_IDs { PosVBO, ColorVBO, NumVBOs};

enum Attrib_IDs { vPosition = 0, vColor = 1 };

void init();

void init1();
void init2();
void init3();

void display();

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

}

#endif