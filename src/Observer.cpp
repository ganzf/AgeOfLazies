# include "Observer.hpp"
# include "Game/Map.hpp"
# include "Message.hpp"
# include "Game/Player.hpp"
# include "Game/AllBuildings.hpp"
# include "Game/AllUnits.hpp"
# include "Scenes/Scenes.hpp"
# include "Factory.hpp"
# include "Game/Score.hpp"

void		AoL::Observer::assocFunctions()
{
  // Events
  this->functions[AoL::SPAWN] = &AoL::Observer::entitySpawn;
  this->functions[AoL::DEATH] = &AoL::Observer::entityDeath;
  this->functions[AoL::BUILT] = &AoL::Observer::buildingBuilt;
  this->functions[AoL::DESTROYED] = &AoL::Observer::buildingDestroyed;
  this->functions[AoL::COLLECT] = &AoL::Observer::unitCollect;
  this->functions[AoL::DEPOSIT] = &AoL::Observer::unitDeposit;
  this->functions[AoL::GAINCONTROL] = &AoL::Observer::gainControl;
  this->functions[AoL::RELEASECONTROL] = &AoL::Observer::releaseControl;
  this->functions[AoL::ATTACK] = &AoL::Observer::controlledAttack;
  this->functions[AoL::KILL] = &AoL::Observer::controlledKilled;
  this->functions[AoL::COLLECT_DONE] = &AoL::Observer::collectDone;
  this->functions[AoL::LEVEL_UP] = &AoL::Observer::levelUp;
  
  // Unit Creation
  this->functions[AoL::CREATE_COLLECTOR] = &AoL::Observer::createCollector;
  this->functions[AoL::CREATE_WARRIOR] = &AoL::Observer::createWarrior;
  this->functions[AoL::CREATE_GATHERER] = &AoL::Observer::createGatherer;
  this->functions[AoL::CREATE_GOLDMINER] = &AoL::Observer::createGoldMiner;
  this->functions[AoL::CREATE_MINER] = &AoL::Observer::createMiner;
  this->functions[AoL::CREATE_LUMBERJACK] = &AoL::Observer::createLumberjack;

  // Building Creation
  this->functions[AoL::CREATE_MILL] = &AoL::Observer::createMill;
  this->functions[AoL::CREATE_MININGCAMP] = &AoL::Observer::createMiningCamp;
  this->functions[AoL::CREATE_LUMBERCAMP] = &AoL::Observer::createLumberCamp;
  this->functions[AoL::CREATE_HABITATION] = &AoL::Observer::createHabitation;
  this->functions[AoL::CREATE_FORUM] = &AoL::Observer::createForum;

  // Sound Effects
  this->sounds[AoL::MessageType::DEPOSIT] = "Assets/sound/OhBahNon.ogg";
  this->sounds[AoL::MessageType::COLLECT_DONE] = "Assets/sound/OhBahNon.ogg";
  this->sounds[AoL::MessageType::SPAWN] = "Assets/sound/POURQUOITASFAITCA.ogg";
  this->sounds[AoL::MessageType::CREATE_WARRIOR] = "Assets/sound/POURQUOITASFAITCA.ogg";
  this->sounds[AoL::MessageType::CREATE_COLLECTOR] = "Assets/sound/POURQUOITASFAITCA.ogg";
  this->sounds[AoL::MessageType::LEVEL_UP] = "Assets/sound/POURQUOITASFAITCA.ogg";
  this->sounds[AoL::MessageType::DEATH] = "Assets/sound/POURQUOITASFAITCA.ogg";

  // Queries / Finders
  this->finderFuncs[AoL::Game::UnitRole::FIGHTER] = nullptr;
  this->finderFuncs[AoL::Game::UnitRole::LUMBERJACK] = &AoL::Observer::findWood;
  this->finderFuncs[AoL::Game::UnitRole::MINER] = &AoL::Observer::findStone;
  this->finderFuncs[AoL::Game::UnitRole::GATHERER] = &AoL::Observer::findFood;
  this->finderFuncs[AoL::Game::UnitRole::GOLDDIGGER] = &AoL::Observer::findGold;
  this->buildingFinders[AoL::Game::UnitRole::LUMBERJACK] = &AoL::Observer::findLumberCamp;
  this->buildingFinders[AoL::Game::UnitRole::FIGHTER] = nullptr;
  this->buildingFinders[AoL::Game::UnitRole::MINER] = &AoL::Observer::findMiningCamp;
  this->buildingFinders[AoL::Game::UnitRole::GOLDDIGGER] = &AoL::Observer::findMiningCamp;
  this->buildingFinders[AoL::Game::UnitRole::GATHERER] = &AoL::Observer::findMill;
}

