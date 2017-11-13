#ifndef NEEDHUG_BINDINGS_HPP
#define NEEDHUG_BINDINGS_HPP

#include <input/KeyMap.hpp>
#include <vector>

namespace NeedHug
{
    static std::vector<KeyMap> InitializeKeyMap()
    {
        std::shared_ptr<EventManager> em = NeedHugContext::GetContext().GetEventManager();
        std::vector<KeyMap> map;
        KeyMap temp;
        
        temp.name = "p1_jump";
        temp.action = UserAction::P1_JUMP;
        temp.key = sf::Keyboard::Key::Space;
        temp.keyState = KeyState::HOLD;
        temp.notify = [&em]() { em->Notify<EventJump*>(new EventJump(1)); };
        map.push_back(temp);

        return map;
    }
}

#endif