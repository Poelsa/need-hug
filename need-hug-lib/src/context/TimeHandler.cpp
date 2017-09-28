#include <context/TimeHandler.hpp>
#include <thread>
#include <chrono>

namespace NeedHug
{
    TimeHandler::TimeHandler(bool minTime) :
        minTime(minTime) { }

    void TimeHandler::Update()
    {
        if (minTime)
        {
            const int64_t sleepAmount = (minDeltaT - clock.getElapsedTime()).asMicroseconds();
            std::this_thread::sleep_for(std::chrono::microseconds(sleepAmount));
        }
        deltaT = clock.getElapsedTime();
        totalT += deltaT;
        clock.restart();
    }

    const float TimeHandler::GetElapsedTime()
    {
        return deltaT.asSeconds();
    }

    const float TimeHandler::GetTotalTime()
    {
        return totalT.asSeconds();
    }
}