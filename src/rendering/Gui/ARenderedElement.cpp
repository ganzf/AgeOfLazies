#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/ARenderedElement.hpp"

AoL::rendering::ARenderedElement::ARenderedElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder)
  : _elementInfo(buttonHolder, moduleParent.getInfo()), _elementType(buttonHolder->getType())
{
  this->_firstImage = moduleParent.getGUI().getDriver()->getTexture(buttonHolder->getButton()->getPicturePath().c_str());
  this->_secondImage = moduleParent.getGUI().getDriver()->getTexture(buttonHolder->getButton()->getPicturePressedPath().c_str());
}

void	AoL::rendering::ARenderedElement::modifyText(std::wstring const &txt)
{
  this->_element->setText(txt.c_str());
}
void	AoL::rendering::ARenderedElement::setFirstImage(AoL::rendering::ARenderedModule &moduleParent, std::string const &path)
{
  if (this->_firstImage != nullptr)
    moduleParent.getGUI().getDriver()->removeTexture(this->_firstImage);
  this->_firstImage = moduleParent.getGUI().getDriver()->getTexture(path.c_str());
}

