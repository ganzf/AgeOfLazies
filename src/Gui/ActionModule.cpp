#include "Gui/ActionModule.hpp"

AoL::Gui::ActionModule::ActionModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos1(2.5, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action1", pos1, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION1));
  
  irr::core::vector2df         pos2(25, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action2", pos2, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION2));

  irr::core::vector2df         pos3(47.5, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action3", pos3, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION3));

  irr::core::vector2df         pos4(69.5, 5);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action4", pos4, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION4));

  irr::core::vector2df         pos5(2.5, 45);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action5", pos5, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION5));

  irr::core::vector2df         pos6(25, 45);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action6", pos6, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION6));

  irr::core::vector2df         pos7(47.5, 45);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action7", pos7, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION7));

  irr::core::vector2df         pos8(69.5, 45);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Action8", pos8, 20, 35,
						      AoL::Gui::GUITypeId::B_ACTION8));
}

AoL::Gui::ActionModule::~ActionModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::ActionModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::ActionModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::ActionModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::ActionModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId            	AoL::Gui::ActionModule::getType() const
{
  return (_type);
}

inline bool				AoL::Gui::ActionModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::ActionModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
