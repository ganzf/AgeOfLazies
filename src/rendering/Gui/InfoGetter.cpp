#include "rendering/Gui/InfoGetter.hpp"

AoL::rendering::elementInformationGetter::elementInformationGetter(AoL::Gui::ButtonHolder *buttonHolder, AoL::rendering::elementInformationGetter const &moduleInfo)
{
  this->posX = this->getValueFromPercent(buttonHolder->getPos().X, moduleInfo.width);

  this->posY = this->getValueFromPercent(buttonHolder->getPos().Y, moduleInfo.height);

  this->width = this->getValueFromPercent(buttonHolder->getWidth(), moduleInfo.width);

  this->height = this->getValueFromPercent(buttonHolder->getHeight(), moduleInfo.height);
}

AoL::rendering::elementInformationGetter::elementInformationGetter(AoL::Gui::ModuleHolder *moduleHolder)
{
  this->posX = this->getValueFromPercent(moduleHolder->getPos().X, AoL::Constants::Rendering::g_screen_width);

  this->posY = this->getValueFromPercent(moduleHolder->getPos().Y, AoL::Constants::Rendering::g_screen_height);

  this->width = this->getValueFromPercent(moduleHolder->getWidth(), AoL::Constants::Rendering::g_screen_width);

  this->height = this->getValueFromPercent(moduleHolder->getHeight(), AoL::Constants::Rendering::g_screen_height);
}


