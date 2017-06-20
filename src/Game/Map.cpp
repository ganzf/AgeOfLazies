#include "Game/Map.hpp"

AoL::Game::Map::Map(irr::core::vector2df const &dims): dims(dims), grid(dims.X, dims.Y)
{
  this->hoverControlled = nullptr;
}

bool		AoL::Game::Map::addOriginEntity(Entity *e, AoL::Game::Team team)
{
  Scopelock	lock(this->mu, __FUNCTION__);
  
  if (e == nullptr)
    return (false);
  e->setTeam(team);
  irr::core::vector2df	pos = this->grid.transformRealPos(e->getPosition());
  e->setPosition(pos);
  this->grid.placeEntity(*e);
  this->allEntities[e->getId()] = e;

  switch (e->getType())
    {
    case AoL::Game::EntityType::UNIT :
      {
	if (team == AoL::Game::Team::TEAM_ONE)
	  this->playerUnits[e->getId()] = dynamic_cast<AoL::Game::Unit *>(e);
	else if (team != AoL::Game::Team::UNDEFINED)
	  this->enemiesUnits[e->getId()] = dynamic_cast<AoL::Game::Unit *>(e);
	break ;
      }
    case AoL::Game::EntityType::BUILDING :
      {
	if (team == AoL::Game::Team::TEAM_ONE)
	  this->playerBuildings[e->getId()] = dynamic_cast<AoL::Game::Building *>(e);
	else if (team != AoL::Game::Team::UNDEFINED)
	  this->enemiesBuildings[e->getId()] = dynamic_cast<AoL::Game::Building *>(e);
	irr::core::vector2df  updatedPos;
	irr::s32              scale = this->grid.getScale();
	updatedPos.Y = e->getPosition().Y - scale;
	updatedPos.X = e->getPosition().X - scale;
	auto built = dynamic_cast<AoL::Game::Building *>(e);
	built->setSpawnPoint(updatedPos);
	break ;
      }
    case AoL::Game::EntityType::RESSOURCE :
      {
	this->ressources[e->getId()] = dynamic_cast<AoL::Game::Ressource *>(e);
	break ;
      }
    default:
      break ;
    }

  if (team != AoL::Game::Team::UNDEFINED)
    {
      AoL::Game::Controlled *controlled = dynamic_cast<AoL::Game::Controlled *>(e);
      if (controlled)
	controlled->setTeam(team);

      irr::core::vector2df  updatedPos;
      irr::s32              scale = this->grid.getScale();
      updatedPos.Y = e->getPosition().Y - (2 * scale);
      updatedPos.X = e->getPosition().X;
      if (auto built = dynamic_cast<AoL::Game::Building *>(e))
	built->setSpawnPoint(updatedPos);
    }
  this->scene->add(e);
  return (true);
}

irr::core::vector2df	&AoL::Game::Map::findPosRec(irr::core::vector2df &start, irr::core::vector2df &pos, int iter, int range)
{
  if (iter == 16)
    return (start);
  if (iter == 0 || iter == 8)
    pos.X += this->grid.getScale() *range;
  if (iter == 1 || iter == 9)
    pos.X -= this->grid.getScale() * range;
  if (iter == 3 || iter == 10)
    pos.Y += this->grid.getScale() * range;
  if (iter == range || iter == 11)
    pos.Y -= this->grid.getScale() *range;
  if (iter == 4 || iter == 12)
  {
    pos.X += this->grid.getScale() * range;
    pos.Y += this->grid.getScale() * range;
  }
  if (iter == 5 || iter == 13)
  {
    pos.X -= this->grid.getScale() * range;
    pos.Y -= this->grid.getScale() * range;
  }
  if (iter == 6 || iter == 14)
  {
    pos.X += this->grid.getScale() * range;
    pos.Y -= this->grid.getScale() * range;
  }
  if (iter == 7 || iter == 15)
  {
    ++range;
    pos.X -= this->grid.getScale() * range;
    pos.Y += this->grid.getScale() * range;
  }
   if (!this->grid.isOccupiedAt(pos))
   {
     pos = start;
     return (findPosRec(start, pos, ++iter, range));
   }
  return (pos);
}

irr::core::vector2df	AoL::Game::Map::findPosForBuilding(irr::core::vector2df &start, irr::s32 rangeOfSearch)
{
  if (rangeOfSearch >= 3)
    return start;
  irr::core::vector2df	tmp(start.X - this->grid.getScale() * rangeOfSearch, start.Y - this->grid.getScale() * rangeOfSearch);
  irr::core::vector2df	tmpEnd(this->grid.getWidth(),
      this->grid.getHeight());

  while (this->getGrid().transformSimplePos(tmp) < this->grid.getSize() &&
      tmp.Y < start.Y + this->grid.getScale() * rangeOfSearch)
  {
    if (tmp.X >= start.X + this->grid.getScale() * rangeOfSearch)
    {
      tmp.X = start.X - this->grid.getScale() * rangeOfSearch;
      tmp.Y += this->grid.getScale();
    }
    if (!this->grid.isOccupiedAt(tmp))
    {
      irr::core::vector2df	bckp(tmp);

      if (this->findPosRec(bckp, tmp, 0, 1) == bckp)
      {
	start.X = bckp.X;
	start.Y = bckp.Y;
	return start;
      }
      tmp = bckp;
    }
    tmp.X += 1;
  }
  return this->findPosForBuilding(start, ++rangeOfSearch);
}

