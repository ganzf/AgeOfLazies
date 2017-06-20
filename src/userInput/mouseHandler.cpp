#include "userInput/mouseHandler.hpp"

AoL::UserInput::MouseHandler::MouseHandler(void)
  : _mouse(), _idGUI(-1)
{
  for (irr::u32 i = 0; i < static_cast<irr::u32>(AoL::UserInput::MouseAttributs::NBR_ATTRIBUTS); i++)
    _mouse.push_back(0);
}

AoL::UserInput::MouseHandler::~MouseHandler(void)
{}

bool	AoL::UserInput::MouseHandler::OnEvent(const irr::SEvent &event)
{
  this->_position.X = event.MouseInput.X;
  this->_position.Y = event.MouseInput.Y;
  if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
    {
      if (event.MouseInput.Event == irr::EMIE_MOUSE_WHEEL)
	{
	  if (event.MouseInput.Wheel == -1)
	    _mouse[MouseAttributs::WHEEL_UP] = 1;
	  else if (event.MouseInput.Wheel == 1)
	    _mouse[MouseAttributs::WHEEL_DOWN] = 1;
	}
      if (event.MouseInput.Event == irr::EMIE_LMOUSE_PRESSED_DOWN)
	_mouse[MouseAttributs::LEFT_CLICK] = 1;
      if (event.MouseInput.Event == irr::EMIE_LMOUSE_LEFT_UP)
	_mouse[MouseAttributs::LEFT_CLICK] = 0;
      if (event.MouseInput.Event == irr::EMIE_RMOUSE_PRESSED_DOWN)
	_mouse[MouseAttributs::RIGHT_CLICK] = 1;
      if (event.MouseInput.Event == irr::EMIE_RMOUSE_LEFT_UP)
	_mouse[MouseAttributs::RIGHT_CLICK] = 0;
      if (event.MouseInput.Event == irr::EMIE_MMOUSE_PRESSED_DOWN)
	_mouse[MouseAttributs::MIDDLE_CLICK] = 1;
    }
  if (event.EventType == irr::EET_GUI_EVENT)
    {
      _idGUI = -1;
      if (event.GUIEvent.EventType == irr::gui::EGET_BUTTON_CLICKED
	  || event.GUIEvent.EventType == irr::gui::EGET_FILE_SELECTED)
	{
	  _mouse[MouseAttributs::GUI] = 1;
	  _idGUI = event.GUIEvent.Caller->getID();
	}
    }
  return (false);
}

void		AoL::UserInput::MouseHandler::resetEventQueue()
{
  for (auto &event: _mouse)
    {
      event = false;
    }
}

bool       	AoL::UserInput::MouseHandler::getEvent(MouseAttributs event)
{
  bool  	status = false;

  if (event != MouseAttributs::UNDEFINED)
    {
      status = static_cast<bool>(_mouse[static_cast<irr::u32>(event)]);
    }
  return (status);
}
