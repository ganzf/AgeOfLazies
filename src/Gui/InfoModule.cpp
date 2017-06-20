#include "Gui/InfoModule.hpp"

AoL::Gui::InfoModule::InfoModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos1(11, 18);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Health", pos1, 22, 17,
						      AoL::Gui::GUITypeId::B_HEALTH));

  irr::core::vector2df         pos8(11, 7);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"XP", pos8, 22, 10,
						      AoL::Gui::GUITypeId::B_XP));

  irr::core::vector2df         pos2(11, 53);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Attack", pos2, 22, 35,
						      AoL::Gui::GUITypeId::B_ATTACK));

  irr::core::vector2df         pos3(37, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Wood", pos3, 25, 18,
						      AoL::Gui::GUITypeId::B_WOOD));

  irr::core::vector2df         pos4(37, 29);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Food", pos4, 25, 18,
						      AoL::Gui::GUITypeId::B_FOOD));

  irr::core::vector2df         pos5(37, 52);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Stone", pos5, 25, 18,
						      AoL::Gui::GUITypeId::B_STONE));

  irr::core::vector2df         pos6(37, 73);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Gold", pos6, 25, 18,
						      AoL::Gui::GUITypeId::B_GOLD));

  irr::core::vector2df         pos7(70, 18);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Picture", pos7, 20, 60,
						      AoL::Gui::GUITypeId::B_PICTURE));
}

AoL::Gui::InfoModule::~InfoModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::InfoModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::InfoModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::InfoModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::InfoModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	      	AoL::Gui::InfoModule::getType() const
{
  return (_type);
}

inline bool				AoL::Gui::InfoModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::InfoModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
