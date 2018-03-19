#include <configuration/InputConfiguration.hpp>
#include <configuration/ConfigurationManager.hpp>

#include <SFML/Window/Keyboard.hpp>

namespace NeedHug
{
    ButtonActionDefinition InputConfiguration::DefaultInputConfig(ActionType actionType, PlayerId playerId)
    {
        std::string buttonString;
        if (!ConfigurationManager::GetValue(ToString(actionType) + "_" + ToString(playerId) + "_key", &buttonString))
        {
            return ButtonActionDefinition();
        }
        int buttonConstraint;
        if (!ConfigurationManager::GetValue(ToString(actionType) + "_" + ToString(playerId) + "_constraint") &buttonConstraint)
        {
            return ButtonActionDefinition();
        }
        
        return ButtonActionDefinition(StringToActiveButtonCallback(buttonString),
                                      EnumsToActionCallback(actionType, playerId),
                                      IntToConstraint(buttonConstraint));
    }

    ActiveButtonCallback InputConfiguration::StringToActiveButtonCallback(const std::string& buttonString)
    {
        auto sfKey = giveKey(buttonString);
        return [sfKey]()->bool {return sf::Keyboard::isKeyPressed(sfKey); };
    }

    ActionCallback InputConfiguration::EnumsToActionCallback(const ActionType actionType, const PlayerId playerId)
    {
        auto actionCallback = giveEvent(actionType, playerId);
        return[actionCallback]()->{ /*event*/ };
    }
}