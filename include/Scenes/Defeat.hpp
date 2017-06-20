#ifndef DEFEAT_HPP_
# define DEFEAT_HPP_

# include "Gui/MenuInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"

# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {    
    class		Defeat : public AScene
    {
    public:
      Defeat(AoL::Manager &, AoL::CommonData &);
      ~Defeat();
      
      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui();
      virtual irr::s32			init() { return 0; };
      void				playScore();
    private:
      AoL::rendering::Sound	mixer;
    };
  }  
}

#endif /* !DEFEAT_HPP_ */
