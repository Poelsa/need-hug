#include <context/TimeHandlerTest.hpp>
#include <thread>
#include <chrono>

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

TEST_F(TimeHandlerTest, PauseAndResume)
{
    timeHandler->Update();
    timeHandler->Pause();
    const int64_t sleepAmount = 2000000/60;
    std::this_thread::sleep_for(std::chrono::microseconds(sleepAmount));
    timeHandler->Update();
    timeHandler->Update();
    timeHandler->Update();
    timeHandler->Update();
    timeHandler->Update();
    timeHandler->Update();

    timeHandler->Resume();

    ASSERT_LT(timeHandler->GetTotalTime(), 2.0f / 60);
    timeHandler->Update();
    timeHandler->Update();
    ASSERT_GT(timeHandler->GetTotalTime(), 2.0f / 60);
}