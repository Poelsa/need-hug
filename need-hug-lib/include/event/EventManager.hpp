#ifndef NEEDHUG_EVENTMANAGER_HPP
#define NEEDHUG_EVENTMANAGER_HPP

#include <functional>
#include <vector>
#include <map>
#include <typeindex>

#include <events/BaseEvent.hpp>

namespace NeedHug
{
    class EventManager
    {
    public:
        EventManager() {};
        virtual ~EventManager() = default;

        template <typename T>
        void Subscribe(std::function<void(BaseEvent*)> callback)
        {
            auto key = std::type_index(typeid(T));
            if (eventCallbacks.find(key) == eventCallbacks.end())
            {
                eventCallbacks[key] = std::vector<std::function<void(BaseEvent*)>>();
            }
            eventCallbacks[key].push_back(callback);
        }

        template <typename T>
        void Notify(BaseEvent* payload)
        {
            for (auto callback : eventCallbacks[std::type_index(typeid(T))])
            {
                callback(payload);
            }
        }
        
    private:
        std::map<std::type_index, std::vector<std::function<void(BaseEvent*)>>> eventCallbacks;
    };
}

#endif