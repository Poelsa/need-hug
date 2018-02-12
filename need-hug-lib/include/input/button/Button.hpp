#ifndef NEEDHUG_BUTTON_HPP
#define NEEDHUG_BUTTON_HPP

#include <functional>
#include <string>

#include <input/button/Constraint.hpp>

namespace NeedHug
{
    class Button
    {
    public:
        Button(std::function<bool(void)> ImplSpecCallback, std::function<void(void)> Callback, Constraint Constraint);
        virtual ~Button() {};

        Button(Button&& button) = delete;
        Button(const Button& button) = delete;

        void Update();

    private:
        bool wasPressed;
        bool isPressed;

        std::function<bool(void)> implSpecCallback;
        std::function<void(void)> callback;
        Constraint constraint;
    };
}
#endif