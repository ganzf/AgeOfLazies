#ifndef RENDERED_ACTIONS_HPP_
# define RENDERED_ACTIONS_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace Game
  {
    class Entity;
  }
  namespace rendering
  {
    class RenderedActions : public ARenderedModule
    {
    public:
      RenderedActions(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder, AoL::Game::Entity *entity);
      ~RenderedActions();

    public:
      void		setButtons(AoL::Gui::IModule *module);
      void		verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId);
      void		setEntity(AoL::Game::Entity *player);
      void		draw();
      void		setVisible(bool visible);
      void		updateButtons();

    private:
     AoL::Game::Entity				*_inspectedEntity;
     std::vector<AoL::rendering::ARenderedElement *>	_buttons;
    };
  }
}

#endif // RENDERED_ACTION_HPP_

