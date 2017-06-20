# include <unordered_map>
# include <vector>
# include <functional>
# include "Game/AiPlayer.hpp"
# include "Game/Map.hpp"
# include "Game/LuaFunc.hpp"
# include "Game/AllUnits.hpp"
# include "Game/AllBuildings.hpp"

static std::unordered_map<std::string, AoL::Game::AiPlayer *>     g_ai;

AoL::Game::AiPlayer	*AiPlayer_new(lua_State *L)
{
  std::string	name = luaL_checkstring(L, 1);
  if (g_ai.find(name) != g_ai.end())
    return g_ai.at(name);
  return (nullptr);
}

static const luaL_Reg AiPlayer_table[] = {
  {nullptr, nullptr}
};

static const luaL_Reg AiPlayer_metatable[] = {
  {"print", AiPlayer_print},
  {"getWood", AiPlayer_getWood},
  {"getMaxWood", AiPlayer_getMaxWood},
  {"getStone", AiPlayer_getStone},
  {"getMaxStone", AiPlayer_getMaxStone},
  {"getFood", AiPlayer_getFood},
  {"getMaxFood", AiPlayer_getMaxFood},
  {"getGold", AiPlayer_getGold},
  {"getMaxGold", AiPlayer_getMaxGold},
  {"collect", AiPlayer_collect},
  {"createUnit", AiPlayer_createUnit},
  {"createBuilding", AiPlayer_createBuilding},
  {"getNbUnit", AiPlayer_getNbUnit},
  {"getCostBuilding", AiPlayer_getCostBuilding},
  {"getCostUnit", AiPlayer_getCostUnit},
  {"checkFrame", AiPlayer_checkFrame},
  {"getNbCollector", AiPlayer_getNbCollector},
  {"getNbWarrior", AiPlayer_getNbWarrior},
  {nullptr, nullptr}
};

AoL::Game::AiPlayer::AiPlayer(AoL::Game::Player &player, std::string const &filename)
  : _player(player), _luaFile(filename)
{
  this->_ai = std::thread(&AoL::Game::AiPlayer::execute, std::ref(*this));
  g_ai[player.getName()] = this;
}

AoL::Game::Building	*AoL::Game::AiPlayer::findForum() const
{
  auto			buildings = this->_player.getBuildings();

  for (auto const &building: buildings)
  {
    auto tmp = dynamic_cast<AoL::Game::Forum *>(building);
    if (tmp != nullptr && tmp->getName() == AoL::Game::EntityName::FORUM)
      return building;
  }
  return nullptr;
}

bool		AoL::Game::AiPlayer::createUnit(AoL::Game::UnitType unit)
{
  auto		forum = this->findForum();

  if (forum == nullptr)
    return false;
  if (this->getWood() >= this->getWoodCostUnit(unit)
      && this->getStone() >= this->getStoneCostUnit(unit)
      && this->getGold() >= this->getGoldCostUnit(unit)
      && this->getFood() >= this->getFoodCostUnit(unit))
  {
    std::unordered_map<AoL::Game::UnitType, std::function<void()>> factor =
    {
      {AoL::Game::UnitType::COLLECTOR,
	[this, &forum]()
	{this->_player.createEntity<AoL::Game::Collector>(forum->getSpawnPoint()); } },
      {AoL::Game::UnitType::WARRIOR,
	[this, &forum]()
	{this->_player.createEntity<AoL::Game::Warrior>(forum->getSpawnPoint()); } },
      {AoL::Game::UnitType::WOOD_COLLECTOR,
	[this, &forum]()
	{this->_player.createEntity<AoL::Game::Lumberjack>(forum->getSpawnPoint()); } },
      {AoL::Game::UnitType::FOOD_COLLECTOR,
	[this, &forum]()
	{this->_player.createEntity<AoL::Game::Gatherer>(forum->getSpawnPoint()); } },
      {AoL::Game::UnitType::STONE_COLLECTOR,
	[this, &forum]()
	{this->_player.createEntity<AoL::Game::Miner>(forum->getSpawnPoint()); } },
      {AoL::Game::UnitType::GOLD_COLLECTOR,
	[this, &forum]()
	{this->_player.createEntity<AoL::Game::Golddigger>(forum->getSpawnPoint()); } }
    };
    factor[unit]();
  }
  return true;
}

