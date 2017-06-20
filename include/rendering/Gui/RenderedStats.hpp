#ifndef RENDERED_STATS_HPP_
# define RENDERED_STATS_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace Game
  {
    class Player;
  }
  namespace rendering
  {
    class RenderedStats : public ARenderedModule
    {
    public:
      RenderedStats(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder, AoL::Game::Player *player);
      ~RenderedStats();

    public:
      void		setButtons(AoL::Gui::IModule *module);
      void		verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId);
      void		setPlayer(AoL::Game::Player *player);
      void		draw();

    private:
      void		setButtonTextForType(std::vector<AoL::rendering::ARenderedElement *>::iterator it);

      void		setButtonTextForPeople(std::vector<AoL::rendering::ARenderedElement *>::iterator it);

      void		setTimer(std::vector<AoL::rendering::ARenderedElement *>::iterator it);
      std::vector<AoL::rendering::ARenderedElement *>::iterator
	findButtonById(AoL::Gui::GUITypeId id);

    private:
     AoL::Game::Player					*_inspectedPlayer;
     std::vector<AoL::rendering::ARenderedElement *>	_buttons;
    };
  }
}

#endif // RENDERED_STATS_HPP_
