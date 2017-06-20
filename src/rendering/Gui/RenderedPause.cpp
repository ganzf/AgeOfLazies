#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedPause.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedPause::RenderedPause(AoL::rendering::Gui &gui,
						 AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  _moduleHolder = moduleHolder;
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedPause::~RenderedPause()
{}

void		AoL::rendering::RenderedPause::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();
  AoL::rendering::RenderedTextButton    *title;

  title = new AoL::rendering::RenderedTextButton(*this, buttonHolder[0]);
  title->setColor(RED);
  this->_buttons.push_back(title);
  for (irr::u32 i = 1; i < buttonHolder.size(); i++)
    this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedPause::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    {
      if (this->_buttons[i]->getType() == functionId)
	this->_buttons[i]->callFunction();
    }
}

void		AoL::rendering::RenderedPause::draw()
{
  setVisible(!_moduleHolder->getModule()->isHide());
  for (irr::u32 j = 0; j < this->_buttons.size(); j++)
    _buttons[j]->setVisible(!_moduleHolder->getModule()->isHide());
}
