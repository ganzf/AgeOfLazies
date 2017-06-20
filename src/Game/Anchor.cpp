#include "Game/Anchor.hpp"
#include "Game/Units/Unit.hpp"
#include "Print.hpp"

AoL::Game::Anchor::Anchor(irr::s32 x, irr::s32 y, irr::core::vector2df offset, irr::s32 index)
  : _dispo(nullptr), _pos(x, y), _offset(offset), index(index)
{}

bool		AoL::Game::Anchor::attach(AoL::Game::Unit &u)
{
  if (_dispo == nullptr)
    {
      _dispo = &u;
      u.setNbAnchred(this->index);
      return true;
    }
  return false;
}

AoL::Game::Anchor::~Anchor()
{

}

AoL::Game::Unit *AoL::Game::Anchor::isFree()
{
  if (_dispo)
    {
      if (_dispo->getPosition().getDistanceFrom(this->_pos) >= 5)
	this->_dispo = nullptr;
    }
  return _dispo;
}
