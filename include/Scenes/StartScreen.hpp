#ifndef STARTSCREEN_HPP_
# define STARTSCREEN_HPP_

# include "Gui/MenuInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"

# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {
    class		StartScreen : public AScene
    {
    public:
      StartScreen(AoL::Manager &, AoL::CommonData &);
      ~StartScreen();

      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone() { return this->done; }
      virtual void			reset() {}
      virtual void			initGui();
      virtual irr::s32			init() { return 0; };
    };
  }
}

#endif /* !STARTSCREEN_HPP_ */
