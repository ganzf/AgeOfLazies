#include "Gui/EndGameModule.hpp"

AoL::Gui::EndGameModule::EndGameModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos0(10, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos0, 38, 90,
						      AoL::Gui::GUITypeId::B_BACK));

  irr::core::vector2df         pos1(52, 4);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"New Game", pos1, 38, 90,
						      AoL::Gui::GUITypeId::B_SCORE));
}

AoL::Gui::EndGameModule::~EndGameModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::EndGameModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::EndGameModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::EndGameModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::EndGameModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::EndGameModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::EndGameModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::EndGameModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
