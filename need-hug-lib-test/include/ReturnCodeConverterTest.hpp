#ifndef RETURNCODECONVERTERTEST_HPP
#define RETURNCODECONVERTERTEST_HPP

#include <gtest/gtest.h>

#include <need-hug-lib/include/ReturnCode/ReturnCodeConverter.hpp>

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

#endif