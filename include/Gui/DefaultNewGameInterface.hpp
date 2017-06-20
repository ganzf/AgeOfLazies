#ifndef DEFAULTNEWGAMEINTERFACE_HPP_
# define DEFAULTNEWGAMEINTERFACE_HPP_

# include "NewGameInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    /*
    ** =========================================
    ** |                                       |
    ** |             NEWGAME INTERFACE         |
    ** |                                       |
    ** =========================================
    ** |            0 MODULE NEWGAME           |
    ** |           GUITypeId:M_NEWGAME         |
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

    class DefaultNewGameInterface : public NewGameInterface
    {
    public:
      DefaultNewGameInterface();
      virtual ~DefaultNewGameInterface();
    };
  }
}

#endif //DEFAULTNEWGAMEINTERFACE_HPP_
