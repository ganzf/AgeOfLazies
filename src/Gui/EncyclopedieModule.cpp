#include <unordered_map>
#include "Gui/EncyclopedieModule.hpp"

struct	ModuleInfo
{
  std::wstring		name;
  irr::core::vector2df	pos;
  irr::f32		w;
  irr::f32		h;
  AoL::Gui::GUITypeId	type;
};

static const	std::vector<ModuleInfo> infos =
  {
    {L"Titre", {10, 4}, 80, 10, AoL::Gui::GUITypeId::B_TITLE},
    {L"Encyclo", {15, 4}, 5, 10, AoL::Gui::GUITypeId::B_ENCYCLO},
    {L"Info1", {6, 20}, 20, 4, AoL::Gui::GUITypeId::B_INFO1},
    {L"Info2", {6, 24}, 20, 4, AoL::Gui::GUITypeId::B_INFO2},
    {L"Info3", {6, 28}, 20, 4, AoL::Gui::GUITypeId::B_INFO3},
    {L"Info4", {6, 32}, 20, 4, AoL::Gui::GUITypeId::B_INFO4},
    {L"Info5", {6, 36}, 20, 4, AoL::Gui::GUITypeId::B_INFO5},
    {L"Info6", {6, 40}, 20, 4, AoL::Gui::GUITypeId::B_INFO6},
    {L"Info7", {6, 44}, 20, 4, AoL::Gui::GUITypeId::B_INFO7},
    {L"Info8", {6, 48}, 20, 4, AoL::Gui::GUITypeId::B_INFO8},
    {L"Info9", {6, 52}, 20, 4, AoL::Gui::GUITypeId::B_INFO9},
    {L"Info10", {6, 56}, 20, 4, AoL::Gui::GUITypeId::B_INFO10},
    {L"Info11", {6, 60}, 20, 4, AoL::Gui::GUITypeId::B_INFO11},
    {L"Info12", {6, 64}, 20, 4, AoL::Gui::GUITypeId::B_INFO12},
    {L"Info13", {6, 68}, 20, 4, AoL::Gui::GUITypeId::B_INFO13},
    {L"Info14", {6, 72}, 20, 4, AoL::Gui::GUITypeId::B_INFO14},
    {L"Icone", {30, 20}, 10, 20, AoL::Gui::GUITypeId::B_INFO_ICON},
    {L"Name", {45, 20}, 20, 20, AoL::Gui::GUITypeId::B_INFO_NAME},
    {L"Picture", {70, 20}, 25, 18, AoL::Gui::GUITypeId::B_INFO_PICTURE},
    {L"Text", {28, 20}, 60, 75, AoL::Gui::GUITypeId::B_TEXT},
  };

AoL::Gui::EncyclopedieModule::EncyclopedieModule(std::wstring const &text,
				 std::string const &picturePath)
  :_text(text),
   _picturePath(picturePath)
{
  for (auto &info: infos)
    _buttonsHolder.push_back(new AoL::Gui::ButtonHolder(info.name, info.pos,
							info.w, info.h,
							info.type));
}

AoL::Gui::EncyclopedieModule::~EncyclopedieModule()
{
  for (irr::u32 i = 0; i < _nbButtonsHolder; ++i)
    delete _buttonsHolder[i];
}

inline std::wstring const		&AoL::Gui::EncyclopedieModule::getText() const
{
  return (_text);
}

inline std::string const		&AoL::Gui::EncyclopedieModule::getPicturePath() const
{
  return (_picturePath);
}

inline std::vector<AoL::Gui::ButtonHolder *>	&AoL::Gui::EncyclopedieModule::getButtonsHolder()
{
  return (_buttonsHolder);
}

inline irr::u32				AoL::Gui::EncyclopedieModule::getNbButtonsHolder() const
{
  return (_nbButtonsHolder);
}

inline AoL::Gui::GUITypeId	AoL::Gui::EncyclopedieModule::getType() const
{
  return (_type);
}

inline bool			AoL::Gui::EncyclopedieModule::isHide() const
{
  return (_hide);
}

void		     			AoL::Gui::EncyclopedieModule::dump() const
{

}
