#include "Gui/EndGameInterface.hpp"

AoL::Gui::EndGameInterface::EndGameInterface()
{
  irr::core::vector2df         pos(60, 80);
  _modulesHolder.push_back(new ModuleHolder(L"EndGame", pos, 35, 15,
					    AoL::Gui::GUITypeId::M_ENDGAME));
  setModule(new EndGameModule(L"EndGame", "Assets/textures/endGame.png"));
  _modulesHolder[0]->lock();
}

AoL::Gui::EndGameInterface::~EndGameInterface()
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    delete _modulesHolder[i];
}

inline std::vector<AoL::Gui::ModuleHolder *>  	&AoL::Gui::EndGameInterface::getModulesHolder()
{
  return (_modulesHolder);
}

inline irr::u32			       	AoL::Gui::EndGameInterface::getNbModulesHolder() const
{
  return (_nbModulesHolder);
}

bool                              AoL::Gui::EndGameInterface::setButton(AoL::Gui::GUITypeId moduleType,
								     IButton *button)
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    {
      if (_modulesHolder[i]->getModule()
	  && _modulesHolder[i]->getModule()->getType() == moduleType)
	{
	  std::vector<ButtonHolder *> buttonsHolder = _modulesHolder[i]->getModule()->getButtonsHolder();
	  for (irr::u32 j = 0; j < buttonsHolder.size(); ++j)
	    {
	      if (buttonsHolder[j]->getType() == button->getId())
		{
		  buttonsHolder[j]->setButton(button);
		  return (true);
		}
	    }
	}
    }
  return (false);
}

inline bool		       		AoL::Gui::EndGameInterface::setModule(IModule *module)
{
  for (irr::u32 j = 0; j < _nbModulesHolder; ++j)
    {
      if (_modulesHolder[j]->getType() == module->getType())
	{
	  _modulesHolder[j]->setModule(module);
	  return (true);
	}
    }
  return (false);
}

bool                              AoL::Gui::EndGameInterface::setEventClick(AoL::Gui::GUITypeId moduleType,
									 AoL::Gui::GUITypeId buttonType,
									 std::function<void()> function)
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    {
      if (_modulesHolder[i]->getModule()
	  && _modulesHolder[i]->getModule()->getType() == moduleType)
	{
	  std::vector<ButtonHolder *> buttonsHolder = _modulesHolder[i]->getModule()->getButtonsHolder();
	  for (irr::u32 j = 0; j < buttonsHolder.size(); ++j)
	    {
	      if (buttonsHolder[j]->getType() == buttonType)
		{
		  buttonsHolder[j]->getButton()->setEventClick(function);
		  return (true);
		}
	    }
	}
    }
  return (false);
}

bool                              AoL::Gui::EndGameInterface::setEventShow(AoL::Gui::GUITypeId moduleType,
									AoL::Gui::GUITypeId buttonType,
									std::function<void()> function)
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    {
      if (_modulesHolder[i]->getModule()
	  && _modulesHolder[i]->getModule()->getType() == moduleType)
	{
	  std::vector<ButtonHolder *> buttonsHolder = _modulesHolder[i]->getModule()->getButtonsHolder();
	  for (irr::u32 j = 0; j < buttonsHolder.size(); ++j)
	    {
	      if (buttonsHolder[j]->getType() == buttonType)
		{
		  buttonsHolder[j]->getButton()->setEventShow(function);
		  return (true);
		}
	    }
	}
    }
  return (false);
}

void                              AoL::Gui::EndGameInterface::executeFunctionClick(AoL::Gui::GUITypeId moduleType,
										AoL::Gui::GUITypeId buttonType)
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    {
      if (_modulesHolder[i]->getModule()
	  && _modulesHolder[i]->getModule()->getType() == moduleType)
	{
	  std::vector<ButtonHolder *> buttonsHolder = _modulesHolder[i]->getModule()->getButtonsHolder();
	  for (irr::u32 j = 0; j < buttonsHolder.size(); ++j)
	    {
	      if (buttonsHolder[j]->getType() == buttonType)
		{
		  std::function<void()> function= buttonsHolder[j]->getButton()->getEventClick();
		  if (function != nullptr)
		    function();
		  return ;
		}
	    }
	}
    }
}

void                              AoL::Gui::EndGameInterface::executeFunctionShow(AoL::Gui::GUITypeId moduleType,
									       AoL::Gui::GUITypeId buttonType)
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    {
      if (_modulesHolder[i]->getModule()
	  && _modulesHolder[i]->getModule()->getType() == moduleType)
	{
	  std::vector<ButtonHolder *> buttonsHolder = _modulesHolder[i]->getModule()->getButtonsHolder();
	  for (irr::u32 j = 0; j < buttonsHolder.size(); ++j)
	    {
	      if (buttonsHolder[j]->getType() == buttonType)
		{
		  std::function<void()> function= buttonsHolder[j]->getButton()->getEventShow();
		  if (function != nullptr)
		    function();
		  return ;
		}
	    }
	}
    }
}

void					AoL::Gui::EndGameInterface::dump() const
{
  // std::cout << "===== MENU INTERFACE =====" << std::endl << std::endl;
  // for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
  //   {
  //     if (_modulesHolder[i])
  // 	_modulesHolder[i]->dump();
  //     else
  // 	std::cout << "=====EMPTY=====" << std::endl;
  //     std::cout << std::endl;
  //   }
}
