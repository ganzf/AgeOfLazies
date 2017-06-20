#ifndef MYPRINT_HPP_
# define MYPRINT_HPP_

# include <iostream>
# include <fstream>
# include <exception>
# include <chrono>
# include <thread>
# include <unordered_map>
# include <string>

# define D_INFO		"line " + std::to_string(__LINE__) + std::string(" in ") + __FILE__
# define STRINGIFY(x) #x
# define TOSTRING(x) STRINGIFY(x)
# define VAR(s)	"\t" + std::string(TOSTRING(s)) + " = ", s

namespace Print
{
  template	<typename T>
  void		out(T t)
  {
    std::cout << t << std::endl;
  };

  template	<typename T>
  void		err(T t)
  {
    std::cerr << t << std::endl;
  };

  template	<typename T>
  void		out(std::string const &prefix, T t, std::string const &suffix = "")
  {
    std::cout << prefix << t << suffix << std::endl;
  };

  template	<typename T>
  void		err(std::string const &prefix, T t, std::string const &suffix = "")
  {
    std::cerr << prefix << t << suffix << std::endl;
  };

  namespace Color
  {
    namespace ColorSet
    {
      static std::string	reset = "\e[0m";
      static std::string	red = "\e[031m";
      static std::string	blue = "\e[032m";
    }

    template	<typename T>
    void	out(T t)
    {
      std::cout << ColorSet::blue << t << ColorSet::reset << std::endl;
    };

    template	<typename T>
    void	err(T t)
    {
      std::cerr << ColorSet::red << t << ColorSet::reset << std::endl;
    };

    template	<typename T>
    void	out(std::string const &prefix, T t, std::string const &suffix = "")
    {
      std::cout << ColorSet::blue << prefix << ColorSet::reset << t << suffix << std::endl;
    };

    template	<typename T>
    void	err(std::string const &prefix, T t, std::string const &suffix = "")
    {
      std::cerr << ColorSet::red << prefix << ColorSet::reset << t << suffix << std::endl;
    };
  }
}

#endif /* !MYPRINT_HPP_ */
