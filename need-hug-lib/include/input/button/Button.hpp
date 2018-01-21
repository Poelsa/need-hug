#ifndef NEEDHUG_BUTTON_HPP
#define NEEDHUG_BUTTON_HPP

#include <functional>
#include <string>

namespace NeedHug
{
    class Button
    {
    public:
        Button() = default;
        virtual ~Button() {};

        Button(Button&& button) = delete;
        Button(const Button& button) = delete;

        virtual bool IsValid() = 0;
        virtual bool DoStuff() = 0;
    };
}
#endif