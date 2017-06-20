#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedEcoScore.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedEcoScore::RenderedEcoScore(AoL::rendering::Gui &gui,
						 AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  _moduleHolder = moduleHolder;
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedEcoScore::~RenderedEcoScore()
{}

void		AoL::rendering::RenderedEcoScore::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  AoL::rendering::RenderedTextButton	*title;
  title = new AoL::rendering::RenderedTextButton(*this, buttonHolder[0]);
  title->setColor(RED);
  this->_buttons.push_back(title);
  for (irr::u32 i = 1; i < buttonHolder.size(); i++)
    {
      if (i >= buttonHolder.size() - 3)
	this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
      else
	{
	  AoL::rendering::RenderedTextButton    *text;
	  text = new AoL::rendering::RenderedTextButton(*this, buttonHolder[i]);
	  text->setColor(BLACK);
	  this->_buttons.push_back(text);
	}
    }
}

void		AoL::rendering::RenderedEcoScore::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      this->_buttons[i]->callFunction();
}

void		AoL::rendering::RenderedEcoScore::draw()
{
  setVisible(!_moduleHolder->getModule()->isHide());
  for (irr::u32 j = 0; j < this->_buttons.size(); j++)
    _buttons[j]->setVisible(!_moduleHolder->getModule()->isHide());
}
