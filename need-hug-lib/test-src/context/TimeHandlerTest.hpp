#ifndef NEEDHUG_TIMEHANDLERTEST_HPP
#define NEEDHUG_TIMEHANDLERTEST_HPP

#include <gtest/gtest.h>
#include <context/TimeHandler.hpp>

class TimeHandlerTest : public testing::Test
{
public:
    TimeHandlerTest() {}
    virtual ~TimeHandlerTest() {}

    NeedHug::TimeHandler* timeHandler;

    void SetUp() override { timeHandler = new NeedHug::TimeHandler(true); }
    void TearDown() override { delete timeHandler; }
};

#endif