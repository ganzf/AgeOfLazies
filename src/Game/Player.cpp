#include <iostream>
#include <string>
#include "Game/Player.hpp"
#include "Game/AiPlayer.hpp"
#include "Game/AllRessources.hpp"
#include "Game/Entity.hpp"
#include "Game/AllUnits.hpp"
#include "Game/AllBuildings.hpp"
#include "Manager.hpp"

AoL::Game::Player::Player(AoL::Manager &manager, AoL::Game::Map &map, AoL::Game::Team team, std::string const &name, irr::s32 timeDefeat)
  : _name(name), _manager(manager), _map(map), _population(10),
  _stock({500, 100000}, {500, 100000}, {250, 100000}, {200, 100000}),
  _team(team),
  _status(AoL::Game::PlayerStatus::INGAME),
  _timeDefeat(timeDefeat),
  _start(false)
{
   if (_team != Team::TEAM_ONE)
   {
     Print::out(VAR(name));
     this->_ai = new AiPlayer(*this, "LuaScripts/" + name);
     this->_ai->detach();
   }
}

AoL::Game::Player::~Player()
{
  this->_status = AoL::Game::PlayerStatus::LOOSE;
}

template<typename T>
T		*AoL::Game::Player::createOriginEntity(irr::core::vector2df const &pos)
{
  AoL::Game::Entity	*entity = this->_manager.getFactory().createEntity<T>(pos.X, pos.Y);
  if (!entity)
    return nullptr;
  this->_map.addOriginEntity(entity, this->_team);
  T			*controlled = dynamic_cast<T *>(entity);

  if (entity->getType() == AoL::Game::EntityType::UNIT)
    _units.push_back(dynamic_cast<AoL::Game::Unit *>(controlled));
  else if (entity->getType() == AoL::Game::EntityType::BUILDING)
    _buildings.push_back(dynamic_cast<AoL::Game::Building *>(controlled));
  return (controlled);
}

  template<typename T>
T		*AoL::Game::Player::createEntity(irr::core::vector2df const &pos)
{
  AoL::Game::Entity	*entity = this->_map.addEntity(this->_manager.getFactory().createEntity<T>(pos.X, pos.Y), this->_team);
  T			*controlled = dynamic_cast<T *>(entity);

  if (entity->getType() == AoL::Game::EntityType::UNIT)
    _units.push_back(dynamic_cast<AoL::Game::Unit *>(controlled));
  else if (entity->getType() == AoL::Game::EntityType::BUILDING)
    {
      _buildings.push_back(dynamic_cast<AoL::Game::Building *>(controlled));
      if (entity->getName() == AoL::Game::EntityName::HABITATION)
	this->_population += 5;
    }
  this->removeRessource(AoL::Game::RessourceType::WOOD, controlled->getCost()[0]);
  this->removeRessource(AoL::Game::RessourceType::FOOD, controlled->getCost()[1]);
  this->removeRessource(AoL::Game::RessourceType::STONE, controlled->getCost()[2]);
  this->removeRessource(AoL::Game::RessourceType::GOLD, controlled->getCost()[3]);
  return (controlled);
}

void            AoL::Game::Player::attack(AoL::Game::Unit *selectedUnit,
    AoL::Game::Controlled &target) const
{
  selectedUnit->giveOrder<AoL::Game::Orders::Attack>(target);
}

void            AoL::Game::Player::deposit(AoL::Game::Unit *selectedUnit,
    AoL::Game::Building &target) const
{
  selectedUnit->deposit(target);
}

void            AoL::Game::Player::collect(AoL::Game::Unit *selectedUnit) const
{
  auto target = dynamic_cast<AoL::Game::Ressource *>(_selectedEntities.front());

  if (target)
    selectedUnit->collect(*target);
}

void            AoL::Game::Player::move(AoL::Game::Unit *selectedUnit, irr::core::vector3df pos) const
{
  irr::core::vector2df  const dest(pos.X, pos.Y);
  selectedUnit->goTo(&dest);
}

void		AoL::Game::Player::selectUnit(const std::vector<AoL::Game::Entity *> &selectedEntities)
{
  _selectedEntities = selectedEntities;
}

void			AoL::Game::Player::updateWinStatus()
{
  if (_stock.getNb(AoL::Game::RessourceType::WOOD) > 1000
      && _stock.getNb(AoL::Game::RessourceType::FOOD) > 1000
      && _stock.getNb(AoL::Game::RessourceType::STONE) > 1000
      && _stock.getNb(AoL::Game::RessourceType::GOLD) > 1000)
    _status = PlayerStatus::WIN;
  if ((_stock.getNb(AoL::Game::RessourceType::WOOD) < 50
       && _stock.getNb(AoL::Game::RessourceType::FOOD) < 25
       && this->_units.size() < 1)
      || _timer.getTime() > _timeDefeat)
    _status = PlayerStatus::LOOSE;
}

