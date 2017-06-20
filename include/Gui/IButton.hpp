#ifndef IBUTTON_HPP_
# define IBUTTON_HPP_


# include <iostream>
# include <functional>
# include "GuiId.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Gui
  {
 
    class IButton
    {
    public:
      virtual ~IButton() {};
      virtual std::string const	&getPicturePath() const = 0;
      virtual void		setPicturePath(std::string const &picturePath) = 0;
      virtual std::string const	&getPicturePressedPath() const = 0;
      virtual std::wstring const	&getText() const = 0;
      virtual void			setText(std::wstring const &text) = 0;
      virtual AoL::Gui::GUITypeId      	getId() const = 0;
      virtual std::function<void()>	const &getEventClick() const = 0;
      virtual std::function<void()>	const &getEventShow() const = 0;
      virtual void			setEventClick(std::function<void()> eventClick) = 0;
      virtual void			setEventShow(std::function<void()> eventShow) = 0;
    };
  }
}

#endif //IBUTTON_HPP_
