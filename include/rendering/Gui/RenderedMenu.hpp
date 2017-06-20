#ifndef RENDEREDMENU_HPP_
# define RENDEREDMENU_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedMenu : public ARenderedModule
    {
    public:
      RenderedMenu(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      ~RenderedMenu();

    public:
      void		setButtons(AoL::Gui::IModule *module);
      void		setTitle(AoL::Gui::ButtonHolder *buttonHolder);
      void		verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId);

    private:
     std::vector<AoL::rendering::ARenderedElement *>			_buttons;
    };
  }
}

#endif //RENDEREDMENU_HPP_
