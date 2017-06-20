#include "Scenes/OptionMenu.hpp"
#include "Gui/DefaultOptionInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Print.hpp"
#include "Core/Core.hpp"

AoL::Scenes::OptionMenu::OptionMenu(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Menu Option", data, new AoL::Gui::DefaultOptionInterface)
{
  this->initGui();
}

void	AoL::Scenes::OptionMenu::initGui()
{
  // AoL::rendering::Sound	mixer;
  // mixer.play("Assets/sound/ambiance.ogg", true);
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/AolMenuBackground.png");
  static irr::u32 song = 75;
  static std::wstring reso = gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
    ->getButton()->getText();
  static std::wstring FullScreen = gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
    ->getButton()->getText();
  gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
    ->getButton()->setText(std::wstring(reso.begin(), reso.end()));
  std::string msg = "Song : " + std::to_string(song) + "%";
  gui->getModulesHolder().front()->getModule()->getButtonsHolder()[8]
    ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_BACK,
			   ([this]() { this->done = true; }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_FULLSCREEN_OFF,
			   ([this]() {
			     gui->getModulesHolder().front()->getModule()->getButtonsHolder()[2]
			       ->getButton()->setText(reso = L"FullScreen : Off");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_FULLSCREEN_ON,
			   ([this]() {
			     gui->getModulesHolder().front()->getModule()->getButtonsHolder()[2]
			       ->getButton()->setText(reso = L"FullScreen : On");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_RESO_MINUS,
			   ([this]() {
			     if (gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				 ->getButton()->getText() == L"Format : 1920x1080")
			       gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1440x900");
			     else if (gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				      ->getButton()->getText() == L"Format : 1440x900")
			       gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1280x800");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_RESO_PLUS,
			   ([this]() {
			     if (gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				 ->getButton()->getText() == L"Format : 1440x900")
			       gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1920x1080");
			     else if (gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				      ->getButton()->getText() == L"Format : 1280x800")
			       gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1440x900");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_SONG_MINUS,
			   ([this]() {
			     if (song > 0)
			       song -= 5;
			     std::string msg = "Song : " + std::to_string(song) + "%";
			     gui->getModulesHolder().front()->getModule()->getButtonsHolder()[8]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_SONG_PLUS,
			   ([this]() {
			     if (song < 100)
			       song += 5;
			     std::string msg = "Song : " + std::to_string(song) + "%";
			     gui->getModulesHolder().front()->getModule()->getButtonsHolder()[8]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_KEYS,
			   ([this]() {
			     this->pause();
			     this->dropGui();
			     this->manager.playScene(manager.getFactory().createScene<AoL::Scenes::KeysBinding>(this->data));
			     this->initGui();
			     this->unpause();
			   }));
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::OptionMenu::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::OptionMenu::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::OptionMenu::~OptionMenu()
{
  
}
