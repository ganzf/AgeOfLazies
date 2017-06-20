#include "Gui/MapModule.hpp"

AoL::Gui::MapModule::MapModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos1(2, 2);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Map", pos1, 96, 96,
						      AoL::Gui::GUITypeId::B_MAP));
}

AoL::Gui::MapModule::~MapModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::MapModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::MapModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::MapModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::MapModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId     	       	AoL::Gui::MapModule::getType() const
{
  return (_type);
}

inline bool				AoL::Gui::MapModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::MapModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
