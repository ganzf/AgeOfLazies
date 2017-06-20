#ifndef SELECTOR_HPP_
# define SELECTOR_HPP_

# include <unordered_map>
# include <vector>
# include "Constants.hpp"
# include "irrlicht/irrlicht.h"
# include "rendering/Mouse.hpp"
# include "rendering/Camera.hpp"

namespace AoL
{
  namespace Game
  {
    struct	SelectorInfo
    {
      std::vector<Entity *>	selected;
      irr::core::vector3df	pos;
    };

    class	Selector
    {
      using	entityInfo = std::pair<AoL::Game::Entity *, irr::scene::ITriangleSelector *>;
      using	entitiesSelectors = std::unordered_map<irr::s32, entityInfo>;

      AoL::rendering::Mouse					&mouse;
      AoL::rendering::Camera					&camera;
      irr::scene::ISceneCollisionManager			*collisionManager;
      irr::core::vector3df					hitpos;
      irr::core::triangle3df					polygon;
      irr::scene::ITriangleSelector				*terrainSelector;
      irr::core::line3df					ray;
      irr::scene::ISceneNode					*target;
      entitiesSelectors						selectors;
      SelectorInfo						result;

      bool							intersect(irr::scene::ITriangleSelector *tri)
      {
	return this->collisionManager->getCollisionPoint(this->ray, tri, this->hitpos, this->polygon, this->target);
      }

    public:
      Selector(AoL::rendering::Mouse &mouse,
	       irr::scene::ISceneCollisionManager *collisionManager,
	       AoL::rendering::Camera &camera):
	mouse(mouse),
	camera(camera),
	collisionManager(collisionManager)
      {

      }
      ~Selector() = default;

      void		setTerrainSelector(irr::scene::ITriangleSelector *selector)
      {
      	this->terrainSelector = selector;
      }

      irr::core::vector3df	getPos()
      {
	irr::core::vector3df	hitpos;

	this->ray = this->collisionManager->getRayFromScreenCoordinates(this->mouse.getPos(), this->camera());
	this->collisionManager->getCollisionPoint(this->ray, this->terrainSelector, hitpos, this->polygon, this->target);
	return hitpos;
      }

      bool			mouseIsGui() const
      {
	return this->mouse.getPos().Y > 0.75 * AoL::Constants::Rendering::g_screen_height;
      }
      
      AoL::Game::SelectorInfo	select()
      {
	this->result.selected.clear();
	this->ray = this->collisionManager->getRayFromScreenCoordinates(this->mouse.getPos(), this->camera());
	if (this->intersect(terrainSelector))
	  {
	    this->result.pos.X = this->hitpos.X;
	    this->result.pos.Y = this->hitpos.Z;
	    this->result.pos.Z = this->hitpos.Y;
	  }
	for (auto &entityInfo: selectors)
	  {
	    if (entityInfo.second.first != nullptr && this->intersect(entityInfo.second.second))
	      this->result.selected.push_back(entityInfo.second.first);
	  }
	return (this->result);
      }

      void		addEntity(AoL::Game::Entity *entity, irr::scene::ITriangleSelector *tri)
      {
	if (!entity || !tri)
	  return ;
	this->selectors[entity->getId()] = std::make_pair(entity, tri);
      }

      void		removeEntity(irr::s32 id)
      {
	this->selectors.erase(id);
      }
    };
  }
}

#endif /* !SELECTOR_HPP_ */
