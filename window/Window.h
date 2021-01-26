#ifndef __NT_WINDOWS_H__
#define __NT_WINDOWS_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../NTMacro.h"

NT_NAMESPACE_BEGIN

class MainWindow
{
public:
    static GLFWwindow* create();
    static GLFWwindow* create(int width, int height, const char* title);
    static void run();
private:
    static int init();
    static void update();
private:
    static GLFWwindow *_winHandle;
    static int _width;
    static int _height;
    static const char* _title;
};

NT_NAMESPACE_END

#endif