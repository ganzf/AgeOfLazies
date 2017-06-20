#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedEndGame.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedEndGame::RenderedEndGame(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedEndGame::~RenderedEndGame()
{}

void		AoL::rendering::RenderedEndGame::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (irr::u32 i = 0; i < buttonHolder.size(); i++)
    this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedEndGame::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      this->_buttons[i]->callFunction();
}

