#include <return_code/ReturnCodeConverter.hpp>
#include <gtest/gtest.h>

using namespace NeedHug;
class ReturnCodeConverterTest : public testing::Test
{
public:
	ReturnCodeConverterTest() {}
	virtual ~ReturnCodeConverterTest() {}

	ReturnCodeConverter* m_returnCodeConverter;

	void SetUp() override { m_returnCodeConverter = new ReturnCodeConverter(); }

	void TearDown() override
	{
		delete m_returnCodeConverter;
	}
};

TEST_F(ReturnCodeConverterTest, simpleTest)
{

}

TEST_F(ReturnCodeConverterTest, convert_codeUnknown)
{
	ASSERT_STREQ("Unknown", m_returnCodeConverter->Convert(ReturnCode::Unknown).info.c_str());
}

TEST_F(ReturnCodeConverterTest, convert_codeRunning)
{
	ASSERT_STREQ("Running", m_returnCodeConverter->Convert(ReturnCode::Running).info.c_str());
}

TEST_F(ReturnCodeConverterTest, convert_codeStopEnd)
{
	ASSERT_STREQ("Stop_End", m_returnCodeConverter->Convert(ReturnCode::Stop_End).info.c_str());
}

TEST_F(ReturnCodeConverterTest, convert_codeStopRestart)
{
	ASSERT_STREQ("Stop_Restart", m_returnCodeConverter->Convert(ReturnCode::Stop_Restart).info.c_str());
}
