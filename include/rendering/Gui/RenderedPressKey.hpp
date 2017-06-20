#ifndef RENDEREDKEYPRESS_HPP_
# define RENDEREDKEYPRESS_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedPressKey : public ARenderedModule
    {
    public:
      RenderedPressKey(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      ~RenderedPressKey();

    public:
      void		setButtons(AoL::Gui::IModule *module);
      void		setTitle(AoL::Gui::ButtonHolder *buttonHolder);
      void		verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId);
      void		draw();

    private:
      std::vector<AoL::rendering::ARenderedElement *>			_buttons;
      AoL::Gui::ModuleHolder						*_moduleHolder;
    };
  }
}

#endif //RENDEREDKEYPRESS_HPP_
