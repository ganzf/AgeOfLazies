#ifndef DYNAMICCAMERA_H_INCLUDED
# define DYNAMICCAMERA_H_INCLUDED

# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace rendering
  {
    class					DynamicCamera : public irr::scene::ISceneNodeAnimatorCameraFPS
    {
    public:
      struct				SCamKeyMap
      {
	SCamKeyMap(void) {}
	SCamKeyMap(irr::s32 a, irr::EKEY_CODE k) : action(a), keycode(k) {}

	irr::s32				action;
	irr::EKEY_CODE			keycode;
      };

    private:
      void allKeysUp(void);

      irr::gui::ICursorControl		*CursorControl;
      irr::f32				MaxVerticalAngle;
      irr::f32				MoveSpeed;
      irr::f32				RotateSpeed;
      irr::f32				JumpSpeed;
      irr::f32				currentZoom;
      irr::s32				LastAnimationTime;
      irr::core::vector3df			movedir;
      irr::core::vector3df			walkDirection;
      irr::core::vector3df			TargetVector;
      irr::core::array<SCamKeyMap>		KeyMap;
      irr::core::position2d<irr::f32>	CenterCursor;
      irr::core::position2d<irr::f32>	CursorPos;
      irr::core::array<irr::SKeyMap>	keyMap;

      bool					CursorKeys[6];
      bool					firstUpdate;
      bool					NoVerticalMovement; /// NOM PAS ACCORDES


    public:
      DynamicCamera(irr::gui::ICursorControl* cursorControl,
		    irr::f32 rotateSpeed = 100.0f, irr::f32 moveSpeed = .5f, irr::f32 jumpSpeed=0.f,
		    irr::SKeyMap* keyMapArray=0, irr::u32 keyMapSize=0, bool noVerticalMovement=false);

      virtual ~DynamicCamera(void)
      {
	if (CursorControl)
	  CursorControl->drop();
      }

      /* FUNCTIONS */
      virtual ISceneNodeAnimator*		createClone(irr::scene::ISceneNode* node,
							    irr::scene::ISceneManager* newManager = 0);
      virtual void				animateNode(irr::scene::ISceneNode* node, irr::u32 timeMs);
      virtual bool				OnEvent(const irr::SEvent& event);
      virtual bool				isEventReceiverEnabled(void) const
      { return true; }


      /* GETTERS */
      irr::core::vector3df			getWalkDirection(void) { return (walkDirection); }; /// CONST ?
      virtual irr::f32			getMoveSpeed(void) const { return (MoveSpeed); };
      virtual irr::f32			getRotateSpeed(void) const { return (RotateSpeed); };
      bool					*getKey(void) { return (CursorKeys); };
      const irr::core::array<irr::SKeyMap>&	getKeyMap(void) const
      { return (this->keyMap); } ///implem for instanciation
      virtual irr::scene::ESCENE_NODE_ANIMATOR_TYPE	getType(void) const
      { return irr::scene::ESNAT_CAMERA_FPS; }


      /* SETTERS */
      virtual void				setMoveSpeed(irr::f32 moveSpeed) { MoveSpeed = moveSpeed; };
      virtual void				setRotateSpeed(irr::f32 rotateSpeed) { RotateSpeed = rotateSpeed; };
      virtual void				setKeyMap(irr::SKeyMap *map, irr::u32 count);
      virtual void				setVerticalMovement(bool allow) { NoVerticalMovement = !allow; };
      void					setKeyMap(const irr::core::array<SCamKeyMap>& keymap) { KeyMap = keymap; };
      void					setKeyMap(const irr::core::array<irr::SKeyMap>& keymap)
      { this->keyMap = keymap; } ///implem for instanciation
      void					setInvertMouse(bool)
      { this->movedir = -this->movedir; } ///implem for instanciation
    };
    
  }
}

#endif
