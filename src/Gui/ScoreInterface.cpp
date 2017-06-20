#include "Gui/ScoreInterface.hpp"

AoL::Gui::ScoreInterface::ScoreInterface()
{
  irr::core::vector2df         pos(10, 10);
  _modulesHolder.push_back(new ModuleHolder(L"General Score", pos, 80, 80,
					    AoL::Gui::GUITypeId::M_GENERAL_SCORE));
  setModule(new GeneralScoreModule(L"Score General", "Assets/textures/Scroll.png"));
  _modulesHolder[0]->lock();

  _modulesHolder.push_back(new ModuleHolder(L"Economic Score", pos, 80, 80,
					    AoL::Gui::GUITypeId::M_ECO_SCORE));
  setModule(new EcoScoreModule(L"Economic Score", "Assets/textures/Scroll.png"));
  _modulesHolder[1]->lock();

  _modulesHolder.push_back(new ModuleHolder(L"Fight Score", pos, 80, 80,
					    AoL::Gui::GUITypeId::M_FIGHT_SCORE));
  setModule(new FightScoreModule(L"Fight Score", "Assets/textures/Scroll.png"));
  _modulesHolder[2]->lock();

  _modulesHolder.push_back(new ModuleHolder(L"Lazy Score", pos, 80, 80,
					    AoL::Gui::GUITypeId::M_LAZY_SCORE));
  setModule(new LazyScoreModule(L"Lazy Score", "Assets/textures/Scroll.png"));
  _modulesHolder[3]->lock();
}

AoL::Gui::ScoreInterface::~ScoreInterface()
{
  // for (irr::u32 i = 0; i < _nbModulesHolder; ++i)
  //   delete _modulesHolder[i];
}

inline std::vector<AoL::Gui::ModuleHolder *>  	&AoL::Gui::ScoreInterface::getModulesHolder()
{
  return (_modulesHolder);
}

inline irr::u32			       	AoL::Gui::ScoreInterface::getNbModulesHolder() const
{
  return (_nbModulesHolder);
}

bool                              AoL::Gui::ScoreInterface::setButton(AoL::Gui::GUITypeId moduleType,
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

inline bool		       		AoL::Gui::ScoreInterface::setModule(IModule *module)
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

bool                              AoL::Gui::ScoreInterface::setEventClick(AoL::Gui::GUITypeId moduleType,
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

bool                              AoL::Gui::ScoreInterface::setEventShow(AoL::Gui::GUITypeId moduleType,
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

void                              AoL::Gui::ScoreInterface::executeFunctionClick(AoL::Gui::GUITypeId moduleType,
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

void                              AoL::Gui::ScoreInterface::executeFunctionShow(AoL::Gui::GUITypeId moduleType,
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

void					AoL::Gui::ScoreInterface::dump() const
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