bool		AoL::Game::AiPlayer::createBuilding(AoL::Game::BuildingType building)
{
  if (this->getWood() >= this->getWoodCostBuilding(building)
      && this->getStone() >= this->getStoneCostBuilding(building)
      && this->getGold() >= this->getGoldCostBuilding(building)
      && this->getFood() >= this->getFoodCostBuilding(building))
    {
      AoL::Game::Unit *unit = this->findEmergencyUnit(AoL::Game::NONE);

      if (unit)
	{
	  irr::core::vector2df result;
	  std::unordered_map<AoL::Game::BuildingType, std::function<void()>> factor =
	    {
	      {AoL::Game::BuildingType::FORUM,
	       [this, &result]()
	       {this->_player.createEntity<AoL::Game::Forum>(result); } },
	      {AoL::Game::BuildingType::HABITATION,
	       [this, &result]()
	       {this->_player.createEntity<AoL::Game::Habitation>(result); } },
	      {AoL::Game::BuildingType::LUMBERCAMP,
	       [this, &result]()
	       {this->_player.createEntity<AoL::Game::LumberCamp>(result); } },
	      {AoL::Game::BuildingType::MININGCAMP,
	       [this, &result]()
	       {this->_player.createEntity<AoL::Game::MiningCamp>(result); } },
	      {AoL::Game::BuildingType::MILL,
	       [this, &result]()
	       {this->_player.createEntity<AoL::Game::Mill>(result); } },
	    };
	  irr::core::vector2df start = unit->getPosition();
	  irr::core::vector2df bckp = unit->getPosition();
	  if ((result = this->_player.getMap().findPosForBuilding(start, 1)) != bckp)
	    {
	      if (!this->_player.getMap().getGrid().isOccupiedAt(result))
		factor[building]();
	    }
	}
    }
  return true;
}

irr::s32	AoL::Game::AiPlayer::getNbUnit(AoL::Game::UnitRole role) const
{
  auto		units = this->_player.getUnits();
  irr::s32	nb = 0;

  for (auto const &unit : units)
  {
    if (unit->getRole() == role)
      nb++;
  }
  return nb;
}

AoL::Game::Unit	*AoL::Game::AiPlayer::findUnit(AoL::Game::UnitRole role) const
{
  auto		units = this->_player.getUnits();

  for (auto const &unit : units)
  {
    if (!unit->isBusy())
      return unit;
  }
  return nullptr;
}

AoL::Game::Unit	*AoL::Game::AiPlayer::findEmergencyUnit(AoL::Game::UnitRole role) const
{
  if (this->_player.getUnits().size() > 0)
    {
      this->_player.getUnits().front()->cancelOrders();
      return this->_player.getUnits().front();
    }
  return nullptr;
}

bool		AoL::Game::AiPlayer::attack(irr::s32 distance)
{
  auto		units = this->_player.getUnits();

  for (auto const &unit : units)
  {
    if (unit->getRole() == AoL::Game::UnitRole::FIGHTER)
    {
      auto pos = unit->getPosition();
      auto nearest = this->_player.getMap().FindFrom<AoL::Game::Unit>(pos, this->_player.getTeam());
      if (nearest != nullptr)
      {
	auto nearestPos = nearest->getPosition();
	if (nearestPos.X <= pos.X + distance && nearestPos.X >= pos.X - distance
	    && nearestPos.Y <= pos.Y + distance && nearestPos.Y >= pos.Y - distance)
	  unit->giveOrder<AoL::Game::Orders::Attack>(*nearest);
      }
    }
  }
  return (true);
}

bool		AoL::Game::AiPlayer::collectWood()
{
  auto		unit = this->findUnit();
  if (!unit)
    return false;

  auto		pos = unit->getPosition();
  auto		nearest = this->_player.getMap().FindFrom<AoL::Game::Wood>(pos, AoL::Game::Team::UNDEFINED);

  if (nearest == nullptr)
    return false;
  unit->collect(*nearest);
  return true;
}

bool		AoL::Game::AiPlayer::collectStone()
{
  auto		unit = this->findUnit(AoL::Game::UnitRole::NONE);
  if (!unit)
    return false;
  auto		pos = unit->getPosition();
  auto		nearest = this->_player.getMap().FindFrom<AoL::Game::Stone>(pos, AoL::Game::Team::UNDEFINED);

  if (nearest == nullptr)
    return false;
  unit->collect(*nearest);
  return true;
}

bool		AoL::Game::AiPlayer::collectGold()
{
  auto		unit = this->findUnit(AoL::Game::UnitRole::NONE);
  if (!unit)
    return false;
  auto		pos = unit->getPosition();
  auto		nearest = this->_player.getMap().FindFrom<AoL::Game::Gold>(pos, AoL::Game::Team::UNDEFINED);

  if (nearest == nullptr)
    return false;
  unit->collect(*nearest);
  return true;
}

bool		AoL::Game::AiPlayer::collectFood()
{
  auto		unit = this->findUnit(AoL::Game::UnitRole::NONE);
  if (!unit)
    return false;
  auto		pos = unit->getPosition();
  auto		nearest = this->_player.getMap().FindFrom<AoL::Game::Food>(pos, AoL::Game::Team::UNDEFINED);

  if (nearest == nullptr)
    return false;
  unit->collect(*nearest);
  return true;
}

