#include <sys/types.h>
#include "Scenes/LoadGameMenu.hpp"
#include "Gui/DefaultLoadGameInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Print.hpp"
#include "Core/Core.hpp"

AoL::Scenes::LoadGameMenu::LoadGameMenu(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Menu Nouvelle Partie", data, new AoL::Gui::DefaultLoadGameInterface)
{
  // this->setTransparency(true);
  this->initGui();
  // static AoL::rendering::Sound	mixer;
  // mixer.play("Assets/sound/aol.wav", true);
}

std::string	AoL::Scenes::LoadGameMenu::updateSave(irr::u32 index, std::string ai)
{
  return ("");
}

std::string	AoL::Scenes::LoadGameMenu::LoadPicture(std::string const &save)
{
  if (save != "")
    {
      std::string path = save.substr(7, save.size() - 4);
      path = "Saves/" + path + ".png";
    }
  return "Assets/textures/rectangle.png";
}

void	AoL::Scenes::LoadGameMenu::initGui()
{
  // AoL::rendering::Sound	mixer;
  // mixer.play("Assets/sound/ambiance.ogg", true);
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/AolMenuBackground.png");
  static irr::u32 save = 0;
  static std::string msg = updateSave(save, "Save : ");
  gui->getModulesHolder().back()->getModule()->getButtonsHolder()[4]
    ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
  gui->getModulesHolder().back()->getModule()->getButtonsHolder()[2]
    ->getButton()->setPicturePath(LoadPicture(msg));

  this->gui->setEventClick(AoL::Gui::GUITypeId::M_LOADGAME, AoL::Gui::GUITypeId::B_BACK,
			   ([this]() { this->done = true; save = 0;
			     msg = updateSave(save, "Save : ");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_LOADGAME, AoL::Gui::GUITypeId::B_SAVE_MINUS,
      ([this]() {
       if (save > 0)
       {
       msg = updateSave(--save, "Save : ");
       gui->getModulesHolder().back()->getModule()->getButtonsHolder()[4]
       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
       gui->getModulesHolder().back()->getModule()->getButtonsHolder()[2]
	 ->getButton()->setPicturePath(LoadPicture(msg));
       }
       }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_LOADGAME, AoL::Gui::GUITypeId::B_SAVE_PLUS,
      ([this]() {
       msg = updateSave(++save, "Save : ");
       if (msg == "")
	 --save;
       else
	 {
	 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[4]
	   ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
	 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[2]
	   ->getButton()->setPicturePath(LoadPicture(msg));
	 }
       }));
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font28.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::LoadGameMenu::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::LoadGameMenu::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::LoadGameMenu::~LoadGameMenu()
{

}
