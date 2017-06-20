#ifndef LOADGAMEMENU_HPP_
# define LOADGAMEMENU_HPP_

# include <vector>

# include "Gui/LoadGameInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"
# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {    
    class		LoadGameMenu : public AScene
    {
      public:
      LoadGameMenu(AoL::Manager &, AoL::CommonData &);
      ~LoadGameMenu();

	virtual irr::s32			run(irr::f32 elapsed);
	virtual bool			isDone();
	virtual void			reset() {}
	virtual void			initGui();
	virtual irr::s32		init() { return 0; };
	std::string		       	updateSave(irr::u32 index, std::string ai);
	std::string		       	LoadPicture(std::string const &save);

      private:
	AoL::rendering::Sound		mixer;
    };
  }  
}

#endif /* !LOADGAMEMENU_HPP_ */
