#ifndef		WRAPPER_CONTAINERS_HPP_
# define	WRAPPER_CONTAINERS_HPP_

# include <unordered_map>
# include <mutex>

template <class T, class U>
class				WrapperUnorderedMap
{
  private:
  std::unordered_map<T, U>	_container;
    std::mutex			_mut;

  public:
    WrapperUnorderedMap(std::unordered_map<T, U> &container)
      : _container(container) {}
    ~WrapperUnorderedMap() = default;

    U			&operator[](T const &pos)
    {
      U			ret;

      _mut.lock();
      ret = _container[pos];
      _mut.unlock();
      return ret;
    } 

    U			&operator[](T &pos)
    {
      U			ret;

      _mut.lock();
      ret = _container[pos];
      _mut.unlock();
      return ret;
    }

    const U		&at(const T &key) const
    {
      U			ret;

      _mut.lock();
      ret = _container.at(key);
      _mut.unlock();
      return ret;
    }

    U			&at(T &key)
    {
      U			ret;

      _mut.lock();
      ret= _container.at(key);
      _mut.unlock();
      return ret;
    }

    iterator		find(const T &key)
    {
      return _container.find(key);
    }

    const_iterator	find(const T &key)
    {
      return _container.find(key);
    }
};

#endif		/* !WRAPPER_CONTAINERS_HPP_ */
