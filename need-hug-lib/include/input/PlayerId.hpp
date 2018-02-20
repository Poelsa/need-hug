#ifndef NEEDHUG_PLAYERID_HPP
#define NEEDHUG_PLAYERID_HPP

namespace NeedHug
{
    enum class PlayerId
    {
        P1,
        P2
    };

    static std::string ToString(PlayerId playerId)
    {
        switch (playerId)
        {
        case PlayerId::P1:
            return "P1";
        case PlayerId::P2:
            return "P2";
        default:
            break;
        }
        return "";
    }
}

#endif