#ifndef LUMBERCAMP_HPP_
# define LUMBERCAMP_HPP_

# include "Game/Buildings/Building.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	LumberCamp : public Building
    {
    public:
      LumberCamp(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Building(irr::core::vector2df{x, y},
		 BuildingStat{8},
		 "Assets/models/buildings/Lumber-Mill", obs)
      {
	this->baseStats.hp = 800;
	this->baseStats.maxHp = 800;
	this->baseStats.ap = 10;
	this->baseStats.lineOfSight = 6;
	this->baseStats.cost = BuildingCost.at(AoL::Game::BuildingType::LUMBERCAMP);
	this->baseStats.nbActionForCreation = 35;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 500),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0));
	this->_name = EntityName::LUMBERCAMP;
      }

      ~LumberCamp() {}
    };
  }
}

#endif /* LUMBERCAMP_HPP_ */
