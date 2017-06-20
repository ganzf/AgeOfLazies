#include "Gui/EcoScoreModule.hpp"

AoL::Gui::EcoScoreModule::EcoScoreModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  irr::core::vector2df         pos0(10, 3);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Title", pos0, 80, 10,
						      AoL::Gui::GUITypeId::B_TITLE));

  irr::core::vector2df         pos1(10, 17);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Key1", pos1, 37, 10,
						      AoL::Gui::GUITypeId::B_STAT_KEY1));

  irr::core::vector2df         pos2(52, 17);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Value1", pos2, 38, 10,
						      AoL::Gui::GUITypeId::B_STAT_VALUE1));

  irr::core::vector2df         pos3(10, 28);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Key2", pos3, 37, 10,
						      AoL::Gui::GUITypeId::B_STAT_KEY2));

  irr::core::vector2df         pos4(52, 28);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Value2", pos4, 38, 10,
						      AoL::Gui::GUITypeId::B_STAT_VALUE2));

  irr::core::vector2df         pos5(10, 39);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Key3", pos5, 37, 10,
						      AoL::Gui::GUITypeId::B_STAT_KEY3));

  irr::core::vector2df         pos6(52, 39);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Value3", pos6, 38, 10,
						      AoL::Gui::GUITypeId::B_STAT_VALUE3));

  irr::core::vector2df         pos7(10, 50);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Key4", pos7, 37, 10,
						      AoL::Gui::GUITypeId::B_STAT_KEY4));

  irr::core::vector2df         pos8(52, 50);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Key4", pos8, 38, 10,
						      AoL::Gui::GUITypeId::B_STAT_VALUE4));

  irr::core::vector2df         pos9(10, 61);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Value5", pos9, 37, 10,
						      AoL::Gui::GUITypeId::B_STAT_KEY5));

  irr::core::vector2df         pos10(52, 61);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Value5", pos10, 38, 10,
						      AoL::Gui::GUITypeId::B_STAT_VALUE5));

  irr::core::vector2df         pos11(10, 71);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Back", pos11, 25, 10,
						      AoL::Gui::GUITypeId::B_BACK));
  irr::core::vector2df         pos12(45, 71);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Previous", pos12, 20, 10,
						      AoL::Gui::GUITypeId::B_ECO_PREV));
  irr::core::vector2df         pos13(67, 71);
  _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(L"Next", pos13, 20, 10,
						      AoL::Gui::GUITypeId::B_ECO_NEXT));
}

AoL::Gui::EcoScoreModule::~EcoScoreModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::EcoScoreModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::EcoScoreModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::EcoScoreModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::EcoScoreModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::EcoScoreModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::EcoScoreModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::EcoScoreModule::dump() const
{
  // std::cout << "text: " << _text << std::endl << std::endl
  // 	    << "=====Buttons=====" << std::endl;
  // for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
  //   {
  //     _buttonsHolder[i]->dump();
  //     std::cout << std::endl;
  //   }
}
