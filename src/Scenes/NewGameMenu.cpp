#include <sys/types.h>
#include "Scenes/NewGameMenu.hpp"
#include "Gui/DefaultNewGameInterface.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Print.hpp"
#include "Core/Core.hpp"

AoL::Scenes::NewGameMenu::NewGameMenu(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Menu Nouvelle Partie", data, new AoL::Gui::DefaultNewGameInterface),
  _idxMap(0), _idxLazy(0)
{
  this->initGui();
}

void	AoL::Scenes::NewGameMenu::playGame()
{
  this->manager.getMixer().pause();
  this->dropGui();
  this->manager.playScene(this->manager.getFactory().createScene<AoL::Scenes::Game>(this->data));
  this->done = true;
  this->manager.getMixer().unpause();
  this->data.setMapSize(irr::core::vector2df(AoL::Scenes::_mapOption[0].mapSize));
  this->data.resetAi();
  this->data.setTimeLimit(10);
}

std::string	AoL::Scenes::NewGameMenu::updateAI(irr::u32 index, std::string ai)
{
  static std::vector<std::string>	ais =
    {
      "Clarage.lua",
      "Michasa.lua",
      "Fe.lua"
    };
  if (index < 1)
    return ais[0];
  if (index > 2)
    return ais[2];
  return (ais[index - 1]);
}

void	AoL::Scenes::NewGameMenu::initGui()
{
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/AolMenuBackground.png");
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_START,
			   ([this]() { this->playGame(); }));
  static irr::u32 mins = 10;
  static irr::u32 ai1 = 0;
  static irr::u32 ai2 = 0;
  static irr::u32 ai3 = 0;
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_BACK,
			   ([this]() { this->done = true; mins = 10; ai1 = ai2 = ai3 = 0; }));

  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_MAPSIZE_MINUS,
			   ([this]() {
			     if (_idxMap > 0)
			       {
				 _idxMap--;
				 this->data.setMapSize(irr::core::vector2df((AoL::Scenes::_mapOption[this->_idxMap].mapSize)));
				 gui->getModulesHolder().front()->getModule()->getButtonsHolder()[2]->getButton()->setText(AoL::Scenes::_mapOption[this->_idxMap].textButton); 
			       }
			   }));

  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_MAPSIZE_PLUS,
			   ([this]() {
			     if (_idxMap < 5)
			       {
				 _idxMap++;
				 this->data.setMapSize(irr::core::vector2df((AoL::Scenes::_mapOption[this->_idxMap].mapSize)));
				 gui->getModulesHolder().front()->getModule()->getButtonsHolder()[2]->getButton()->setText(AoL::Scenes::_mapOption[this->_idxMap].textButton); 
			       }
			   }));

  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_DIFFICULTY_MINUS,
			   ([this]() {
			     if (_idxLazy > 0)
			       {
				 _idxLazy--;
				 this->data.setLaziness(AoL::Scenes::_lazyOption[this->_idxLazy].Laziness);
				 gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]->getButton()->setText(AoL::Scenes::_lazyOption[this->_idxLazy].textButton); 
			       }
			   }));

  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_DIFFICULTY_PLUS,
			   ([this]() {
			     if (_idxLazy < 4)
			       {
				 _idxLazy++;
				 this->data.setLaziness(AoL::Scenes::_lazyOption[this->_idxLazy].Laziness);
				 gui->getModulesHolder().front()->getModule()->getButtonsHolder()[5]->getButton()->setText(AoL::Scenes::_lazyOption[this->_idxLazy].textButton); 
			       }
			   }));

  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_TIMEMAX_MINUS,
			   ([this]() {
			     if (mins > 5)
			       {
				 if (mins > 20)
				   mins -= 5;
				 else
				   --mins;
			       }
			     std::string msg = "Time : " + std::to_string(mins) + " years";
			     gui->getModulesHolder().front()->getModule()->getButtonsHolder()[8]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			     this->data.setTimeLimit(mins);
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_NEWGAME, AoL::Gui::GUITypeId::B_TIMEMAX_PLUS,
			   ([this]() {
			     if (mins < 60)
			       {
				 if (mins >= 20)
				   mins += 5;
				 else
				   ++mins;
			       }
			     std::string msg = "Time : " + std::to_string(mins) + " years";
			     gui->getModulesHolder().front()->getModule()->getButtonsHolder()[8]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			     this->data.setTimeLimit(mins);
			   }));




  this->gui->setEventClick(AoL::Gui::GUITypeId::M_AI, AoL::Gui::GUITypeId::B_AI1_MINUS,
			   ([this]() {
			     if (ai1 > 0)
			       {
				 std::string msg = updateAI(--ai1, "Lazy1 : ");
				 this->data.setAi(1, msg);
				 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[2]
				   ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			       }
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_AI, AoL::Gui::GUITypeId::B_AI1_PLUS,
			   ([this]() {
			     if (ai1 < 3)
			       ai1++;
			     std::string msg = updateAI(ai1, "Lazy1 : ");
			     gui->getModulesHolder().back()->getModule()->getButtonsHolder()[2]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			     this->data.setAi(1, msg);
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_AI, AoL::Gui::GUITypeId::B_AI2_MINUS,
			   ([this]() {
			     if (ai2 > 0)
			       {
				 std::string msg = updateAI(--ai2, "Lazy2 : ");
				 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[5]
				   ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
				 this->data.setAi(2, msg);
			       }
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_AI, AoL::Gui::GUITypeId::B_AI2_PLUS,
			   ([this]() {
			     if (ai2 < 3)
			       ai2++;
			     std::string msg = updateAI(ai2, "Lazy2 : ");
			     gui->getModulesHolder().back()->getModule()->getButtonsHolder()[5]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			     this->data.setAi(2, msg);
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_AI, AoL::Gui::GUITypeId::B_AI3_MINUS,
			   ([this]() {
			     if (ai3 > 0)
			       {
				 std::string msg = updateAI(--ai3, "Lazy3 : ");
				 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[8]
				   ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
				 this->data.setAi(3, msg);
			       }
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_AI, AoL::Gui::GUITypeId::B_AI3_PLUS,
			   ([this]() {
			     if (ai3 < 3)
			       ai3++;
			     std::string msg = updateAI(ai3, "Lazy3 : ");
			     gui->getModulesHolder().back()->getModule()->getButtonsHolder()[8]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			     this->data.setAi(3, msg);
			   }));
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font28.xml", SMALL);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font48.xml", TITLE);
}

bool	AoL::Scenes::NewGameMenu::isDone()
{
  return this->done;
}

irr::s32	AoL::Scenes::NewGameMenu::run(irr::f32 elapsed)
{
  (void)elapsed;
  return (0);
}

AoL::Scenes::NewGameMenu::~NewGameMenu()
{

}
