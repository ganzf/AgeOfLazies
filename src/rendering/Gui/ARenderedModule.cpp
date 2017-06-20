#include "rendering/Gui/Gui.hpp"

AoL::rendering::ARenderedModule::ARenderedModule(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder)
  : _gui(gui), _moduleInfo(moduleHolder), _moduleType(moduleHolder->getType())
{
  this->setImageFromPath(moduleHolder, moduleHolder->getModule()->getPicturePath());
}

AoL::rendering::ARenderedModule::~ARenderedModule()
{}

void			AoL::rendering::ARenderedModule::setImageFromPath(AoL::Gui::ModuleHolder *moduleHolder, std::string const &imagePath)
{
  irr::video::ITexture	*tmp;

  if ((tmp = this->_gui.getDriver()->getTexture(imagePath.c_str())) == nullptr ||
      (this->_backgrImage =
       this->_gui.getEnv()->addImage(irr::core::rect<irr::s32>(
	   this->_moduleInfo.posX,
	   this->_moduleInfo.posY,
	   this->_moduleInfo.posX + this->_moduleInfo.width,
	   this->_moduleInfo.posY + this->_moduleInfo.height))) == nullptr)
    std::exit(1);
    //throw std::runtime_error(AoL::Constants::Messages::errorGUI);
  this->_backgrImage->setImage(tmp);
  this->_backgrImage->setScaleImage(true);
  this->_backgrImage->setVisible(!moduleHolder->getModule()->isHide());
  this->_gui.getDriver()->removeTexture(tmp);
}
