#ifndef SCENE3D_HPP_
# define SCENE3D_HPP_

# include <mutex>
# include <memory>
# include "irrlicht/irrlicht.h"
# include "rendering/Camera.hpp"
# include "Logger.hpp"
# include "Game/Entity.hpp"
# include "rendering/Mouse.hpp"
# include "Game/Selector.hpp"

namespace AoL
{
  namespace Game
  {
    class	Grid;
  }

  namespace rendering
  {
    class	Renderer;

    class	Scene3d
    {
      using cubePtr = irr::scene::ISceneNode *;

      Renderer						&renderer;
      AoL::Logger					logger;
      irr::scene::ISceneManager				*scene;
      AoL::rendering::Camera				camera;

      AoL::rendering::Mouse				cursor;
      AoL::Game::Selector				selector;
      std::unordered_map<irr::s32, cubePtr>		gridCubes;

      std::vector<std::string>				preloadList3d;
      irr::s32						currentPreloadLine;
      std::string					preloadLine;
      std::ifstream					preloadFile;
      std::unordered_map<AoL::Game::Team, std::string>	teamColors;
      std::mutex					safeLock;


    public:
      Scene3d(Renderer &renderer);
      ~Scene3d();

      irr::scene::ISceneManager		*getScene()
      {
	return scene;
      }

      irr::s32				preload3dAssets();
      bool				createTerrain(irr::core::vector3df dims, irr::core::vector2df const &);
      bool				activateFog(irr::s32 distance);
      bool				addWater(irr::core::vector2df dims);
      void				setIslandScene(irr::core::vector2df const &);

      void				entityAddNode(AoL::Game::Entity &ent);
      void				entityAddSelector(AoL::Game::Entity &ent);
      void				entityAddAnchors(AoL::Game::Entity &ent);

      bool				contains(irr::s32);
      void				add(AoL::Game::Entity *, bool addAnchors = true);
      void				remove(irr::s32);
      void				render();
      void				drawGui();
      void				update(irr::s32, AoL::Game::Entity &);
      void				clear(irr::scene::ISceneNode *, bool);
      irr::core::vector3df		getRotationFromAngle(irr::f32 angle);
      void				centerCameraOn(AoL::Game::Entity &ent);
      void				centerCameraOn(irr::core::vector2df const &pos);
      void				createGrid(AoL::Game::Grid const &grid);
      void				updateGrid(AoL::Game::Grid const &grid);
      void				startPreloading();

      bool				mouseIsGui() const
      {
	return this->selector.mouseIsGui();
      }
      
      AoL::Game::SelectorInfo 		getNodeFromClick()
      {
	return this->selector.select();
      }

      irr::core::vector3df		getPosOnTerrain()
      {
	return this->selector.getPos();
      }
    };
  }
}

#endif /* !SCENE3D_HPP_ */
