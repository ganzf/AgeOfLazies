#ifndef RENDEREDKEYSBINDING_HPP_
# define RENDEREDKEYSBINDING_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedKeysBinding : public ARenderedModule
    {
    public:
      RenderedKeysBinding(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      ~RenderedKeysBinding();

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

#endif //RENDEREDKEYSBINDING_HPP_
