#ifndef GOLD_HPP_
# define GOLD_HPP_

# include "Game/Ressources/Ressource.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Gold : public Ressource
    {
    public:
      Gold(irr::f32 x,irr::f32 y, Observer const &obs) :
	Ressource(irr::core::vector2df{x, y},
		  RessourceStat{RessourceType::GOLD},
		  "Assets/models/GoldMine/GoldMine.3ds", obs)
      {
	this->_name = EntityName::NGOLD;
	this->_associatedRole = AoL::Game::UnitRole::GOLDDIGGER;
      }
      ~Gold() {}
    };
  }
}

#endif /* GOLD_HPP_ */
