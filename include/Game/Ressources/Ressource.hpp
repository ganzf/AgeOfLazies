#ifndef RESSOURCE_HPP_
# define RESSOURCE_HPP_

# include <random>
# include "Game/Entity.hpp"
# include "Game/Units/UnitRole.hpp"

namespace	AoL
{
  namespace	Game
  {
    enum	RessourceType : irr::s32
    {
      WOOD,
      FOOD,
      STONE,
      GOLD,
      NOTHING
    };

    struct		RessourceStat
    {
      RessourceType	type;
    };

    class	Ressource : public Entity
    {
      public:
	Ressource(irr::core::vector2df const &pos,
		  RessourceStat const &stats,
		  std::string const &mesh,
		  AoL::Observer const &obs
		  ) :
	  Entity(pos, mesh, obs), _stats(stats),
	  _associatedRole(AoL::Game::UnitRole::NONE)
	{
	  this->_type = EntityType::RESSOURCE;
	  std::mt19937 rng;
	  rng.seed(std::random_device()());
	  std::uniform_int_distribution<std::mt19937::result_type> dist(1,8);
	  std::uniform_int_distribution<std::mt19937::result_type> nb(1,10);
	  this->_nbAnchors = 8;

	  irr::s32	nbRess = nb(rng);
	  this->getStock().changeNb(_stats.type, nbRess * 20);
	  this->getStock().changeMax(_stats.type, nbRess * 20);
	  this->_scale = irr::core::vector3df{static_cast<irr::f32>(nbRess) / 10,
	    static_cast<irr::f32>(nbRess) / 10,
	    static_cast<irr::f32>(nbRess) / 10};
	}

	virtual ~Ressource() {}

	void			setAssociatedRole(AoL::Game::UnitRole role)
	{
	  this->_associatedRole = role;
	}
	AoL::Game::UnitRole	getAssociatedRole() const
	{
	  return this->_associatedRole;
	}

	RessourceType	getRessourceType() const	{ return (_stats.type); }

      protected:
	RessourceStat	_stats;
	UnitRole	_associatedRole;
    };
  }
}

#endif /* RESSOURCE_HPP_ */
