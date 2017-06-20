#ifndef SCHEDULER_HPP_
# define SCHEDULER_HPP_

# include <vector>
# include <algorithm>
# include "irrlicht/irrlicht.h"

namespace AoL
{
  template	<typename T>
  class	Stack
  {
    std::vector<T *>	frames;
  public:
    Stack() {}
    ~Stack() {}

    void		addScene(T *s)
    {
      this->frames.push_back(s);
    }

    bool		moveUp(T *s)
    {
      for (irr::u32 i = 0; i < this->frames.size(); i++)
	{
	  if (this->frames[i] == s && i < this->frames.size())
	    {
	      T *tmp = this->frames[i];
	      this->frames[i] = this->frames[i + 1];
	      this->frames[i + 1] = tmp;
	      return (true);
	    }
	}
      return (false);
    }

    bool		moveDown(T *s)
    {
      for (irr::u32 i = 0; i < this->frames.size(); i++)
	{
	  if (this->frames[i] == s && i > 0)
	    {
	      T *tmp = this->frames[i];
	      this->frames[i] = this->frames[i - 1];
	      this->frames[i - 1] = tmp;
	      return (true);
	    }
	}
      return (false);
    }
    
    T *top()
    {
      return (frames.back());
    }

    T *getParent(T *s)
    {
      for (irr::u32 i = 0; i < this->frames.size(); i++)
	{
	  if (this->frames[i] == s && i > 0)
	    return (this->frames[i - 1]);
	}
      return (nullptr);
    }

    T *getChild(T *s)
    {
      for (irr::u32 i = 0; i < this->frames.size(); i++)
	{
	  if (this->frames[i] == s && i < this->frames.size())
	    return (this->frames[i + 1]);
	}
      return (nullptr);      
    }

    void pop()
    {
      delete this->frames.back();
      this->frames.pop_back();
    }
  };
}

#endif /* !SCHEDULER_HPP_ */
