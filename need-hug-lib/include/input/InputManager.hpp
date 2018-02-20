#ifndef NEEDHUG_INPUTMANAGER_HPP
#define NEEDHUG_INPUTMANAGER_HPP

#include <vector>
#include <memory>

#include <input/button/Button.hpp>

namespace NeedHug
{
    class InputManager
    {
    public:
        InputManager() {};
        virtual ~InputManager() = default;

        void SetButtons(std::vector<std::unique_ptr<Button>>& Buttons);
        void Update();

    private:
        std::vector<std::unique_ptr<Button>> buttons;

    };
}

#endif