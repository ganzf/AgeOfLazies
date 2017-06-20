#include "Game/Grid.hpp"

AoL::Game::Grid::Grid(irr::s32 width, irr::s32 height)
  : width(width), height(height),
    end(width * initScale,  height * initScale),
    size((end.X / scale) * (end.Y / scale)),
    realSize(width * initScale / scale, height * initScale / scale)
{
  for (irr::s32 i = 0; i < size + 1; i++)
    {
      this->collisionMap.push_back(0);
      this->unitMap.push_back(0);
    }
}

void			AoL::Game::Grid::placeEntity(AoL::Game::Entity const &ent)
{
  Scopelock	lock(this->mu, __FUNCTION__);
  
  irr::s32	position = this->transformSimplePos(ent.getPosition());
  if (dynamic_cast<AoL::Game::Unit const *>(&ent) == nullptr)
    {
      if (collisionMap[position] == 0)
	collisionMap[position] = 1;
      else
	throw std::runtime_error("Cannot place at " + std::to_string(ent.getPosition().X) +
				 ", " + std::to_string(ent.getPosition().Y) + "!");
    }
  else
    unitMap[position] += 1;
}

void			AoL::Game::Grid::dump() const
{
  irr::core::vector2df	tmp(0, 0);
  irr::core::vector2df	tmpEnd(end.X / scale, end.Y / scale);

  while (tmp.Y < tmpEnd.Y)
    {
      if (tmp.X == tmpEnd.X)
	{
	  tmp.X = 0;
	  tmp.Y += 1;
	  std::cout << "||" << std::endl;
	}
      else
	{
	  tmp.X *= this->scale;
	  tmp.Y *= this->scale;
	  if (collisionMap[this->transformSimplePos(tmp)] > 0
	      || unitMap[this->transformSimplePos(tmp)] > 0)
	    std::cout << "[]";
	  else
	    std::cout << "  ";
	  tmp.X /= this->scale;
	  tmp.Y /= this->scale;
	  tmp.X += 1;
	}
    }
}

bool			AoL::Game::Grid::isOccupiedAt(irr::core::vector2df const &pos,
						      irr::s32 scale) const
{
  irr::core::vector2df	tmp(pos.X, pos.Y);
  irr::core::vector2df	end(tmp.X + scale, tmp.Y + scale);

  return (collisionMap[this->transformSimplePos(pos)] > 0
	  || unitMap[this->transformSimplePos(pos)] > 0);
}
