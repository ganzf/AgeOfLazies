#ifndef RENDERED_HP_LIFE_HPP_
# define RENDERED_HP_LIFE_HPP_

# include "rendering/Gui/RenderedBarButton.hpp"

namespace AoL
{
  namespace Game
  {
    class	Entity;
  }
  namespace rendering
  {
    class RenderedHPLife : public RenderedBarButton
    {
    public:
      RenderedHPLife(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder, AoL::Game::Entity *entity);
      ~RenderedHPLife();

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

