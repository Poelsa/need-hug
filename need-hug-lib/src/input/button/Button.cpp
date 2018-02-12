#include <input/button/Button.hpp>
#include <input/ConstraintSolver.hpp>

namespace NeedHug
{
    Button::Button(std::function<bool(void)> ImplSpecCallback, std::function<void(void)> Callback, NeedHug::Constraint Constraint) :
        implSpecCallback(ImplSpecCallback), callback(Callback), constraint(Constraint)
    { }

    void Button::Update()
    {
        wasPressed = isPressed;
        isPressed = implSpecCallback();
        if (ResolveConstraint(isPressed, wasPressed, constraint))
        {
            callback();
        }
    }
}