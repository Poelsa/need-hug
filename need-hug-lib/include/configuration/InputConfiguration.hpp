#ifndef NEEDHUG_INPUTCONFIGURATION_HPP
#define NEEDHUG_INPUTCONFIGURATION_HPP

namespace NeedHug
{
	class InputConfiguration
	{
	public:
		InputConfiguration() = default;
		~InputConfiguration() = default;
		InputConfiguration(const InputConfiguration& configurationManager) = delete;
		InputConfiguration(InputConfiguration&& configurationManager) = delete;
	};
}

#endif