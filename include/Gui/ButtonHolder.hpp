#ifndef BUTTONHOLDER_HPP_
# define BUTTONHOLDER_HPP_

# include <iostream>
# include <string>
# include "IButton.hpp"
# include "SimpleButton.hpp"
# include "TextButton.hpp"
# include "ClickButton.hpp"
# include "BarButton.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Gui
  { 
    class	ButtonHolder
    {
    public:
      ButtonHolder(std::wstring const &name, irr::core::vector2df const &pos,
		   irr::f32 width, irr::f32 height, AoL::Gui::GUITypeId type)
	:_name(name), _pos(pos), _width(width),
	 _height(height), _button(nullptr), _type(type) {}
      ~ButtonHolder() {}

      std::wstring const       	&getName() const
      { return (_name); }
      void			setButton(IButton *button)
      { _button = button; }
      IButton			*getButton() const
      { return (_button); }
      irr::core::vector2df const       	&getPos() const
      { return (_pos); }
      irr::f32			getWidth() const
      { return (_width); }
      irr::f32			getHeight() const
      { return (_height); }
      AoL::Gui::GUITypeId	getType() const
      { return (_type); }
      void			dump() const
      {	// std::cout << _name;
      }
    private:
      std::wstring		_name;
      irr::core::vector2df	_pos;
      irr::f32			_width;
      irr::f32			_height;
      IButton			*_button;
      AoL::Gui::GUITypeId	_type;
    };   
  }
}

#endif //BUTTONHOLDER_HPP_
