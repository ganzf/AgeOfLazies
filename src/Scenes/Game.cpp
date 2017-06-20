// Vraiment beaucoup de simplifications d'inclusions a faire. (felix)
#include "Scenes/Scenes.hpp"
#include "Scenes/Game.hpp"
#include "Manager.hpp"
#include "Constants.hpp"
#include "rendering/Sound.hpp"

#include "Gui/DefaultGameInterface.hpp"

#include "Game/AllBuildings.hpp"
#include "Game/AllRessources.hpp"
#include "Game/AllUnits.hpp"
#include "Game/AllOrders.hpp"
#include "Core/Core.hpp"

struct EncycloInfo
{
  std::wstring		name;
  std::wstring		text;
  std::string		pathIcon;
  std::string		pathPicture;
};

AoL::Scenes::Game::Game(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Splashscreen", data, new AoL::Gui::DefaultGameInterface),
  generator(map.getDims().X,
	    map.getDims().Y)
{
  this->setTransparency(false);
  this->scene3d.setIslandScene(irr::core::vector2df(map.getDims()));
  this->manager.associateObserver(&this->observer);
  this->initGui();
  this->scene3d.startPreloading();
  irr::s32 loading = 0;
  while (loading < 40)
    loading = this->scene3d.preload3dAssets();
}

void		AoL::Scenes::Game::encycloSetup()
{
  std::vector<EncycloInfo>	infos = {
    {L"History", L"Once upon a time, gods decided they didn't want to do anything anymore.\nThey created Collectors and Warriors to do their biding.", "collector", "medievalCollector"},
    {L"Laziness", L"A god is as powerful as he is lazy.\nDo less, get more.", "Histoire", "HistoireLarge"},
    
    {L"Collector", L"Slave of the lazy gods. Will do anything.\nEven build new buildings for them."
     "\n20 Wood, 30 Food, 2 Stone, 3 Gold\nBorn in Forums (Key: G)", "collector", "medievalCollector"},
    {L"Warrior", L"Furious slave of the gods. Hates Collectors.\nWill kill and steal from them. Maybe."
     "\n15 Wood, 40 Food, 30 Stone, 50 Gold\nBorn in Forums (Key: H)", "warrior", "medievalWarrior"},
    
    {L"Gatherer", L"Specialised collector : wants a lot of food and nothing else.\n10 Wood, 300 Food, 5 Stone, 5 Gold\nBorn in Forums (Key: Y)", "gatherer", "medievalGatherer"},
    {L"Lumberjack", L"Specialised collector : wants a lot of wood and nothing else.\n300 Wood, 50 Food, 5 Stone, 5 Gold\nBorn in Forums (Key: U)", "lumberjack", "medievalLumberjack"},
    {L"Miner", L"Specialised collector : wants a lot of stone and nothing else.\n10 Wood, 50 Food, 300 Stone, 5 Gold\nBorn in Forums (Key: I)", "miner", "medievalMiner"},
    {L"Gold Digger", L"Specialised collector : wants a lot of gold and nothing else.\n10 Wood, 50 Food, 5 Stone, 300 Gold\nBorn in Forums (Key: O)", "golddigger", "medievalGoldDigger"},
    
    {L"Forum", L"Given by the gods. Collectors can create them.\n500 Wood, 300 Food, 150 Stone, 150 Gold", "forum", "medievalForum"},
    {L"Habitation", L"Expands the gods' powers to enslave Collectors and Warrior and such...\n150 Wood, 75 Food, 20 Stone, 20 Gold", "house", "medievalHouse"},
    {L"Mill", L"Mills are beautiful creations of the gods extending delicious food storage.\n200 Wood, 100 Food, 10 Stone, 10 Gold", "mill", "medievalMill"},
    {L"Forge", L"Masterpiece of the gods with a forever enslaved slave.\nUsed for Gold and Stone storage.\n300 Wood, 10 Food, 200 Stone, 200 Gold", "miningcamp", "medievalSmithy"},
    {L"LumberCamp", L"A mad God sent his giant axe on the ground. And magically created a Lumbercamp.\n500 Wood, 10 Food, 50 Stone, 50 Gold", "lumbercamp", "medievalLumberCamp"},
    {L"Ressources", L"Cacahuete.", "ressources", "medievalRessources"},
  };

  irr::s32	val = AoL::Gui::GUITypeId::B_INFO1;
  for (auto &info: infos)
    {
      this->gui->setEventClick(AoL::Gui::GUITypeId::M_ENCYCLO, static_cast<AoL::Gui::GUITypeId>(val),
			       ([this, info]() {
				 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[17]
				   ->getButton()->setText(info.name);
				 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[19]
				   ->getButton()->setText(info.text);
				 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[16]
				   ->getButton()->setPicturePath("Assets/textures/" + info.pathIcon + ".png");
				 gui->getModulesHolder().back()->getModule()->getButtonsHolder()[18]
				   ->getButton()->setPicturePath("Assets/textures/" + info.pathPicture + ".png");
			       }));
      val++;
    }
}

void		AoL::Scenes::Game::optionsSetup()
{
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_STAT, AoL::Gui::GUITypeId::B_PAUSE,
			   ([this]() {
			     if ((gui->getModulesHolder()[7])->getModule()->isHide())
			       {
				 pauseGame();
				 pause();
				 (gui->getModulesHolder()[4])->getModule()->display();
			       }}));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_PAUSE, AoL::Gui::GUITypeId::B_CONTINUE,
			   ([this]() {
			     pauseGame();
			     unpause();
			     (gui->getModulesHolder()[4])->getModule()->hide();
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_PAUSE, AoL::Gui::GUITypeId::B_OPTION,
			   ([this]() {
			     (gui->getModulesHolder()[4])->getModule()->hide();
			     (gui->getModulesHolder()[5])->getModule()->display();
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_PAUSE, AoL::Gui::GUITypeId::B_SURREND,
			   ([this]() {
			     players.front()->surrend();
			     pauseGame();
			     unpause();
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_PAUSE, AoL::Gui::GUITypeId::B_QUIT,
			   ([this]() {
			     this->done = true;
			   }));

  static irr::u32 song = 75;
  static std::wstring reso = gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
    ->getButton()->getText();
  static std::wstring FullScreen = gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
    ->getButton()->getText();
  gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
    ->getButton()->setText(std::wstring(reso.begin(), reso.end()));
  std::string msg = "Song : " + std::to_string(song) + "%";
  gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[8]
    ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_BACK,
			   ([this]() {
			     (gui->getModulesHolder()[5])->getModule()->hide();
			     (gui->getModulesHolder()[4])->getModule()->display();
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_FULLSCREEN_OFF,
			   ([this]() {
			     gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[2]
			       ->getButton()->setText(reso = L"FullScreen : Off");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_FULLSCREEN_ON,
			   ([this]() {
			     gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[2]
			       ->getButton()->setText(reso = L"FullScreen : On");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_RESO_MINUS,
			   ([this]() {
			     if (gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				 ->getButton()->getText() == L"Format : 1920x1080")
			       gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1440x900");
			     else if (gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				      ->getButton()->getText() == L"Format : 1440x900")
			       gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1280x800");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_RESO_PLUS,
			   ([this]() {
			     if (gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				 ->getButton()->getText() == L"Format : 1440x900")
			       gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1920x1080");
			     else if (gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				      ->getButton()->getText() == L"Format : 1280x800")
			       gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[5]
				 ->getButton()->setText(reso = L"Format : 1440x900");
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_SONG_MINUS,
			   ([this]() {
			     if (song > 0)
			       song -= 5;
			     std::string msg = "Song : " + std::to_string(song) + "%";
			     gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[8]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_SONG_PLUS,
			   ([this]() {
			     if (song < 100)
			       song += 5;
			     std::string msg = "Song : " + std::to_string(song) + "%";
			     gui->getModulesHolder()[5]->getModule()->getButtonsHolder()[8]
			       ->getButton()->setText(std::wstring(msg.begin(), msg.end()));
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_OPTION, AoL::Gui::GUITypeId::B_KEYS,
			   ([this]() {
			     (gui->getModulesHolder()[5])->getModule()->hide();
			     (gui->getModulesHolder()[6])->getModule()->display();
			   }));
  this->gui->setEventClick(AoL::Gui::GUITypeId::M_KEYSBINDING, AoL::Gui::GUITypeId::B_BACK2,
			   ([this]() {
			     (gui->getModulesHolder()[6])->getModule()->hide();
			     (gui->getModulesHolder()[5])->getModule()->display();
			   }));
}

void            AoL::Scenes::Game::initGui()
{
  this->optionsSetup();
  this->encycloSetup();
}

irr::s32	AoL::Scenes::Game::init()
{
  this->map.setScene(this->scene3d);
  this->observer.setMap(&this->map);
  this->observer.setScoreBoard(&this->data.getScoreBoard());
  this->manager.getMixer().play("Assets/sound/ambiance.ogg", true);

  this->generator.genMap();

  this->players.push_back(std::make_shared<AoL::Game::Player>(this->manager, this->map,
							      AoL::Game::Team::TEAM_ONE, this->data.getPlayers()[0]));
  this->players[0]->setTimerDefeat(this->data.getTimeLimit());
  this->observer.registerPlayer(*this->players[0]);
  for (irr::s32 playerIdx = 1; playerIdx < this->data.getNbPlayers(); playerIdx++)
    {
      this->players.push_back(std::make_shared<AoL::Game::Player>(this->manager, this->map, static_cast<AoL::Game::Team>(playerIdx), this->data.getPlayers()[playerIdx]));
      this->observer.registerPlayer(*this->players[playerIdx]);
    }

  std::vector<AoL::Game::Tile>	const &mapSource = generator.getMap();
  try
    {
      for (auto &i : mapSource)
	  {
	    if (i.type == AoL::Game::RessourceType::WOOD)
	      if (this->map.addOriginEntity(this->manager.getFactory().createEntity<AoL::Game::Wood>(i.pos.X, i.pos.Y)) == false)
		return (-1);
	    if (i.type == AoL::Game::RessourceType::GOLD)
	      if (this->map.addOriginEntity(this->manager.getFactory().createEntity<AoL::Game::Gold>(i.pos.X, i.pos.Y)) == false)
		return (-1);
	    if (i.type == AoL::Game::RessourceType::FOOD)
	      if (this->map.addOriginEntity(this->manager.getFactory().createEntity<AoL::Game::Food>(i.pos.X, i.pos.Y)) == false)
		return (-1);
	    if (i.type == AoL::Game::RessourceType::STONE)
	      if (this->map.addOriginEntity(this->manager.getFactory().createEntity<AoL::Game::Stone>(i.pos.X, i.pos.Y)) == false)
		return (-1);
	  }
      for (irr::s32 idx = 0; idx < this->data.getNbPlayers(); idx++)
	{
	  irr::core::vector2df	spawnPoint = this->generator.getSpawnPoints(idx);
	  AoL::Game::Forum *forum = this->players[idx]->createOriginEntity<AoL::Game::Forum>(spawnPoint);
	  if (!forum)
	    return (-1);
	  forum->getStock().changeNb(AoL::Game::RessourceType::WOOD, 500);
	  forum->getStock().changeNb(AoL::Game::RessourceType::FOOD, 500);
	  forum->getStock().changeNb(AoL::Game::RessourceType::STONE, 250);
	  forum->getStock().changeNb(AoL::Game::RessourceType::GOLD, 200);
	}
      this->scene3d.centerCameraOn(this->map.getRealPos(this->generator.getSpawnPoints(0)));
    }
  catch (std::exception const &err)
    {
      this->done = true;
      return (-1);
    }
  this->manager.getCore().getRenderer().getGui().modifyPlayer(this->players[0].get());
  this->manager.getCore().getRenderer().getGui().setGui(*this->gui);
  this->manager.getCore().getRenderer().getGui().setFont("Assets/fonts/font18.xml", SMALL);
  return (0);
}

bool		AoL::Scenes::Game::isDone()
{
  return this->done;
}

void		AoL::Scenes::Game::pauseGame()
{
  if (this->isPaused())
    this->unpause();
  else
    this->pause();
}

void		AoL::Scenes::Game::focus()
{
  if (this->selectedEntities.size() > 0)
    this->scene3d.centerCameraOn(*this->selectedEntities.front());
}

void		AoL::Scenes::Game::placeBuild()
{
  this->map.updateHoverPos(this->scene3d.getPosOnTerrain());
  if (this->isClicked(AoL::UserInput::MouseAttributs::LEFT_CLICK))
    {
      if (this->map.hoverIsValid())
	{
	  players.front()->removeRessource(AoL::Game::RessourceType::WOOD, map.getHoverControlled()->getCost()[0]);
	  players.front()->removeRessource(AoL::Game::RessourceType::FOOD, map.getHoverControlled()->getCost()[1]);
	  players.front()->removeRessource(AoL::Game::RessourceType::STONE, map.getHoverControlled()->getCost()[2]);
	  players.front()->removeRessource(AoL::Game::RessourceType::GOLD, map.getHoverControlled()->getCost()[3]);
	  // players.front()->getBuildings().push_back(dynamic_cast<AoL::Game::Building *>(map.getHoverControlled())); /// A VOIR
	  players.front()->removeRessInBuildings(map.getHoverControlled()->getCost());
	  if (this->map.getHoverControlled()->getName() == AoL::Game::EntityName::HABITATION)
	    this->players.front()->incPopulation(5);
	  this->map.addHoverToMap();
	}
    }
}

irr::s32	AoL::Scenes::Game::actionOnControlled(AoL::Game::Unit *controlledUnit) const
{
  auto target = dynamic_cast<AoL::Game::Controlled*>(this->selectorInfo.selected.front());
  if (target && target->getTeam() != AoL::Game::Team::TEAM_ONE)
    players.front()->attack(controlledUnit, *target);
  else if (target && dynamic_cast<AoL::Game::Building *>(target) != nullptr)
    {
      players.front()->deposit(controlledUnit, *dynamic_cast<AoL::Game::Building *>(target));
    }
  else
    return (1);
  return (0);
}

void		AoL::Scenes::Game::controlledActions(AoL::Game::Unit *controlledUnit) const
{
  if (this->selectorInfo.selected.front()->getNbAnchorsFree() <= 0)
    return ;
  controlledUnit->goTo(this->selectorInfo.selected.front());
  if (actionOnControlled(controlledUnit) == 1)
    {
      auto target = dynamic_cast<AoL::Game::Controlled*>(this->selectorInfo.selected.front());
      players.front()->collect(controlledUnit);
    }
}

void		AoL::Scenes::Game::select()
{
  if (this->scene3d.mouseIsGui() || this->map.hasHover())
    return ;
  AoL::Game::Controlled *controlled = nullptr;
  for (auto &s: this->selectedEntities)
    {
      if (s != nullptr)
	s->setSelected(false);
    }
  this->selectedEntities.clear();
  this->selectorInfo = this->scene3d.getNodeFromClick();
  this->selectedEntities = this->selectorInfo.selected;
  if (this->selectorInfo.selected.size() > 0)
    {
      controlled = dynamic_cast<AoL::Game::Controlled *>(selectedEntities.front());
      if (!controlled || (controlled && controlled->getTeam() == AoL::Game::Team::TEAM_ONE))
	{
	  players.front()->selectUnit(selectedEntities);
	  this->selectorInfo.selected.front()->setSelected(true);
	}
      this->manager.getCore().getRenderer().getGui().modifyInspector(this->selectedEntities.front());
    }
  else
    this->manager.getCore().getRenderer().getGui().modifyInspector(nullptr);
}

void		AoL::Scenes::Game::target()
{
  if (this->map.hasHover())
    return ;
  AoL::Game::Unit *controlledUnit = dynamic_cast<AoL::Game::Unit *>(this->selectedEntities.front());
  if (controlledUnit != nullptr && controlledUnit->getTeam() == AoL::Game::Team::TEAM_ONE)
    {
      bool valid = this->map.posIsInbound(irr::core::vector2df(this->selectorInfo.pos.X, this->selectorInfo.pos.Y));
      this->selectorInfo = this->scene3d.getNodeFromClick();
      players.front()->selectUnit(selectorInfo.selected);
      if (valid)
	controlledUnit->cancelOrders();
      if (this->selectorInfo.selected.size() > 0)
	controlledActions(controlledUnit);
      else if (valid)
	players.front()->move(controlledUnit, selectorInfo.pos);
    }
}

irr::s32	AoL::Scenes::Game::run(irr::f32 elapsed)
{
  for (auto &player: this->players)
    player->setStart(true);
  this->selectorInfo.selected.clear();
  if (this->isPressed(AoL::UserInput::KeyValue::ESCAPE)
      && this->map.hasHover())
    this->cancelBuild();
  if (this->isPressed(AoL::UserInput::KeyValue::F))
    focus();
  if (this->isPressed(AoL::UserInput::KeyValue::E))
    {
      if ((gui->getModulesHolder()[7])->getModule()->isHide())
	(gui->getModulesHolder()[7])->getModule()->display();
      else
	(gui->getModulesHolder()[7])->getModule()->hide();
    }
  if (this->isClicked(AoL::UserInput::MouseAttributs::LEFT_CLICK))
    select();
  if (this->isClicked(AoL::UserInput::MouseAttributs::RIGHT_CLICK) && this->selectedEntities.size() > 0)
    target();
  if (this->map.hasHover())
    placeBuild();
  if (this->selectedEntities.size() > 0)
    {
      if (this->selectedEntities.front()->getName() == AoL::Game::COLLECTOR)
	{
	  if (this->isPressed(AoL::UserInput::KeyValue::H))
	    this->startBuildProcess<AoL::Game::Habitation>();
	  if (this->isPressed(AoL::UserInput::KeyValue::J))
	    this->startBuildProcess<AoL::Game::Mill>();
	  if (this->isPressed(AoL::UserInput::KeyValue::M))
	    this->startBuildProcess<AoL::Game::MiningCamp>();
	  if (this->isPressed(AoL::UserInput::KeyValue::L))
	    this->startBuildProcess<AoL::Game::LumberCamp>();
	  if (this->isPressed(AoL::UserInput::KeyValue::G))
	    this->startBuildProcess<AoL::Game::Forum>();
	}
      if (this->selectedEntities.front()->getName() == AoL::Game::FORUM)
	{
	  if (this->isPressed(AoL::UserInput::KeyValue::G))
	    this->spawn<AoL::Game::Warrior>();
	  if (this->isPressed(AoL::UserInput::KeyValue::H))
	    this->spawn<AoL::Game::Collector>();
	}
    }
  // End of frame for the map.
  this->players[0]->consumeRessources(elapsed);
  this->map.doOrders(elapsed);
  this->map.deleteDead();
  this->map.updateBuildingInProgress();

  // Check if the game is over.
  for (auto &player: this->players)
    player->updateWinStatus();
  for (irr::s32 playerIdx = 1; playerIdx < this->players.size(); playerIdx++)
    if (this->players[playerIdx]->hasWon() == true)
      this->players[0]->setStatus(AoL::Game::PlayerStatus::LOOSE);
  if (this->players[0]->hasWon() == true
      || this->players[0]->hasLost() == true)
    {
      this->done = true;
      this->data.setWinStatus(this->players[0]->getStatus() == AoL::Game::PlayerStatus::WIN);
    }

  // Stop AI Scripts.
  for (auto &player: this->players)
    player->setStart(false);
  return (0);
}

AoL::Scenes::Game::~Game()
{
  this->manager.getMixer().pause();
  this->dropGui();
  if (players.front()->getStatus() == AoL::Game::PlayerStatus::LOOSE)
    this->manager.playScene(manager.getFactory().createScene<AoL::Scenes::Defeat>(this->data));
  else if (players.front()->getStatus() == AoL::Game::PlayerStatus::WIN)
    this->manager.playScene(manager.getFactory().createScene<AoL::Scenes::Victory>(this->data));
}

void		AoL::Scenes::Game::deselectEntities()
{
  this->selectedEntities.clear();
}
