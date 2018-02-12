#include <input/InputManager.hpp>

namespace NeedHug
{
    void InputManager::AddButtons(std::vector<std::unique_ptr<Button>> Buttons)
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