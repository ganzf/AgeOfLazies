#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedNewGame.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedNewGame::RenderedNewGame(AoL::rendering::Gui &gui,
						 AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  _moduleHolder = moduleHolder;
  this->setTitle(moduleHolder->getModule()->getButtonsHolder()[0]);
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedNewGame::~RenderedNewGame()
{}

void					AoL::rendering::RenderedNewGame::setTitle(AoL::Gui::ButtonHolder *buttonHolder)
{
  AoL::rendering::RenderedTextButton	title(*this, buttonHolder);
  title.setColor(RED);
}

void		AoL::rendering::RenderedNewGame::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (irr::u32 i = 1; i < buttonHolder.size(); i++)
    this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedNewGame::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      this->_buttons[i]->callFunction();
}

void		AoL::rendering::RenderedNewGame::draw()
{
  auto buttons = _moduleHolder->getModule()->getButtonsHolder();

  for (irr::u32 i = 1; i < buttons.size(); i++)
    {
      for (irr::u32 j = 0; j < this->_buttons.size(); j++)
	{
	  if (_buttons[j]->getType() == buttons[i]->getType())
	    _buttons[j]->modifyText(buttons[i]->getButton()->getText());
	}
    }
}
