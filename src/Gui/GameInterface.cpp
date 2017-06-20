#include "Gui/GameInterface.hpp"

AoL::Gui::GameInterface::GameInterface()
{
  irr::core::vector2df  pos(0, 0);
  _modulesHolder.push_back(new ModuleHolder(L"Stat", pos, 100, 5,
					    AoL::Gui::GUITypeId::M_STAT));
  setModule(new StatModule(L"Stat", "Assets/textures/statMenu.jpg"));
  _modulesHolder[0]->lock();

  pos.Y = 75;
  _modulesHolder.push_back(new ModuleHolder(L"Action", pos, 23, 25,
					    AoL::Gui::GUITypeId::M_ACTION));
  setModule(new ActionModule(L"Action", "Assets/textures/actionMenu.png"));
  _modulesHolder[1]->lock();

  pos.X = 23;
  _modulesHolder.push_back(new ModuleHolder(L"Info", pos, 77, 25,
					    AoL::Gui::GUITypeId::M_INFO));
  setModule(new InfoModule(L"Info", "Assets/textures/infoMenu.png"));
  _modulesHolder[2]->lock();

  pos.X = 77;
  _modulesHolder.push_back(new ModuleHolder(L"Map", pos, 23, 25,
					    AoL::Gui::GUITypeId::M_MAP));
  setModule(new MapModule(L"Map", "Assets/textures/mapMenu.png"));
  _modulesHolder[3]->lock();

  pos.X = 30;
  pos.Y = 5;
  _modulesHolder.push_back(new ModuleHolder(L"Pause", pos, 40, 95,
					    AoL::Gui::GUITypeId::M_PAUSE));
  setModule(new PauseModule(L"Pause", "Assets/textures/Scroll.png"));
  _modulesHolder[3]->lock();

  _modulesHolder.push_back(new ModuleHolder(L"Option", pos, 40, 95,
					    AoL::Gui::GUITypeId::M_OPTION));
  OptionModule *Option = new OptionModule(L"Option", "Assets/textures/Scroll.png");
  Option->hide();
  setModule(Option);
  _modulesHolder[4]->lock();

  _modulesHolder.push_back(new ModuleHolder(L"KeysBinding", pos, 40, 95,
					    AoL::Gui::GUITypeId::M_KEYSBINDING));

  KeysBindingModule *Keys = new KeysBindingModule(L"KeysBinding", "Assets/textures/Scroll.png");
  Keys->hide();
  setModule(Keys);
  _modulesHolder[5]->lock();

  pos.X = 5;
  pos.Y = 5;
  _modulesHolder.push_back(new ModuleHolder(L"Encyclolazy", pos, 90, 90,
					    AoL::Gui::GUITypeId::M_ENCYCLO));
  setModule(new EncyclopedieModule(L"Encyclopedie", "Assets/textures/Scroll.png"));
  _modulesHolder[6]->lock();
}

AoL::Gui::GameInterface::~GameInterface()
{
  for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
    delete _modulesHolder[i];
}

inline std::vector<AoL::Gui::ModuleHolder *>  	&AoL::Gui::GameInterface::getModulesHolder()
{
  return (_modulesHolder);
}

inline irr::u32			       	AoL::Gui::GameInterface::getNbModulesHolder() const
{
  return (_nbModulesHolder);
}

bool                              AoL::Gui::GameInterface::setButton(AoL::Gui::GUITypeId moduleType,
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

inline bool                             AoL::Gui::GameInterface::setModule(IModule *module)
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

bool                              AoL::Gui::GameInterface::setEventClick(AoL::Gui::GUITypeId moduleType,
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

bool                              AoL::Gui::GameInterface::setEventShow(AoL::Gui::GUITypeId moduleType,
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

void                              AoL::Gui::GameInterface::executeFunctionClick(AoL::Gui::GUITypeId moduleType,
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

void                              AoL::Gui::GameInterface::executeFunctionShow(AoL::Gui::GUITypeId moduleType,
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

void					AoL::Gui::GameInterface::dump() const
{
  // std::cout << "===== GAME INTERFACE =====" << std::endl << std::endl;
  // for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
  //   {
  //     if (_modulesHolder[i])
  // 	_modulesHolder[i]->dump();
  //     else
  // 	std::cout << "=====EMPTY=====" << std::endl;
  //     std::cout << std::endl;
  //   }
}
