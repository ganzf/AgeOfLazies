#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedPressKey.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedPressKey::RenderedPressKey(AoL::rendering::Gui &gui,
						 AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  _moduleHolder = moduleHolder;
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedPressKey::~RenderedPressKey()
{}

void		AoL::rendering::RenderedPressKey::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (irr::u32 i = 0; i < buttonHolder.size(); i++)
    this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedPressKey::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      this->_buttons[i]->callFunction();
}

void		AoL::rendering::RenderedPressKey::draw()
{
  setVisible(!_moduleHolder->getModule()->isHide());
  for (irr::u32 j = 0; j < this->_buttons.size(); j++)
    _buttons[j]->setVisible(!_moduleHolder->getModule()->isHide());
}
