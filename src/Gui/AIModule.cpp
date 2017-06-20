#include "Gui/AIModule.hpp"

AoL::Gui::AIModule::AIModule(std::wstring const &text,
				       std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos0(10, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos0, 80, 10,
						      AoL::Gui::GUITypeId::B_TITLE));  
  irr::core::vector2df         pos1(16, 19);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos1, 5, 15,
						      AoL::Gui::GUITypeId::B_AI1_MINUS));
  irr::core::vector2df         pos2(20, 19);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"AI 1", pos2, 60, 15,
						      AoL::Gui::GUITypeId::B_AI1));
  irr::core::vector2df         pos3(79, 19);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos3, 5, 15,
						      AoL::Gui::GUITypeId::B_AI1_PLUS));
  irr::core::vector2df         pos4(16, 41);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos4, 5, 15,
						      AoL::Gui::GUITypeId::B_AI2_MINUS));
  irr::core::vector2df         pos5(20, 41);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"AI 2", pos5, 60, 15,
						      AoL::Gui::GUITypeId::B_AI2));
  irr::core::vector2df         pos6(79, 41);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos6, 5, 15,
						      AoL::Gui::GUITypeId::B_AI2_PLUS));
  irr::core::vector2df         pos7(16, 63);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"-", pos7, 5, 15,
						      AoL::Gui::GUITypeId::B_AI3_MINUS));
  irr::core::vector2df         pos8(20, 63);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"AI 3", pos8, 60, 15,
						      AoL::Gui::GUITypeId::B_AI3));
  irr::core::vector2df         pos9(79, 63);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"+", pos9, 5, 15,
						      AoL::Gui::GUITypeId::B_AI3_PLUS));
}

AoL::Gui::AIModule::~AIModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::AIModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::AIModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::AIModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::AIModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::AIModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::AIModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::AIModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
