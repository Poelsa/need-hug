#include <context/InputHandler.hpp>

namespace NeedHug
{
    InputHandler::InputHandler()
    {
        KeyMap thingy;
        thingy.action = UserAction::P1_MOVE_RIGHT;
        thingy.key = sf::Keyboard::Key::Left;
        thingy.keyState = KeyState::HOLD;
        testMapList.push_back(thingy);
    }

    void InputHandler::Update()
    {
        for (const auto& km : testMapList)
        {
            if (!km.wasPressed && sf::Keyboard::isKeyPressed(km.key))
            {
                //Do (start) event
            }
            else if (km.keyState == KeyState::HOLD && km.wasPressed && !sf::Keyboard::isKeyPressed(km.key));
            {
                //Do end event
            }
        }

    }
}