AoL::Observer::Observer(AoL::Scenes::AScene &parent): parent(parent)
{
  this->assocFunctions();
}

AoL::Observer::Observer(AoL::Observer const &ref):
  parent(ref.getParent()),
  gameMap(ref.getMap()),
  players(ref.getPlayers())
{
  this->assocFunctions();
}

void	AoL::Observer::setScoreBoard(AoL::Game::Score *score)
{
  this->scoreboard = score;
}

void	AoL::Observer::collectDone(AoL::Message &msg)
{
  if (msg.getParent().getType() == AoL::Game::UNIT)
    {
      auto unit = dynamic_cast<AoL::Game::Unit *>(&msg.getParent());
      if (unit)
	{
	  AoL::Game::Building *(AoL::Observer::*finder)(AoL::Message &) = this->buildingFinders[unit->getRole()];

	  AoL::Game::Building *target = (this->*finder)(msg);
	  if (target)
	    unit->deposit(*target);
	}
    }
}

template	<typename T>
void		AoL::Observer::createUnit(AoL::Message &msg)
{
  if (msg.getParent().getType() == AoL::Game::BUILDING)
    {
      auto building = dynamic_cast<AoL::Game::Building *>(&msg.getParent());
      T		tmp(0, 0, *this);
      if (building && building->hasStock(tmp.getCost()) == 0)
	{
	  if (this->players[msg.getParent().getTeam()]->hasRoomForUnits())
	    {
	      this->players[msg.getParent().getTeam()]->createEntity<T>(building->getSpawnPoint());
	      building->getStock().changeNb(AoL::Game::RessourceType::WOOD, -tmp.getCost()[0]);
	      building->getStock().changeNb(AoL::Game::RessourceType::FOOD, -tmp.getCost()[1]);
	      building->getStock().changeNb(AoL::Game::RessourceType::STONE, -tmp.getCost()[2]);
	      building->getStock().changeNb(AoL::Game::RessourceType::GOLD, -tmp.getCost()[3]);
	    }
	  else
	    {
	      // static AoL::rendering::Sound	mixer;
	      // Play sound
	    }
	}
    }
}

template	<typename T>
void		AoL::Observer::createBuilding(AoL::Message &msg)
{
  if (msg.getParent().getType() == AoL::Game::UNIT)
    {
      auto gameScene = dynamic_cast<AoL::Scenes::Game *>(&parent);
      if (gameScene)
	{
	  gameScene->startBuildProcess<T>();
	}
    }
}

void	AoL::Observer::createWarrior(AoL::Message &msg)
{
  this->createUnit<AoL::Game::Warrior>(msg);
}

void	AoL::Observer::createCollector(AoL::Message &msg)
{
    this->createUnit<AoL::Game::Collector>(msg);
  // if (msg.getParent().getType() == AoL::Game::BUILDING)
  //   {
  //     auto building = dynamic_cast<AoL::Game::Building *>(&msg.getParent());
  //     AoL::Game::Collector		tmp(0, 0, *this);
  //     if (building && building->hasStock(tmp.getCost()) == 0)
  // 	{
  // 	  if (this->players[msg.getParent().getTeam()]->hasRoomForUnits())
  // 	    {
  // 	      this->players[msg.getParent().getTeam()]->createEntity<AoL::Game::Collector>(building->getSpawnPoint());
  // 	      building->getStock().changeNb(AoL::Game::RessourceType::WOOD, -tmp.getCost()[0]);
  // 	      building->getStock().changeNb(AoL::Game::RessourceType::FOOD, -tmp.getCost()[1]);
  // 	      building->getStock().changeNb(AoL::Game::RessourceType::STONE, -tmp.getCost()[2]);
  // 	      building->getStock().changeNb(AoL::Game::RessourceType::GOLD, -tmp.getCost()[3]);
  // 	    }
  // 	}
  //     else
  // 	{
  // 	  // static AoL::rendering::Sound	mixer;
  // 	  // Play sound
  // 	}
  //   }
}

void	AoL::Observer::createLumberjack(AoL::Message &msg)
{
  this->createUnit<AoL::Game::Lumberjack>(msg);
}

