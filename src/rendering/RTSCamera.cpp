#include "rendering/RTSCamera.hpp"

namespace
{
  static const irr::f32		g_move_speed = 0.35;
  static const irr::u32		g_max_zoom = 800;
  static const irr::u32		g_min_zoom = 30;
  static const irr::u32		g_zoom_speed = 8;
  static const irr::u32		g_default_angle = 45;
  static const irr::f32		g_map_limit_min_x = -2000;
  static const irr::f32		g_map_limit_min_z = -2000;
  static const irr::f32		g_map_limit_max_x = 2000;
  static const irr::f32		g_map_limit_max_z = 2000;
}


AoL::rendering::DynamicCamera::DynamicCamera(irr::gui::ICursorControl* cursorControl,
			     irr::f32 rotateSpeed, irr::f32 moveSpeed, irr::f32 jumpSpeed,
			     irr::SKeyMap* keyMapArray, irr::u32 keyMapSize, bool noVerticalMovement)
  : CursorControl(cursorControl), MaxVerticalAngle(88.0f),
    MoveSpeed(moveSpeed), RotateSpeed(rotateSpeed), JumpSpeed(jumpSpeed),
    LastAnimationTime(0), firstUpdate(true), NoVerticalMovement(noVerticalMovement)
{

  if (CursorControl)
    CursorControl->grab();

  allKeysUp();

  // KEYMAP
  if (!keyMapArray || !keyMapSize)
    {
      // DEFAULT KEY MAP "ZSQD"
      KeyMap.push_back(SCamKeyMap(irr::EKA_MOVE_FORWARD, irr::KEY_KEY_Z));
      KeyMap.push_back(SCamKeyMap(irr::EKA_MOVE_BACKWARD, irr::KEY_KEY_S));
      KeyMap.push_back(SCamKeyMap(irr::EKA_STRAFE_LEFT, irr::KEY_KEY_Q));
      KeyMap.push_back(SCamKeyMap(irr::EKA_STRAFE_RIGHT, irr::KEY_KEY_D));
      KeyMap.push_back(SCamKeyMap(irr::EKA_JUMP_UP, irr::KEY_SPACE));
    }
  else
    {
      // CUSTOM KEYMAP
      setKeyMap(keyMapArray, keyMapSize);
    }
  currentZoom = 100;
}

bool		AoL::rendering::DynamicCamera::OnEvent(const irr::SEvent& event)
{
  switch (event.EventType)
    {
    case irr::EET_KEY_INPUT_EVENT:
      for (irr::u32 i = 0; i < KeyMap.size(); ++i)
	{
	  if (KeyMap[i].keycode == event.KeyInput.Key)
	    {
	      CursorKeys[KeyMap[i].action] = event.KeyInput.PressedDown;
	      return true;
	    }
	}
      break;
    case irr::EET_MOUSE_INPUT_EVENT:
      if (event.MouseInput.Event == irr::EMIE_MOUSE_MOVED)
	{
	  CursorPos = CursorControl->getRelativePosition();
	  return true;
	}
      if (event.MouseInput.Event == irr::EMIE_MOUSE_WHEEL)
	{
	  currentZoom -= event.MouseInput.Wheel * g_zoom_speed;
	  if (currentZoom > g_max_zoom || currentZoom < g_min_zoom)
	    currentZoom += event.MouseInput.Wheel * g_zoom_speed;
	  return true;
	}
      break;
    default:
      break;
    }
  return false;
}

