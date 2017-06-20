#ifndef DEFAULTLOADGAMEINTERFACE_HPP_
# define DEFAULTLOADGAMEINTERFACE_HPP_

# include "LoadGameInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class DefaultLoadGameInterface : public LoadGameInterface
    {
    public:
      DefaultLoadGameInterface();
      virtual ~DefaultLoadGameInterface();
    };
  }
}

#endif //DEFAULTLOADGAMEINTERFACE_HPP_
