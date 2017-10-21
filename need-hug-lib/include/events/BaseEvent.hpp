#ifndef NEEDHUG_BASEEVENT_HPP
#define NEEDHUG_BASEEVENT_HPP

namespace NeedHug
{
    struct BaseEvent
    {
    };

    struct TestEvent : public BaseEvent
    {
        int a;
    };
}

#endif 
