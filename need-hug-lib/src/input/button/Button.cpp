#include <input/button/Button.hpp>
#include <input/ConstraintSolver.hpp>

namespace NeedHug
{
    Button::Button(ButtonActionDefinition buttonActionDefinition) :
        isActiveButtonCallback(std::get<ActiveButtonCallback>(buttonActionDefinition)), callback(std::get<ActionCallback>(buttonActionDefinition)), constraint(std::get<Constraint>(buttonActionDefinition))
    { }

    void Button::Update()
    {
        wasPressed = isPressed;
        isPressed = isActiveButtonCallback();
        if (ResolveConstraint(isPressed, wasPressed, constraint))
        {
            callback();
        }
    }
}