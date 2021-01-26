
#include "EventMouse.h"

NT_USING_NAMESPACE

EventMouse *EventMouse::create()
{
    EventMouse *event = new EventMouse();
    if (event != nullptr)
    {
        return event;
    }
    return nullptr;
}
    
void EventMouse::doEvent()
{

}