#include <input/button/ButtonFactory.hpp>
#include <input/button/Button.hpp>
#include <configuration/InputConfiguration.hpp>

#include <tuple>

namespace NeedHug
{
    std::vector<std::unique_ptr<Button>> GetSFMLButtons()
    {
        std::vector<std::unique_ptr<Button>> list;
        list.emplace_back(InputConfiguration::DefaultInputConfig(ActionType::JUMP, PlayerId::P1));
    }
}