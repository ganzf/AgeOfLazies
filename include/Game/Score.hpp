#ifndef GAMESCORE_HPP_
# define GAMESCORE_HPP_

# include <vector>

namespace	AoL
{
  namespace	Game
  {
    class	Score
    {
    public:
      Score() :
	_mouseClicked(0),
	_keyboardPressed(0),
	_deposits(0)
      {
	
      }
      ~Score() {}

    private:
      std::vector<irr::u32>	_entitiesAdded;
      std::vector<irr::u32>	_entitiesDestroyed;
      irr::u32			_mouseClicked;
      irr::u32			_keyboardPressed;
      irr::u32			_deposits;
    };
  }
}

#endif /* GAMESCORE_HPP_ */
