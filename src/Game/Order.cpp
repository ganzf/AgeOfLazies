#include "Game/Orders/Order.hpp"
#include "Game/Controlled.hpp"
#include "Print.hpp"

AoL::Game::AttackOrder::AttackOrder(Controlled &parent, Controlled *target):
  parent(parent), target(target)
{
  this->done = false;
}

bool	AoL::Game::AttackOrder::apply(irr::f32 elapsedTime)
{
  (void)elapsedTime;
  return (true);
}
