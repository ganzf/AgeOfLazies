#include "Gui/OptionModule.hpp"

AoL::Gui::OptionModule::OptionModule(std::wstring const &text,
				       std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos0(10, 3);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos0, 80, 10,
						      AoL::Gui::GUITypeId::B_TITLE));  
  irr::core::vector2df         pos1(10, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos1, 5, 10,
						      AoL::Gui::GUITypeId::B_FULLSCREEN_OFF));
  irr::core::vector2df         pos2(15, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Full Screen", pos2, 70, 10,
						      AoL::Gui::GUITypeId::B_FULLSCREEN));
  irr::core::vector2df         pos3(85, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos3, 5, 10,
						      AoL::Gui::GUITypeId::B_FULLSCREEN_ON));
  irr::core::vector2df         pos4(10, 32);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos4, 5, 10,
						      AoL::Gui::GUITypeId::B_RESO_MINUS));
  irr::core::vector2df         pos5(15, 32);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Resolution", pos5, 70, 10,
						      AoL::Gui::GUITypeId::B_RESO));
  irr::core::vector2df         pos6(85, 32);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos6, 5, 10,
						      AoL::Gui::GUITypeId::B_RESO_PLUS));
  irr::core::vector2df         pos7(10, 44);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos7, 5, 10,
						      AoL::Gui::GUITypeId::B_SONG_MINUS));
  irr::core::vector2df         pos8(15, 44);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"SONG", pos8, 70, 10,
						      AoL::Gui::GUITypeId::B_SONG));
  irr::core::vector2df         pos9(85, 44);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos9, 5, 10,
						      AoL::Gui::GUITypeId::B_SONG_PLUS));
  irr::core::vector2df         pos10(10, 56);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Key Binding", pos10, 80, 10,
						      AoL::Gui::GUITypeId::B_KEYS));
  irr::core::vector2df         pos11(10, 69);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Back", pos11, 80, 10,
						      AoL::Gui::GUITypeId::B_BACK));
}

AoL::Gui::OptionModule::~OptionModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::OptionModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::OptionModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::OptionModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::OptionModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::OptionModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::OptionModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::OptionModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
