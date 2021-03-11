#ifndef __NT_EXAMPLE2_H__
#define __NT_EXAMPLE2_H__

#include "../image/stb_image.h"
#include "lib/glew/include/glew.h"
#include "lib/glfw/include/glfw3.h"
#include "../shader/LoadShaders.h"
#include "NTMacro.h"
#include "NTConstant.h"

namespace NT_EXAMPLE2{

enum Attrib_IDs { vPosition = 0, vColor = 1, vTexture = 2 };

void init();

void display();

void keyboardCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

}

#endif