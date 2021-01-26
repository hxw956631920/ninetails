#ifndef __NT_EVENTMOUSE_H__
#define __NT_EVENTMOUSE_H__


#include "EventBase.h"

NT_NAMESPACE_BEGIN

class EventMouse : public EventBase
{
public:
    EventMouse *create();
    void doEvent();
private:
    void callback(GLFWwindow* window, double xpos, double ypos);
};

NT_NAMESPACE_END

#endif