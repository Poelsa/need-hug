#ifndef NEEDHUG_EVENTMANAGER_HPP
#define NEEDHUG_EVENTMANAGER_HPP

#include <functional> // std::function, std::reference_wrapper, std::bind
#include <type_traits> // std::decay
#include <vector> // std::vector
#include <cassert> // std::assert
#include <iostream> // std::cout, std::cin, std::endl, TODO

using std::cin; // TODO
using std::cout;
using std::endl;

namespace NeedHug
{
    template<class T>
    class EventManager final
    {
        //using Event = std::reference_wrapper<const std::decay_t<T>>;
        using Event = T;
        using Callback = std::function<bool(const Event&)>;
        using CallbackHandle = void;

    public:
        static void Setup()
        {
            assert(instance == nullptr);
            instance = new EventManager();
        }

        static void Teardown()
        {
            assert(instance != nullptr);
            delete instance;
        }

        static EventManager& GetInstance()
        {
            assert(instance != nullptr);
            return *instance;
        }

        EventManager(EventManager& eventManager) = delete;
        EventManager(EventManager&& eventManager) = delete;
		
		CallbackHandle Subscribe(Callback&& callBack) // TODO, confirm that both are used.
        {
			cout << "A" << endl;
            subscribers.push_back(callBack);
        }

		CallbackHandle Subscribe(Callback& callBack) // TODO, confirm that both are used.
		{
			cout << "Q" << endl;
			subscribers.push_back(callBack);
		}

		/*
			This function must not carry the same signature as the one which only takes one parameter, thus the second argument.
			And the second argument will always be required if the function is to be binded within here.
		*/
        template<typename CallableT, typename SecondArg, typename ... ArgTs>
		CallbackHandle Subscribe(CallableT&& callable, SecondArg&& secondArg, ArgTs&& ... args)
        {
			static_assert(std::is_bind_expression<CallableT>::value == false, "Parameter must not already by bound with std::bind.");
            cout << "C" << endl;
            subscribers.push_back(Callback(std::bind(callable, secondArg, std::forward<ArgTs>(args)...)));
        }

        template<class U>
        void QueueEvent(U&& event)
        {
            cout << "QueueEvent" << endl;
            cout << "Value: " << event << endl;
            cout << endl;
            // Required to abuse the universal reference effect for U&&
            static_assert(std::is_same<std::decay_t<U>, std::decay_t<T>>::value, "U must be the same as T");
            events.push_back(Event(event));
        }

        void ProcessEvents()
        {
            std:: cout << "events.size(): " << events.size() << endl;
            std:: cout << "callback.size(): " << subscribers.size() << endl;
            for(const auto& event : events)
            {
            //  cout << event.get() << endl;
            //  cout << event << endl;
                for(const auto& callback : subscribers)
                {
                    bool remove = callback(event);
                    if(remove)
                    {
                        // Remove callback TODO
                    }
                }
            }
            events.clear();
        }

    private:
        EventManager() = default;
        ~EventManager() = default;

        std::vector<Callback> subscribers;
        std::vector<Event> events;

		static EventManager* instance;
    };

	template<class T>
	EventManager<T>* EventManager<T>::instance = nullptr;
}

#endif