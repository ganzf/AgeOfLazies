#include "Game/LuaFunc.hpp"
#include "Game/Buildings/Building.hpp"
#include "Game/Units/Unit.hpp"
#include "Game/luawrapper.hpp"
#include "Game/AiPlayer.hpp"

static const std::unordered_map<std::string, AoL::Game::BuildingType>	convertBuild = 
{
  {"FORUM", AoL::Game::BuildingType::FORUM},
  {"MILL", AoL::Game::BuildingType::MILL},
  {"HABITATION", AoL::Game::BuildingType::HABITATION},
  {"LUMBERCAMP", AoL::Game::BuildingType::LUMBERCAMP},
  {"MININGCAMP", AoL::Game::BuildingType::MININGCAMP},
};

static const std::unordered_map<std::string, AoL::Game::UnitType>	convertUnit = 
{
  {"WARRIOR", AoL::Game::UnitType::WARRIOR},
  {"COLLECTOR", AoL::Game::UnitType::COLLECTOR},
  {"WOOD_COLLECTOR", AoL::Game::UnitType::WOOD_COLLECTOR},
  {"STONE_COLLECTOR", AoL::Game::UnitType::STONE_COLLECTOR},
  {"GOLD_COLLECTOR", AoL::Game::UnitType::GOLD_COLLECTOR},
  {"FOOD_COLLECTOR", AoL::Game::UnitType::FOOD_COLLECTOR},
};

static const std::unordered_map<std::string, AoL::Game::RessourceType>	convertRessource =
{
  {"WOOD", AoL::Game::RessourceType::WOOD},
  {"FOOD", AoL::Game::RessourceType::FOOD},
  {"STONE", AoL::Game::RessourceType::STONE},
  {"GOLD", AoL::Game::RessourceType::GOLD},
};

static const std::unordered_map<std::string, AoL::Game::UnitRole>	convertRole = 
{
  {"WARRIOR", AoL::Game::UnitRole::FIGHTER},
  {"LUMBERJACK", AoL::Game::UnitRole::LUMBERJACK},
  {"MINER", AoL::Game::UnitRole::MINER},
  {"GOLDDIGGER", AoL::Game::UnitRole::GOLDDIGGER},
  {"GATHERER", AoL::Game::UnitRole::GATHERER},
};

static AoL::Game::RessourceType	getRessource(const std::string &ressource)
{
  if (convertRessource.find(ressource) != convertRessource.end())
    return convertRessource.at(ressource);
  return AoL::Game::RessourceType::NOTHING;
}

static AoL::Game::BuildingType	getBuilding(const std::string &building)
{
  if (convertBuild.find(building) != convertBuild.end())
    return convertBuild.at(building);
  return AoL::Game::BuildingType::UNDEFINED;
}

static AoL::Game::UnitType	getUnit(const std::string &unit)
{
  if (convertUnit.find(unit) != convertUnit.end())
    return convertUnit.at(unit);
  return AoL::Game::UnitType::UNDEFINED;
}

static AoL::Game::UnitRole	getRole(const std::string &role)
{
  if (convertRole.find(role) != convertRole.end())
    return convertRole.at(role);
  return AoL::Game::UnitRole::NONE;
}

int	AiPlayer_getNbUnit(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);
  auto			role = getRole(luaL_checkstring(L, 2));

  return ai->getNbUnit(role);
}

int	AiPlayer_getCostBuilding(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);
  auto			building = getBuilding(luaL_checkstring(L, 2));
  auto			ressource = getRessource(luaL_checkstring(L, 3));

  if (building == AoL::Game::BuildingType::UNDEFINED
      || ressource == AoL::Game::RessourceType::NOTHING)
    return (0);
  if (ressource == AoL::Game::RessourceType::WOOD)
    return ai->getWoodCostBuilding(building);
  else if (ressource == AoL::Game::RessourceType::STONE)
    return ai->getStoneCostBuilding(building);
  else if (ressource == AoL::Game::RessourceType::GOLD)
    return ai->getGoldCostBuilding(building);
  else
    return ai->getFoodCostBuilding(building);
}

int	AiPlayer_getCostUnit(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);
  auto			unit = getUnit(luaL_checkstring(L, 2));
  auto			ressource = getRessource(luaL_checkstring(L, 3));

  if (unit == AoL::Game::UnitType::UNDEFINED
      || ressource == AoL::Game::RessourceType::NOTHING)
    return (0);
  if (ressource == AoL::Game::RessourceType::WOOD)
    return ai->getWoodCostUnit(unit);
  else if (ressource == AoL::Game::RessourceType::STONE)
    return ai->getStoneCostUnit(unit);
  else if (ressource == AoL::Game::RessourceType::GOLD)
    return ai->getGoldCostUnit(unit);
  else
    return ai->getFoodCostUnit(unit);
}

int	AiPlayer_createUnit(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);
  auto			unit = getUnit(luaL_checkstring(L, 2));

  if (unit == AoL::Game::UnitType::UNDEFINED)
  {
    return (-1);
  }
  ai->createUnit(unit);
  return (0);
}

int	AiPlayer_createBuilding(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);
  auto			building = getBuilding(luaL_checkstring(L, 2));

  if (building == AoL::Game::BuildingType::UNDEFINED)
    return (-1);
  ai->createBuilding(building);
  return (0);
}

int	AiPlayer_collect(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);
  auto			ressource = getRessource(luaL_checkstring(L, 2));
  bool			ret;

  if (ressource == AoL::Game::RessourceType::NOTHING)
    return (-1);
  if (ressource == AoL::Game::RessourceType::WOOD)
    ret = ai->collectWood();
  else if (ressource == AoL::Game::RessourceType::STONE)
    ret = ai->collectStone();
  else if (ressource == AoL::Game::RessourceType::GOLD)
    ret = ai->collectGold();
  else
    ret = ai->collectFood();
  if (ret == true)
    return (0);
  return (-1);
}

int	AiPlayer_getPopulation(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  return (ai->getPopulation());
}

int	AiPlayer_print(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  ai->print();
  return (0);
}

int   AiPlayer_getWood(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getWood();
  std::cout << "Ret : " << ret << std::endl;
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_getMaxWood(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getMaxWood();
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_getStone(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getStone();
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_getMaxStone(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getMaxStone();
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_getFood(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getFood();
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_getMaxFood(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getMaxFood();
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_getGold(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getGold();
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_getMaxGold(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getMaxGold();
  lua_pushnumber(L, ret);
  return 1;
}

int   AiPlayer_checkFrame(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->checkStatus();
  lua_pushnumber(L, ret);
  return 1;
}

int	AiPlayer_getNbCollector(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getNbUnitsFromName(AoL::Game::EntityName::COLLECTOR);
  lua_pushnumber(L, ret);
  return 1;  
}

int	AiPlayer_getNbWarrior(lua_State *L)
{
  AoL::Game::AiPlayer	*ai = luaW_check<AoL::Game::AiPlayer>(L, 1);

  int ret = ai->getNbUnitsFromName(AoL::Game::EntityName::WARRIOR);
  lua_pushnumber(L, ret);
  return 1;
}
