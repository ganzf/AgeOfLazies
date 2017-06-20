#ifndef DEFAULTGAMEINTERFACE_HPP_
# define DEFAULTGAMEINTERFACE_HPP_

# include "GameInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class DefaultGameInterface : public GameInterface
    {
    public:
      DefaultGameInterface();
      virtual ~DefaultGameInterface();
    };
  }
}

#endif //DEFAULTGAMEINTERFACE_HPP_
