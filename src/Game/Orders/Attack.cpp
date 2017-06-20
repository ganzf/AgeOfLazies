#include "Game/Orders/Move.hpp"
#include "Game/Units/Unit.hpp"
#include "Game/Entity.hpp"

AoL::Game::Orders::Attack::Attack(AoL::Game::Controlled &parent, AoL::Game::Controlled *target):
  parent(parent), target(target), _cooldown(1.0)
{
  this->done = false;
  if (target)
    {
      this->target->notifyAttack(dynamic_cast<AoL::Game::Unit *>(&this->parent));
    }
}

bool	AoL::Game::Orders::Attack::apply(irr::f32 elapsedTime)
{
  Scopelock	lock(this->orderMutex, __FUNCTION__);
  
  if (irr::core::line2df(this->target->getPosition(), this->parent.getPosition()).getLength() > 50)
    {
      auto controlledUnit = dynamic_cast<AoL::Game::Unit *>(&this->parent);
      if (controlledUnit != nullptr)
	{
	  controlledUnit->goTo(this->target);
	  controlledUnit->giveOrder<AoL::Game::Orders::Attack>(*this->target);
	}
      this->done = true;
      return true;
    }
  _cooldown -= elapsedTime;
  this->parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::WORK);
  this->parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::WORK);
  auto unitParent = dynamic_cast<AoL::Game::Unit *>(&this->parent);
  if (_cooldown <= 0)
    {
      _cooldown = 1.17000943827368487;
      if (this->target)
	{
	  if (this->target->getHP() > 0)
	    {
	      if (unitParent)
		unitParent->addExp(1);
	      this->parent.attack(this->target, elapsedTime);
	    }
	  if (this->target->getHP() <= 0)
	    {
	      this->parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::STAND);
	      this->parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::STAND);
	      if (unitParent)
		unitParent->addExp(5);
	      this->done = true;
	      return (true);
	    }
	}
    }
  return (false);
}

AoL::Game::Orders::Attack::~Attack()
{
  auto parentUnit = dynamic_cast<AoL::Game::Unit *>(&this->parent);
  auto targetEntity = dynamic_cast<AoL::Game::Entity *>(this->target);
  if (parentUnit != nullptr)
    {
      if (targetEntity != nullptr)
	{
	  parentUnit->take(*targetEntity, RessourceType::WOOD,
			   targetEntity->getStock().getNb(RessourceType::WOOD) / 2);
	  parentUnit->take(*targetEntity, RessourceType::FOOD,
			   targetEntity->getStock().getNb(RessourceType::FOOD) / 2);
	  parentUnit->take(*targetEntity, RessourceType::STONE,
			   targetEntity->getStock().getNb(RessourceType::STONE) / 2);
	  parentUnit->take(*targetEntity, RessourceType::GOLD,
			   targetEntity->getStock().getNb(RessourceType::GOLD) / 2);
	}
    }
  this->target = nullptr;
}
