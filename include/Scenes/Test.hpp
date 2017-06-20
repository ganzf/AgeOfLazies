#ifndef TEST_HPP_
# define TEST_HPP_

# include "Scenes.hpp"
# include "Game/Units/Unit.hpp"
# include "Game/Player.hpp"
# include "irrlicht/irrlicht.h"
# include "Game/MapGenerator.hpp"

namespace AoL
{
  namespace Scenes
  {
    class		Test : public AScene
    {
      std::vector<std::shared_ptr<AoL::Game::Player>>	players;
      AoL::Game::MapGenerator				generator;

      public:
      Test(AoL::Manager &, AoL::CommonData &);
      ~Test();

      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui() {}
      virtual irr::s32			init();
      void				pauseGame();
      void				focus();
      void				target();
      void				startBuildProcess();
      void				placeBuild();
      void				select();
      void				spawn();
      void				controlledActions(AoL::Game::Unit *) const;
      void				move(AoL::Game::Unit *) const;
      void				collect(AoL::Game::Unit *) const;
      void				deposit(AoL::Game::Unit *) const;
      void				attack(AoL::Game::Controlled *, AoL::Game::Unit *) const;
      irr::s32				actionOnControlled(AoL::Game::Unit *) const;
    };
  }
}

#endif /* !TEST_HPP_ */
