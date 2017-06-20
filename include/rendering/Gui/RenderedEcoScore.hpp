#ifndef RENDEREDECOSCORE_HPP_
# define RENDEREDECOSCORE_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedEcoScore : public ARenderedModule
    {
    public:
      RenderedEcoScore(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      ~RenderedEcoScore();

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

#endif //RENDEREDECOSCORE_HPP_
