#ifndef NEEDHUG_BUTTON_HPP
#define NEEDHUG_BUTTON_HPP

#include <functional>
#include <tuple>

#include <input/button/Constraint.hpp>

namespace NeedHug
{
    using ActiveButtonCallback = std::function<bool(void)>;
    using ActionCallback = std::function<void(void)>;
    using ButtonActionDefinition = std::tuple<ActiveButtonCallback, ActionCallback, Constraint>;
    class Button
    {
    public:
        explicit Button(ButtonActionDefinition buttonActionDefinition);
        virtual ~Button() {};

        Button(Button&& button) = delete;
        Button(const Button& button) = delete;

        void Update();

    private:
        bool wasPressed;
        bool isPressed;

        const ActiveButtonCallback isActiveButtonCallback;
        const ActionCallback callback;
        const Constraint constraint;
    };
}
#endif