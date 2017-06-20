#ifndef CORE_HPP_
# define CORE_HPP_

# include <memory>
# include "rendering/Renderer.hpp"
# include "rendering/Sound.hpp"
# include "userInput/inputHandler.hpp"
# include "Constants.hpp"
# include "Manager.hpp"
# include "Scenes/Scenes.hpp"
# include "CommonData.hpp"

namespace			AoL
{
  class				Core
  {
  private:
    // A destination du renderer
    // std::unique_ptr<AoL::rendering::Window>	_win;
    // std::unique_ptr<AoL::rendering::Sound>	_sound;
    // AoL::UserInput::InputHandler		*_inputHandler;

    // Modules du Core (game, renderer, sound)
    AoL::Manager				game;
    AoL::rendering::Renderer			renderer;
    AoL::CommonData				data;
    // AoL::Sound::Mixer			mixer;


  public:
    Core();
    ~Core() = default;

  public:
    // appelle le clear screen du renderer
    void					clearScreen();
    void					refreshWindow();

  public:
    // /* GETTERS */
    // std::unique_ptr<AoL::rendering::Window>	&getWindow(void)
    // { return (this->_win); }
    // std::unique_ptr<AoL::rendering::Sound>	&getSound(void)
    // { return (this->_sound); }
    // AoL::UserInput::InputHandler		*getInputHandler(void)
    // { return (this->_inputHandler); }

    bool					keyIsPressed(AoL::UserInput::KeyValue v)
    {
      return this->renderer.keyIsPressed(v);
    }

    bool					isClicked(AoL::UserInput::MouseAttributs v)
    {
      return this->renderer.isClicked(v);
    }

    irr::s32					start(bool debug);

    bool					isFine() const
    {
      return this->renderer.deviceIsRunning();
    }

    AoL::rendering::Renderer			&getRenderer();
    void					drawLine(irr::core::vector2df const &s, irr::core::vector3df const &e)
    {
      irr::core::vector3df			tmp;
      tmp.X = s.X;
      tmp.Y = s.Y;
      tmp.Z = 0;
      this->getRenderer().getWindow().getWin()->getDriver()->draw3DLine(e, tmp, irr::video::SColor(255, 200, 200, 200));
    }
    
    void					renderScene(AoL::Scenes::AScene &s)
    {
      this->renderer.renderScene(s);
    }

    void					resetEventQueue()
    {
      this->renderer.resetEventQueue();
    }
  };
}

#endif
