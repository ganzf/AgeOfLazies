#ifndef OBSERVER_HPP_
# define OBSERVER_HPP_

# include <unordered_map>
# include <vector>
# include "irrlicht/irrlicht.h"
# include "rendering/Sound.hpp"

namespace AoL
{
  class		Message;
  enum		MessageType : irr::s32;

  namespace Game
  {
    class	Player;
    class	Map;
    enum class	Team : irr::c8;
    class	Ressource;
    class	Building;
    class	Score;
  }

  namespace Scenes
  {
    class	AScene;
  }

  class	Observer
  {
    using function = void (AoL::Observer::*)(AoL::Message &);
    using finderFunc = AoL::Game::Ressource *(AoL::Observer::*)(AoL::Message &);
    using buildingFinder = AoL::Game::Building *(AoL::Observer::*)(AoL::Message &);

    AoL::Scenes::AScene						&parent;
    AoL::Game::Map						*gameMap;
    AoL::Game::Score						*scoreboard;
    std::unordered_map<AoL::Game::Team, AoL::Game::Player *>	players;
    std::unordered_map<irr::s32, function>			functions;
    std::unordered_map<irr::s32, finderFunc>			finderFuncs;
    std::unordered_map<irr::s32, buildingFinder>		buildingFinders;
    std::unordered_map<AoL::MessageType, std::string>		sounds;

    void						assocFunctions();
    
    void						entityDeath(AoL::Message &);
    void						entitySpawn(AoL::Message &);
    void						buildingBuilt(AoL::Message &);
    void						buildingDestroyed(AoL::Message &);
    void						unitCollect(AoL::Message &);
    void						unitDeposit(AoL::Message &);
    void						gainControl(AoL::Message &);
    void						releaseControl(AoL::Message &);
    void						controlledAttack(AoL::Message &);
    void						controlledKilled(AoL::Message &);
    void						unitMove(AoL::Message &);
    void						collectDone(AoL::Message &);
    void						levelUp(AoL::Message &);

    // finderFuncs
    AoL::Game::Ressource				*findWood(AoL::Message &msg);
    AoL::Game::Ressource				*findStone(AoL::Message &msg);
    AoL::Game::Ressource				*findFood(AoL::Message &msg);
    AoL::Game::Ressource				*findGold(AoL::Message &msg);
    AoL::Game::Building					*findLumberCamp(AoL::Message &msg);
    AoL::Game::Building					*findMiningCamp(AoL::Message &msg);
    AoL::Game::Building					*findMill(AoL::Message &msg);

    // createFuncs
    void						createWarrior(AoL::Message &msg);
    void						createCollector(AoL::Message &msg);
    void						createGatherer(AoL::Message &msg);
    void						createLumberjack(AoL::Message &msg);
    void						createGoldMiner(AoL::Message &msg);
    void						createMiner(AoL::Message &msg);
    void						createMill(AoL::Message &msg);
    void						createLumberCamp(AoL::Message &msg);
    void						createMiningCamp(AoL::Message &msg);
    void						createHabitation(AoL::Message &msg);
    void						createForum(AoL::Message &msg);
  
    template	<typename T>
    void	createUnit(AoL::Message &);
  
    template	<typename T>
    void	createBuilding(AoL::Message &);
    
  public:
    Observer() = default;
    Observer(AoL::Scenes::AScene &parent);
    Observer(const Observer &observer);
    ~Observer() = default;

    void						setScoreBoard(AoL::Game::Score *);
    void	notify(AoL::Message &msg);
    void	setMap(AoL::Game::Map *map) { this->gameMap = map; }
    AoL::Game::Map	*getMap() const { return this->gameMap; }
    std::unordered_map<AoL::Game::Team, AoL::Game::Player *>	const &getPlayers() const { return this->players; }
    void	registerPlayer(AoL::Game::Player &);
    void	unregisterPlayer(AoL::Game::Player &);
    
    AoL::Scenes::AScene		&getParent() const { return this->parent; }

  };
}

#endif /* !OBSERVER_HPP_ */
