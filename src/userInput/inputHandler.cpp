#include "userInput/inputHandler.hpp"

AoL::UserInput::InputHandler::InputHandler(void) :
  _keyboardHandler(), _mouseHandler()
{}

bool	AoL::UserInput::InputHandler::OnEvent(const irr::SEvent& event)
{
  this->_keyboardHandler.OnEvent(event);
  this->_mouseHandler.OnEvent(event);
  return (false);
}
