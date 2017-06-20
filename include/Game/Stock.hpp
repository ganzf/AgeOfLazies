#ifndef STOCK_HPP_
# define STOCK_HPP_

# include <vector>
# include "irrlicht/irrlicht.h"
# include "Scopelock.hpp"

namespace	AoL
{
  namespace	Game
  {
    enum	RessourceType : irr::s32;

    class	Stock
    {
    public:
      Stock(std::pair<irr::s32, irr::s32> const &wood, std::pair<irr::s32, irr::s32> const &food,
	    std::pair<irr::s32, irr::s32> const &stone, std::pair<irr::s32, irr::s32> const &gold);
      Stock(const Stock &ref);
      Stock &operator = (const Stock &ref);
      ~Stock();

      std::vector<std::pair<irr::s32,irr::s32>>	const &operator () () const;
      irr::s32		getNb(RessourceType type) const;
      irr::s32		getMax(RessourceType type) const;
      void		changeNb(RessourceType type, irr::s32 nb);
      void		changeMax(RessourceType type, irr::s32 max);
    private:
      std::mutex					stockMutex;
      std::vector<std::pair<irr::s32, irr::s32>>	_stock; /// first -> current ; second -> max capacity
    };
  }
}

#endif /* STOCK_HPP_ */
