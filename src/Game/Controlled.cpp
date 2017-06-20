#include "Game/Controlled.hpp"
#include "Message.hpp"

void		AoL::Game::Controlled::notifyControl()
{
  AoL::Message	msg(*this, AoL::GAINCONTROL);

  this->_observer.notify(msg);
}

void		AoL::Game::Controlled::notifyNoControl()
{
  AoL::Message	msg(*this, AoL::RELEASECONTROL);

  this->_observer.notify(msg);
}

void		AoL::Game::Controlled::notifyAttack(AoL::Game::Unit *)
{
  Print::Color::err("You are under attack!");
}

bool		AoL::Game::Controlled::hasStock(std::vector<irr::s32> const &cost) const
{
  irr::u32      i = 0;

  while (i < cost.size())
    {
      if (cost[i] > _stocks.getNb((static_cast<AoL::Game::RessourceType>(i))))
	return (1);
      i++;
    }
  return (0);
  
}
