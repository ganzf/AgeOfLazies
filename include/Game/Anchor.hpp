#ifndef ANCHOR_HPP_
# define ANCHOR_HPP_

# include "irrlicht/irrlicht.h"

namespace	AoL
{
  namespace	Game
  {
    class			Unit;

    class			Anchor
    {
      AoL::Game::Unit		*_dispo;
      irr::core::vector2df	_pos;
      irr::core::vector2df	_offset;
      irr::s32			index;

    public:
      Anchor(irr::s32 x, irr::s32 y, irr::core::vector2df offset, irr::s32 index);
      ~Anchor();

      AoL::Game::Unit				*isFree();
      bool					attach(AoL::Game::Unit &u);

      irr::core::vector2df	const &		getPos() const { return (_pos); }
      void					setPos(irr::core::vector2df const &pos)
      {
	this->_pos.X = pos.X + this->_offset.X;
	this->_pos.Y = pos.Y + this->_offset.Y;
      }
    };
  }
}

#endif /* ANCHOR_HPP_ */
