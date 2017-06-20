#include "Gui/LoadGameModule.hpp"

AoL::Gui::LoadGameModule::LoadGameModule(std::wstring const &text,
				       std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos0(10, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos0, 80, 10,
						      AoL::Gui::GUITypeId::B_TITLE));  
  irr::core::vector2df         pos1(16, 19);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos1, 5, 30,
						      AoL::Gui::GUITypeId::B_SAVE_MINUS));
  irr::core::vector2df         pos2(20, 19);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"AI 1", pos2, 60, 30,
						      AoL::Gui::GUITypeId::B_SAVE));
  irr::core::vector2df         pos3(79, 19);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos3, 5, 30,
						      AoL::Gui::GUITypeId::B_SAVE_PLUS));
  irr::core::vector2df         pos4(10, 50);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Save Name", pos4, 80, 15,
						      AoL::Gui::GUITypeId::B_SAVE_NAME));
  irr::core::vector2df         pos5(16, 67);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Back", pos5, 35, 10,
						      AoL::Gui::GUITypeId::B_BACK));
  irr::core::vector2df         pos6(54, 67);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Load", pos6, 35, 10,
						      AoL::Gui::GUITypeId::B_LOADGAME));
}

AoL::Gui::LoadGameModule::~LoadGameModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::LoadGameModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::LoadGameModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::LoadGameModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::LoadGameModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::LoadGameModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::LoadGameModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::LoadGameModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
