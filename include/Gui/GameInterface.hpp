#ifndef GAMEINTERFACE_HPP_
# define GAMEINTERFACE_HPP_
  
# include "IUserInterface.hpp"

namespace AoL
{
  namespace Gui
  {
    /*
    ** ================================================================================
    ** |                                                                              |
    ** |                                  GAME INTERFACE                              |
    ** |                                                                              |
    ** ================================================================================
    ** | ========== ========== ============                               ==========  |
    ** | | 0 Wood | | 1 Food | | 2 People |        AGE OF LAZIES          | 3 Menu |  |
    ** | ========== ========== ============                               ==========  |
    ** |==============================================================================|
    ** |                              0 MODULE STATISTIQUE                            |
    ** |                                 ModuleType::STAT                             |
    ** |                                                                              |
    ** |                                                                              |
    ** |                                                                              |
    ** |                             =========================                        |
    ** |                             |                       |   (DEFAULT EMPTY)      |
    ** |                             |                       |   4 MODULE PAUSE       |
    ** |                             |                       |  ModuleType::PAUSE     |
    ** |                             |                       |                        |
    ** |                             =========================                        |
    ** |                                                                              |
    ** |                                                                              |
    ** |   (DEFAULT EMPTY)              (DEFAULT EMPTY)                               |
    ** |   1 MODULE ACTION           2 MODULE INFORMATION            3 MODULE MAP     |
    ** |  ModuleType::ACTION           ModuleType::INFO             ModuleType::MAP   |
    ** |==============================================================================|
    ** | ====  ==== ==== ==== | ============  ================= | =================== |
    ** | |00|  |01| |02| |03| | | 0 Attack |  |               | | |                 | |
    ** | ====  ==== ==== ==== | ============  |   2 Picture   | | |      0 Map      | |
    ** | ====  ==== ==== ==== | ============  |               | | |                 | |
    ** | |04|  |05| |06| |07| | | 1 Health |  |               | | |                 | |
    ** | ====  ==== ==== ==== | ============  ================= | =================== |
    ** ================================================================================
    */

    class GameInterface : public IUserInterface
    {
    public:
      GameInterface();
      virtual ~GameInterface();
      std::vector<ModuleHolder *>     	&getModulesHolder();
      irr::u32				getNbModulesHolder() const;
      bool	       			setButton(AoL::Gui::GUITypeId moduleId,
						  IButton *button);
      bool	       			setEventClick(AoL::Gui::GUITypeId moduleId,
						      AoL::Gui::GUITypeId buttonId,
						      std::function<void()> function);
      bool	       			setEventShow(AoL::Gui::GUITypeId moduleId,
						     AoL::Gui::GUITypeId buttonId,
						     std::function<void()> function);
      bool	       			setModule(IModule *module);
      void                              executeFunctionClick(AoL::Gui::GUITypeId moduleId,
							     AoL::Gui::GUITypeId buttonId);
      void                              executeFunctionShow(AoL::Gui::GUITypeId moduleId,
							     AoL::Gui::GUITypeId buttonId);
      void 				dump() const;

    protected:
      std::vector<ModuleHolder *>      	_modulesHolder;
      irr::u32				_nbModulesHolder = 8;
    };
  }
}

#endif //GAMEINTERFACE_HPP_
