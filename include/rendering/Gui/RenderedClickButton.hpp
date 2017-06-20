#ifndef RENDEREDCLICKBUTTON_HPP_
# define RENDEREDCLICKBUTTON_HPP_

# include "rendering/Gui/ARenderedElement.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedClickButton : public ARenderedElement
    {
    public:
      RenderedClickButton(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder);
      ~RenderedClickButton();

    public:
      void	setElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder);
      void			callFunction();
      void			setFunction(std::function<void()> const &function);
      void			setFirstImage(AoL::rendering::ARenderedModule &moduleParent, std::string const &path);

    private:
      irr::gui::IGUIButton		*_button;
      std::function<void()>		_buttonFunction;
    };
  }
}

#endif
