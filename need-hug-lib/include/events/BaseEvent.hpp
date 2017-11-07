#ifndef NEEDHUG_BASEEVENT_HPP
#define NEEDHUG_BASEEVENT_HPP

namespace NeedHug
{
    // TODO: Namespace events?
    struct BaseEvent
    {
        virtual ~BaseEvent() {}
    };

    struct EventJump : public BaseEvent
    {
        explicit EventJump(int p) : player(p) {};
        int player;
    };
}

#endif 
