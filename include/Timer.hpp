#ifndef TIMER_HPP_
# define TIMER_HPP_

# include <chrono>
# include <thread>
# include "Print.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Time
  {
    using Point = std::chrono::system_clock::time_point;
    using Duration = std::chrono::duration<irr::f32>;
    using MillisecondDuration = std::chrono::duration<irr::f32, std::ratio<1, 1>>;

    class	Fps
    {
      irr::s32	rate;
      irr::f32	actual_rate;
    public:
      Fps(irr::u8 rate):
	rate(rate), actual_rate(1 / static_cast<irr::f32>(rate)) {}
      ~Fps() {}

      void	setRateFromFloat(irr::f32 f)
      {
	this->rate = 1.0 / f;
	this->actual_rate = f;
      }

      irr::s32	getRate() const
      {
	return this->rate;
      }
      
      irr::f32	operator () () const
      {
	return this->actual_rate;
      }
    };


    class	Timer
    {
      Time::Point		start;
      Time::Point		globalStart;

    public:
      auto	now() const
      {
	return std::chrono::system_clock::now();
      }

      Timer():
	start(this->now()), globalStart((this->now()))
      {}
      ~Timer() {};

      void	wait(irr::s32 sec) const // INT ET DOUBLE
      {
	Duration	esec(sec);
	std::this_thread::sleep_for(esec);
      }
  
      void	wait(irr::f64 msec) const
      {
	Duration	esec(msec);
	std::this_thread::sleep_for(esec);
      }

      void	reset()
      {
	this->start = this->now();
      }
  
      irr::s32	seconds() const
      {
	Duration	dur = this->now() - start;

	return (dur.count());
      }

      irr::f32	getTime() const
      {
       	MillisecondDuration dur = this->now() - start;
	return (dur.count());
      }

      irr::f32	getTotalTime() const
      {
	MillisecondDuration dur = this->now() - globalStart;
	return (dur.count());
      }
  
      irr::f32		getElapsedTimeAndReset()
      {
	irr::f32	res = this->getTime();
	this->reset();
	return res;
      }  
    };
  }
}

#endif /* !TIMER_HPP_ */
