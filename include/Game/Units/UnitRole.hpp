#ifndef UNITROLE_HPP_
# define UNITROLE_HPP_

# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Game
  {
    enum	UnitRole : irr::c8
    {
      NONE = 0,
      LUMBERJACK,
      GATHERER,
      MINER,
      GOLDDIGGER,
      FIGHTER,
    }; 
  }  
}

#endif /* !UNITROLE_HPP_ */
