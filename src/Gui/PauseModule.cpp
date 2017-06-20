#include "Gui/PauseModule.hpp"

AoL::Gui::PauseModule::PauseModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos0(10, 3);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos0, 80, 10,
						      AoL::Gui::GUITypeId::B_TITLE));
  irr::core::vector2df         pos1(10, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Continue", pos1, 80, 10,
						      AoL::Gui::GUITypeId::B_CONTINUE));
  irr::core::vector2df         pos2(10, 32);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Save Game", pos2, 37, 10,
						      AoL::Gui::GUITypeId::B_SAVE));
  irr::core::vector2df         pos3(53, 32);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Load Game", pos3, 37, 10,
						      AoL::Gui::GUITypeId::B_LOADGAME));
  irr::core::vector2df         pos4(10, 44);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Option", pos4, 80, 10,
						      AoL::Gui::GUITypeId::B_OPTION));
  irr::core::vector2df         pos5(10, 56);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Surrend", pos5, 80, 10,
						      AoL::Gui::GUITypeId::B_SURREND));
  irr::core::vector2df         pos6(10, 68);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Quit", pos6, 80, 10,
						      AoL::Gui::GUITypeId::B_QUIT));
}

AoL::Gui::PauseModule::~PauseModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::PauseModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::PauseModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::PauseModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::PauseModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId            	AoL::Gui::PauseModule::getType() const
{
  return (_type);
}

inline bool				AoL::Gui::PauseModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::PauseModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
