#ifndef GOLDDIGGER_HPP_
# define GOLDDIGGER_HPP_

# include "Game/Units/Unit.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Golddigger : public Unit
    {
    public:
      Golddigger(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Unit(irr::core::vector2df{x, y},
	     UnitStat{10, 1, {0, 0, 0, 2}, 0, 100},
	     "Assets/Collector", obs)
      {
	this->baseStats.hp = 200;
	this->baseStats.maxHp = 200;
	this->baseStats.ap = 20;
	this->baseStats.lineOfSight = 3.5;
	this->baseStats.cost = UnitCost.at(AoL::Game::UnitType::GOLD_COLLECTOR);
	this->baseStats.nbActionForCreation = 10;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 60),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0));
	this->_name = EntityName::GOLD_COLLECTOR;
	this->_role = UnitRole::GOLDDIGGER;
      }
      ~Golddigger() {}
    };
  }
}

#endif
