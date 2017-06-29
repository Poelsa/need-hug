#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace NeedHug
{
    class Component
    {
    public:
        virtual ~Component() = 0;
    
    private:
        static int typeId;
    };
}

#endif