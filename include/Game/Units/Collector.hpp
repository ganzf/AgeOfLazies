#ifndef COLLECTOR_HPP_
# define COLLECTOR_HPP_

# include "Game/Units/Unit.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Collector : public Unit
    {
    public:
      Collector(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Unit(irr::core::vector2df{x, y},
	     UnitStat{10, 1, {0.5, 0.5, 0.5, 0.5}, 0, 20},
	     "Assets/Collector", obs)
      {
	this->baseStats.hp = 200;
	this->baseStats.maxHp = 200;
	this->baseStats.ap = 10;
	this->baseStats.lineOfSight = 3.5;
	this->baseStats.cost = UnitCost.at(AoL::Game::UnitType::COLLECTOR);
	this->baseStats.nbActionForCreation = 10;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 10),
			      std::pair<irr::s32, irr::s32>(0, 20),
			      std::pair<irr::s32, irr::s32>(0, 5),
			      std::pair<irr::s32, irr::s32>(0, 10));
	this->_name = EntityName::COLLECTOR;
	this->_role = UnitRole::NONE;
      }

      virtual void		notifyAttack(AoL::Game::Unit *attacker)
      {
	if (attacker->getPosition().getDistanceFrom(this->getPosition()) < 10)
	  {
	    // TODO: Faire la fonction qui renvoie le collector au forum de son equipe le plus proche.
	  }
      }

      ~Collector() {}
    };
  }
}

#endif
