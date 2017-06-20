#ifndef RENDERED_XP_BAR_HPP_
# define RENDERED_XP_BAR_HPP_

# include "rendering/Gui/RenderedBarButton.hpp"

namespace AoL
{
  namespace Game
  {
    class	Entity;
  }
  namespace rendering
  {
    class RenderedXPBar : public RenderedBarButton
    {
    public:
      RenderedXPBar(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder, AoL::Game::Entity *entity);
      ~RenderedXPBar();

    public:
      void		setElement(AoL::rendering::ARenderedModule &, AoL::Gui::ButtonHolder *)
      {}
      void		setEntity(AoL::Game::Entity *entity);
      void		draw(AoL::rendering::Gui &gui);
      irr::s32		getValue () { return (this->_actualVal); }

    };
  }
}

#endif


