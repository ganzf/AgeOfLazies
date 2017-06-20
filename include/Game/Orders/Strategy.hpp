#ifndef STRATEGY_HPP_
# define STRATEGY_HPP_

# include <string>
# include <unordered_map>
# include <functional>

# include "Predicat.hpp"

namespace AoL
{
  namespace Game
  {
    using		Predicat =	std::function<bool(Unit const &)>;
    using		Action =	std::function<bool(Unit const &)>;

    class		Strategy
    {
      std::string				stratName;
      Unit					&parent;
      std::vector<std::pair<Predicat, Action>>	options;

    public:

      Strategy(std::string const &stratName, Unit const &parent);
      virtual ~Strategy() = default;

      virtual bool				apply()
      {
	for (auto const &p: this->options)
	  {
	    if (p.first(this->parent))
	      {
		p.second(this->parent);
		break ;
	      }
	  }
      }
    };
  }
}

#endif /* !STRATEGY_HPP_ */
