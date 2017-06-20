#include "Game/Entity.hpp"
#include "IdGenerator.hpp"
#include "Game/Units/Unit.hpp"
#include "Message.hpp"
#include "Game/AllRessources.hpp"

extern AoL::IdGenerator getId;

AoL::Game::Entity::Entity(const irr::core::vector2d<irr::f32> &pos,
			  const std::string &mesh,
			  AoL::Observer const &obs):
  _observer(obs), _pos(pos), _prevPos(pos), _mesh(mesh), _type(EntityType::UNDEF),
  _rotation(0), _id(::getId()),
  _dispo(false), _stocks(Stock(std::pair<irr::s32, irr::s32>(0, 0),
			       std::pair<irr::s32, irr::s32>(0, 0),
			       std::pair<irr::s32, irr::s32>(0, 0),
			       std::pair<irr::s32, irr::s32>(0, 0))),
  _nbAnchors(8), _node(nullptr), _gridScale(1), _scale(irr::core::vector3df{1.0, 1.0, 1.0}),
  _name(EntityName::UNDEFINED),
  _team(Team::UNDEFINED), _selected(false), _markedForDeath(false)
{

}

bool		AoL::Game::Entity::give(Entity &other, RessourceType type, irr::s32 nb)
{
  if (other.getStock().getMax(type) - other.getStock().getNb(type) < nb
      || getStock().getNb(type) < nb)
    {
      irr::s32	i = 0;
      irr::s32	maxOther = other.getStock().getMax(type) - other.getStock().getNb(type);
      irr::s32	maxMine = getStock().getNb(type);
      while (i < nb && i < maxOther && i < maxMine)
	{
	  other.getStock().changeNb(type, 1);
	  getStock().changeNb(type, -1);
	  i++;
	}
      return false;
    }
  other.getStock().changeNb(type, nb);
  getStock().changeNb(type, -nb);
  return true;
}

void		AoL::Game::Entity::createAnchors()
{
  if (this->_node && this->_anchors.size() == 0)
    {
      irr::f32			angle = this->_nbAnchors;
      angle = 1 / angle;
      angle *= 180 / 3.14;
      irr::f32			tmp = angle;
      irr::f32			idx = 0;
      irr::core::vector2df	modifier;
      irr::core::vector3df	scale = this->_node->getBoundingBox().getExtent();
      while (idx < this->_nbAnchors)
	{
	  tmp = idx * (angle / 1.015);
	  modifier.X = scale.X * cos(tmp) * 3.14;
	  modifier.Y = scale.X * sin(tmp) * 3.14;
	  this->_anchors.push_back(std::make_unique<AoL::Game::Anchor>(this->_pos.X + modifier.X, this->_pos.Y + modifier.Y, modifier, idx));
	  idx++;
	}
    }
}

void				AoL::Game::Entity::resetAnchorPosition(void)
{
  for (const auto &anchor : this->_anchors)
    {
      anchor->setPos(this->getPosition());
    };
}

bool		AoL::Game::Entity::take(Entity &other, RessourceType type, irr::s32 nb)
{
  if (getStock().getMax(type) - getStock().getNb(type) < nb
      || other.getStock().getNb(type) < nb)
    {
      irr::s32	i = 0;
      irr::s32	maxMine = getStock().getMax(type) - getStock().getNb(type);
      irr::s32	maxOther = other.getStock().getNb(type);

      while (i < nb && i < maxOther && i < maxMine)
	{
	  other.getStock().changeNb(type, -1);
	  getStock().changeNb(type, 1);
	  i++;
	}
      return false;
    }
  getStock().changeNb(type, nb);
  other.getStock().changeNb(type, -nb);
  return true;
}

irr::s32			AoL::Game::Entity::getNbAnchorsFree() const
{
  irr::s32			nb = 0;
  irr::u32			i = 0;

  while (i < _anchors.size())
    {
      if (_anchors[i]->isFree() == nullptr)
	nb++;
      i++;
    }
  return (nb);
}

irr::core::vector2df const	&AoL::Game::Entity::getAnchorPos(Unit &target)
{
  irr::u32			i = 0;

  while (i < _anchors.size())
    {
      if (_anchors[i]->isFree() == nullptr)
	{
	  _anchors[i]->attach(target);
	  return (_anchors[i]->getPos());
      	}
      i++;
    }
  return (this->_anchors[0]->getPos());
}

void		AoL::Game::Entity::notifyDeath()
{
  AoL::Message	msg(*this, AoL::DEATH);

  this->_observer.notify(msg);
}
