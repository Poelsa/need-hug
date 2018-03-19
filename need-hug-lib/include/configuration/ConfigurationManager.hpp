#ifndef NEEDHUG_CONFIGURATIONMANAGER_HPP
#define NEEDHUG_CONFIGURATIONMANAGER_HPP

#include <string>

namespace NeedHug
{
	class ConfigurationManager
	{
	public:
		ConfigurationManager() = default;
		~ConfigurationManager() = default;
		ConfigurationManager(const ConfigurationManager& configurationManager) = delete;
		ConfigurationManager(ConfigurationManager&& configurationManager) = delete;

		bool GetValue(const std::string& name, std::string& value);
		bool GetValue(const std::string& name, std::int32_t& value);
		bool GetValue(const std::string& name, float& value);
		bool GetValue(const std::string& name, bool& value);
	};
}

#endif