
#include "Window.h"
#include <iostream>

NT_USING_NAMESPACE

class EventManager;

MainWindow* MainWindow::_mainWin = nullptr;

MainWindow *MainWindow::create()
{
    if(_mainWin == nullptr)
    {
        _mainWin = new MainWindow();
    }
    return _mainWin;
}

void MainWindow::createWindow(int width, int height, const char* title)
{
    if (_winHandle == nullptr)
    {
        if (!glfwInit())
            return ;
        _width = width;
        _height = height;
        _title = title;
        _winHandle = glfwCreateWindow(width, height, title, NULL, NULL);
        init();
    }
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
    glfwSwapInterval(1);

    glewExperimental = GL_TRUE;
    // glew初始化
    if (glewInit())
    {
        std::cerr << "Unable to initialize GLEW ... exiting" << std::endl;
        exit(1);
    }
    return 1;
}

void MainWindow::run(void (*display)())
{
    // 创建事件管理器
    EventManager *eventManager = EventManager::create();
    while (!glfwWindowShouldClose(_winHandle))
    {
        // update();
        display();
        glfwSwapBuffers(_winHandle);
        eventManager->dealEvent();
    }
    glfwDestroyWindow(_winHandle);
    glfwTerminate();
}

void MainWindow::update()
{

}

