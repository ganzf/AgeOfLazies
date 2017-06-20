#include <vector>
#include <unordered_map>
#include "Game/Ressources/Ressource.hpp"
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedActions.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"
#include "Game/Units/Collector.hpp"
#include "Game/Buildings/Forum.hpp"

AoL::rendering::RenderedActions::RenderedActions(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder, AoL::Game::Entity *entity)
  : ARenderedModule(gui, moduleHolder)
{
  this->setButtons(moduleHolder->getModule());
  this->setEntity(entity);
  this->_backgrImage->setVisible(true);
}

AoL::rendering::RenderedActions::~RenderedActions()
{}

void		AoL::rendering::RenderedActions::setButtons(AoL::Gui::IModule *module)
{
  irr::u32	i = 0;
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (i = 0; i < buttonHolder.size(); i++)
    this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedActions::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      this->_buttons[i]->callFunction();
}

void		AoL::rendering::RenderedActions::setEntity(AoL::Game::Entity *entity)
{
  this->_inspectedEntity = entity;
  this->updateButtons();
}

void		AoL::rendering::RenderedActions::updateButtons()
{
  if (this->_inspectedEntity != nullptr)
  {
    auto controlled = dynamic_cast<AoL::Game::Controlled *>(this->_inspectedEntity);
    if (!controlled)
      return ;
    if (controlled != nullptr)
    {
      irr::u32 i = 0;
      auto actions = controlled->getActions().begin();
      for (i = 0; i < controlled->getActions().size(); i++)
      {
	this->_buttons[i]->setFirstImage(*this, actions->first);
	this->_buttons[i]->setFunction(actions->second);
	this->_buttons[i]->setVisible(true);
	this->_buttons[i]->modifyText(L"");
	actions++;
      }
      for (; i < this->_buttons.size(); i++)
	this->_buttons[i]->setVisible(false);
    }
  }
  else
    this->setVisible(false);
}

void		AoL::rendering::RenderedActions::draw()
{
}

void		AoL::rendering::RenderedActions::setVisible(bool visible)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    this->_buttons[i]->setVisible(visible);
}
