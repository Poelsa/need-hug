#include <input/button/ButtonFactory.hpp>
#include <input/button/Button.hpp>

#include <tuple>

namespace NeedHug
{
    std::vector<std::unique_ptr<Button>> ButtonFactory::GetSFMLButtons()
    {
        std::vector<std::unique_ptr<Button>> list;
        list.emplace_back(getbutton(PlayerId, ActionType);
    }
}