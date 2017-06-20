#ifndef WARRIOR_HPP_
# define WARRIOR_HPP_

# include "Game/Units/Unit.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Warrior : public Unit
    {
    public:
      Warrior(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Unit(irr::core::vector2df{x, y},
	     UnitStat{13, 1, {0, 0, 0, 0}, 0, 30},
	     "Assets/Warrior/Warrior", obs)
      {
	this->baseStats.hp = 200;
	this->baseStats.maxHp = 200;
	this->baseStats.ap = 25;
	this->baseStats.lineOfSight = 3.5;
	this->baseStats.cost = UnitCost.at(AoL::Game::UnitType::WARRIOR);
	this->baseStats.nbActionForCreation = 10;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 5),
			      std::pair<irr::s32, irr::s32>(0, 5),
			      std::pair<irr::s32, irr::s32>(0, 5),
			      std::pair<irr::s32, irr::s32>(0, 5));
	this->_name = EntityName::WARRIOR;
	this->_role = UnitRole::FIGHTER;
      }

      virtual void		notifyAttack(AoL::Game::Unit *attacker)
      {
	if (this->lastAttacker != attacker)
	  {
	    this->lastAttacker = attacker;
	    if (attacker->getPosition().getDistanceFrom(this->getPosition()) < 30)
	      {
		this->giveOrder<AoL::Game::Orders::Attack>(*attacker);
	      }
	  }
      }

      ~Warrior() {}
    };
  }
}

#endif /* WARRIOR_HPP_ */
