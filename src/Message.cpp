#include "Message.hpp"
#include "Game/Entity.hpp"

AoL::Game::Entity	&AoL::Message::getParent()
{
  return this->parent;
}
