#ifndef MININGCAMP_HPP_
# define MININGCAMP_HPP_

# include "Game/Buildings/Building.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	MiningCamp : public Building
    {
    public:
      MiningCamp(irr::f32 x, irr::f32 y, AoL::Observer const &obs):
	Building(irr::core::vector2df{x, y},
		 BuildingStat{6},
		 "Assets/models/buildings/Miner-Camp", obs)
      {
	this->baseStats.hp = 800;
	this->baseStats.maxHp = 800;
	this->baseStats.ap = 10;
	this->baseStats.lineOfSight = 6;
	this->baseStats.cost = BuildingCost.at(AoL::Game::BuildingType::MININGCAMP);
	this->baseStats.nbActionForCreation = 10;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 300),
			      std::pair<irr::s32, irr::s32>(0, 300));
	this->_name = EntityName::MININGCAMP;
      }

      ~MiningCamp() {}
    };
  }
}

#endif /* MININGCAMP_HPP_ */
