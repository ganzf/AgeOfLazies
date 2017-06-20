#ifndef	  AIPLAYER_HPP_
# define  AIPLAYER_HPP_

# include <string>
# include <thread>

extern "C" {
# include "lualib/lua.h"
# include "lualib/lauxlib.h"
# include "lualib/lualib.h"
}

# include "irrlicht/irrlicht.h"
# include "Player.hpp"
# include "luawrapper.hpp"
# include "Game/Units/UnitRole.hpp"

namespace AoL
{
  namespace Game
  {
    enum class	UnitType;
    enum class	BuildingType;
    enum EntityName : irr::s32;


    enum class AiType : irr::c8
      {
	UNDEFINED = -1,
	  AGRESSIVE,
	  PASSIVE,
	  };

    class Ressource;

    class			AiPlayer
    {
    private:
      AoL::Game::Player	&_player;
      std::string		_luaFile;
      std::thread		_ai;

    public:
      AiPlayer(AoL::Game::Player &player, std::string const &filename);
      ~AiPlayer() = default;

      void			execute() const;
      void			print() const;
      irr::s32		getWood() const;
      irr::s32		getMaxWood() const;
      irr::s32		getStone() const;
      irr::s32		getMaxStone() const;
      irr::s32		getFood() const;
      irr::s32		getMaxFood() const;
      irr::s32		getGold() const;
      irr::s32		getMaxGold() const;
      irr::s32		getPopulation() const;
      irr::s32		getCollector() const;
      irr::s32		getPassiveCollector() const;
      bool			collectWood();
      bool			collectStone();
      bool			collectGold();
      bool			collectFood();
      irr::s32		getStoneCostBuilding(AoL::Game::BuildingType building) const;
      irr::s32		getWoodCostBuilding(AoL::Game::BuildingType building) const;
      irr::s32		getGoldCostBuilding(AoL::Game::BuildingType building) const;
      irr::s32		getFoodCostBuilding(AoL::Game::BuildingType building) const;
      irr::s32		getWoodCostUnit(AoL::Game::UnitType unit) const;
      irr::s32		getStoneCostUnit(AoL::Game::UnitType unit) const;
      irr::s32		getGoldCostUnit(AoL::Game::UnitType unit) const;
      irr::s32		getFoodCostUnit(AoL::Game::UnitType unit) const;
      bool			createBuilding(AoL::Game::BuildingType building);
      bool			createUnit(AoL::Game::UnitType unit);
      irr::s32	getNbUnitsFromName(AoL::Game::EntityName name) const;
	bool			attack(irr::s32 distance);
      irr::s32		getNbUnit(AoL::Game::UnitRole role) const;
      std::string const	&getFile() const { return _luaFile; }

      bool			shouldContinue() const
      {
	if (_player.getStatus() != AoL::Game::PlayerStatus::INGAME)
	  return (false);
	return (true);
      }
      bool			checkStatus()
      { return (this->_player.getStart()); }
      void			detach() { this->_ai.detach(); }
      std::thread const	&getThread() const { return _ai; }

    private:
      AoL::Game::Unit		*findUnit(AoL::Game::UnitRole role = AoL::Game::UnitRole::NONE) const;
      AoL::Game::Unit		*findEmergencyUnit(AoL::Game::UnitRole role) const;
      AoL::Game::Building	*findForum() const;
    };
  }
}

#endif	  /* !AIPLAYER_HPP_ */
