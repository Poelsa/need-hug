#ifndef NEEDHUG_CONFIGURATIONDATA_HPP
#define NEEDHUG_CONFIGURATIONDATA_HPP

#include <unordered_map>
#include <string>

namespace NeedHug
{
	namespace ConfigurationData
	{
		const std::unordered_map<std::string, std::string> stringData =
		{
			{"this is a key", "this is a value"}
		};

		const std::unordered_map<std::string, std::int32_t> intData =
		{
			{"this is a key", 42}
		};

		const std::unordered_map<std::string, float> floatData =
		{
			{"this is a key", 4.2f}
		};

		const std::unordered_map<std::string, bool> boolData =
		{
			{"this is a key", false}
		};
	}
}


#endif