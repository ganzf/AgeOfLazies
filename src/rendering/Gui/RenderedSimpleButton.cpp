#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedSimpleButton.hpp"

AoL::rendering::RenderedSimpleButton::RenderedSimpleButton(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder)
  : ARenderedElement(moduleParent, buttonHolder)
{
  this->setElement(moduleParent, buttonHolder);
}

AoL::rendering::RenderedSimpleButton::~RenderedSimpleButton()
{}

void	AoL::rendering::RenderedSimpleButton::setElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder)
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
  this->_button->setImage(this->_firstImage);
  this->_button->setUseAlphaChannel(true);
  this->_button->setScaleImage(true);
  this->_button->setIsPushButton(false);
  this->_button->setDrawBorder(0);
  this->_element = this->_button;
}

void	AoL::rendering::RenderedSimpleButton::setFirstImage(AoL::rendering::ARenderedModule &moduleParent, std::string const &path)
{
  if (this->_firstImage != nullptr)
    moduleParent.getGUI().getDriver()->removeTexture(this->_firstImage);
  this->_firstImage = moduleParent.getGUI().getDriver()->getTexture(path.c_str());
  this->_button->setImage(this->_firstImage);
}
