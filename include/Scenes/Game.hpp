#ifndef GAME_HPP_
# define GAME_HPP_

# include "Scenes.hpp"
# include "Game/AllUnits.hpp"
# include "Game/AllBuildings.hpp"
# include "Game/Player.hpp"
# include "irrlicht/irrlicht.h"
# include "Game/MapGenerator.hpp"

namespace AoL
{
  namespace Scenes
  {
    class		Game : public AScene
    {
      std::vector<std::shared_ptr<AoL::Game::Player>>	players;
      AoL::Game::MapGenerator				generator;

    public:
      Game(AoL::Manager &, AoL::CommonData &);
      ~Game();

      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui();
      virtual irr::s32			init();
      void				pauseGame();
      void				focus();
      void				target();
      

      void				placeBuild();
      void				select();
      void				spawn();
      void				controlledActions(AoL::Game::Unit *) const;
      irr::s32				actionOnControlled(AoL::Game::Unit *) const;
      void				encycloSetup();
      void				optionsSetup();

      template	<typename Building>
      void				startBuildProcess()
      {
	if (dynamic_cast<Building *>(this->map.getHoverControlled()) == nullptr)
	  this->cancelBuild();
	Building	*build = new Building(this->selectorInfo.pos.X,
					      this->selectorInfo.pos.Y,
					      this->observer);
	if (this->selectedEntities.size() > 0 && players.front()->hasStock(build->getCost()) == 0)
	  this->map.addHoverControlled(build);
	else
	  delete build;
      }

      template	<typename Unit>
      void				spawn()
      {
	AoL::Game::Forum	*build;
	Unit			tmp(0, 0, this->observer);

	if (this->selectedEntities.size() > 0
	    && (build = dynamic_cast<AoL::Game::Forum *>(selectedEntities[0])) != nullptr)
	  {
	    if (build->hasStock(tmp.getCost()) == 0)
	      {
		Unit *spawned = this->players.front()->createEntity<Unit>(build->getSpawnPoint());
		if (spawned)
		  {
		    build->getStock().changeNb(AoL::Game::RessourceType::WOOD, -spawned->getCost()[0]);
		    build->getStock().changeNb(AoL::Game::RessourceType::FOOD, -spawned->getCost()[1]);
		    build->getStock().changeNb(AoL::Game::RessourceType::STONE, -spawned->getCost()[2]);
		    build->getStock().changeNb(AoL::Game::RessourceType::GOLD, -spawned->getCost()[3]);
		  }
	      }
	  }
      }

      void				deselectEntities();
      
      void				cancelBuild()
      {
	this->map.removeHover();
      }
    };
  }
}

#endif /* !GAME_HPP_ */
