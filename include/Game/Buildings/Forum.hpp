#ifndef FORUM_HPP_
# define FORUM_HPP_

# include "Game/Buildings/Building.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Forum : public Building
    {
    public:
      Forum(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Building(irr::core::vector2df{x, y},
		 BuildingStat{10},
		 "Assets/models/buildings/Castle", obs)
      {
	this->baseStats.hp = 2400;
	this->baseStats.maxHp = 2400;
	this->baseStats.ap = 10;
	this->baseStats.lineOfSight = 8;
	this->baseStats.cost = BuildingCost.at(AoL::Game::BuildingType::FORUM);
	this->baseStats.nbActionForCreation = 150;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 700),
			      std::pair<irr::s32, irr::s32>(0, 700),
			      std::pair<irr::s32, irr::s32>(0, 400),
			      std::pair<irr::s32, irr::s32>(0, 400));
	this->_name = EntityName::FORUM;
      }
      ~Forum() {}
    };
  }
}

#endif /* FORUM_HPP_ */
