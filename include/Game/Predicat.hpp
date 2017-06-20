#ifndef PREDICAT_HPP_
# define PREDICAT_HPP_

# include "Game/Unit.hpp"

namespace AoL
{
  namespace Game
  {
    Predicat has1life = [](Unit &e)	{ return e.getHP() > 0; };
    Predicat has10life = [](Unit &e)	{ return e.getHP() >= 10; };
    Predicat has20life = [](Unit &e)	{ return e.getHP() >= 20; };
    Predicat has30life = [](Unit &e)	{ return e.getHP() >= 30; };
    Predicat has40life = [](Unit &e)	{ return e.getHP() >= 40; };
    Predicat has50life = [](Unit &e)	{ return e.getHP() >= 50; };
    Predicat has60life = [](Unit &e)	{ return e.getHP() >= 60; };
    Predicat has70life = [](Unit &e)	{ return e.getHP() >= 70; };
    Predicat has80life = [](Unit &e)	{ return e.getHP() >= 80; };
    Predicat has90life = [](Unit &e)	{ return e.getHP() >= 90; };
    Predicat has100life = [](Unit &e)	{ return e.getHP() == 100; };
  }
}

#endif /* !PREDICAT_HPP_ */
