#include "Scenes/MainMenu.hpp"
#include "Gui/DefaultMenuInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Print.hpp"
#include "Core/Core.hpp"

AoL::Scenes::MainMenu::MainMenu(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Menu Principal", data, new AoL::Gui::DefaultMenuInterface)
{
  this->initGui();
}

void	AoL::Scenes::MainMenu::playNewGameMenu()
{
  this->pause();
  this->dropGui();
  this->manager.playScene(manager.getFactory().createScene<AoL::Scenes::NewGameMenu>(this->data));
  this->initGui();
  this->unpause();
}

void	AoL::Scenes::MainMenu::playLoadGameMenu()
{
  this->pause();
  this->dropGui();
  this->manager.playScene(manager.getFactory().createScene<AoL::Scenes::LoadGameMenu>(this->data));
  this->initGui();
  this->unpause();
}

void	AoL::Scenes::MainMenu::playOptionMenu()
{
  this->pause();
  this->dropGui();
  this->manager.playScene(manager.getFactory().createScene<AoL::Scenes::OptionMenu>(this->data));
  this->initGui();
  this->unpause();
}

void	AoL::Scenes::MainMenu::initGui()
{
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/AolMenuBackground.png");
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_MENU, AoL::Gui::GUITypeId::B_NEWGAME,
  			   ([this]() { this->playNewGameMenu(); }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_MENU, AoL::Gui::GUITypeId::B_QUIT,
  			   ([this]() { this->done = true; }));
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font28.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::MainMenu::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::MainMenu::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::MainMenu::~MainMenu()
{
  this->manager.getMixer().pause();
}
