#include "Scenes/KeysBinding.hpp"
#include "Gui/DefaultKeysBindingInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Print.hpp"
#include "Core/Core.hpp"

AoL::Scenes::KeysBinding::KeysBinding(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "KeysBinding Principal", data, new AoL::Gui::DefaultKeysBindingInterface)
{
  // this->setTransparency(true);
  this->initGui();
  // static AoL::rendering::Sound	mixer;
}
static AoL::Gui::GUITypeId  currentKey = AoL::Gui::GUITypeId::M_PRESSKEY;

void	AoL::Scenes::KeysBinding::initGui()
{
  // AoL::rendering::Sound	mixer;
  // mixer.play("Assets/sound/ambiance.ogg", true);
   this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/AolMenuBackground.png");
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_KEYSBINDING, AoL::Gui::GUITypeId::B_BACK2,
  			   ([this]() { this->done = true; }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_KEYSBINDING, AoL::Gui::GUITypeId::B_KEY_VALUE1,
  			   ([this]() {
			     currentKey = AoL::Gui::GUITypeId::B_KEY_VALUE1;
			     (gui->getModulesHolder()[1])->getModule()->display();
			   }));
  
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::KeysBinding::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::KeysBinding::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::KeysBinding::~KeysBinding()
{
}
