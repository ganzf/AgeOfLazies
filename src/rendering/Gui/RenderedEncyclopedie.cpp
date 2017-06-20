#include <vector>
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedEncyclopedie.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedSimpleButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedEncyclopedie::RenderedEncyclopedie(AoL::rendering::Gui &gui,
						 AoL::Gui::ModuleHolder *moduleHolder)
  : ARenderedModule(gui, moduleHolder)
{
  _moduleHolder = moduleHolder;
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedEncyclopedie::~RenderedEncyclopedie()
{}

void		AoL::rendering::RenderedEncyclopedie::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();
  AoL::rendering::RenderedTextButton    *title;

  title = new AoL::rendering::RenderedTextButton(*this, buttonHolder[0]);
  title->setColor(RED);
  this->_buttons.push_back(title);
  for (irr::u32 i = 1; i < buttonHolder.size(); i++)
    {
      if (i == 17 || i == 19)
	{
	  AoL::rendering::RenderedTextButton    *text;

	  text = new AoL::rendering::RenderedTextButton(*this, buttonHolder[i]);
	  text->setColor(BLACK);
	  this->_buttons.push_back(text);
	}
      else if (i == 16 || i == 18)
	this->_buttons.push_back(new RenderedSimpleButton(*this, buttonHolder[i]));
      else
	this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
    }
}

void		AoL::rendering::RenderedEncyclopedie::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  auto buttons = _moduleHolder->getModule()->getButtonsHolder();
  
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    {
      if (this->_buttons[i]->getType() == functionId)
	{
	  this->_buttons[i]->callFunction();
	  _buttons[17]->modifyText(buttons[17]->getButton()->getText());
	  _buttons[19]->modifyText(buttons[19]->getButton()->getText());
	  _buttons[16]->setFirstImage(*this, buttons[16]->getButton()->getPicturePath());
	  _buttons[18]->setFirstImage(*this, buttons[18]->getButton()->getPicturePath());
	}
    }
}

void		AoL::rendering::RenderedEncyclopedie::draw()
{
  setVisible(!_moduleHolder->getModule()->isHide());
  for (irr::u32 j = 0; j < this->_buttons.size(); j++)
    _buttons[j]->setVisible(!_moduleHolder->getModule()->isHide());
}
