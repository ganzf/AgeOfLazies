#ifndef STONE_HPP_
# define STONE_HPP_

# include "Game/Ressources/Ressource.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Stone : public Ressource
    {
    public:
      Stone(irr::f32 x,irr::f32 y, Observer const &obs) :
	Ressource(irr::core::vector2df{x, y},
		  RessourceStat{RessourceType::STONE}, "Assets/models/Mine/Mine.3ds",
		  obs)
      {
	this->_name = EntityName::NSTONE;
	this->_associatedRole = AoL::Game::UnitRole::MINER;
      }
      ~Stone() {}
    };
  }
}

#endif /* STONE_HPP_ */
