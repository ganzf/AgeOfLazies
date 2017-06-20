#ifndef RENDERER_HPP_
# define RENDERER_HPP_

# include "irrlicht/irrlicht.h"
# include "rendering/Window.hpp"
# include "rendering/Camera.hpp"
# include "Constants.hpp"

// include all submodules
# include "rendering/Context.hpp"
# include "rendering/Scene3d.hpp"
# include "rendering/Gui/Gui.hpp"

# include "Scenes/Scenes.hpp"

namespace AoL
{
  class		Core;

  namespace rendering
  {
    class	Renderer
    {
      Core	&core;
      Context	window;
      Gui	gui;

      void	renderMap(AoL::Game::Map &, AoL::rendering::Scene3d &);
    public:
      Renderer(AoL::Core &core);
      ~Renderer();

      irr::core::vector2di	const	&getMousePosition() const { return this->window.getMousePosition(); }
      Context	&getWindow() { return this->window; }
      bool	keyIsPressed(AoL::UserInput::KeyValue v) { return this->window.keyIsPressed(v); }
      bool	isClicked(AoL::UserInput::MouseAttributs v) { return this->window.isClicked(v); }
      void	clearScreen()	{ this->window.clearScreen(); }
      void	renderScene(AoL::Scenes::AScene &);
      void	refreshWindow()	{ this->window.refreshWindow(); }
      bool	deviceIsRunning() const { return this->window.isRunning(); }
      irr::scene::ISceneManager	*getSceneManager() { return this->window.getWin()->getDevice()->getSceneManager(); }

      irr::scene::ISceneNode		*createScene();
      AoL::rendering::Gui &getGui()
      { return (this->gui); }
      AoL::rendering::Context &getContext()
      { return (this->window); }

      void				resetEventQueue()
      {
	this->window.resetEventQueue();
      }
    };
  }
}

#endif /* !RENDERER_HPP_ */