void				AoL::rendering::DynamicCamera::animateNode(irr::scene::ISceneNode* node,
							   irr::u32 timeMs)
{
  walkDirection.X = 0;
  walkDirection.Y = 0;
  walkDirection.Z = 0;

  if (node->getType() != irr::scene::ESNT_CAMERA)
    return ;

  irr::scene::ICameraSceneNode	*camera = static_cast<irr::scene::ICameraSceneNode*>(node);
  irr::core::vector3df		pos = camera->getPosition();
  irr::core::vector3df		oldPos = pos; 
  irr::core::vector3df		target = (camera->getTarget() - camera->getAbsolutePosition());

  if (firstUpdate)
    {
      irr::core::matrix4	mat;

      camera->updateAbsolutePosition();
      mat.setRotationDegrees(irr::core::vector3df(50, 30, 0));
      mat.transformVect(target);

      LastAnimationTime = timeMs;
      CursorPos = CenterCursor = CursorControl->getRelativePosition();
      firstUpdate = false;
    }

  irr::f32			timeDiff = (irr::f32) ( timeMs - LastAnimationTime );
  LastAnimationTime = timeMs;

  irr::core::vector3df		relativeRotation = target.getHorizontalAngle();
  irr::core::vector3df		strafevect = target;
  strafevect = strafevect.crossProduct(camera->getUpVector());


  //SLOWING MOVEMENT DEPEDING ON CURRENT ZOOM
  irr::f32 oldMoveSpeed = MoveSpeed;
  MoveSpeed = MoveSpeed + (currentZoom / g_max_zoom) / 2 - g_move_speed;

  // STRAFE
  strafevect.normalize();
  if (CursorKeys[irr::EKA_STRAFE_LEFT])
    pos += strafevect * timeDiff * MoveSpeed;

  if (CursorKeys[irr::EKA_STRAFE_RIGHT])
    pos -= strafevect * timeDiff * MoveSpeed;

  // SCREEN EDGES MOVES
  if (CursorControl)
    {
      if (CursorPos.X <= 0.001)
	pos += strafevect * timeDiff * MoveSpeed;
      if (CursorPos.X >= 0.999)
	pos += strafevect * timeDiff * -MoveSpeed;
      if(CursorPos.Y <= 0.001)
	pos += movedir * timeDiff * MoveSpeed;
      if(CursorPos.Y >= 0.999)
	pos += movedir * timeDiff * -MoveSpeed;
    }


  // MOVES
  movedir = camera->getUpVector();
  movedir = movedir.crossProduct(strafevect);
  movedir.normalize();

  if (CursorKeys[irr::EKA_MOVE_FORWARD])
    pos += movedir * timeDiff * MoveSpeed;

  if (CursorKeys[irr::EKA_MOVE_BACKWARD])
    pos -= movedir * timeDiff * MoveSpeed;

  MoveSpeed = oldMoveSpeed; // RESET MOVE SPEED

  target.set(0,0,irr::core::max_(1.f, pos.getLength()));

  // SET CAMERA ROTATION
  irr::core::matrix4			mat;
  mat.setRotationDegrees(irr::core::vector3df(relativeRotation.X, g_default_angle, 0));
  mat.transformVect(target);

  pos.Y = currentZoom;

  // SET MAP LIMIT
  if (pos.X <= g_map_limit_min_x || pos.X >= g_map_limit_max_x)
    pos.X = oldPos.X;
  if (pos.Z <= g_map_limit_min_z || pos.Z >= g_map_limit_max_z)
    pos.Z = oldPos.Z;

  camera->setPosition(pos);

  TargetVector = target;
  target += pos;
  camera->setTarget(target);
}

void AoL::rendering::DynamicCamera::allKeysUp(void)
{
  for (irr::u32 i=0; i<6; ++i)
    CursorKeys[i] = false;
}

void AoL::rendering::DynamicCamera::setKeyMap(irr::SKeyMap *map, irr::u32 count)
{
  KeyMap.clear();

  for (irr::u32 i=0; i<count; ++i)
    {
      switch(map[i].Action)
	{
	case irr::EKA_MOVE_FORWARD: KeyMap.push_back(SCamKeyMap(irr::EKA_MOVE_FORWARD, map[i].KeyCode));
	  break;
	case irr::EKA_MOVE_BACKWARD: KeyMap.push_back(SCamKeyMap(irr::EKA_MOVE_BACKWARD, map[i].KeyCode));
	  break;
	case irr::EKA_STRAFE_LEFT: KeyMap.push_back(SCamKeyMap(irr::EKA_STRAFE_LEFT, map[i].KeyCode));
	  break;
	case irr::EKA_STRAFE_RIGHT: KeyMap.push_back(SCamKeyMap(irr::EKA_STRAFE_RIGHT, map[i].KeyCode));
	  break;
	case irr::EKA_JUMP_UP: KeyMap.push_back(SCamKeyMap(irr::EKA_JUMP_UP, map[i].KeyCode));
	  break;
	default:
	  break;
	}
    }
}

irr::scene::ISceneNodeAnimator* AoL::rendering::DynamicCamera::createClone(irr::scene::ISceneNode* node, irr::scene::ISceneManager* newManager)
{
  (void)node;
  (void)newManager;
  DynamicCamera * newAnimator =
    new DynamicCamera(CursorControl, RotateSpeed, MoveSpeed, JumpSpeed,
		      0, 0, NoVerticalMovement);
  newAnimator->setKeyMap(KeyMap);
  return newAnimator;
}
