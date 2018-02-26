#include <configuration/InputConfiguration.hpp>
#include <configuration/ConfigurationManager.hpp>

namespace NeedHug
{
    ButtonActionDefinition InputConfiguration::DefaultInputConfig(ActionType actionType, PlayerId playerId)
    {
        std::string buttonString = ConfigurationManager::GetValue(actionType.toString() + "_" + playerId.toString());
        StringToButton(buttonString); //Hur konverteras knappsträngen till ButtonActionDefinition?
    }
}