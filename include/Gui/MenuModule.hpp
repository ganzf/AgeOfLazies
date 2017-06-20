#ifndef MENUMODULE_HPP_
# define MENUMODULE_HPP_

# include "IModule.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Gui
  {
    /*
    ** ====================================
    ** |           MODULE MENU            |
    ** ====================================
    ** |                                  |
    ** |    ==========================    |
    ** |  0 |    Button New Game     |    |
    ** |    ==========================    |
    ** |                                  |
    ** |                                  |
    ** |    ==========================    |
    ** |  1 |    Button Load Game    |    |
    ** |    ==========================    |
    ** |                                  |
    ** |                                  |
    ** |    ==========================    |
    ** |  2 |      Button Option     |    |
    ** |    ==========================    |
    ** |                                  |
    ** |                                  |
    ** |    ==========================    |
    ** |  3 |      Button Quit       |    |
    ** |    ==========================    |
    ** |                                  |
    ** ====================================
    */

    class	MenuModule : public IModule
    {
    public:
      MenuModule(std::wstring const &text,
		 std::string const &picturePath);
      ~MenuModule();

      std::wstring const	       	&getText() const;
      std::string const			&getPicturePath() const;
      std::vector<ButtonHolder *>	&getButtonsHolder();
      irr::u32				getNbButtonsHolder() const;
      AoL::Gui::GUITypeId	       	getType() const;
      bool				isHide() const;
      void				dump() const;
      void                              hide() { _hide = true; }
      void                              display() { _hide = false; }
      
    private:
      std::wstring			_text;
      std::string			_picturePath;
      std::vector<ButtonHolder *>	_buttonsHolder;
      irr::u32				_nbButtonsHolder = 5;
      bool				_hide = false;
      AoL::Gui::GUITypeId	       	_type = AoL::Gui::GUITypeId::M_MENU;
    };
  }
}

#endif //MENUMODULE_HPP_
