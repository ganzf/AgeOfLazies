#ifndef ARENDEREDMODULE_HPP_
# define ARENDEREDMODULE_HPP_

# include <unordered_map>
# include "irrlicht/irrlicht.h"
# include "Gui/GuiId.hpp"
# include "rendering/Gui/ARenderedElement.hpp"
# include "rendering/Gui/InfoGetter.hpp"

namespace AoL
{
  namespace Gui
  {
    class	ModuleHolder;
    class	IModule;
  }
  namespace rendering
  {
    class	Gui;

    class ARenderedModule
    {
    public:
      ARenderedModule(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder);
      virtual ~ARenderedModule();

      // Getters
    public:
      AoL::Gui::GUITypeId				getType() const
      { return (this->_moduleType); }
      AoL::rendering::Gui	 			&getGUI()
      { return (this->_gui); }
      irr::gui::IGUIImage				*getParentElement()
      { return (this->_backgrImage); }
      AoL::rendering::elementInformationGetter const	&getInfo()
      { return (this->_moduleInfo); }

      // Setters
    public:
      void	setImageFromPath(AoL::Gui::ModuleHolder *moduleHolder, std::string const &path);

      // Virtual functions
    public:
      virtual void	draw() {}
      virtual void	setVisible(bool visible)
      { this->_backgrImage->setVisible(visible); }
      virtual void	verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId) = 0;

    protected:
      AoL::rendering::Gui	&_gui;

    protected:
      AoL::rendering::elementInformationGetter	_moduleInfo;
      AoL::Gui::GUITypeId			_moduleType;
      irr::gui::IGUIImage			*_backgrImage;
    };
  }
}

#endif //ARENDEREDMODULE_HPP_
