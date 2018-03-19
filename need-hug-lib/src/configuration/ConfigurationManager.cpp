#include <configuration/ConfigurationManager.hpp>
#include <configuration/ConfigurationData.hpp>

bool NeedHug::ConfigurationManager::GetValue(const std::string& name, std::string& value)
{
    if (NeedHug::ConfigurationData::stringData.count(name) == 0)
    {
        return false;
    }
	value = NeedHug::ConfigurationData::stringData.at(name);
	return true;
}

bool NeedHug::ConfigurationManager::GetValue(const std::string& name, std::int32_t& value)
{
	if (NeedHug::ConfigurationData::intData.count(name) == 0)
    {
        return false;
    }
	value = NeedHug::ConfigurationData::intData.at(name);
	return true;
}

bool NeedHug::ConfigurationManager::GetValue(const std::string& name, float& value)
{
	if (NeedHug::ConfigurationData::floatData.count(name) == 0)
    {
        return false;
    }
	value = NeedHug::ConfigurationData::floatData.at(name);
	return true;
}

bool NeedHug::ConfigurationManager::GetValue(const std::string& name, bool& value)
{
	if (NeedHug::ConfigurationData::boolData.count(name) == 0)
    {
        return false;
    }
	value = NeedHug::ConfigurationData::boolData.at(name);
	return true;
}
