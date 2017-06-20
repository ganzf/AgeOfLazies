#ifndef IDGENERATOR_HPP_
# define IDGENERATOR_HPP_

# include "irrlicht/irrlicht.h"
# include "Print.hpp"

namespace AoL
{
  class	IdGenerator
  {
    irr::s32		i;
  public:
    IdGenerator(): i(0)
    {

    }
    ~IdGenerator() = default;

    irr::s32		operator () ()
    {
      return ++i;
    }
  };
}

#endif /* !IDGENERATOR_HPP_ */
