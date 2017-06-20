#ifndef DEPOSIT_HPP_
# define DEPOSIT_HPP_

# include "Game/Orders/Order.hpp"

namespace AoL
{
  namespace Game
  {
    class	Unit;
    class	Building;

    namespace	Orders
    {
      class	Deposit : public AOrder
      {
	AoL::Game::Unit		&_parent;
	AoL::Game::Building	*_target;
	
	
      public:
	Deposit(AoL::Game::Unit &parent, AoL::Game::Building *target);
	~Deposit();
	
	virtual bool	apply(irr::f32 elapsedTime);
      };
    }
  }
}

#endif /* !DEPOSIT_HPP_ */
