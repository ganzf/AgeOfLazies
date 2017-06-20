#ifndef CAMERA_HPP_
# define CAMERA_HPP_

# include <memory>
# include "irrlicht/irrlicht.h"
# include "rendering/RTSCamera.hpp"

namespace	AoL
{
  namespace	rendering
  {
    class	Camera
    {
    private:
      irr::scene::ICameraSceneNode		*_camera;

    public:
      Camera(irr::scene::ISceneManager *, irr::IrrlichtDevice *);
      ~Camera() = default;

      irr::scene::ICameraSceneNode		*operator () ()
      {
	return this->_camera;
      }

      void					setPosition(irr::core::vector2df const &pos)
      {
	irr::core::vector3df		updatedPos(pos.X, 0, pos.Y);
	this->_camera->setPosition(updatedPos);
      }
      irr::core::vector3df			getPosition() const
      {
	return this->_camera->getPosition();
      }
    };
  }
}

#endif
