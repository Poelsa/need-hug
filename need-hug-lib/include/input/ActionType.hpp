#ifndef NEEDHUG_ACTIONTYPE_HPP
#define NEEDHUG_ACTIONTYPE_HPP

#include <string>

namespace NeedHug
{
    enum class ActionType
    {
        JUMP,
        CROUCH,
        MOVE_LEFT,
        MOVE_RIGHT,
        ATTACK,
        BLOCK
    };

    static std::string ToString(ActionType actionType)
    {
        switch (actionType)
        {
        case ActionType::JUMP:
            return "JUMP";
        case ActionType::CROUCH:
            return "CROUCH";
        case ActionType::MOVE_LEFT:
            return "MOVE_LEFT";
        case ActionType::MOVE_RIGHT:
            return "MOVE_RIGHT";
        case ActionType::ATTACK:
            return "ATTACK";
        case ActionType::BLOCK:
            return "BLOCK";
        default:
            break;
        }
        return "";
    }
}

#endif