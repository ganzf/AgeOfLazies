#ifndef ORDER_HPP_
# define ORDER_HPP_

# include "irrlicht/irrlicht.h"
# include "Scopelock.hpp"

namespace AoL
{ 
  namespace Game
  {
    class	Controlled;
    class	Entity;
    
    namespace Orders
    {
      class	AOrder
      {
      protected:
	bool		done;
	std::mutex	orderMutex;

      public:
	virtual ~AOrder() {}
	virtual bool	apply(irr::f32 elapsedTime) = 0;
      
	bool		isDone() const { return this->done; };
      };
    }
  }
}

#endif /* !ORDER_HPP_ */
