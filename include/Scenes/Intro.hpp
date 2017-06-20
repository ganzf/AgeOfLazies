#ifndef INTRO_HPP_
# define INTRO_HPP_

# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Scenes
  {    
    class		Intro : public AScene
    {
    public:
      Intro(AoL::Manager &, AoL::CommonData &);
      ~Intro();
      
      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui() {}
      virtual irr::s32			init();
    };
  }  
}

#endif /* !INTRO_HPP_ */
