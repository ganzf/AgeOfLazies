#include "userInput/keyboardHandler.hpp"

AoL::UserInput::KeyboardHandler::KeyboardHandler(void)
  : _keys()
{
  for (irr::u32 i = 0; i < static_cast<irr::u32>(AoL::UserInput::KeyValue::NBR_KEYS); i++)
    _keys.push_back(AoL::UserInput::KeyStatus::UNDEFINED);
}

bool	AoL::UserInput::KeyboardHandler::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown)
    {
      for (auto &key : _keys)
	key = AoL::UserInput::KeyStatus::UNDEFINED;
      if (AoL::UserInput::_convKey.find(event.KeyInput.Key) != AoL::UserInput::_convKey.end())
	_keys[static_cast<irr::s32>(AoL::UserInput::_convKey.at(event.KeyInput.Key))]
	  = AoL::UserInput::KeyStatus::PRESSED;
    }
  return (false);
}

AoL::UserInput::KeyStatus	AoL::UserInput::KeyboardHandler::isKeyPressed(AoL::UserInput::KeyValue keyValue)
{
  AoL::UserInput::KeyStatus status = AoL::UserInput::KeyStatus::UNDEFINED;
  
  if (keyValue != AoL::UserInput::KeyValue::UNDEFINED &&
      (status = _keys[static_cast<irr::s32>(keyValue)]) != KeyStatus::UNDEFINED)
    _keys[static_cast<irr::s32>(keyValue)] = KeyStatus::UNDEFINED;
  return (status);
}
