#ifndef NEEDHUG_BASEEVENT_HPP
#define NEEDHUG_BASEEVENT_HPP

namespace NeedHug
{
    struct BaseEvent
    {
        virtual ~BaseEvent() {}
    };

    struct TestEvent : public BaseEvent
    {
        int a;
    };
}

#endif 
