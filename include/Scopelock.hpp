#ifndef SCOPELOCK_HPP_
# define SCOPELOCK_HPP_

# include <mutex>
# include "Print.hpp"
class	Scopelock
{
  std::mutex	&mu;
  std::string	func;
public:
  Scopelock(std::mutex &mu, std::string const &func = "__FUNCTION_MISSING__"): mu(mu), func(func)
  {
    mu.lock();
  }
  ~Scopelock()
  {
    mu.unlock();
  }
  Scopelock(Scopelock const &) = delete;
  Scopelock &operator = (Scopelock const &) = delete;
};

#endif /* !SCOPELOCK_HPP_ */
