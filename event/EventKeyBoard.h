#ifndef __NT_EVENT_KEY_BOARD_H__
#define __NT_EVENT_KEY_BOARD_H__

#include "EventBase.h"

NT_NAMESPACE_BEGIN

class EventKeyBoard : public EventBase
{
public:
    EventKeyBoard *create();
};

NT_NAMESPACE_END

#endif
