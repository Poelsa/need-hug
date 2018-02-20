#include <input/InputManager.hpp>

namespace NeedHug
{
    void InputManager::SetButtons(std::vector<std::unique_ptr<Button>>& Buttons)
    {
        buttons = std::move(Buttons);
    }

    void InputManager::Update()
    {
        for (auto& button : buttons)
        {
            button->Update();
        }
    }
}