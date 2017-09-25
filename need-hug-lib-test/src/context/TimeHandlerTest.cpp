#include <context/TimeHandlerTest.hpp>

TEST_F(TimeHandlerTest, GetElapsedTime)
{
    // Check that the dT less than one tick
    ASSERT_LT(timeHandler->GetElapsedTime(), 1.0f/60);
    // After update check that dT is over one tick
    timeHandler->Update();
    ASSERT_GE(timeHandler->GetElapsedTime(), 1.0f/60);
}

TEST_F(TimeHandlerTest, GetTotalTime)
{
    timeHandler->Update();
    timeHandler->Update();
    ASSERT_GE(timeHandler->GetTotalTime(), 2.0f/60);
}