#ifndef LUMBERJACK_HPP_
# define LUMBERJACK_HPP_

# include "Game/Units/Unit.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Lumberjack : public Unit
    {
    public:
      Lumberjack(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Unit(irr::core::vector2df{x, y},
	     UnitStat{10, 1, {2, 0, 0, 0}, 0, 100},
	     "Assets/Collector", obs)
      {
	this->baseStats.hp = 200;
	this->baseStats.maxHp = 200;
	this->baseStats.ap = 20;
	this->baseStats.lineOfSight = 3.5;
	this->baseStats.cost = UnitCost.at(AoL::Game::UnitType::WOOD_COLLECTOR);
	this->baseStats.nbActionForCreation = 10;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 60),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0));
	this->_name = EntityName::WOOD_COLLECTOR;
	this->_role = UnitRole::LUMBERJACK;
      }
      ~Lumberjack() {}
    };
  }
}

#endif