bool			AoL::Game::Player::hasLost() const
{
  return _status == PlayerStatus::LOOSE;
}

bool			AoL::Game::Player::hasWon() const
{
  return _status == PlayerStatus::WIN;
}

irr::s32	AoL::Game::Player::hasStock(std::vector<irr::s32> const &cost) const
{
  irr::u32     	i = 0;

  while (i < cost.size())
  {
    if (cost[i] > _stock.getNb((static_cast<AoL::Game::RessourceType>(i))))
      return (1);
    i++;
  }
  return (0);
}

void		AoL::Game::Player::consumeRessources(irr::f32 elapsed)
{
  static irr::f32		cooldown = 5;

  cooldown -= elapsed;
  if (cooldown <= 0)
    {
      cooldown = 5;
      this->removeRessource(AoL::Game::RessourceType::FOOD, this->_units.size() * 1);
      this->removeRessource(AoL::Game::RessourceType::WOOD, this->_buildings.size() * 1);
      removeRessInBuildings({static_cast<irr::s32>(this->_buildings.size()) * 1,
	    static_cast<irr::s32>(this->_units.size()) * 1, 0, 0});
    }
}

void		AoL::Game::Player::removeRessInBuildings(std::vector<irr::s32> const & costs)
{
  irr::u32	buildings = 0;
  irr::u32	ress = 0;
  irr::s32	tmpCost;

  while (ress < 4)
    {
      buildings = 0;
      tmpCost = costs[ress];
      while (tmpCost > 0 && buildings < getBuildings().size())
	{
	  while (tmpCost > 0
		 && getBuildings()[buildings]->getStock().getNb(static_cast<AoL::Game::RessourceType>(ress)) > 0)
	    {
	      getBuildings()[buildings]->getStock().changeNb(static_cast<AoL::Game::RessourceType>(ress), -1);
	      tmpCost--;
	    }
	  buildings++;
	}
      ress++;
    }
}

void		AoL::Game::Player::destroyEntity(AoL::Game::Controlled *controlled)
{
  irr::u32	i = 0;

  if (controlled->getType() == AoL::Game::EntityType::UNIT)
    {
      for (auto &tmpUnit: this->_units)
	{
	  if (controlled->getId() == tmpUnit->getId())
	    {
	      this->_units.erase(this->_units.begin() + i);
	      break ;
	    }
	  ++i;
	}
    }
  else
    {
      for (auto &tmpBuilding: this->_buildings)
	{
	  if (controlled->getId() == tmpBuilding->getId())
	    {
	      this->_buildings.erase(this->_buildings.begin() + i);
	      break ;
	    }
	  ++i;
	}
    }
}

template
AoL::Game::Collector	*AoL::Game::Player::createEntity<AoL::Game::Collector>(irr::core::vector2df const &);
template
AoL::Game::Lumberjack	*AoL::Game::Player::createEntity<AoL::Game::Lumberjack>(irr::core::vector2df const &);
template
AoL::Game::Gatherer	*AoL::Game::Player::createEntity<AoL::Game::Gatherer>(irr::core::vector2df const &);
template
AoL::Game::Golddigger	*AoL::Game::Player::createEntity<AoL::Game::Golddigger>(irr::core::vector2df const &);
template
AoL::Game::Miner	*AoL::Game::Player::createEntity<AoL::Game::Miner>(irr::core::vector2df const &);
template
AoL::Game::Warrior	*AoL::Game::Player::createEntity<AoL::Game::Warrior>(irr::core::vector2df const &);

template
AoL::Game::Forum	*AoL::Game::Player::createOriginEntity<AoL::Game::Forum>(irr::core::vector2df const &);
template
AoL::Game::Habitation	*AoL::Game::Player::createOriginEntity<AoL::Game::Habitation>(irr::core::vector2df const &);

template
AoL::Game::Forum	*AoL::Game::Player::createEntity<AoL::Game::Forum>(irr::core::vector2df const &);

template
AoL::Game::Habitation	*AoL::Game::Player::createEntity<AoL::Game::Habitation>(irr::core::vector2df const &);

template
AoL::Game::LumberCamp	*AoL::Game::Player::createEntity<AoL::Game::LumberCamp>(irr::core::vector2df const &);

template
AoL::Game::MiningCamp	*AoL::Game::Player::createEntity<AoL::Game::MiningCamp>(irr::core::vector2df const &);

template
AoL::Game::Mill		*AoL::Game::Player::createEntity<AoL::Game::Mill>(irr::core::vector2df const &);


