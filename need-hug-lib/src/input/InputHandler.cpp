#include <input/InputHandler.hpp>
#include <context/NeedHugContext.hpp>
#include <event/EventManager.hpp>
#include <input/bindings.hpp>

#include <memory>

namespace NeedHug
{
    InputHandler::InputHandler()
    {
        testMapList = InitializeKeyMap();
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