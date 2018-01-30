#ifndef NEEDHUG_CONTRAINTSOLVER_HPP
#define NEEDHUG_CONTRAINTSOLVER_HPP

#include <input/button/Constraint.hpp>

namespace NeedHug
{
    static bool ResolveConstraint(bool isPressed, bool wasPressed, Constraint constraint)
    {
        switch (constraint)
        {
        case Constraint::HOLD:
            if (isPressed)
            {
                return true;
            }
            else
            {
                return false;
            }
        case Constraint::KEY_DOWN:
            if (isPressed && !wasPressed)
            {
                return true;
            }
            else
            {
                return false;
            }
        case Constraint::KEY_UP:
            if (!isPressed && wasPressed)
            {
                return true;
            }
            else
            {
                return false;
            }
        default:
            return false;
        }
    }
}

#endif