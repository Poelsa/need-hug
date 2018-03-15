#include <configuration/InputConfiguration.hpp>
#include <configuration/ConfigurationManager.hpp>

namespace NeedHug
{
    ButtonActionDefinition InputConfiguration::DefaultInputConfig(ActionType actionType, PlayerId playerId)
    {
        std::string buttonString = ConfigurationManager::GetValue(actionType.toString() + "_" + playerId.toString() + "_key");
        int buttonConstraint = ConfigurationManager::GetValue(actionType.toString() + "_" + playerId.toString() + "_constraint");
        StringToActiveButtonCallback(buttonString); 
        EnumToActionCallback(actionType, playerId);
        IntToContraintCallback(buttonConstraint);
    }

    // string till activebuttoncallback
}