AoL::Game::Entity		*AoL::Game::Map::addEntity(Entity *e, AoL::Game::Team team)
{
  Scopelock	lock(this->mu, __FUNCTION__);

  e->setTeam(team);
  if (e == nullptr)
    return (nullptr);
  this->grid.placeEntity(*e);
  this->allEntities[e->getId()] = e;
  switch (e->getType())
  {
    case AoL::Game::EntityType::UNIT :
      {
	if (team == AoL::Game::Team::TEAM_ONE)
	  this->playerUnits[e->getId()] = dynamic_cast<AoL::Game::Unit *>(e);
	else if (team != AoL::Game::Team::UNDEFINED)
	  this->enemiesUnits[e->getId()] = dynamic_cast<AoL::Game::Unit *>(e);
	break ;
      }
    case AoL::Game::EntityType::BUILDING :
      {
	if (team == AoL::Game::Team::TEAM_ONE)
	  this->playerBuildings[e->getId()] = dynamic_cast<AoL::Game::Building *>(e);
	else if (team != AoL::Game::Team::UNDEFINED)
	  this->enemiesBuildings[e->getId()] = dynamic_cast<AoL::Game::Building *>(e);
	irr::core::vector2df  updatedPos;
	irr::s32              scale = this->grid.getScale();
	updatedPos.Y = e->getPosition().Y - (2 * scale);
	updatedPos.X = e->getPosition().X;
	auto built = dynamic_cast<AoL::Game::Building *>(e);
	built->setSpawnPoint(updatedPos);
	break ;
      }
    case AoL::Game::EntityType::RESSOURCE :
      {
	auto ressource = dynamic_cast<AoL::Game::Ressource *>(e);
	this->ressources[e->getId()] = ressource;
	switch (ressource->getRessourceType())
	{
	  case AoL::Game::RessourceType::WOOD :
	    {
	      auto wood = dynamic_cast<AoL::Game::Wood *>(ressource);
	      this->woods[e->getId()] = wood;
	      break ;
	    }
	  case AoL::Game::RessourceType::STONE :
	    {
	      auto stone = dynamic_cast<AoL::Game::Stone *>(ressource);
	      this->stones[e->getId()] = stone;
	      break ;
	    }
	  case AoL::Game::RessourceType::GOLD :
	    {
	      auto gold = dynamic_cast<AoL::Game::Gold *>(ressource);
	      this->golds[e->getId()] = gold;
	      break ;
	    }
	  case AoL::Game::RessourceType::FOOD :
	    {
	      auto food = dynamic_cast<AoL::Game::Food *>(ressource);
	      this->foods[e->getId()] = food;
	      break ;
	    }
	  default :
	    break;
	  }
	break ;
      }
    default:
      break ;
    }
  this->scene->add(e);
  e->createAnchors();
  if (team != AoL::Game::Team::UNDEFINED)
  {
    AoL::Game::Controlled *controlled = dynamic_cast<AoL::Game::Controlled *>(e);
    if (controlled)
      controlled->setTeam(team);
  }
  return (e);
}

void		AoL::Game::Map::addHoverControlled(AoL::Game::Controlled *ent)
{
  Scopelock	lock(this->mu, __FUNCTION__);
  
  if (this->hoverControlled)
    return ;
  ent->setTeam(AoL::Game::Team::TEAM_ONE);
  this->scene->add(ent, false);
  this->hoverControlled = ent;
}

void		AoL::Game::Map::markDead(Entity &entity)
{
  Scopelock	lock(this->deathMutex, __FUNCTION__);

  this->markedEntities.push_back(&entity);
}

void		AoL::Game::Map::updateHoverPos(irr::core::vector3df const &pos)
{
  irr::core::vector2df	updatedPos;
  irr::s32		scale = this->grid.getScale();

  updatedPos.X = (static_cast<irr::s32>(pos.X) / scale) * scale;
  updatedPos.Y = (static_cast<irr::s32>(pos.Z) / scale) * scale;
  if (this->grid.isInBound(updatedPos))
  {
    this->hoverControlled->setPosition(updatedPos);
    auto built = dynamic_cast<AoL::Game::Building *>(this->hoverControlled);
    if (built)
    {
      updatedPos.Y -= scale;
      built->setSpawnPoint(updatedPos);
    }
  }
}

void		AoL::Game::Map::deleteDead()
{
  Scopelock	lock(this->deathMutex, __FUNCTION__);

  for (auto &deadEntity: this->markedEntities)
    this->remove(*deadEntity);
  this->markedEntities.clear();
}

AoL::Game::Map::~Map()
{
}

void		AoL::Game::Map::doOrders(irr::f32 elapsedTime)
{
  Scopelock	lock(this->mu, __FUNCTION__);
  
  for (auto const &pair: this->controlledEntities)
  {
    if (pair.second)
      pair.second->doOrder(elapsedTime);
  }
}

void					AoL::Game::Map::updateUnitPos()
{
  Scopelock	lock(this->mu, __FUNCTION__);
  
  for (auto &pair: this->playerUnits)
  {
    if (pair.second)
    {
      AoL::Game::Unit	&unit = *pair.second;
      if (this->grid.transformSimplePos(unit.getPrevPos()) !=
	  this->grid.transformSimplePos(unit.getPosition()))
      {
	this->grid.removeEntity(*static_cast<AoL::Game::Entity *>(&unit));
	this->grid.placeEntity(*static_cast<AoL::Game::Entity *>(&unit));
      }
    }
  }
}

void					AoL::Game::Map::addControlled(AoL::Game::Controlled *toAdd)
{
  this->controlledEntities[toAdd->getId()] = toAdd;
}

void					AoL::Game::Map::removeControlled(AoL::Game::Controlled *toRemove)
{
  this->controlledEntities[toRemove->getId()] = nullptr;
}