void		AoL::Game::AiPlayer::print() const
{

}

irr::s32	AoL::Game::AiPlayer::getWoodCostBuilding(AoL::Game::BuildingType building) const
{
  std::vector<irr::s32>		cost = AoL::Game::BuildingCost.at(building);

  return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::WOOD)]);
}

irr::s32	AoL::Game::AiPlayer::getStoneCostBuilding(AoL::Game::BuildingType building) const
{
  std::vector<irr::s32>		cost = AoL::Game::BuildingCost.at(building);

  return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::STONE)]);
}

irr::s32	AoL::Game::AiPlayer::getGoldCostBuilding(AoL::Game::BuildingType building) const
{
  std::vector<irr::s32>		cost = AoL::Game::BuildingCost.at(building);

  return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::GOLD)]);
}

irr::s32	AoL::Game::AiPlayer::getFoodCostBuilding(AoL::Game::BuildingType building) const
{
  std::vector<irr::s32>		cost = AoL::Game::BuildingCost.at(building);

  return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::FOOD)]);
}

irr::s32	AoL::Game::AiPlayer::getWoodCostUnit(AoL::Game::UnitType unit) const
{
  std::vector<irr::s32>		cost = AoL::Game::UnitCost.at(unit);

  //return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::WOOD)]);
  return 0;
}

irr::s32	AoL::Game::AiPlayer::getGoldCostUnit(AoL::Game::UnitType unit) const
{
  std::vector<irr::s32>		cost = AoL::Game::UnitCost.at(unit);

  return 0;
  return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::GOLD)]);
}

irr::s32	AoL::Game::AiPlayer::getStoneCostUnit(AoL::Game::UnitType unit) const
{
  std::vector<irr::s32>		cost = AoL::Game::UnitCost.at(unit);

  return 0;
  return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::STONE)]);
}

irr::s32	AoL::Game::AiPlayer::getFoodCostUnit(AoL::Game::UnitType unit) const
{
  std::vector<irr::s32>		cost = AoL::Game::UnitCost.at(unit);

  return 0;
  return (cost[static_cast<irr::s32>(AoL::Game::RessourceType::FOOD)]);
}

irr::s32	AoL::Game::AiPlayer::getPopulation() const
{
  return this->_player.getPopulation();
}

irr::s32	AoL::Game::AiPlayer::getWood() const
{
  return this->_player.getStock().getNb(AoL::Game::RessourceType::WOOD);
}

irr::s32	AoL::Game::AiPlayer::getMaxWood() const
{
  return this->_player.getStock().getMax(AoL::Game::RessourceType::WOOD);
}

irr::s32	AoL::Game::AiPlayer::getStone() const
{
  return this->_player.getStock().getNb(AoL::Game::RessourceType::STONE);
}

irr::s32	AoL::Game::AiPlayer::getMaxStone() const
{
  return this->_player.getStock().getMax(AoL::Game::RessourceType::STONE);
}

irr::s32	AoL::Game::AiPlayer::getFood() const
{
  return this->_player.getStock().getNb(AoL::Game::RessourceType::FOOD);
}

irr::s32	AoL::Game::AiPlayer::getMaxFood() const
{
  return this->_player.getStock().getMax(AoL::Game::RessourceType::FOOD);
}

irr::s32	AoL::Game::AiPlayer::getGold() const
{
  return this->_player.getStock().getNb(AoL::Game::RessourceType::GOLD);
}

irr::s32	AoL::Game::AiPlayer::getMaxGold() const
{
  return this->_player.getStock().getMax(AoL::Game::RessourceType::GOLD);
}

static int	luaopen_Ai(lua_State *L)
{
  luaW_register<AoL::Game::AiPlayer>(L, "AiPlayer", AiPlayer_table, AiPlayer_metatable, AiPlayer_new);
  return (0);
}


void		AoL::Game::AiPlayer::execute() const
{
  lua_State *L = luaL_newstate();
  luaL_openlibs(L);
  luaopen_Ai(L);
  while (this->_player.getStart() == false);
  while (this->shouldContinue())
  {
    lua_createtable(L, 1, 0);
    lua_pushnumber(L, 1);
    lua_pushstring(L, this->_player.getName().c_str());
    lua_settable(L, -3);
    lua_setglobal(L, "arg");
    if (luaL_loadfile(L, this->_luaFile.c_str()))
      break;
    lua_pcall(L, 0, 0, 0);
    break;
  }
}

irr::s32	AoL::Game::AiPlayer::getNbUnitsFromName(AoL::Game::EntityName name) const
{
  irr::s32	nbUnits = 0;
  for (auto const &unit: this->_player.getUnits())
    {
      if (unit->getName() == name)
	nbUnits++;
    }
  return nbUnits;
}
