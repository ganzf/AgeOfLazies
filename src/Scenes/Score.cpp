#include <sys/types.h>
#include "Scenes/Score.hpp"
#include "Gui/DefaultScoreInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Print.hpp"
#include "Core/Core.hpp"

AoL::Scenes::Score::Score(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Score", data, new AoL::Gui::DefaultScoreInterface)
{
  this->initGui();
}

void	AoL::Scenes::Score::initGui()
{
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/AolMenuBackground.png");
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_GENERAL_SCORE, AoL::Gui::GUITypeId::B_BACK,
  			   ([this]() { this->done = true; }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_GENERAL_SCORE, AoL::Gui::GUITypeId::B_GENERAL_NEXT,
  			   ([this]() { (gui->getModulesHolder()[0])->getModule()->hide();
			     (gui->getModulesHolder()[1])->getModule()->display(); }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_ECO_SCORE, AoL::Gui::GUITypeId::B_ECO_NEXT,
  			   ([this]() { (gui->getModulesHolder()[1])->getModule()->hide();
  			     (gui->getModulesHolder()[2])->getModule()->display(); }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_FIGHT_SCORE, AoL::Gui::GUITypeId::B_FIGHT_NEXT,
  			   ([this]() { (gui->getModulesHolder()[2])->getModule()->hide();
  			     (gui->getModulesHolder()[3])->getModule()->display(); }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_ECO_SCORE, AoL::Gui::GUITypeId::B_ECO_PREV,
  			   ([this]() { (gui->getModulesHolder()[1])->getModule()->hide();
			     (gui->getModulesHolder()[0])->getModule()->display(); }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_FIGHT_SCORE, AoL::Gui::GUITypeId::B_FIGHT_PREV,
  			   ([this]() { (gui->getModulesHolder()[2])->getModule()->hide();
  			     (gui->getModulesHolder()[1])->getModule()->display(); }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_LAZY_SCORE, AoL::Gui::GUITypeId::B_LAZY_PREV,
  			   ([this]() {  (gui->getModulesHolder()[3])->getModule()->hide();
  			     (gui->getModulesHolder()[2])->getModule()->display(); }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_ECO_SCORE, AoL::Gui::GUITypeId::B_BACK,
  			   ([this]() { this->done = true; }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_FIGHT_SCORE, AoL::Gui::GUITypeId::B_BACK,
  			   ([this]() { this->done = true; }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_LAZY_SCORE, AoL::Gui::GUITypeId::B_BACK,
  			   ([this]() { this->done = true; }));
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::Score::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::Score::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::Score::~Score()
{

}
