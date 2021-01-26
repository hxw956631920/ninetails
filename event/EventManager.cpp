
#include "EventManager.h"


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

}

void EventManager::addEvent(EventBase *event)
{
    if(event != nullptr)
        event_vector.push_back(event);
}

void EventManager::dealEvent()
{
    // 处理事件 
    glfwPollEvents();
    
}