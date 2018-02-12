#ifndef NEEDHUG_COMPONENT_HPP
#define NEEDHUG_COMPONENT_HPP

#include <need-hug-lib/include/components/BaseComponent.hpp>

namespace NeedHug
{
    template <typename T>
    class Component : public BaseComponent
    {
    public:
        virtual ~Component() {}
        static const int typeId = __COUNTER__;
    };
}

#endif