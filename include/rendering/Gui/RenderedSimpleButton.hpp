#ifndef RENDEREDSIMPLEBUTTON_HPP_
# define RENDEREDSIMPLEBUTTON_HPP_

# include "rendering/Gui/ARenderedElement.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedSimpleButton : public ARenderedElement
    {
    public:
      RenderedSimpleButton(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder);
      ~RenderedSimpleButton();

    public:
      void	setElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder);
      void			setFirstImage(AoL::rendering::ARenderedModule &moduleParent, std::string const &path);

    private:
      irr::gui::IGUIButton		*_button;
    };
  }
}

#endif

