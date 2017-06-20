#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedXPBar.hpp"
#include "Game/Units/Unit.hpp"


AoL::rendering::RenderedXPBar::RenderedXPBar(AoL::rendering::ARenderedModule &_moduleParent, AoL::Gui::ButtonHolder *buttonHolder, AoL::Game::Entity *entity)
  : RenderedBarButton(_moduleParent, buttonHolder, entity)
{
  if (entity != nullptr)
    this->setEntity(entity);
}

AoL::rendering::RenderedXPBar::~RenderedXPBar()
{}

void	AoL::rendering::RenderedXPBar::setEntity(AoL::Game::Entity *entity)
{
  if (entity != nullptr)
  {
    auto controlled = dynamic_cast<AoL::Game::Unit *>(entity);
    if (!controlled)
      return ;
    this->_maxVal = controlled->getLevelStep();
    this->_actualVal = controlled->getCurrExp() * 100 / this->_maxVal * this->_elementInfo.width / 100;
  }
  this->_inspectedEntity = entity;
}

void	AoL::rendering::RenderedXPBar::draw(AoL::rendering::Gui &gui)
{
  if (this->_inspectedEntity != nullptr)
  {
    auto controlled = dynamic_cast<AoL::Game::Unit *>(this->_inspectedEntity);
    if (!controlled)
      return ;
    this->_maxVal = controlled->getLevelStep();
    this->_actualVal = controlled->getCurrExp() * 100 / this->_maxVal * this->_elementInfo.width / 100;
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

