#ifndef DEFAULTSCOREINTERFACE_HPP_
# define DEFAULTSCOREINTERFACE_HPP_

# include "ScoreInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class DefaultScoreInterface : public ScoreInterface
    {
    public:
      DefaultScoreInterface();
      virtual ~DefaultScoreInterface();
    };
  }
}

#endif //DEFAULTSCOREINTERFACE_HPP_
