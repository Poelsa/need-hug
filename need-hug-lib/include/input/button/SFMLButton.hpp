#ifndef NEEDHUG_SFMLBUTTON_HPP
#define NEEDHUG_SFMLBUTTON_HPP

#include <input/button/Button.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace NeedHug
{
    struct ButtonActionDefinition
    {
        std::string key;
        std::string constraint;
        std::function<void(void)> dispatchAction;
    };
    class SFMLButton : public Button
    {
    public:
        SFMLButton(const ButtonActionDefinition& definition);
        ~SFMLButton() override = default;
        
        SFMLButton(SFMLButton&& button) = delete;
        SFMLButton(const SFMLButton& button) = delete;

        bool IsValid() override;
        void DoStuff() override;
    private:
        const ButtonActionDefinition definition;
        const sf::Keyboard::Key sfKey;
        bool wasPressed;
        bool isPressed;
    };
}
#endif