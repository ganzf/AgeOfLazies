#include "Game/Orders/Deposit.hpp"
#include "Game/Units/Unit.hpp"
#include "Game/Buildings/Building.hpp"

AoL::Game::Orders::Deposit::Deposit(AoL::Game::Unit &parent, AoL::Game::Building *target) :
  _parent(parent), _target(target)
{
  done = false;
}

AoL::Game::Orders::Deposit::~Deposit()
{
  
}

bool	AoL::Game::Orders::Deposit::apply(irr::f32)
{
  Scopelock	lock(this->orderMutex, __FUNCTION__);
  
  if (_target)
    {
      this->_parent.notifyDeposit();
      for (irr::s32 i = 0; i < 4; i++)
	_parent.give(*_target, static_cast<AoL::Game::RessourceType>(i),
		     _parent.getStock().getNb(static_cast<AoL::Game::RessourceType>(i)));
      done = true;
    }
  return (true);
}

