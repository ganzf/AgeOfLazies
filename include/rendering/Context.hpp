#ifndef CONTEXT_HPP_
# define CONTEXT_HPP_

# include <memory>
# include "irrlicht/irrlicht.h"
# include "userInput/inputHandler.hpp"
# include "rendering/Window.hpp"

namespace AoL
{
  namespace rendering
  {
    class	Renderer;

    class	Context
    {
      Renderer						&renderer;
      std::shared_ptr<AoL::UserInput::InputHandler>	_inputHandler;
      std::shared_ptr<AoL::rendering::Window>		_win;
    public:
      Context(Renderer &renderer);
      ~Context();

      irr::core::vector2di		const		&getMousePosition() const
      {
	return this->_inputHandler->_mouseHandler.getPosition();
      }
      
      bool						keyIsPressed(AoL::UserInput::KeyValue v)
      {
	return (this->_inputHandler->_keyboardHandler.isKeyPressed(v) != AoL::UserInput::KeyStatus::UNDEFINED);
      }

      bool						isClicked(AoL::UserInput::MouseAttributs v)
      {
	return (this->_inputHandler->_mouseHandler.getEvent(v));
      }

      std::shared_ptr<AoL::rendering::Window> getWin()	{ return this->_win; }
      void	clearScreen()				{ this->_win->getDriver()->beginScene(true, true, irr::video::SColor(255, 100, 120, 180)); }
      void	refreshWindow()				{ this->_win->getDriver()->endScene(); }
      bool	isRunning()	 const			{ return this->_win->getDevice()->run(); }
      std::shared_ptr<AoL::UserInput::InputHandler> &getInputHandler()
      { return this->_inputHandler; }
      void						resetEventQueue()
      {
	this->_inputHandler->resetEventQueue();
      }
    };
  }
}

# include "rendering/Renderer.hpp"

#endif /* !CONTEXT_HPP_ */
