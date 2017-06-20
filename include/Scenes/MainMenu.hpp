#ifndef MAINMENU_HPP_
# define MAINMENU_HPP_

# include "Gui/MenuInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"

# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {    
    class		MainMenu : public AScene
    {
    public:
      MainMenu(AoL::Manager &, AoL::CommonData &);
      ~MainMenu();
      
      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui();
      virtual irr::s32			init() { return 0; };
      void				playNewGameMenu();
      void				playLoadGameMenu();
      void				playOptionMenu();
    private:
      AoL::rendering::Sound  mixer;
    };
  }  
}

#endif /* !MAINMENU_HPP_ */
