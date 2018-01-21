#ifndef NEEDHUG_INPUTMANAGER_HPP
#define NEEDHUG_INPUTMANAGER_HPP

#include <vector>
#include <input/button/Button.hpp>

namespace NeedHug
{
    class InputManager
    {
    public:
        InputManager() {};
        virtual ~InputManager() = default;

    private:
        std::vector<Button*> buttons;

    };
}

#endif