#ifndef __NT_EVENT_H__
#define __NT_EVENT_H__

#include <GLFW/glfw3.h>
#include "../NTMacro.h"

NT_NAMESPACE_BEGIN

// 事件类型
enum EventType{
    // 鼠标事件
    NT_MOUSE_EVENT,
    // 键盘事件
    NT_KEYBOARD_EVENT
};

// 事件响应回调
union EventCallBack{
    // 键盘事件回调
    void (* keyboard_callback)(GLFWwindow* window, int key, int scancode, int action, int mods);
    // 鼠标事件回调
    void (* mouse_callback)(GLFWwindow* window, double xpos, double ypos);
};

// 事件基类
class EventBase
{
protected:
    EventBase();
    ~EventBase();
protected:
    // 事件类型
    EventType _type;
};

NT_NAMESPACE_END

#endif