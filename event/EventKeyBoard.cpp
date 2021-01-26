
#include "EventBase.h"
#include "EventKeyBoard.h"

NT_USING_NAMESPACE

EventKeyBoard* EventKeyBoard::create()
{
    EventKeyBoard *event = new EventKeyBoard();
    if (event != nullptr)
    {
        return event;
    }
    return nullptr;
}