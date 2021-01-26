#include "EventKeyBoard.h"

NT_USING_NAMESPACE

EventKeyBoard* EventKeyBoard::create()
{
    EventKeyBoard *event = new EventKeyBoard();
    if (event != nullptr)
    {
        auto mainWindow = MainWindow::create();
        glfwSetKeyCallback(mainWindow, EventKeyBoard::callback);
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
            auto window = MainWindow::create();
            glfwSetWindowShouldClose(window, true);
            break;
        }
    }
}