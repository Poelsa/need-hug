#ifndef NEEDHUG_TIMEHANDLER_HPP
#define NEEDHUG_TIMEHANDLER_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace NeedHug
{
    class TimeHandler
    {
    public:
        /// minTime decides if the update function should 
        /// wait a minimum amount of time before continuing.
        TimeHandler(bool minTime = false);

        virtual ~TimeHandler() = default;

        void Update();

        void Pause();

        void Resume();

        /// Returns time since last update
        const float GetElapsedTime();

        /// Returns time since start
        const float GetTotalTime();
    private:
        //Functions
    private:
        /// Should be const
        bool minTime;
        bool isPaused = false;
        const sf::Time minDeltaT = sf::seconds(1.0f / 60);
        sf::Time deltaT = sf::Time::Zero;
        sf::Time totalT = sf::Time::Zero;
        sf::Clock clock = sf::Clock();
    };
} // namespace NeedHug

#endif