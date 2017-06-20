#ifndef SCOREINTERFACE_HPP_
# define SCOREINTERFACE_HPP_

# include "IUserInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    class ScoreInterface : public IUserInterface
    {
    public:
      ScoreInterface();
      virtual ~ScoreInterface();
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
      irr::u32				_nbModulesHolder = 4;
    };
  }
}

#endif //SCOREINTERFACE_HPP_
