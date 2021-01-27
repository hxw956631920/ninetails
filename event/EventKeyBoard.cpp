#include "EventKeyBoard.h"

NT_USING_NAMESPACE

EventKeyBoard* EventKeyBoard::create()
{
    EventKeyBoard *event = new EventKeyBoard();
    if (event != nullptr)
    {
        MainWindow* mainWindow = MainWindow::create();
        GLFWwindow* handle = mainWindow->getWinHandle();
        glfwSetKeyCallback(handle, EventKeyBoard::callback);
        return event;
    }
    return nullptr;
}

void EventKeyBoard::doEvent()
{

}

void EventKeyBoard::callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case NT_KEY_ESCAPE:
            MainWindow *window = MainWindow::create();
            GLFWwindow* winHandle = window->getWinHandle();
            glfwSetWindowShouldClose(winHandle, true);
            break;
        }
    }
}