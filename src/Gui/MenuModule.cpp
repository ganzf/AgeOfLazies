#include "Gui/MenuModule.hpp"

AoL::Gui::MenuModule::MenuModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos0(10, 4);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos0, 80, 10,
						      AoL::Gui::GUITypeId::B_TITLE));

  irr::core::vector2df         pos1(10, 20);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"New Game", pos1, 80, 11,
						      AoL::Gui::GUITypeId::B_NEWGAME));

  irr::core::vector2df         pos2(10, 35);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Load Game", pos2, 80, 11,
						      AoL::Gui::GUITypeId::B_LOADGAME));

  irr::core::vector2df         pos3(10, 51);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Option", pos3, 80, 11,
						      AoL::Gui::GUITypeId::B_OPTION));

  irr::core::vector2df         pos4(10, 68);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Quit", pos4, 80, 11,
						      AoL::Gui::GUITypeId::B_QUIT));
}

AoL::Gui::MenuModule::~MenuModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::MenuModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::MenuModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::MenuModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::MenuModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::MenuModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::MenuModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::MenuModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
