#ifndef __NT_WINDOWS_H__
#define __NT_WINDOWS_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../NTMacro.h"
#include "../event/EventManager.h"

NT_NAMESPACE_BEGIN

class MainWindow
{
public:
    static MainWindow* create();
    void createWindow(int width = 960, int height = 540, const char* title = "NineTails");
    void run(void (*display)());
private:
    int init();
    void update();
private:
    static MainWindow* _mainWin;
    NT_PROPERTY_RDONLY(GLFWwindow *, _winHandle, WinHandle)
    int _width;
    int _height;
    const char* _title;
};

NT_NAMESPACE_END

#endif