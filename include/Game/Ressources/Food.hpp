#ifndef FOOD_HPP_
# define FOOD_HPP_

# include "Game/Ressources/Ressource.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Food : public Ressource
    {
    public:
      Food(irr::f32 x,irr::f32 y, Observer const &obs) :
	Ressource(irr::core::vector2df{x, y},
		  RessourceStat{RessourceType::FOOD}, "Assets/models/Bush.3ds",
		  obs)
      {
	this->_name = EntityName::NFOOD;
	this->_associatedRole = AoL::Game::UnitRole::GATHERER;
      }
      
      ~Food() {}
    };
  }
}

#endif /* FOOD_HPP_ */
