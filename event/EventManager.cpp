
#include "EventManager.h"
#include "EventKeyBoard.h"
#include "EventMouse.h"

NT_USING_NAMESPACE

EventManager* EventManager::_eventManager = nullptr;

EventManager* EventManager::create()
{
    if(_eventManager == nullptr)
    {
        _eventManager = new EventManager();
    }
    // 初始化
    _eventManager->init();
    return _eventManager;
}

void EventManager::init()
{
    // 注册键盘事件
    EventBase *keyboardEvent = (EventBase *)EventKeyBoard::create();
    // this->addEvent(keyboardEvent);
}

void EventManager::addEvent(EventBase *event)
{
    if(event != nullptr)
    {
        _event_vector.push_back(event);
    }  
}

void EventManager::dealEvent()
{
    // 处理事件 
    glfwPollEvents();
    // std::vector<EventBase *>::iterator iter = _event_vector.begin();    
    // for (; iter != _event_vector.end(); iter++)
    // {
    //     (*iter)->doEvent();
    // }
}