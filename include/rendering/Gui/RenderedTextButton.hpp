#ifndef RENDERED_TEXT_BUTTON_HPP_
# define RENDERED_TEXT_BUTTON_HPP_

# include "irrlicht/irrlicht.h"
# include "rendering/Gui/ARenderedElement.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedTextButton : public ARenderedElement
    {
      public:
	RenderedTextButton(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder);
	~RenderedTextButton();

      public:
	void	setElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder);
	void	setColor(irr::video::SColor const &color);

      private:
	irr::gui::IGUIStaticText	*_text;
    };

  }

}


#endif
