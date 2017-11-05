#include <context/InputHandler.hpp>
#include <context/NeedHugContext.hpp>
#include <event/EventManager.hpp>

#include <iostream>

namespace NeedHug
{
    InputHandler::InputHandler()
    {
        KeyMap thingy;
        thingy.action = UserAction::P1_JUMP;
        thingy.key = sf::Keyboard::Key::Space;
        thingy.keyState = KeyState::HOLD;
        thingy.event = new EventJump(1);
        testMapList.push_back(thingy);
    }

    void InputHandler::Update()
    {
        for (auto& km : testMapList)
        {
            if (!km.wasPressed && sf::Keyboard::isKeyPressed(km.key))
            {
                km.wasPressed = true;
                //Do (start) event
                NeedHugContext::GetContext().GetEventManager()->Notify<EventJump*>(km.event);
            }
            else if (km.wasPressed && !sf::Keyboard::isKeyPressed(km.key))
            {
                km.wasPressed = false;
                if(km.keyState == KeyState::HOLD)
                {
                    //Do end event
                }
            }
        }

    }
}