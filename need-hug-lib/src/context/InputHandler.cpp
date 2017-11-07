#include <context/InputHandler.hpp>
#include <context/NeedHugContext.hpp>
#include <event/EventManager.hpp>

#include <memory>

namespace NeedHug
{
    InputHandler::InputHandler()
    {
        std::shared_ptr<EventManager> em = NeedHugContext::GetContext().GetEventManager();
        KeyMap thingy;
        thingy.action = UserAction::P1_JUMP;
        thingy.key = sf::Keyboard::Key::Space;
        thingy.keyState = KeyState::HOLD;
        thingy.notify = [&em]() { em->Notify<EventJump*>(new EventJump(1)); };
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
                km.notify();
            }
            else if (km.wasPressed && !sf::Keyboard::isKeyPressed(km.key))
            {
                km.wasPressed = false;
                if(km.keyState == KeyState::HOLD)
                {
                    //Do end event
                    km.notifyStop();
                }
            }
        }

    }
}