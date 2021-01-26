#ifndef __NT_EVENTMANAGER_H__
#define __NT_EVENTMANAGER_H__

#include "EventBase.h"
#include "EventKeyBoard.h"
#include "EventMouse.h"
#include <vector>

NT_NAMESPACE_BEGIN

class EventManager : public NTObject
{
public:
    static EventManager *create();
    // 添加事件
    void addEvent(EventBase *event);
    // 处理事件
    void dealEvent();
protected:
    EventManager(){};
    EventManager(const EventManager&){};
    ~EventManager(){};
    EventManager& operator=(const EventManager&){};
    void init();
private:
    static EventManager *_eventManager;
    std::vector<EventBase *> _event_vector;
};

NT_NAMESPACE_END

#endif