#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedBarButton.hpp"
#include "Game/Controlled.hpp"

AoL::rendering::RenderedBarButton::RenderedBarButton(AoL::rendering::ARenderedModule &_moduleParent, AoL::Gui::ButtonHolder *buttonHolder, AoL::Game::Entity *entity)
  : ARenderedElement(_moduleParent, buttonHolder), _inspectedEntity(nullptr),
  _moduleParent(_moduleParent),
  _destRect(
      _moduleParent.getInfo().posX + this->_elementInfo.posX,
      _moduleParent.getInfo().posY + this->_elementInfo.posY,
      _moduleParent.getInfo().posX + this->_elementInfo.posX + this->_elementInfo.width,
      _moduleParent.getInfo().posY + this->_elementInfo.posY + this->_elementInfo.height
      ),
  _originRect(
      0, 0,
      this->_firstImage->getSize().Width,
      this->_firstImage->getSize().Height
      )

{
  this->_inspectedEntity = nullptr;
  this->_maxVal = 0;
  this->_actualVal = 0;
}

AoL::rendering::RenderedBarButton::~RenderedBarButton()
{}

