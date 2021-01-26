#ifndef __NT_EVENT_KEY_BOARD_H__
#define __NT_EVENT_KEY_BOARD_H__

#include "../ninetails.h"

NT_NAMESPACE_BEGIN

class EventKeyBoard : public EventBase
{
public:
    static EventKeyBoard *create();
    void doEvent();
    static void callback(GLFWwindow* window, int key, int scancode, int action, int mods);
private:
    EventKeyBoard(){};
};

NT_NAMESPACE_END

#endif
