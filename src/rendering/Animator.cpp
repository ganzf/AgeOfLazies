#include "rendering/Animator.hpp"
#include "Game/Ressources/Ressource.hpp"

void	AoL::rendering::Animator::setAnimSpeed(AoL::rendering::AnimSpeed speed,
					       AoL::Game::RessourceType type)
{
  if (speed == AoL::rendering::AnimSpeed::WORK)
    {
      if (type == AoL::Game::RessourceType::FOOD)
	speed = AoL::rendering::AnimSpeed::COLLECT;
      else if (type == AoL::Game::RessourceType::STONE
	       || type == AoL::Game::RessourceType::GOLD)
	speed = AoL::rendering::AnimSpeed::MINE;
    }

  irr::s32			speeds = static_cast<irr::s32>(speed);
  this->_node->setAnimationSpeed(this->_animSpeed = speeds);
}

void    AoL::rendering::Animator::setBuildingSpeed(AoL::Game::EntityName name)
{
  this->_node->setAnimationSpeed((this->_animSpeed = this->buildAnimSpeed[static_cast<irr::s32>(name) - 4]));
}

void	 AoL::rendering::Animator::setAnim(AoL::rendering::AnimFrames anim,
					   AoL::Game::RessourceType type)
{
  if (anim == getCurrentAnim())
    return ;
  if (anim == AoL::rendering::AnimFrames::WORK)
    {
      if (type == AoL::Game::RessourceType::FOOD)
	anim = AoL::rendering::AnimFrames::COLLECT;
      else if (type == AoL::Game::RessourceType::STONE
	       || type == AoL::Game::RessourceType::GOLD)
	anim = AoL::rendering::AnimFrames::MINE;
    }

  irr::s32			i = static_cast<irr::s32>(this->_currentAnim = anim);
  this->_node->setFrameLoop(_frames[i].first, _frames[i].second);
}
