#ifndef MAP_HPP_
# define MAP_HPP_

# include <iostream>
# include <array>
# include <list>
# include <vector>
# include <memory>
# include <unordered_map>
# include <functional>
# include "Game/Ressources/Wood.hpp"
# include "Game/Ressources/Stone.hpp"
# include "Game/Ressources/Gold.hpp"
# include "Game/Ressources/Food.hpp"
# include "Game/Units/Unit.hpp"
# include "irrlicht/irrlicht.h"
# include "rendering/Scene3d.hpp"
# include "Print.hpp"
# include "Game/Grid.hpp"
# include "Game/Ressources/Wood.hpp"
# include "Game/Ressources/Food.hpp"
# include "Game/Ressources/Stone.hpp"
# include "Game/Ressources/Gold.hpp"
# include "Scopelock.hpp"

namespace AoL
{
  namespace Game
  {
    class	Map
    {
      typedef bool (Map::*entityFunc)(Entity &);
      typedef bool (Map::*entityPtrFunc)(Entity *);

      AoL::rendering::Scene3d					*scene;
      irr::core::vector2df					dims;
      std::unordered_map<irr::s32, entityFunc>			placeFuncs;
      std::unordered_map<irr::s32, entityFunc>			removeFuncs;
      std::unordered_map<irr::s32, entityPtrFunc>		addFuncs;

      std::list<AoL::Game::Entity *>				markedEntities;
      std::unordered_map<irr::s32, AoL::Game::Entity *>		allEntities;
      std::unordered_map<irr::s32, AoL::Game::Controlled *>	controlledEntities;
      std::unordered_map<irr::s32, AoL::Game::Controlled *>	playerControlledEntities;
      std::unordered_map<irr::s32, AoL::Game::Controlled *>	enemiesControlledEntities;
      std::unordered_map<irr::s32, AoL::Game::Controlled *>     buildingInProgress;
      std::unordered_map<irr::s32, AoL::Game::Unit *>		playerUnits;
      std::unordered_map<irr::s32, AoL::Game::Unit *>		enemiesUnits;
      std::unordered_map<irr::s32, AoL::Game::Ressource *>	ressources;
      std::unordered_map<irr::s32, AoL::Game::Wood *>		woods;
      std::unordered_map<irr::s32, AoL::Game::Stone *>		stones;
      std::unordered_map<irr::s32, AoL::Game::Gold *>		golds;
      std::unordered_map<irr::s32, AoL::Game::Food *>		foods;
      std::unordered_map<irr::s32, AoL::Game::Building *>	playerBuildings;
      std::unordered_map<irr::s32, AoL::Game::Building *>	enemiesBuildings;
      AoL::Game::Controlled					*hoverControlled;
      AoL::Game::Grid						grid;
      std::mutex						mu;
      std::mutex						deathMutex;
      std::mutex						finderMutex;

    public:
      Map(irr::core::vector2df const &dims);
      ~Map();

      AoL::Game::Entity			*addEntity(Entity *, AoL::Game::Team team = AoL::Game::Team::UNDEFINED);
      bool				addOriginEntity(Entity *, AoL::Game::Team team = AoL::Game::Team::UNDEFINED);

      template <typename T>
      T					*FindFrom(irr::core::position2df const &pos,
						  AoL::Game::Team team = AoL::Game::Team::TEAM_ONE)
      {
	Scopelock			lock(this->finderMutex, __FUNCTION__);
	
	T			*nearestTree = nullptr;
	irr::f32		nearestDist = 999999999;
	irr::f32		tmpDist = 0;

	for (auto &elem : this->allEntities)
	  {
	    T *target = dynamic_cast<T *>(elem.second);
	    if (target && target->getTeam() == team)
	      {
		if ((tmpDist = pos.getDistanceFrom(target->getPosition())) < nearestDist)
		  {
		    nearestDist = tmpDist;
		    nearestTree = target;
		  }
	      }
	  }
	return (nearestTree);
      }
      void				markDead(Entity &entity);
      void				deleteDead();
      void				doOrders(irr::f32 elapsedTime);
      void				updateUnitPos();
      void				addHoverControlled(AoL::Game::Controlled *ent);
      irr::core::vector2df		findPosForBuilding(irr::core::vector2df &start, irr::s32 rangeOfSearch);
      irr::core::vector2df		&findPosRec(irr::core::vector2df &start, irr::core::vector2df &pos, int iter, int range);
      AoL::Game::Controlled		*getHoverControlled()
      {
	return (this->hoverControlled);
      }