void	AoL::Observer::createGoldMiner(AoL::Message &msg)
{
  this->createUnit<AoL::Game::Golddigger>(msg);
}

void	AoL::Observer::createMiner(AoL::Message &msg)
{
  this->createUnit<AoL::Game::Miner>(msg);
}

void	AoL::Observer::createGatherer(AoL::Message &msg)
{
  this->createUnit<AoL::Game::Gatherer>(msg);
}

void	AoL::Observer::createMiningCamp(AoL::Message &msg)
{
  this->createBuilding<AoL::Game::MiningCamp>(msg);
}

void	AoL::Observer::createLumberCamp(AoL::Message &msg)
{
  this->createBuilding<AoL::Game::LumberCamp>(msg);
}

void	AoL::Observer::createMill(AoL::Message &msg)
{
  this->createBuilding<AoL::Game::Mill>(msg);
}

void	AoL::Observer::createHabitation(AoL::Message &msg)
{
  this->createBuilding<AoL::Game::Habitation>(msg);
}

void	AoL::Observer::createForum(AoL::Message &msg)
{
  this->createBuilding<AoL::Game::Forum>(msg);
}

void	AoL::Observer::registerPlayer(AoL::Game::Player &player)
{
  this->players[player.getTeam()] = &player;
}

void	AoL::Observer::unregisterPlayer(AoL::Game::Player &player)
{
  this->players[player.getTeam()] = nullptr;
}

// any entity is created
void	AoL::Observer::entitySpawn(AoL::Message &)
{

}

void	AoL::Observer::levelUp(AoL::Message &)
{

}

// any entity dies
void	AoL::Observer::entityDeath(AoL::Message &msg)
{
  if (msg.getParent().isMarked())
    return ;
  msg.getParent().markDead();
  auto scene = dynamic_cast<AoL::Scenes::Game *>(&this->parent);
  if (scene && msg.getParent().isSelected() == true)
    scene->deselectEntities();
  this->gameMap->markDead(msg.getParent());
  if (msg.getParent().getType() == AoL::Game::EntityType::UNIT ||
      msg.getParent().getType() == AoL::Game::EntityType::BUILDING)
    this->players[msg.getParent().getTeam()]->destroyEntity(dynamic_cast<AoL::Game::Controlled *>(&msg.getParent()));
}

void	AoL::Observer::buildingBuilt(AoL::Message &)
{

}

// a building is destroyed
void	AoL::Observer::buildingDestroyed(AoL::Message &)
{

}

// a unit collect stock from ressources
void	AoL::Observer::unitCollect(AoL::Message &)
{

}

AoL::Game::Building	*AoL::Observer::findLumberCamp(AoL::Message &msg)
{
  AoL::Game::Building	*lumber = this->gameMap->FindFrom<AoL::Game::LumberCamp>(msg.getParent().getPosition(), msg.getParent().getTeam());
  AoL::Game::Building	*forum = this->gameMap->FindFrom<AoL::Game::Forum>(msg.getParent().getPosition(), msg.getParent().getTeam());
  if (lumber && forum)
    {
      irr::f32		dist = lumber->getPosition().getDistanceFrom(msg.getParent().getPosition());
      if (dist > forum->getPosition().getDistanceFrom(msg.getParent().getPosition()))
	return forum;
      return lumber;
    }
  else
    return (lumber ? lumber : forum);
}

AoL::Game::Building	*AoL::Observer::findMiningCamp(AoL::Message &msg)
{
  AoL::Game::Building	*Mining = this->gameMap->FindFrom<AoL::Game::MiningCamp>(msg.getParent().getPosition(), msg.getParent().getTeam());
  AoL::Game::Building	*forum = this->gameMap->FindFrom<AoL::Game::Forum>(msg.getParent().getPosition(), msg.getParent().getTeam());
  if (Mining && forum)
    {
      irr::f32		dist = Mining->getPosition().getDistanceFrom(msg.getParent().getPosition());
      if (dist > forum->getPosition().getDistanceFrom(msg.getParent().getPosition()))
	return forum;
      return Mining;
    }
  else
    return (Mining ? Mining : forum);
}

