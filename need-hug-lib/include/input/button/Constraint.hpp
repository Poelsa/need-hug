#ifndef NEEDHUG_CONTRAINT_HPP
#define NEEDHUG_CONTRAINT_HPP

namespace NeedHug
{
    enum class Constraint
    {
        HOLD,
        KEY_DOWN,
        KEY_UP
    };

    static Constraint IntToConstraint(const int constraint)
    {
        switch (constraint)
        {
        case 0:
            return Constraint::HOLD;
        case 1:
            return Constraint::KEY_DOWN;
        case 2:
            return Constraint::KEY_UP;
        default:
            break;
        }
    }
}

#endif