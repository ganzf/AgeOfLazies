#ifndef KEYSBINDINGINTERFACE_HPP_
# define KEYSBINDINGINTERFACE_HPP_

# include "IUserInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class KeysBindingInterface : public IUserInterface
    {
    public:
      KeysBindingInterface();
      virtual ~KeysBindingInterface();
      std::vector<ModuleHolder *>     	&getModulesHolder();
      irr::u32				getNbModulesHolder() const;
      bool	       			setButton(GUITypeId moduleId,
						  IButton *button);
      bool	       			setModule(IModule *module);
      bool                              setEventClick(AoL::Gui::GUITypeId moduleType,
						      AoL::Gui::GUITypeId buttonType,
						      std::function<void()> function);
      bool                              setEventShow(AoL::Gui::GUITypeId moduleType,
						     AoL::Gui::GUITypeId buttonType,
						     std::function<void()> function);
      void                              executeFunctionClick(GUITypeId moduleType,
							     GUITypeId buttonType);
      void                              executeFunctionShow(GUITypeId moduleType,
							    GUITypeId buttonType);
      void 				dump() const;

    protected:
      std::vector<ModuleHolder *>      	_modulesHolder;
      irr::u32				_nbModulesHolder = 2;
    };
  }
}

#endif //KEYSBINDINGINTERFACE_HPP_
