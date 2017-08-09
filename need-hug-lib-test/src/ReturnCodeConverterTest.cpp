#include <ReturnCodeConverterTest.hpp>

TEST_F(ReturnCodeConverterTest, simpleTest)
{

}

TEST_F(ReturnCodeConverterTest, convert_codeUnknown)
{
	ASSERT_STREQ("Unknown", m_returnCodeConverter->Convert(ReturnCode::Unknown).info.c_str());
}

TEST_F(ReturnCodeConverterTest, convert_codeContinue)
{
	ASSERT_STREQ("Continue", m_returnCodeConverter->Convert(ReturnCode::Continue).info.c_str());
}

TEST_F(ReturnCodeConverterTest, convert_codeStop)
{
	ASSERT_STREQ("Stop", m_returnCodeConverter->Convert(ReturnCode::Stop).info.c_str());
}
