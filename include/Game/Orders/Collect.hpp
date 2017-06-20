#ifndef COLLECT_HPP_
# define COLLECT_HPP_

# include "Game/Orders/Order.hpp"

namespace AoL
{
  namespace Game
  {
    class	Unit;
    class	Ressource;

    namespace	Orders
    {
      class	Collect : public AOrder
      {
	AoL::Game::Unit		&_parent;
	AoL::Game::Ressource	*_target;
	irr::f32		_cooldown;

      public:
	Collect(AoL::Game::Unit &, AoL::Game::Ressource *target);
	~Collect();

	virtual bool	apply(irr::f32 elapsedTime);
      };
    }
  }
}

#endif /* !COLLECT_HPP_ */
