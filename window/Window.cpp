
#include "Window.h"
#include <iostream>

NT_USING_NAMESPACE

GLFWwindow* MainWindow::_winHandle = nullptr;
int MainWindow::_width = 0;
int MainWindow::_height = 0;
const char* MainWindow::_title = "";

GLFWwindow *MainWindow::create()
{
    if(_winHandle == nullptr)
    {
        if (!glfwInit())
            return nullptr;
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        _width = 960;
        _height = 540;
        _title = "NineTails";
        _winHandle = glfwCreateWindow(_width, _height, _title, NULL, NULL);
        init();
    }
    return _winHandle;
}

GLFWwindow *MainWindow::create(int width, int height, const char* title)
{
    if(_winHandle == nullptr)
    {
        if (!glfwInit())
            return nullptr;
        _width = width;
        _height = height;
        _title = title;
        _winHandle = glfwCreateWindow(width, height, title, NULL, NULL);
        init();
    }
    return _winHandle;
}

int MainWindow::init()
{
    if (!_winHandle)
    {
        glfwTerminate(); 
        return -1;
    }
    // 设置当前窗口上下文
    glfwMakeContextCurrent(_winHandle);
    // gladLoadGL(glfwGetProcAddress);
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    // glew初始化
    if (glewInit())
    {
        std::cerr << "Unable to initialize GLEW ... exiting" << std::endl;
        exit(1);
    }
}

void MainWindow::run()
{
    while (!glfwWindowShouldClose(_winHandle))
    {
        update();
    }

    glfwTerminate();
}

void MainWindow::update()
{

}

