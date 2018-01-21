#ifndef NEEDHUG_CONFIGURATIONMANAGER_HPP
#define NEEDHUG_CONFIGURATIONMANAGER_HPP

namespace NeedHug
{
	class ConfigurationManager
	{
	public:
		ConfigurationManager() = default;
		~ConfigurationManager() = default;
		ConfigurationManager(const ConfigurationManager& configurationManager) = delete;
		ConfigurationManager(ConfigurationManager&& configurationManager) = delete;
	};
}

#endif