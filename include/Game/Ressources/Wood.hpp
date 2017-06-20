#ifndef WOOD_HPP_
# define WOOD_HPP_

# include "Game/Ressources/Ressource.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Wood : public Ressource
    {
    public:
      Wood(irr::f32 x,irr::f32 y, Observer const &obs) :
	Ressource(irr::core::vector2df{x, y},
		  RessourceStat{RessourceType::WOOD},
		  "Assets/models/ArbreLowPoly.3ds", obs)
      {
	this->_name = EntityName::NWOOD;
	this->_associatedRole = AoL::Game::UnitRole::LUMBERJACK;
      }
      ~Wood() {}
    };
  }
}

#endif /* WOOD_HPP_ */
