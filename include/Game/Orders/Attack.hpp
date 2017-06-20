#ifndef ATTACK_HPP_
# define ATTACK_HPP_

# include "Game/Orders/Order.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Unit;
    class	Entity;

    namespace Orders
    {
      class	Attack : public AOrder
      {
	AoL::Game::Controlled		&parent;
	AoL::Game::Controlled		*target;
	irr::f32			_cooldown;
      
      public:
	Attack(AoL::Game::Controlled &parent, AoL::Game::Controlled *target); // Useful to follow another unit.
	~Attack();

	virtual bool	apply(irr::f32 elapsedTime);
      };

    }
  }
}

#endif /* !ATTACK_HPP_ */
