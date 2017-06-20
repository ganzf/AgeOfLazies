#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"

AoL::rendering::RenderedClickButton::RenderedClickButton(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder)
  : ARenderedElement(moduleParent, buttonHolder)
{
  this->setElement(moduleParent, buttonHolder);
  this->_buttonFunction = buttonHolder->getButton()->getEventClick();
}

AoL::rendering::RenderedClickButton::~RenderedClickButton()
{}

void	AoL::rendering::RenderedClickButton::setElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder)
{
  if ((this->_button =
	moduleParent.getGUI().getEnv()->addButton(
	  irr::core::rect<irr::s32>(
	    this->_elementInfo.posX,
	    this->_elementInfo.posY,
	    this->_elementInfo.posX + this->_elementInfo.width,
	    this->_elementInfo.posY + this->_elementInfo.height),
	  moduleParent.getParentElement(),
	  buttonHolder->getButton()->getId(),
	  buttonHolder->getButton()->getText().c_str())) == nullptr)
    {
      std::cerr << "Couldn't load textures." << std::endl;
      std::exit(1);
    }
  this->_button->setScaleImage(true);
  this->_button->setUseAlphaChannel(true);
  this->_button->setImage(this->_firstImage);
  this->_button->setPressedImage(this->_secondImage);
  this->_button->setDrawBorder(0);
  this->_element = this->_button;
}

void  AoL::rendering::RenderedClickButton::callFunction()
{
  if (this->_buttonFunction)
    this->_buttonFunction();
}

void  AoL::rendering::RenderedClickButton::setFunction(std::function<void()> const &function)
{
    this->_buttonFunction = function;
}

void	AoL::rendering::RenderedClickButton::setFirstImage(AoL::rendering::ARenderedModule &moduleParent, std::string const &path)
{
  if (this->_firstImage != nullptr)
    moduleParent.getGUI().getDriver()->removeTexture(this->_firstImage);
  this->_firstImage = moduleParent.getGUI().getDriver()->getTexture(path.c_str());
  this->_button->setImage(this->_firstImage);
  this->_button->setPressedImage(this->_firstImage);
}
