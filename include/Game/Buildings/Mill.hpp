#ifndef MILL_HPP_
# define MILL_HPP_

# include "Game/Buildings/Building.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Mill : public Building
    {
    public:
      Mill(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Building(irr::core::vector2df{x, y},
		 BuildingStat{6},
		 "Assets/models/buildings/Mill", obs)
      {
	this->baseStats.hp = 800;
	this->baseStats.maxHp = 800;
	this->baseStats.ap = 10;
	this->baseStats.lineOfSight = 6;
	this->baseStats.cost = BuildingCost.at(AoL::Game::BuildingType::MILL);
	this->baseStats.nbActionForCreation = 35;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 500),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0));
	this->_name = EntityName::MILL;
      }

      ~Mill() {}
    };
  }
}

#endif /* MILL_HPP_ */
