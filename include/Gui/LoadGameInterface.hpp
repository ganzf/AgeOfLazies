#ifndef LOADGAMEINTERFACE_HPP_
# define LOADGAMEINTERFACE_HPP_

# include "IUserInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class LoadGameInterface : public IUserInterface
    {
    public:
      LoadGameInterface();
      virtual ~LoadGameInterface();
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
      irr::u32				_nbModulesHolder = 1;
    };
  }
}

#endif //LOADGAMEINTERFACE_HPP_
