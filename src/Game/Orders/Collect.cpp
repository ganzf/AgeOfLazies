#include "Game/Orders/Collect.hpp"
#include "Game/Units/Unit.hpp"
#include "Game/Ressources/Ressource.hpp"

AoL::Game::Orders::Collect::Collect(AoL::Game::Unit &parent, AoL::Game::Ressource *target) :
  _parent(parent), _target(target), _cooldown(2.17)
{
  done = false;
}

bool	AoL::Game::Orders::Collect::apply(irr::f32 elapsedTime)
{
  Scopelock	lock(this->orderMutex, __FUNCTION__);
  _cooldown -= elapsedTime;
  if (_cooldown <= 0)
    {
      _cooldown = 2.17;
      if (_target)
	{
	  if (_target->getStock().getNb(_target->getRessourceType()) > 0)
	    {
	      if (this->_parent.getAnimator()->getCurrentAnim() == AoL::rendering::AnimFrames::STAND)
		{
		  this->_parent.setRotation(this->_parent.getAngle(this->_parent.getPosition(), _target->getPosition()));
		  this->_parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::WORK, _target->getRessourceType());
		  this->_parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::WORK, _target->getRessourceType());
		}
	      bool ret = _parent.take(*_target, _target->getRessourceType(),
				      _parent.getCpForRessource(_target->getRessourceType()) * 2);
	      this->_parent.addExp(1);
	      if (!ret)
		{
		  this->_parent.addExp(5);
		  done = true;
		}
	    }
	  if (_target->getStock().getNb(_target->getRessourceType()) <= 0)
	    {
	      this->_parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::STAND, AoL::Game::RessourceType::NOTHING);
	      this->_parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::STAND, AoL::Game::RessourceType::NOTHING);
	      done = true;
	      _target->notifyDeath();
	    }
	}
    }
  return (true);
}

AoL::Game::Orders::Collect::~Collect()
{
  this->_parent.getAnimator()->setAnim(AoL::rendering::AnimFrames::STAND, AoL::Game::RessourceType::NOTHING);
  this->_parent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::STAND, AoL::Game::RessourceType::NOTHING);
  this->_parent.notifyCollectDone();
}
