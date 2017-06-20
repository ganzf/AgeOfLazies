#ifndef OPTIONS_HPP_
# define OPTIONS_HPP_

# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Scenes
  {
    struct	Options
    {
      Options(): mapSize(10, 10) {}

      irr::core::vector2di	mapSize;
    };
  }
}

#endif /* !OPTIONS_HPP_ */ 
