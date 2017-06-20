# ifndef CONTROLLED_HPP_
# define CONTROLLED_HPP_

# include <functional>
# include <memory>
# include <queue>
# include <unordered_map>
# include "Game/Entity.hpp"
# include "Game/AllOrders.hpp"
# include "Scopelock.hpp"

namespace	AoL
{
  namespace	Game
  {
    class	Controlled : public AoL::Game::Entity
    {
      struct ControlledStats
      {
	irr::s32		hp;
	irr::s32		maxHp;
	irr::s32		ap;
	irr::f32		lineOfSight;
	std::vector<irr::s32>	cost;
	irr::s32		nbActionForCreation;
      };

    public:
      Controlled(irr::core::vector2df const &pos,
		 std::string const &mesh,
		 AoL::Observer const &obs):
	AoL::Game::Entity(pos, mesh, obs) {}
      virtual ~Controlled()
      {
	this->cancelOrders();
      }

      template		<typename Order>
      void		giveOrder(Entity &target)
      {
	if (this->orders.size() == 0)
	  this->notifyControl();
	this->orders.push(new Order(*this, &target));
      }

      template		<typename Order>
      void		giveOrder(Controlled &target)
      {
	if (this->orders.size() == 0)
	  this->notifyControl();
	this->orders.push(new Order(*this, &target));
      }

      bool		doOrder(irr::f32 elapsed)
      {
	Scopelock	lock(this->orderMutex, __FUNCTION__);
	
	if (this->orders.size() == 0)
	  return (false);
	if (this->orders.front()->isDone() == true)
	  {
	    delete this->orders.front();
	    this->orders.pop();
	    return (true);
	  }
	return (this->orders.front()->apply(elapsed));
      }

      bool		isBusy() const
      {
	return this->orders.size() > 0;
      }

      void		cancelOrders()
      {
	while (!this->orders.empty())
	  {
	    delete this->orders.front();
	    this->orders.pop();
	  }
	this->notifyNoControl();
      }

      void				move(irr::core::vector2df const &pos, irr::f32 elapsed, irr::f32 speed = 1)
      {
	irr::core::vector2df		tmp;

	tmp = pos - this->getPosition();
	tmp = tmp.normalize() * elapsed * speed;
	this->_prevPos = _pos;
	this->setPosition(this->getPosition() + tmp);
      }

      irr::s32				getHP() const { return this->baseStats.hp; }
      irr::s32				getMaxHP() const { return this->baseStats.maxHp; }
      irr::s32				getAP() const { return this->baseStats.ap; }
      irr::f32				getLineOfSight() const { return this->baseStats.lineOfSight; }
      std::vector<irr::s32>	const	&getCost() const { return this->baseStats.cost; }
      irr::s32				getNbActionForCreation() const { return this->baseStats.nbActionForCreation; }
      std::unordered_map<std::string, std::function<void()>> const &getActions()     { return (this->_actions); }
      void				notifyControl();
      void				notifyNoControl();

      virtual void		notifyAttack(AoL::Game::Unit *);

      void				setHP(irr::s32 hp)
      {
	if (hp <= 0)
	  {
	    this->notifyDeath();
	    this->cancelOrders();
	  }
	this->baseStats.hp = hp;
      }
      void				setMaxHP(irr::s32 maxHp) { this->baseStats.maxHp = maxHp; }

      void				setAP(irr::s32 ap) { this->baseStats.ap = ap; }
      void				setLineOfSight(irr::f32 los) { this->baseStats.lineOfSight = los; }
      void				setCost(std::vector<irr::s32> const &vector) { this->baseStats.cost = vector; }
      void				setNbActionForCreation(irr::s32 actions) { this->baseStats.nbActionForCreation = actions; }

      void				attack(AoL::Game::Controlled *target, irr::f32)
      {
	target->setHP(target->getHP() - this->baseStats.ap);
      }
      bool       hasStock(std::vector<irr::s32> const &cost) const;


    protected:
      std::queue<AoL::Game::Orders::AOrder *>			orders;
      AoL::Game::Controlled::ControlledStats			baseStats;
      std::unordered_map<std::string, std::function<void()>>	_actions;
      AoL::Game::Controlled					*lastAttacker;
      std::mutex						orderMutex;
    };
  }
}

#endif /* CONTROLLED_HPP_ */
