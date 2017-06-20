#ifndef MOUSE_HPP_
# define MOUSE_HPP_

# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace rendering
  {
    class	Mouse
    {
      irr::gui::ICursorControl	*cursorControl;
      irr::video::IVideoDriver	*driver;

      irr::core::position2di	mouse2dPos;
      irr::video::ITexture	*cursor_img;

    public:
      Mouse(irr::gui::ICursorControl *cursorControl, irr::video::IVideoDriver *driver): cursorControl(cursorControl), driver(driver)
      {
	this->cursor_img = this->driver->getTexture("Assets/Hud/cursor.png");
      }
      ~Mouse() = default;

      void				updatePos()
      {
	this->mouse2dPos = this->cursorControl->getPosition();
      }

      irr::core::position2di const &getPos() const
      {
	return this->mouse2dPos;
      }
      void				draw()
      {
	this->updatePos();
	this->driver->draw2DImage(this->cursor_img,
				  irr::core::position2d<irr::s32>(this->mouse2dPos.X,
								  this->mouse2dPos.Y),
				  irr::core::rect<irr::s32>(0, 0,
							    this->cursor_img->getSize().Width,
							    this->cursor_img->getSize().Height),
				  0,
				  irr::video::SColor(200, 255, 255, 255), true);
      }
    };
  }
}

#endif /* !MOUSE_HPP_ */