AoL::Game::Building	*AoL::Observer::findMill(AoL::Message &msg)
{
  AoL::Game::Building	*mill = this->gameMap->FindFrom<AoL::Game::Mill>(msg.getParent().getPosition(), msg.getParent().getTeam());
  AoL::Game::Building	*forum = this->gameMap->FindFrom<AoL::Game::Forum>(msg.getParent().getPosition(), msg.getParent().getTeam());
  if (mill && forum)
    {
      irr::f32		dist = mill->getPosition().getDistanceFrom(msg.getParent().getPosition());
      if (dist > forum->getPosition().getDistanceFrom(msg.getParent().getPosition()))
	return forum;
      return mill;
    }
  else
    return (mill ? mill : forum);
}

AoL::Game::Ressource	*AoL::Observer::findWood(AoL::Message &msg)
{
  return this->gameMap->FindFrom<AoL::Game::Wood>(msg.getParent().getPosition(), AoL::Game::Team::UNDEFINED);
}
AoL::Game::Ressource	*AoL::Observer::findStone(AoL::Message &msg)
{
  return this->gameMap->FindFrom<AoL::Game::Stone>(msg.getParent().getPosition(), AoL::Game::Team::UNDEFINED);
}
AoL::Game::Ressource	*AoL::Observer::findFood(AoL::Message &msg)
{
  return this->gameMap->FindFrom<AoL::Game::Food>(msg.getParent().getPosition(), AoL::Game::Team::UNDEFINED);
}
AoL::Game::Ressource	*AoL::Observer::findGold(AoL::Message &msg)
{
  return this->gameMap->FindFrom<AoL::Game::Gold>(msg.getParent().getPosition(), AoL::Game::Team::UNDEFINED);
}

// a unit deposits stock
void				AoL::Observer::unitDeposit(AoL::Message &msg)
{
  this->players[msg.getParent().getTeam()]->addRessource(msg.getRessource(), msg.getAmount());
  if (msg.getParent().getType() == AoL::Game::UNIT)
    {
      auto unit = dynamic_cast<AoL::Game::Unit *>(&msg.getParent());
      if (unit && unit->getRole() != AoL::Game::UnitRole::NONE)
	{
	  AoL::Game::Ressource *(AoL::Observer::*finderFunction)(AoL::Message &) = this->finderFuncs[unit->getRole()];
	  if (finderFunction == nullptr)
	    return ;
	  AoL::Game::Ressource *target = (this->*finderFunction)(msg);
	  if (target)
	    unit->collect(*target);
	}
    }
}

// A control who didn't have any orders gains one
void	AoL::Observer::gainControl(AoL::Message &msg)
{
  auto	controlledEntity = dynamic_cast<AoL::Game::Controlled *>(&msg.getParent());
  if (controlledEntity)
    this->gameMap->addControlled(controlledEntity);
}

// a controlled has no more orders
void	AoL::Observer::releaseControl(AoL::Message &msg)
{
  auto	controlledEntity = dynamic_cast<AoL::Game::Controlled *>(&msg.getParent());
  if (controlledEntity)
    this->gameMap->removeControlled(controlledEntity);
}

// A unit attacks another one
void	AoL::Observer::controlledAttack(AoL::Message &)
{

}

// A unit killed another one
void	AoL::Observer::controlledKilled(AoL::Message &)
{

}

void	AoL::Observer::notify(AoL::Message &msg)
{
  static AoL::rendering::Sound	mixer;
  void	(AoL::Observer::*ptr)(AoL::Message &) = this->functions[msg.getType()];

  (this->*ptr)(msg);
  // mixer.play(sounds[msg.getType()]);
}

template void	AoL::Observer::createUnit<AoL::Game::Collector>(AoL::Message &);
template void	AoL::Observer::createUnit<AoL::Game::Warrior>(AoL::Message &);
template void	AoL::Observer::createUnit<AoL::Game::Lumberjack>(AoL::Message &);
template void	AoL::Observer::createUnit<AoL::Game::Golddigger>(AoL::Message &);
template void	AoL::Observer::createUnit<AoL::Game::Gatherer>(AoL::Message &);
template void	AoL::Observer::createUnit<AoL::Game::Miner>(AoL::Message &);

template void	AoL::Observer::createBuilding<AoL::Game::MiningCamp>(AoL::Message &);
template void	AoL::Observer::createBuilding<AoL::Game::LumberCamp>(AoL::Message &);
template void	AoL::Observer::createBuilding<AoL::Game::Habitation>(AoL::Message &);
template void	AoL::Observer::createBuilding<AoL::Game::Mill>(AoL::Message &);
