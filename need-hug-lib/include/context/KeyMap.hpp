#ifndef NEEDHUG_KEYMAP_HPP
#define NEEDHUG_KEYMAP_HPP

#include <SFML/Keyboard.hpp>

namespace NeedHug 
{
    // Action | Key | KeyState
    // P1_MOVE_LEFT | kb::left | HOLD

    enum class UserAction
    {
        P1_MOVE_LEFT;
        P1_MOVE_RIGHT;
        P1_JUMP;
    };

    enum class KeyState
    {
        PRESSED,
        HOLD
    };

    struct KeyMap
    {
        UserAction action;
        sf::Keyboard::Key key;
        KeyState keyState;
        bool wasPressed = false;
    };

}

#endif