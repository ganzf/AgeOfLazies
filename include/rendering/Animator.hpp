#ifndef ANIMATOR_HPP_
# define ANIMATOR_HPP_

# include <map>
# include "irrlicht/irrlicht.h"

namespace				AoL
{
  namespace Game
  {
    enum RessourceType : irr::s32;
    enum EntityName : irr::s32;
  }
  
  namespace				rendering
  {
    enum class				AnimFrames: irr::s32
    {
      WORK = 0,
      WALK,
      STAND,
      COLLECT,
      MINE,
      BUILD,
      BUILD_ANIM
    };

    enum class				AnimSpeed: irr::s32
    {
      WORK = 20,
      WALK = 80,
      STAND = 20,
      COLLECT = 20,
      MINE = 20,
      BUILD = 2,
      BUILD_ANIM = 3
    };

    class						Animator
    {
    private:
      AoL::rendering::AnimFrames			_currentAnim;
      irr::f32						_animSpeed;
      std::map<irr::s32, std::pair<irr::s32, irr::s32>>	_frames;
      irr::scene::IAnimatedMeshSceneNode		*_node;
      irr::f32 const					buildAnimSpeed[7] =
	{ 0, 0, 4, 1, 1, 3, 1 };

    public:
      Animator(irr::scene::IAnimatedMeshSceneNode *node)
	: _node(node)
      {
	irr::s32			frame[7][2] = {{0, 45}, {50, 115},
						       {125, 165}, {170, 199},
						       {205, 237}, {1, 10}, {9, 18}};
	std::pair<irr::s32, irr::s32>	pair;

	for (irr::s32 i = 0; i < 7; ++i)
	  _frames.insert(std::make_pair(i, std::make_pair(frame[i][0], frame[i][1])));
      }
      ~Animator(void) = default;

      /* SETTERS */
      void				setAnimSpeed(AoL::rendering::AnimSpeed speed,
						     AoL::Game::RessourceType type
						     = static_cast<AoL::Game::RessourceType>(4));

      void				setAnim(AoL::rendering::AnimFrames anim,
						AoL::Game::RessourceType type
						= static_cast<AoL::Game::RessourceType>(4));

      void				setBuildingSpeed(AoL::Game::EntityName name);

      /* GETTERS */
      irr::f32				getAnimSpeed(void) const
      { return (this->_animSpeed); }

      AoL::rendering::AnimFrames	getCurrentAnim(void) const
      { return (this->_currentAnim); }

      irr::s32				getEndFrame()
      { return (this->_node->getEndFrame()); }

      irr::f32				getFrameNr()
      { return (this->_node->getFrameNr()); }
    };
  };
};

#endif /* ANIMATION_HPP_ */
