#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedLoadGame.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedSimpleButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedLoadGame::RenderedLoadGame(AoL::rendering::Gui &gui,
						 AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  _moduleHolder = moduleHolder;
  this->setTitle(moduleHolder->getModule()->getButtonsHolder()[0]);
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedLoadGame::~RenderedLoadGame()
{}

void					AoL::rendering::RenderedLoadGame::setTitle(AoL::Gui::ButtonHolder *buttonHolder)
{
  AoL::rendering::RenderedTextButton	title(*this, buttonHolder);
  title.setColor(RED);
}

void		AoL::rendering::RenderedLoadGame::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (irr::u32 i = 1; i < buttonHolder.size(); i++)
    {
      if (i == 2)
	this->_buttons.push_back(new RenderedSimpleButton(*this, buttonHolder[i]));
      else
	this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
    }
}

void		AoL::rendering::RenderedLoadGame::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      {
	this->_buttons[i]->callFunction();
	auto buttons = _moduleHolder->getModule()->getButtonsHolder();
	_buttons[3]->modifyText(buttons[4]->getButton()->getText());
	_buttons[1]->setFirstImage(*this, buttons[2]->getButton()->getPicturePath()); 
      }
}

void		AoL::rendering::RenderedLoadGame::draw()
{

}
