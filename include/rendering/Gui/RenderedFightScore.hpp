#ifndef RENDEREDFIGHTSCORE_HPP_
# define RENDEREDFIGHTSCORE_HPP_

# include <vector>
# include "rendering/Gui/ARenderedModule.hpp"

namespace AoL
{
  namespace rendering
  {
    class RenderedFightScore : public ARenderedModule
    {
    public:
      RenderedFightScore(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      ~RenderedFightScore();

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

#endif //RENDEREDFIGHTSCORE_HPP_
