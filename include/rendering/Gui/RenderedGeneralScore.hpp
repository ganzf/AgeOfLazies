#ifndef RENDEREDGENERALSCORE_HPP_
# define RENDEREDGENERALSCORE_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedGeneralScore : public ARenderedModule
    {
    public:
      RenderedGeneralScore(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      ~RenderedGeneralScore();

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

#endif //RENDEREDGENERALSCORE_HPP_
