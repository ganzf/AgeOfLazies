#ifndef GRID_HPP_
# define GRID_HPP_

# include <iostream>
# include <array>
# include <list>
# include <vector>
# include <memory>
# include <unordered_map>
# include <functional>
# include "Scopelock.hpp"
# include "Game/Entity.hpp"
# include "Game/Units/Unit.hpp"
# include "irrlicht/irrlicht.h"
# include "rendering/Scene3d.hpp"

# define ABS(x)	(x > 0 ? x : -x)

namespace AoL
{
  namespace Game
  {
    class	Grid
    {
      static const irr::s32	initScale = 30;
      static const irr::s32	scale = 30;
      irr::s32			width;
      irr::s32			height;
      irr::core::vector2di	end;
      irr::s32			size;
      std::vector<irr::s32>	collisionMap;
      std::vector<irr::s32>	unitMap;
      irr::core::vector2di	realSize;
      std::mutex		mu;

    public:
      Grid(irr::s32 width, irr::s32 height);
      ~Grid() = default;

      irr::s32				getSize() const { return this->size; }
      irr::s32				getWidth() const { return this->width; }
      irr::s32				getHeight() const { return this->height; }
      bool				isOccupiedAt(irr::core::vector2df const &pos,
						     irr::s32 scale = 1) const;
      
      void				dump() const;
      
      irr::core::vector2df	transformRealPos(irr::core::vector2df const &pos) const
      {
	irr::core::vector2df	result;

	result.X = pos.X;
	result.Y = pos.Y;
	result.X *= this->initScale;
	result.Y *= this->initScale;
	result.X -= this->end.X / 2;
	result.Y -= this->end.Y / 2;
	return (result);
      }
      
      irr::s32			transformSimplePos(irr::core::vector2df const &pos) const
      {
	irr::core::vector2di	offset(ABS((-((realSize.X * scale) / 2) - pos.X) / scale),
				       ABS((-((realSize.Y * scale) / 2) - pos.Y) / scale));
	return (offset.X + offset.Y * realSize.X);
      }

      void			removeEntity(AoL::Game::Entity const &ent)
      {
	Scopelock	lock(this->mu);
	irr::s32	position = this->transformSimplePos(ent.getPrevPos());
	if (dynamic_cast<AoL::Game::Unit const *>(&ent) != nullptr)
	  {
	    if (unitMap[position] > 0)
	      unitMap[position] -= 1;
	  }
	else
	  collisionMap[position] -= 1;
      }

      void			placeEntity(AoL::Game::Entity const &ent);
      bool			hasEntityAt(irr::core::vector2df const &pos) const
      {
	return collisionMap[this->transformSimplePos(pos)];
      }
      bool			hasUnitAt(irr::core::vector2df const &pos) const
      {
	return unitMap[this->transformSimplePos(pos)];
      }

      irr::core::vector2di const &getEnd() const { return this->end; }
      irr::s32			getInitScale() const { return this->initScale; }
      irr::s32			getScale() const { return this->scale; }
      bool			isInBound(irr::core::vector2df const &pos) const
      {
	irr::s32		xlimit = this->end.X / 2;
	irr::s32		ylimit = this->end.Y / 2;
	return (pos.X <= xlimit - 1
		&& pos.X >= -xlimit
		&& pos.Y <= ylimit - 1
		&& pos.Y >= -ylimit);
      }
    };
  }
}

#endif /* GRID_HPP_ */
