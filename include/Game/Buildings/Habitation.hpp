#ifndef HABITATION_HPP_
# define HABITATION_HPP_

# include "Game/Buildings/Building.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Habitation : public Building
    {
    public:
      Habitation(irr::f32 x, irr::f32 y, AoL::Observer const &obs) :
	Building(irr::core::vector2df{x, y},
		 BuildingStat{5},
		 "Assets/models/buildings/Forum", obs)
      {
	this->baseStats.hp = 750;
	this->baseStats.maxHp = 750;
	this->baseStats.ap = 10;
	this->baseStats.lineOfSight = 2;
	this->baseStats.cost = BuildingCost.at(AoL::Game::BuildingType::HABITATION);
	this->baseStats.nbActionForCreation = 25;
	this->_stocks = Stock(std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0),
			      std::pair<irr::s32, irr::s32>(0, 0));
	this->_name = EntityName::HABITATION;
      }
      ~Habitation() {}
    };
  }
}

#endif /* FORUM_HPP_ */
