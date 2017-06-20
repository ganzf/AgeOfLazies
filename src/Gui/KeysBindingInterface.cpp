#include "Gui/KeysBindingInterface.hpp"

AoL::Gui::KeysBindingInterface::KeysBindingInterface()
{
  irr::core::vector2df         pos(30, 10);
  _modulesHolder.push_back(new ModuleHolder(L"KeysBinding", pos, 40, 80,
					    AoL::Gui::GUITypeId::M_KEYSBINDING));
  setModule(new KeysBindingModule(L"KeysBinding", "Assets/textures/Scroll.png"));
  _modulesHolder[0]->lock();

  
  irr::core::vector2df         pos1(40, 30);
  _modulesHolder.push_back(new ModuleHolder(L"KeysBinding", pos1, 20, 20,
					    AoL::Gui::GUITypeId::M_PRESSKEY));
  setModule(new PressKeyModule(L"PressKey", "Assets/textures/endGame.png"));
  _modulesHolder[1]->lock();
}

AoL::Gui::KeysBindingInterface::~KeysBindingInterface()
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    delete _modulesHolder[i];
}

inline std::vector<AoL::Gui::ModuleHolder *>  	&AoL::Gui::KeysBindingInterface::getModulesHolder()
{
  return (_modulesHolder);
}

inline irr::u32			       	AoL::Gui::KeysBindingInterface::getNbModulesHolder() const
{
  return (_nbModulesHolder);
}

bool                              AoL::Gui::KeysBindingInterface::setButton(AoL::Gui::GUITypeId moduleType,
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

inline bool		       		AoL::Gui::KeysBindingInterface::setModule(IModule *module)
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

bool                              AoL::Gui::KeysBindingInterface::setEventClick(AoL::Gui::GUITypeId moduleType,
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

bool                              AoL::Gui::KeysBindingInterface::setEventShow(AoL::Gui::GUITypeId moduleType,
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

void                              AoL::Gui::KeysBindingInterface::executeFunctionClick(AoL::Gui::GUITypeId moduleType,
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

void                              AoL::Gui::KeysBindingInterface::executeFunctionShow(AoL::Gui::GUITypeId moduleType,
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

void					AoL::Gui::KeysBindingInterface::dump() const
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
