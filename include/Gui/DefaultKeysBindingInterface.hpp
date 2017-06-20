#ifndef DEFAULTKEYSBINDINGINTERFACE_HPP_
# define DEFAULTKEYSBINDINGINTERFACE_HPP_

# include "KeysBindingInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class DefaultKeysBindingInterface : public KeysBindingInterface
    {
    public:
      DefaultKeysBindingInterface();
      virtual ~DefaultKeysBindingInterface();
    };
  }
}

#endif //DEFAULTKEYSBINDINGINTERFACE_HPP_
