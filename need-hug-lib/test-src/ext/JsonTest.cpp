#include <gtest/gtest.h>
#include <ext/json/src/json.hpp>

using nlohmann::json;

namespace nh
{
	//TODO: float and/or double
	struct SimpleStruct
	{
		std::int64_t integer;
		std::string string;
		bool boolean;
	};

	void to_json(json& j, const SimpleStruct& s) 
	{
		j = json{ { "integer", s.integer },{ "string", s.string},{"boolean", s.boolean} };
	}

	void from_json(const json& j, SimpleStruct& s)
	{
		s.integer = j.at("integer").get<std::int64_t>();
		s.string = j.at("string").get<std::string>();
		s.boolean = j.at("boolean").get<bool>();
	}
}


TEST(JsonTest, SimpleStructTest)
{
	json simpleJson =
R"(
{
	"integer": 69,
	"string": "this is some text",
	"boolean": true
}
)"_json;
	nh::SimpleStruct s = { 69, "this is some text", true };
	json converted = s;
	ASSERT_EQ(converted, simpleJson);
}
