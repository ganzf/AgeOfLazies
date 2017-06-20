#ifndef RENDEREDBARBUTTON_HPP_
# define RENDEREDBARBUTTON_HPP_

# include "rendering/Gui/ARenderedElement.hpp"

namespace AoL
{
  namespace Game
  {
    class	Entity;
  }
  namespace rendering
  {
    class RenderedBarButton : public ARenderedElement
    {
    public:
      RenderedBarButton(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder, AoL::Game::Entity *entity);
      virtual ~RenderedBarButton();

    public:
      void		setElement(AoL::rendering::ARenderedModule &, AoL::Gui::ButtonHolder *)
      {}
      virtual void		setEntity(AoL::Game::Entity *) {}
      virtual void	draw(AoL::rendering::Gui &) {}
      virtual irr::s32	getValue () { std::cout << "Je rentre ici, c'est chiant" << std::endl; return (0); }

    protected:
      AoL::Game::Entity			*_inspectedEntity;
      AoL::rendering::ARenderedModule 	&_moduleParent;
      irr::core::rect<irr::s32>		_destRect;
      irr::core::rect<irr::s32>		_originRect;
      irr::s32				_maxVal;
      irr::s32				_actualVal;
    };
  }
}

#endif
