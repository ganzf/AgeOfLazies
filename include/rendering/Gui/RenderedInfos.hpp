#ifndef RENDERED_INFOS_HPP_
# define RENDERED_INFOS_HPP_

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
    class RenderedInfos : public ARenderedModule
    {
    public:
      RenderedInfos(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder, AoL::Game::Entity *entity);
      ~RenderedInfos();

    public:
      void		setButtons(AoL::Gui::IModule *module);
      void		verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId);
      void		setEntity(AoL::Game::Entity *player);
      void		draw();
      void		setVisible(bool visible);
      void		setHPLife();
      void		setXP();
      void		setButtonVisibleById(AoL::Gui::GUITypeId id, bool visible);

    private:
      void		setButtonTextForType(std::vector<AoL::rendering::ARenderedElement *>::iterator it);

      std::vector<AoL::rendering::ARenderedElement *>::iterator
	findButtonById(AoL::Gui::GUITypeId id);

      void	writeTeam();

    private:
      AoL::Game::Entity					*_inspectedEntity;
      std::vector<AoL::rendering::ARenderedElement *>	_buttons;
    };
  }
}

#endif // RENDERED_STATS_HPP_
