#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include <chrono>
# include "irrlicht/irrlicht.h"
# include "Stock.hpp"
# include "Timer.hpp"

namespace AoL
{
  class	  Manager;
  namespace Game
  {
    class AiPlayer;
    class Entity;
    class Unit;
    class Building;
    class Controlled;
    class Map;

    enum class Team : irr::c8
    {
      UNDEFINED = -1,
      TEAM_ONE,
      TEAM_TWO,
      TEAM_THREE,
      TEAM_FOUR
    };

    enum class PlayerStatus : irr::c8
    {
      INGAME = 0,
      LOOSE,
      WIN
    };

    class Player
    {
      public:
	Player(AoL::Manager &manager,
	    AoL::Game::Map &map,
	    AoL::Game::Team team,
	    std::string const &name = "Unknown",
	    irr::s32 timeDefeat = 600);
	~Player();

	AoL::Game::Map		&getMap() const { return _map; } 

	std::string const		&getName() const
	{
	  return (this->_name);
	}

	irr::s32			getPopulation() const
	{
	  return (this->_population);
	}

	void			setTeam(AoL::Game::Team t) { this->_team = t; }

	AoL::Game::Team		getTeam() const
	{
	  return (this->_team);
	}

      void			setStatus(AoL::Game::PlayerStatus status)
      {
	this->_status = status;
      }
      
	AoL::Game::PlayerStatus	getStatus() const
	{
	  return (this->_status);
	}

	AoL::Game::Stock		getStock() const
	{
	  return (this->_stock);
	}

	void			addRessource(AoL::Game::RessourceType type, irr::s32 amount)
	{
	  this->_stock.changeNb(type, amount);
	}

	void			removeRessource(AoL::Game::RessourceType type, irr::s32 amount)
	{
	  this->_stock.changeNb(type, -amount);
	}

	std::vector<AoL::Game::Building *> const	&getBuildings() const
	{
	  return (_buildings);
	}

	void			setStart(bool state) { _start = state; }
	bool			getStart() const { return _start; }

	template<typename T>
	  T			*createEntity(irr::core::vector2df const &pos);
	template<typename T>
	  T			*createOriginEntity(irr::core::vector2df const &pos);
	irr::s32			hasStock(std::vector<irr::s32> const &cost) const;
	//void			build();
	void                      attack(AoL::Game::Unit *selectedUnit, AoL::Game::Controlled &) const;
	void                      deposit(AoL::Game::Unit *selectedUnit, AoL::Game::Building &) const;
	void                      collect(AoL::Game::Unit *selectedUnit) const;
	void                      move(AoL::Game::Unit *selectedUnit, irr::core::vector3df pos) const;
	void			selectUnit(const std::vector<AoL::Game::Entity *> &selectedEntities);
	bool			hasLost() const;
	bool			hasWon() const;
	void			destroyEntity(AoL::Game::Controlled *controlled);
      void			updateWinStatus();

	void			surrend()
	{
	  _status = AoL::Game::PlayerStatus::LOOSE;
	}
	std::vector<AoL::Game::Unit *> const	&getUnits() const
	{
	  return (_units);
	}
	bool	hasRoomForUnits() const
	{
	  return (this->_units.size() < this->_population);
	}
	AoL::Time::Timer const &getTimer()
	{ return (this->_timer); }

	irr::s32  getTimerDefeat()
	{ return (this->_timeDefeat); }

      void	setTimerDefeat(irr::f32 limit)
      {
	this->_timeDefeat = limit * 60;
      }

	void			consumeRessources(irr::f32 elapsed);
      void			incPopulation(irr::s32 add) { this->_population = this->_population + add > 50 ? 50 : this->_population + add; }
	void			removeRessInBuildings(std::vector<irr::s32> const &_costs);

      private:
	std::string					_name;
	AoL::Manager					&_manager;
	AoL::Game::Map					&_map;
	irr::u32					_population;
	AoL::Game::Stock				_stock;
	AoL::Game::Team					_team;
	AoL::Game::PlayerStatus				_status;
	std::vector<AoL::Game::Unit *>			_units;
	std::vector<AoL::Game::Building *>      	_buildings;
	AoL::Game::AiPlayer				*_ai;
	std::chrono::system_clock::time_point		 _lastCall;
	std::vector<AoL::Game::Entity *>		_selectedEntities;
	AoL::Time::Timer	       			_timer;
	irr::s32					_timeDefeat;
	bool						_start;
    };
  }
}

#endif
