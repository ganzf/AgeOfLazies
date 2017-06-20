#include "Gui/PressKeyModule.hpp"

AoL::Gui::PressKeyModule::PressKeyModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos1(0, 0);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"PressKey", pos1, 100, 100,
						      AoL::Gui::GUITypeId::B_PRESSKEY));
}

AoL::Gui::PressKeyModule::~PressKeyModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::PressKeyModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::PressKeyModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::PressKeyModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::PressKeyModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::PressKeyModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::PressKeyModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::PressKeyModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
