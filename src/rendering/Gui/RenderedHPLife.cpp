#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedHPLife.hpp"
#include "Game/Controlled.hpp"

AoL::rendering::RenderedHPLife::RenderedHPLife(AoL::rendering::ARenderedModule &_moduleParent, AoL::Gui::ButtonHolder *buttonHolder, AoL::Game::Entity *entity)
  : RenderedBarButton(_moduleParent, buttonHolder, entity)
{
  if (entity != nullptr)
    this->setEntity(entity);
}

AoL::rendering::RenderedHPLife::~RenderedHPLife()
{}

void	AoL::rendering::RenderedHPLife::setEntity(AoL::Game::Entity *entity)
{
  if (entity != nullptr)
  {
    auto controlled = dynamic_cast<AoL::Game::Controlled *>(entity);
    if (!controlled)
      return ;
    this->_maxVal = controlled->getMaxHP();
    this->_actualVal = controlled->getHP() * 100 / this->_maxVal * this->_elementInfo.width / 100;
  }
  this->_inspectedEntity = entity;
}

void	AoL::rendering::RenderedHPLife::draw(AoL::rendering::Gui &gui)
{
  if (this->_inspectedEntity != nullptr)
  {
    auto controlled = dynamic_cast<AoL::Game::Controlled *>(this->_inspectedEntity);
    if (!controlled)
      return ;
    this->_maxVal = controlled->getMaxHP();
    this->_actualVal = controlled->getHP() * 100 / this->_maxVal * this->_elementInfo.width / 100;
    irr::core::rect<irr::s32>	actualHPRatio(
	_moduleParent.getInfo().posX + this->_elementInfo.posX,
	_moduleParent.getInfo().posY + this->_elementInfo.posY,
	_moduleParent.getInfo().posX + this->_elementInfo.posX + this->_actualVal,
	_moduleParent.getInfo().posY + this->_elementInfo.posY + this->_elementInfo.height
	);
    gui.getDriver()->draw2DImage(this->_firstImage, this->_destRect, this->_originRect, 0, 0, true);
    gui.getDriver()->draw2DImage(this->_secondImage, actualHPRatio, this->_originRect, 0, 0, true);
  }
}
