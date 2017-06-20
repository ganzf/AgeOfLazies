#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedTextButton::RenderedTextButton(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder)
  : ARenderedElement(moduleParent, buttonHolder)
{
  this->setElement(moduleParent, buttonHolder);
  std::cout << moduleParent.getInfo().posX + this->_elementInfo.posX << std::endl;
  std::cout << moduleParent.getInfo().posY + this->_elementInfo.posY << std::endl;
}

AoL::rendering::RenderedTextButton::~RenderedTextButton()
{}

void	AoL::rendering::RenderedTextButton::setElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder)
{
  if ((this->_text =
	moduleParent.getGUI().getEnv()->addStaticText(
	  buttonHolder->getButton()->getText().c_str(),
	  irr::core::rect<irr::s32>(
	    moduleParent.getInfo().posX + this->_elementInfo.posX,
	    moduleParent.getInfo().posY + this->_elementInfo.posY,
	    moduleParent.getInfo().posX + this->_elementInfo.posX + this->_elementInfo.width,
	    moduleParent.getInfo().posY + this->_elementInfo.posY + this->_elementInfo.height),
	  0,
	  buttonHolder->getButton()->getId())) == nullptr)
    {
      std::cerr << "Couldn't load textures" << std::endl;
      std::exit(1);
    }
  this->_text->setTextAlignment(irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER, irr::gui::EGUI_ALIGNMENT::EGUIA_CENTER);
  this->_element = this->_text;
}

void	AoL::rendering::RenderedTextButton::setColor(irr::video::SColor const &color)
{
  this->_text->setOverrideColor(color);
}

