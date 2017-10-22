#ifndef NEEDHUG_EVENTMANAGER_HPP
#define NEEDHUG_EVENTMANAGER_HPP

#include <functional>
#include <vector>
#include <map>

#include <events/BaseEvent.hpp>

namespace NeedHug
{
    class EventManager
    {
    public:
        EventManager() {};
        virtual ~EventManager() = default;

        void Subscribe(int eventId, std::function<void(BaseEvent*)> callback)
        {
            if (eventCallbacks.find(eventId) == eventCallbacks.end())
            {
                eventCallbacks[eventId] = std::vector<std::function<void(BaseEvent*)>>();
            }
            eventCallbacks[eventId].push_back(callback);
        }

        void Notify(int eventId, BaseEvent* payload)
        {
            for (auto callback : eventCallbacks[eventId])
            {
                callback(payload);
            }
        }
        
    private:
        std::map<int, std::vector<std::function<void(BaseEvent*)>>> eventCallbacks;
    };
}

#endif