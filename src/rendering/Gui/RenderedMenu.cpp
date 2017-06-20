#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedMenu.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedMenu::RenderedMenu(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  this->setTitle(moduleHolder->getModule()->getButtonsHolder()[0]);
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedMenu::~RenderedMenu()
{}

void					AoL::rendering::RenderedMenu::setTitle(AoL::Gui::ButtonHolder *buttonHolder)
{
  AoL::rendering::RenderedTextButton	title(*this, buttonHolder);
  title.setColor(RED);
}

void		AoL::rendering::RenderedMenu::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (irr::u32 i = 1; i < buttonHolder.size(); i++)
    this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedMenu::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      this->_buttons[i]->callFunction();
}

