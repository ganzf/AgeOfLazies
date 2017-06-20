#include "Gui/NewGameModule.hpp"

AoL::Gui::NewGameModule::NewGameModule(std::wstring const &text,
				       std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos11(10, 4);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos11, 80, 10,
						      AoL::Gui::GUITypeId::B_TITLE));  
  irr::core::vector2df         pos0(16, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos0, 5, 10,
						      AoL::Gui::GUITypeId::B_MAPSIZE_MINUS));
  irr::core::vector2df         pos1(20, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Map Size", pos1, 60, 10,
						      AoL::Gui::GUITypeId::B_MAPSIZE));
  irr::core::vector2df         pos2(79, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos2, 5, 10,
						      AoL::Gui::GUITypeId::B_MAPSIZE_PLUS));
  irr::core::vector2df         pos3(16, 38);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos3, 5, 10,
						      AoL::Gui::GUITypeId::B_DIFFICULTY_MINUS));
  irr::core::vector2df         pos4(20, 38);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Difficulty", pos4, 60, 10,
						      AoL::Gui::GUITypeId::B_DIFFICULTY));
  irr::core::vector2df         pos5(79, 38);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos5, 5, 10,
						      AoL::Gui::GUITypeId::B_DIFFICULTY_PLUS));
  irr::core::vector2df         pos6(16, 58);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos6, 5, 10,
						      AoL::Gui::GUITypeId::B_TIMEMAX_MINUS));
  irr::core::vector2df         pos7(20, 58);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Time Max", pos7, 60, 10,
						      AoL::Gui::GUITypeId::B_TIMEMAX));
  irr::core::vector2df         pos8(79, 58);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos8, 5, 10,
						      AoL::Gui::GUITypeId::B_TIMEMAX_PLUS));
  irr::core::vector2df         pos9(14, 73);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Back", pos9, 20, 6,
						      AoL::Gui::GUITypeId::B_BACK));
  irr::core::vector2df         pos10(66, 73);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Start", pos10, 20, 6,
						      AoL::Gui::GUITypeId::B_START));
}

AoL::Gui::NewGameModule::~NewGameModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::NewGameModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::NewGameModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::NewGameModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::NewGameModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::NewGameModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::NewGameModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::NewGameModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
