#include "Gui/KeyModule.hpp"

AoL::Gui::KeyModule::KeyModule(std::string const &text,
			       std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos1(5, 10);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("Key1", pos1, 40, 10));

  irr::core::vector2df         pos2(5, 25);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("Key2", pos2, 40, 10));

  irr::core::vector2df         pos3(5, 40);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("Key3", pos3, 40, 10));

  irr::core::vector2df         pos4(5, 55);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("key4", pos4, 40, 10));

  irr::core::vector2df         pos5(5, 70);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("key5", pos5, 40, 10));

  irr::core::vector2df         pos6(50, 10);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("key6", pos6, 40, 10));

  irr::core::vector2df         pos7(50, 25);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("key7", pos7, 40, 10));

  irr::core::vector2df         pos8(50, 40);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("key8", pos8, 40, 10));

  irr::core::vector2df         pos9(50, 55);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("key9", pos9, 40, 10));

  irr::core::vector2df         pos10(50, 70);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder("key10", pos10, 40, 10));
}

AoL::Gui::KeyModule::~KeyModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::string const		&AoL::Gui::KeyModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::KeyModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::KeyModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::KeyModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::ModuleType		       	AoL::Gui::KeyModule::getType() const
{
  return (_type);
}

void		     			AoL::Gui::KeyModule::dump() const
{
  std::cout << "text: " << _text << std::endl << std::endl
  	    << "=====Buttons=====" << std::endl;
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    {
      _buttonsHolder[i]->dump();
      std::cout << std::endl;
    }
}
