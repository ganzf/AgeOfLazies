#include "rendering/Camera.hpp"

AoL::rendering::Camera::Camera(irr::scene::ISceneManager *sceneManager,
		    irr::IrrlichtDevice *device):
  _camera(sceneManager->addCameraSceneNode(0))
{
  const irr::core::vector3df	pos(-100, 0, -100);
  _camera->setPosition(pos);
  AoL::rendering::DynamicCamera	*animator = new AoL::rendering::DynamicCamera(device->getCursorControl());
  _camera->addAnimator(animator);
  this->_camera->setFarValue(500);
}
