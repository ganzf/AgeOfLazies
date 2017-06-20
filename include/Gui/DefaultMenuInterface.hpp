#ifndef DEFAULTMENUINTERFACE_HPP_
# define DEFAULTMENUINTERFACE_HPP_

# include "MenuInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    /*
    ** =========================================
    ** |                                       |
    ** |             MENU INTERFACE            |
    ** |                                       |
    ** =========================================
    ** |            0 MODULE MENU              |
    ** |           GUITypeId:M_MENU            |
    ** |  ===================================  |
    ** |  |                                 |  |
    ** |  |    ==========================   |  |
    ** |  |    |    Button New Game     |   |  |
    ** |  |    |  GUITypeId::B_NEWGAME  |   |  |
    ** |  |    ==========================   |  |
    ** |  |                                 |  |
    ** |  |    ==========================   |  |
    ** |  |    |    Button Load Game    |   |  |
    ** |  |    |  GUITypeId::B_LOADGAME |   |  |
    ** |  |    ==========================   |  |
    ** |  |                                 |  |
    ** |  |    ==========================   |  |
    ** |  |    |      Button Option     |   |  |
    ** |  |    |   GUITypeId::B_OPTION  |   |  |
    ** |  |    ==========================   |  |
    ** |  |                                 |  |
    ** |  |    ==========================   |  |
    ** |  |    |      Button Quit       |   |  |
    ** |  |    |   GUITypeId::B_QUIT    |   |  |
    ** |  |    ==========================   |  |
    ** |  |                                 |  |
    ** |  ===================================  |
    ** |                                       |
    ** =========================================
    */

    class DefaultMenuInterface : public MenuInterface
    {
    public:
      DefaultMenuInterface();
      virtual ~DefaultMenuInterface();
    };
  }
}

#endif //DEFAULTMENUINTERFACE_HPP_
