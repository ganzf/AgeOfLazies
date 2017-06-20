#ifndef COMMONDATA_HPP_
# define COMMONDATA_HPP_

# include <array>
# include <string>
# include "irrlicht/irrlicht.h"
# include "Print.hpp"
# include "Game/Score.hpp"

namespace AoL
{
  class		CommonData
  {
    irr::core::vector2df	mapSize;
    std::array<std::string, 4>	AiList;
    irr::f32			laziness;
    irr::s32			timeLimit;
    bool			playerHasWon;
    AoL::Game::Score		score;

    
  public:
    CommonData():
      mapSize(20, 20),
      laziness(0),
      timeLimit(10)
    {
      this->resetAi();
    }
    ~CommonData() = default;

    void			setMapSize(irr::core::vector2df const &mapSize)
    {
      this->mapSize = mapSize;
    }
    irr::core::vector2df	const &getMapSize() const
    {
      return this->mapSize;
    }
    
    void			setAi(irr::s32 index, std::string const &ia)
    {
      if (index < 4 && index > 0)
	this->AiList[index] = ia;
    }
    std::string		const	&getAi(irr::s32 index) const
    {
      return this->AiList[index];
    }
    void			resetAi()
    {
      for (auto &ai: this->AiList)
	ai = "";
    }

    irr::s32			getLaziness() const
    {
      return this->laziness;
    }
    void			setLaziness(irr::s32 laziness)
    {
      this->laziness = laziness;
    }
    
    irr::s32			getTimeLimit() const
    {
      return this->timeLimit;
    }
    void			setTimeLimit(irr::s32 limit)
    {
      this->timeLimit = limit;
    }

    irr::s32			getNbPlayers() const
    {
      irr::s32			nb = 0;
      for (auto &ai: this->AiList)
	{
	  if (ai != "")
	    nb++;
	}
      Print::Color::err(VAR(nb));
      return (nb + 1);
    }

    std::array<std::string, 4> const	&getPlayers() const
    { return this->AiList; }

    void			setWinStatus(bool b)
    {
      this->playerHasWon = b;
    }

    AoL::Game::Score		&getScoreBoard()
    {
      return this->score;
    }
      
  };
}

#endif /* COMMONDATA_HPP_ */
