#ifndef RENDEREDENDGAME_HPP_
# define RENDEREDENDGAME_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedEndGame : public ARenderedModule
    {
    public:
      RenderedEndGame(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      ~RenderedEndGame();

    public:
      void		setButtons(AoL::Gui::IModule *module);
      void		setTitle(AoL::Gui::ButtonHolder *buttonHolder);
      void		verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId);

    private:
     std::vector<AoL::rendering::ARenderedElement *>			_buttons;
    };
  }
}

#endif //RENDEREDENDGAME_HPP_
