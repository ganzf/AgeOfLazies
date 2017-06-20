#ifndef MOVE_HPP_
# define MOVE_HPP_

# include "Game/Orders/Order.hpp"

namespace AoL
{
  namespace Game
  {
    class	Unit;
    class	Entity;

    namespace Orders
    {
      class	Move : public AOrder
      {
	AoL::Game::Unit			&parent;
	AoL::Game::Entity		*target;
	irr::core::vector2df const	*dest;
	bool				toFree;

      public:
	Move(AoL::Game::Unit &parent, AoL::Game::Entity *target);
	Move(AoL::Game::Unit &parent, irr::core::vector2df const *pos);
	~Move();

	virtual bool	apply(irr::f32 elapsedTime);
      };
    }
  }
}

#endif /* !MOVE_HPP_ */
