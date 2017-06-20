#ifndef IUSERINTERFACE_HPP_
# define IUSERINTERFACE_HPP_

# include "Gui/ModuleHolder.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Gui
  {
    class	IUserInterface
    {
    public:
      virtual ~IUserInterface() {};
      virtual std::vector<ModuleHolder *>	&getModulesHolder() = 0;
      virtual irr::u32				getNbModulesHolder() const = 0;
      virtual bool				setButton(AoL::Gui::GUITypeId moduleId,
							  IButton *button) = 0;
      virtual bool				setModule(IModule *module) = 0;
      virtual bool                              setEventClick(AoL::Gui::GUITypeId moduleId,
							      AoL::Gui::GUITypeId buttonId,
							      std::function<void()> function) = 0;
      virtual bool                              setEventShow(AoL::Gui::GUITypeId moduleId,
							     AoL::Gui::GUITypeId buttonId,
							     std::function<void()> function) = 0;
      virtual void                              executeFunctionClick(AoL::Gui::GUITypeId moduleId,
								     AoL::Gui::GUITypeId buttonId) = 0;
      virtual void                              executeFunctionShow(AoL::Gui::GUITypeId moduleId,
								    AoL::Gui::GUITypeId buttonId) = 0;
    };
  }
}

#endif //IUSERINTERFACE_HPP_