      AoL::Game::Grid		const &getGrid() const
      {
	return this->grid;
      }

      bool				hasHover() const
      {
	return this->hoverControlled != nullptr;
      }

      void				removeHover()
      {
	Scopelock			lock(this->mu, __FUNCTION__);
	
	if (this->hoverControlled)
	  {
	    if (this->hoverControlled->getNode())
	      {
		// this->hoverControlled->getNode()->setVisible(false);
		this->hoverControlled->getNode()->remove();
	      }
	    this->hoverControlled = nullptr;
	  }
      }
      
      bool				hoverIsValid() const
      {
	if (this->hoverControlled == nullptr)
	  return (false);
	return !this->grid.isOccupiedAt(this->hoverControlled->getPosition(), this->hoverControlled->getGridScale());
      }

      void				addHoverToMap()
      {
	Scopelock			lock(this->mu, __FUNCTION__);
	
	if (this->hoverControlled == nullptr)
	  return ;
	this->hoverControlled->getAnimator()->setAnim(AoL::rendering::AnimFrames::BUILD);
	this->hoverControlled->getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::BUILD);
	this->buildingInProgress[this->hoverControlled->getId()] = this->hoverControlled;
	this->grid.placeEntity(*this->hoverControlled);
	this->scene->entityAddAnchors(*this->hoverControlled);
	this->allEntities[this->hoverControlled->getId()] = this->hoverControlled;
	this->hoverControlled = nullptr;
      }

      void				updateBuildingInProgress()
      {
	Scopelock			lock(this->mu, __FUNCTION__);
	
	if (this->buildingInProgress.size() == 0)
	  return ;
	for (auto &building : this->buildingInProgress)
	  {
	    if (building.second != nullptr
		&& building.second->getAnimator()->getFrameNr() >= building.second->getAnimator()->getEndFrame() - 1)
	      {
		building.second->getAnimator()->setAnim(AoL::rendering::AnimFrames::BUILD_ANIM);
		building.second->getAnimator()->setBuildingSpeed(building.second->getName());
		this->buildingInProgress[building.first] = nullptr;
		// this->buildingInProgress.erase(building.first);
	      }
	  }
      }

      void				updateHoverPos(irr::core::vector3df const &pos);

      void				addControlled(AoL::Game::Controlled *toAdd);
      void				removeControlled(AoL::Game::Controlled *toRemove);

      std::unordered_map<irr::s32, AoL::Game::Entity *>	&getAllEntities() { return this->allEntities; }

      void				remove(AoL::Game::Entity &entity)
      {
	Scopelock			lock(this->mu, __FUNCTION__);
	
	entity.setNode(nullptr);
	this->allEntities[entity.getId()] = nullptr;
	this->grid.removeEntity(entity);
	
      }

      irr::core::vector2df		getRealPos(irr::core::vector2df const &pos) const
      {
	return this->grid.transformRealPos(pos);
      }

      irr::core::vector2df	const &getDims() const
      {
	return this->dims;
      }

      irr::u32				getSize() const
      {
	return this->dims.X * this->dims.Y;
      }

      void				setScene(AoL::rendering::Scene3d &s)
      {
	this->scene = &s;
      }

      bool	posIsInbound(irr::core::vector2df const &pos) const
      {
	return this->grid.isInBound(pos);
      }
      
    };
  }
}

#endif /* !map_hpp_ */
