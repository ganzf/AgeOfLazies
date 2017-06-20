# include "Game/Orders/Move.hpp"
# include "Game/Units/Unit.hpp"
# include "Game/Entity.hpp"

AoL::Game::Orders::Move::Move(AoL::Game::Unit &parent,
			      AoL::Game::Entity *target):
  parent(parent), target(target), dest(&target->getAnchorPos(parent))
{
  this->toFree = false;
  this->parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::WALK);
  this->parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::WALK);
  this->done = false;
}

AoL::Game::Orders::Move::Move(AoL::Game::Unit &parent, irr::core::vector2df const *pos):
  parent(parent), target(nullptr), dest(new irr::core::vector2df(pos->X, pos->Y))
{
  this->toFree = true;
  this->parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::WALK);
  this->parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::WALK);
  this->done = false;
}

bool				AoL::Game::Orders::Move::apply(irr::f32 elapsedTime)
{
  Scopelock			lock(this->orderMutex, __FUNCTION__);
  if (this->parent.getType() == AoL::Game::UNIT)
    {
      this->parent.move(*this->dest, elapsedTime * 2, dynamic_cast<AoL::Game::Unit *>(&this->parent)->getSpeed());
    }
  if (irr::core::line2df(*this->dest, this->parent.getPosition()).getLength() <= 5)
    {
      this->parent.setRotation(this->parent.getAngle(this->parent.getPosition(), *this->dest));
      this->parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::STAND);
      this->parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::STAND);
      this->done = true;
      this->dest = nullptr;
      return (true);
    }
  else
    {
      this->parent.move(*this->dest, elapsedTime * 2);
      this->parent.setRotation(this->parent.getAngle(this->parent.getPosition(), *this->dest));
    }
  return (false);
}

AoL::Game::Orders::Move::~Move()
{
  if (this->toFree)
    delete this->dest;
}
