#include "Gui/StatModule.hpp"

AoL::Gui::StatModule::StatModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df		pos;

  pos.X = 2;
  pos.Y = 10;
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Wood", pos, 10, 80,
						      AoL::Gui::GUITypeId::B_WOOD));
  pos.X = 14;
  pos.Y = 10;
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Food", pos, 10, 80,
						      AoL::Gui::GUITypeId::B_FOOD));
  pos.X = 26;
  pos.Y = 10;
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Stone", pos, 10, 80,
						      AoL::Gui::GUITypeId::B_STONE));
  pos.X = 38;
  pos.Y = 10;
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Gold", pos, 10, 80,
						      AoL::Gui::GUITypeId::B_GOLD));
  pos.X = 50;
  pos.Y = 10;
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"People", pos, 10, 80,
						      AoL::Gui::GUITypeId::B_PEOPLE));
  pos.X = 76;
  pos.Y = 10;
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Timer", pos, 10, 80,
						      AoL::Gui::GUITypeId::B_TIMER));
  pos.X = 88;
  pos.Y = 10;
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Menu", pos, 10, 80,
						      AoL::Gui::GUITypeId::B_PAUSE));
}

AoL::Gui::StatModule::~StatModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::StatModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::StatModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::StatModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::StatModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId          	AoL::Gui::StatModule::getType() const
{
  return (_type);
}

inline bool				AoL::Gui::StatModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::StatModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
