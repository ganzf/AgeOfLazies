#ifndef SCORE_HPP_
# define SCORE_HPP_

# include "Gui/ScoreInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"

# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {    
    class		Score : public AScene
    {
    public:
      Score(AoL::Manager &, AoL::CommonData &);
      ~Score();
      
      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui();
      virtual irr::s32			init() { return 0; };
    private:
      AoL::rendering::Sound  mixer;
    };
  }  
}

#endif /* !SCORE_HPP_ */
