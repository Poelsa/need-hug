#include <gtest/gtest.h>
#include <ext/json/src/json.hpp>

#include <variant>

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


	using JValue = std::variant<std::string, std::int64_t, bool>;

	struct JObject
	{
		std::string name;
		JValue value;
	};

	void to_json(json& j, const JObject& s)
	{
		std::visit([j, s](auto&& arg)
		{
			using T = std::decay_t<decltype(arg)>;
			j = json{ {s.name, arg} };

			if constexpr (std::is_same_v<T, std::string>)
			{

			}
			else if constexpr (std::is_same_v<T, std::int64_t>)
			{

			}
			else if constexpr (std::is_same_v<T, bool>)
			{

			}
			else {
				static_assert(false, "non-exhaustive visitor!");
			}
		}, s.value
		);
	//	j = json{ { "integer", s.integer },{ "string", s.string },{ "boolean", s.boolean } };
	}

	/*
	void from_json(const json& j, JObject& s)
	{
		s.integer = j.at("integer").get<std::int64_t>();
		s.string = j.at("string").get<std::string>();
		s.boolean = j.at("boolean").get<bool>();
	}
	*/
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
