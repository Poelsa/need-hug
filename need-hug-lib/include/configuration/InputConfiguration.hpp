#ifndef NEEDHUG_INPUTCONFIGURATION_HPP
#define NEEDHUG_INPUTCONFIGURATION_HPP

#include <input/ActionType.hpp>
#include <input/PlayerId.hpp>

namespace NeedHug
{
	class InputConfiguration
	{
	public:
		InputConfiguration() = default;
		~InputConfiguration() = default;
		InputConfiguration(const InputConfiguration& configurationManager) = delete;
		InputConfiguration(InputConfiguration&& configurationManager) = delete;

        ButtonActionDefinition DefaultInputConfig(ActionType actionType, PlayerId playerId);
	};
}

#endif