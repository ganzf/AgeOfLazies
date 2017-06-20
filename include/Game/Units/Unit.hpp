#ifndef UNIT_HPP_
# define UNIT_HPP_

# include "Game/Controlled.hpp"
# include "Game/Buildings/Building.hpp"
# include "Game/Ressources/Ressource.hpp"
# include "Message.hpp"
# include "Game/Units/UnitRole.hpp"

static const	irr::f32	g_pi = 3.141592;

namespace	AoL
{
  namespace	Game
  {
   struct		UnitStat
    {
      irr::f32			speed;
      irr::s32			level;
      std::vector<irr::f32>	cp;
      irr::s32			currExp;
      irr::s32			levelStep;
    };

    enum class		UnitType : irr::s32
    {
      WARRIOR,
	COLLECTOR,
	WOOD_COLLECTOR,
	FOOD_COLLECTOR,
	STONE_COLLECTOR,
	GOLD_COLLECTOR,
	UNDEFINED,
    };
    
    static const std::unordered_map<UnitType, std::vector<irr::s32>>  UnitCost = 
    {
      {UnitType::WARRIOR,		{15,	40,	30,	50}},
      {UnitType::COLLECTOR,		{20,	30,	2,	3}},
      {UnitType::WOOD_COLLECTOR,	{300,	50,	5,	5}},
      {UnitType::FOOD_COLLECTOR,	{10,	300,	5,	5}},
      {UnitType::STONE_COLLECTOR,	{10,	50,	300,	5}},
      {UnitType::GOLD_COLLECTOR,	{10,	50,	5,	300}},
    };
    
    class	Unit : public AoL::Game::Controlled
    {
      public:
	Unit(irr::core::vector2df const &pos,
	     UnitStat const &stats,
	     std::string const &mesh,
	     AoL::Observer const &obs) :
	  AoL::Game::Controlled(pos, mesh, obs),
	  _stats(stats), _nbAnchor(-1), _attachedTo(nullptr), _role(UnitRole::NONE)
      {
	this->_type = EntityType::UNIT;
	this->_actions.emplace("Assets/textures/lumber.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_LUMBERCAMP);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/miningcamp.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_MININGCAMP);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/mill.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_MILL);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/house.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_HABITATION);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/forum.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_FORUM);
				 this->_observer.notify(msg);
			       });

      }
      ~Unit() {}

      irr::f32		getSpeed() const { return (_stats.speed); }
      void		setSpeed(irr::f32 speed) { _stats.speed = speed; }

      irr::s32		getLevel() const { return (_stats.level); }
      void		setLevel(irr::s32 level) { _stats.level = level; }
      void		levelUp()
      {
	notifyLevelUp();
	_stats.level++;
	_stats.currExp = 0;
	_stats.levelStep *= 2;
	_stats.speed += 0.5;
	this->setMaxHP(this->getMaxHP() + 10);
	this->setHP(this->getHP() + 10);
	irr::s32	i = 0;

	while (i < 4)
	  {
	    _stocks.changeMax(static_cast<AoL::Game::RessourceType>(i),
			      _stocks.getMax(static_cast<AoL::Game::RessourceType>(i)) + 10 * _stats.level);
	    _stats.cp[i] *= 2;
	    i++;
	  }
	if (getName() == WARRIOR)
	  baseStats.ap += 15;
      }

      irr::f32		getCpForRessource(AoL::Game::RessourceType type) const
      {
	return (_stats.cp[static_cast<irr::s32>(type)]);
      }
      
      irr::s32		getCurrExp() const { return (_stats.currExp); }
      void		addExp(irr::s32 exp)
      {
	_stats.currExp += exp;
	if (_stats.currExp >= _stats.levelStep)
	  levelUp();
      }

      irr::s32		getLevelStep() const { return (_stats.levelStep); }

      irr::s32		getNbAnchred() const { return (_nbAnchor); }
      void		setNbAnchred(irr::s32 nb) { _nbAnchor = nb; }

      Entity		*isAttachedTo() { return (_attachedTo); }
      void		setAttachedTo(Entity *target) { _attachedTo = target; }

      irr::f32		getAngle(const irr::core::vector2df &vec1,
				 const irr::core::vector2df &vec2)
      {
	irr::core::vector3df	vector;

	irr::f32 deltaY = vec2.Y - vec1.Y;
	irr::f32 deltaX = vec2.X - vec1.X;
	irr::f32 angle = std::atan2(deltaY, deltaX) * 180 / 3.14;
	return (-angle - 90);
      }

      void		goTo(irr::core::vector2df const *pos)
      {
	if (this->orders.size() == 0)
	  this->notifyControl();
	this->orders.push(new AoL::Game::Orders::Move(*this, pos));
	this->_rotation = getAngle(this->_pos, *pos);
	// AoL::Message	msg(*this, AoL::MOVE, pos);
	// this->_observer.notify(msg);
      }

      void		goTo(AoL::Game::Entity *target)
      {
	if (this->orders.size() == 0)
	  this->notifyControl();
	this->orders.push(new AoL::Game::Orders::Move(*this, target));
	this->_rotation = getAngle(this->_pos, target->getPosition());
      }

      void		collect(Ressource &target)
      {
	if (this->orders.size() == 0)
	  this->notifyControl();
	this->goTo(static_cast<AoL::Game::Entity *>(&target));
	this->orders.push(new AoL::Game::Orders::Collect(*this, &target));
	this->_role = target.getAssociatedRole();
      }

      void		deposit(Building &target)
      {
	if (this->orders.size() == 0)
	  this->notifyControl();
	this->goTo(static_cast<AoL::Game::Entity *>(&target));
	this->orders.push(new AoL::Game::Orders::Deposit(*this, &target));
      }

      void		notifyDeposit()
      {
	for (irr::s32 i = 0; i < 4; i++)
	  {
	    if (this->getStock().getNb(static_cast<AoL::Game::RessourceType>(i)) > 0)
	      {
		AoL::Message	msg(*this,
				    AoL::DEPOSIT,
				    this->getStock().getNb(static_cast<AoL::Game::RessourceType>(i)));
		msg.setRessource(static_cast<AoL::Game::RessourceType>(i));
		this->_observer.notify(msg);
	      }
	  }
      }

      virtual void		notifyAttack(AoL::Game::Unit *)
      {
	
      }
      
      void		notifySpawn()
      {
	AoL::Message	msg(*this, AoL::SPAWN);
	this->_observer.notify(msg);
      }

      void		notifyLevelUp()
      {
	AoL::Message	msg(*this, AoL::LEVEL_UP);
	this->_observer.notify(msg);
      }

      void		setRole(AoL::Game::UnitRole role) { this->_role = role; }
      UnitRole		getRole() const { return _role; }
      
      void		notifyCollectDone()
      {
	AoL::Message	msg(*this, AoL::COLLECT_DONE);
	this->_observer.notify(msg);
      }

    protected:
      UnitStat			_stats;
      irr::s32			_nbAnchor;
      Entity			*_attachedTo;
      UnitRole			_role;
    };
  }
}

#endif /* UNIT_HPP_ */
