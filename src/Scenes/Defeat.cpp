#include "Scenes/Defeat.hpp"
#include "Gui/DefaultEndGameInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Core/Core.hpp"

AoL::Scenes::Defeat::Defeat(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Menu Principal", data, new AoL::Gui::DefaultEndGameInterface)
{
  this->initGui();
}

void	AoL::Scenes::Defeat::playScore()
{
  this->dropGui();
  this->manager.playScene(this->manager.getFactory().createScene<AoL::Scenes::Score>(this->data));
  this->done = true;
}

void	AoL::Scenes::Defeat::initGui()
{
  // AoL::rendering::Sound	mixer;
  // mixer.play("Assets/sound/ambiance.ogg", true);
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/Defeat.png");
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_ENDGAME, AoL::Gui::GUITypeId::B_BACK,
  			   ([this]() { this->done = true; }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_ENDGAME, AoL::Gui::GUITypeId::B_SCORE,
  			   ([this]() { this->playScore(); }));
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::Defeat::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::Defeat::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::Defeat::~Defeat()
{

}
