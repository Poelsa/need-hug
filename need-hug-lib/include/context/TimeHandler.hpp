#ifndef NEEDHUG_TIEHANDLER_HPP
#define NEEDHUG_TIEHANDLER_HPP

#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

namespace NeedHug
{
    class TimeHandler
    {
    public:
        /// minTime decides if the update function should 
        /// wait a minimum amount of time before continuing.
        TimeHandler(bool minTime);
        virtual ~TimeHandler();

        void Update();
        /// Returns time since last update
        float GetElapsedTime();
        /// Returns time since start
        float GetTotalTime();
    private:
        //Functions
    private:
        /// Should be const
        bool minTime;
        const sf::Time minDeltaT = sf::seconds(1.0f/60);
        sf::Time deltaT = sf::Time::Zero;
        sf::Time totalT = sf::Time::Zero;
        sf::Clock clock = sf::Clock();
    };
}

#endif