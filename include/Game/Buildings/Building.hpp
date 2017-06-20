#ifndef BUILDING_HPP_
# define BUILDING_HPP_

# include "Game/Controlled.hpp"
# include "Message.hpp"

namespace	AoL
{
  namespace	Game
  {
    struct			BuildingStat
    {
      irr::s32			defense;
    };

    enum class		BuildingType : irr::s32
    {
      UNDEFINED,
      FORUM,
      HABITATION,
      LUMBERCAMP,
      MININGCAMP,
      MILL
    };

    static const std::unordered_map<AoL::Game::BuildingType, std::vector<irr::s32>> BuildingCost =
    {
      {BuildingType::FORUM,		{500,	 300,	 150,	150}},
      {BuildingType::HABITATION,	{150,	 75,	 20,	20}},
      {BuildingType::LUMBERCAMP,	{500,	 10,	 50,	50}},
      {BuildingType::MININGCAMP,	{300,	 10,	 200,	200}},
      {BuildingType::MILL,		{200,	 100,	 10,	10}},
    };

    class	Building : public AoL::Game::Controlled
    {
    public:
      Building(irr::core::vector2df const &pos,
	       BuildingStat const &stats,
	       std::string const &mesh,
	       AoL::Observer const &obs) :
	Controlled(pos, mesh, obs), _stats(stats), _spawnPoint(pos.X - 1, pos.Y - 1)
      {
	this->_type = EntityType::BUILDING;
	this->_actions.emplace("Assets/textures/warrior.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_WARRIOR);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/miner.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_MINER);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/goldminer.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_GOLDMINER);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/gatherer.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_GATHERER);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/lumberjack.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_LUMBERJACK);
				 this->_observer.notify(msg);
			       });
	this->_actions.emplace("Assets/textures/collector.png", [this]()
			       {
				 AoL::Message	msg(*this, AoL::CREATE_COLLECTOR);
				 this->_observer.notify(msg);
			       });

	_nbAnchors = 16;
      }
      virtual void		notifyAttack(AoL::Game::Unit *)
      {
	
      }
      
      irr::s32			getHP() const					{ return (baseStats.hp); }
      void			setHP(irr::s32 hp)				{ baseStats.hp = hp; }
      
      std::vector<irr::s32>	getCost() const					{ return (baseStats.cost); }
      void			setCost(std::vector<irr::s32> const &cost)	{ baseStats.cost = cost; }
      void			setSpawnPoint(irr::core::vector2df spawn) { _spawnPoint = spawn; }
      irr::core::vector2df const &getSpawnPoint() const { return (_spawnPoint); }

      private:
	BuildingStat		_stats;
	irr::core::vector2df	_spawnPoint;
    };
  }
}

#endif /* BUILDING_HPP_ */
