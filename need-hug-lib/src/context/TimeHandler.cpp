#include <context/TimeHandler.hpp>
#include <thread>
#include <chrono>

namespace NeedHug
{
    TimeHandler::TimeHandler(bool minTime)
    {
        this->minTime = minTime;
    }
    TimeHandler::~TimeHandler()
    {

    }

    void TimeHandler::Update()
    {
        if (minTime)
        {
            int64_t sleepAmount = (minDeltaT - clock.getElapsedTime()).asMilliseconds();
            std::this_thread::sleep_for(std::chrono::milliseconds(sleepAmount));
        }
        deltaT = clock.getElapsedTime();
        totalT += deltaT;
        clock.restart();
    }

    float TimeHandler::GetElapsedTime()
    {
        return deltaT.asSeconds();
    }

    float TimeHandler::GetTotalTime()
    {
        return totalT.asSeconds();
    }
}