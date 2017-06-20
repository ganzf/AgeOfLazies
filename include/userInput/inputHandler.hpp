#ifndef INPUTHANDLER_HPP_
# define INPUTHANDLER_HPP_

# include "userInput/keyboardHandler.hpp"
# include "userInput/mouseHandler.hpp"

namespace				AoL
{
  namespace				UserInput
  {
    struct				InputHandler : public irr::IEventReceiver
    {
      InputHandler(void);
      ~InputHandler(void) = default;
      bool				OnEvent(const irr::SEvent& event);

      AoL::UserInput::KeyboardHandler	_keyboardHandler;
      AoL::UserInput::MouseHandler	_mouseHandler;
      void				resetEventQueue()
      {
	this->_mouseHandler.resetEventQueue();
      }
      
    };
  }
}

#endif
