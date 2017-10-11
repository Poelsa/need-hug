#ifndef NEEDHUG_INPUTHANDLER_HPP
#define NEEDHUG_INPUTHANDLER_HPP

#include <context/KeyMap.hpp>
#include <vector>

namespace NeedHug
{
    class InputHandler
    {
    public: //Functions
        InputHandler();

        virtual ~InputHandler() {};

        ///Updates the current input state
        void Update();

    private: //Functions
    private: //Variables

        std::vector<KeyMap> testMapList;

    };
}

#endif