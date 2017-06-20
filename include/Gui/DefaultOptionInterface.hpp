#ifndef DEFAULTOPTIONINTERFACE_HPP_
# define DEFAULTOPTIONINTERFACE_HPP_

# include "OptionInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class DefaultOptionInterface : public OptionInterface
    {
    public:
      DefaultOptionInterface();
      virtual ~DefaultOptionInterface();
    };
  }
}

#endif //DEFAULTOPTIONINTERFACE_HPP_
