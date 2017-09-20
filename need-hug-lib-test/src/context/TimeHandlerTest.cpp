#include <context/TimeHandlerTest.hpp>

TEST_F(TimeHandlerTest, GetElapsedTime)
{
    ASSERT_LT(timeHandler->GetElapsedTime(), 1.0f/60);
    timeHandler->Update();
    ASSERT_GE(timeHandler->GetElapsedTime(), 1.0f/60);
}

TEST_F(TimeHandlerTest, GetTotalTime)
{
    timeHandler->Update();
    timeHandler->Update();
    ASSERT_GE(timeHandler->GetTotalTime(), 2.0f/60);
}