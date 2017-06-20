#ifndef OPTIONMENU_HPP_
# define OPTIONMENU_HPP_

# include "Gui/OptionInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"

# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {    
    class		OptionMenu : public AScene
    {
    public:
      OptionMenu(AoL::Manager &, AoL::CommonData &);
      ~OptionMenu();
      
      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui();
      virtual irr::s32			init() { return 0; };
      //void				playGame();

    private:
      AoL::rendering::Sound  mixer;
    };
  }  
}

#endif /* !OPTIONMENU_HPP_ */
