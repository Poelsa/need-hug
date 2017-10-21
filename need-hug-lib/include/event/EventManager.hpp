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

        template <typename T>
        void Subscribe<T>(std::function<void(T)> callback)
        {
            eventCallbacks.push_back(callback);
        }

        template <typename T>
        void Notify<T>(T payload)
        {
            for (auto callback : eventCallbacks)
            {
                callback(payload);
            }
        }
        
    private:
        template <typename T>
        std::vector<std::function<void(T)>> eventCallbacks;
    };
}

#endif