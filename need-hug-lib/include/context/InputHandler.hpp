#ifndef NEEDHUG_INPUTHANDLER_HPP
#define NEEDHUG_INPUTHANDLER_HPP

/* TODO : Should we have some kind of wrapper for the two different input systems (sfml/logfile)?
          In that case, should _all_ keys be mapped like NeedHug::kb::A corresponds to both 
          sf::KeyBoard::A and logfile_button_A (or whatever) and so on? 
          
          How should this handler be used by other objects? 
          if (InputHandler.isButtonPressed(button))
          or like events?*/

namespace NeedHug
{
    class InputHandler
    {
    public: //Functions
        InputHandler() {};

        virtual ~InputHandler() {};

        ///Updates the current input state
        void Update();

    private: //Functions
    private: //Variables

    };
}

#endif