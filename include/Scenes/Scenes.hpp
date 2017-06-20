#ifndef SCENES_HPP_
# define SCENES_HPP_

# include <string>
# include <vector>
# include "IdGenerator.hpp"
# include "Timer.hpp"
# include "userInput/inputHandler.hpp"
# include "Gui/IUserInterface.hpp"
# include "irrlicht/irrlicht.h"
# include "rendering/Camera.hpp"
# include "rendering/Scene3d.hpp"
# include "Game/Map.hpp"
# include "CommonData.hpp"

namespace	AoL
{
  class		Manager;

  namespace	Scenes
  {
    class		AScene
    {
    protected:
      // Scene name.
      std::string			name;

      // Reference on scene Manager to allow each scene to stack new scenes
      AoL::Manager			&manager;

      // Scene Graphical User Interface
      AoL::Gui::IUserInterface		*gui;

      // Protected scene attributes
      bool				transparent;
      bool				paused;
      bool				done;
      irr::f32				lifespan; // en secondes (0.5 possible)
      AoL::Time::Timer			timer;
      AoL::Time::Fps			updateRate;

      // std::shared_ptr<AoL::Camera>	_irrCamera; //y
      AoL::Game::Map			map;

      // A faire passer en vector de selected;
      AoL::Game::SelectorInfo		selectorInfo;
      std::vector<AoL::Game::Entity *>	selectedEntities;

      AoL::rendering::Scene3d		scene3d;
      AoL::rendering::Sound		mixer;
      AoL::CommonData			&data;
      AoL::Observer			observer;

    public:
      explicit			AScene(AoL::Manager &manager,
				       std::string const &name,
				       AoL::CommonData &data,
				       AoL::Gui::IUserInterface *gui = nullptr);
      virtual			~AScene();
      virtual irr::s32		run(irr::f32 elapsed)		= 0;
      virtual bool		isDone()			= 0;
      virtual void		reset()				= 0;
      virtual irr::s32		init()				= 0;
      virtual void		initGui()			= 0;

      void			stop() { this->done = true; }

      void			dropGui();

      AoL::rendering::Scene3d	&getScene3d()
      {
	return this->scene3d;
      }

      AoL::Game::Map		&getMap()
      {
	return this->map;
      }

      void			drawAll()
      {
	this->scene3d.render();
      }

      irr::f32			getTime() const
      {
	return this->timer.getTime();
      }

      irr::f32			getLifespan()	const
      {
	return this->lifespan;
      }

      bool				isRunning() const	{ return (this->timer.getTime() > 0); }
      bool				restart()		{ if (!this->isRunning()) return false ; this->reset(); }

      bool				isPressed(AoL::UserInput::KeyValue);
      bool				isClicked(AoL::UserInput::MouseAttributs);

      bool				shouldUpdate();
      bool				isPaused() const	{ return this->paused; }
      bool				isTransparent() const	{ return this->transparent; };
      void				pause()			{ this->paused = true; }
      void				unpause()		{ this->paused = false; }
      void				setTransparency(bool b) { this->transparent = b; };
      void				resetEventQueue();

      std::string const &		getName() const		{ return (this->name); }
    };

    class			ScenePool
    {
      AoL::Manager		&manager;
      std::vector<AScene *>	scenes;
      std::vector<AoL::Game::Entity *>	entities;
    public:
      ScenePool(AoL::Manager &manager);
      ~ScenePool();

      void				cleanUp(); // Call this function to collect garbage ?
      template	<typename Scene>AScene	*getScene();
      template	<typename Entity>AoL::Game::Entity *getEntity(irr::f32 x, irr::f32 y);
    };
  }
}

#endif /* !SCENES_HPP_ */
