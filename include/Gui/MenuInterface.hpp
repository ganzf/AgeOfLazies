#ifndef MENUINTERFACE_HPP_
# define MENUINTERFACE_HPP_

# include "IUserInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    /*                                                                              
    ** =========================================                                    
    ** |                                       |                                    
    ** |             MENU INTERFACE            |                                    
    ** |                                       |                                    
    ** =========================================                                    
    ** |            0 MODULE MENU              |                                    
    ** |           GUITypeId:M_MENU            |                                    
    ** |  ===================================  |                                    
    ** |  |                                 |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |    |    Button New Game     |   |  |                                    
    ** |  |    |  GUITypeId::B_NEWGAME  |   |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |                                 |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |    |    Button Load Game    |   |  |                                    
    ** |  |    |  GUITypeId::B_LOADGAME |   |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |                                 |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |    |      Button Option     |   |  |                                    
    ** |  |    |   GUITypeId::B_OPTION  |   |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |                                 |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |    |      Button Quit       |   |  |                                    
    ** |  |    |   GUITypeId::B_QUIT    |   |  |                                    
    ** |  |    ==========================   |  |                                    
    ** |  |                                 |  |                                    
    ** |  ===================================  |                                    
    ** |                                       |                                    
    ** =========================================                                    
    */
    
    class MenuInterface : public IUserInterface
    {
    public:
      MenuInterface();
      virtual ~MenuInterface();
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

#endif //MENUINTERFACE_HPP_
