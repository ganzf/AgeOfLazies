#include "Scenes/Victory.hpp"
#include "Gui/DefaultEndGameInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Core/Core.hpp"

AoL::Scenes::Victory::Victory(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Menu Principal", data, new AoL::Gui::DefaultEndGameInterface)
{
  this->initGui();
}

void	AoL::Scenes::Victory::playScore()
{
  this->dropGui();
  this->manager.playScene(this->manager.getFactory().createScene<AoL::Scenes::Score>(this->data));
  this->done = true;
}

void	AoL::Scenes::Victory::initGui()
{
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/Victory.png");
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_ENDGAME, AoL::Gui::GUITypeId::B_BACK,
  			   ([this]() { this->done = true; }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_ENDGAME, AoL::Gui::GUITypeId::B_SCORE,
  			   ([this]() { this->playScore(); }));
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::Victory::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::Victory::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::Victory::~Victory()
{
  
}
