#ifndef ENTITY_HPP_
# define ENTITY_HPP_

# include <ostream>
# include "irrlicht/irrlicht.h"
# include "Game/Player.hpp"
# include "Game/Stock.hpp"
# include "Print.hpp"
# include "Game/Anchor.hpp"
# include "Observer.hpp"

namespace	AoL
{
  namespace	rendering { class Animator; }
  namespace	Game
  {
    enum	RessourceType : irr::s32;
    enum	UnitRole : irr::c8;
    
    enum	EntityType
      {
	UNDEF = -1,
	UNIT,
	BUILDING,
	RESSOURCE
      };

    enum	EntityName : irr::s32
      {
	WARRIOR,
	  COLLECTOR,
	  WOOD_COLLECTOR,
	  FOOD_COLLECTOR,
	  STONE_COLLECTOR,
	  GOLD_COLLECTOR,
	  FORUM,
	  HABITATION,
	  MILL,
	  MININGCAMP,
	  LUMBERCAMP,
	  NWOOD,
	  NFOOD,
	  NSTONE,
	  NGOLD,
	  UNDEFINED,
      };

    class	Entity
    {
      using	smartAnchor	= std::unique_ptr<AoL::Game::Anchor>;
    public:
      Entity(irr::core::vector2df const &pos,
	     std::string const &mesh,
	     AoL::Observer const &obs);
      virtual ~Entity()
      {

      }

      bool				hasAnchors() const
      { return this->_anchors.size() > 0; }

      void				resetAnchorPosition(void);

      const irr::core::vector2df	&getPosition() const				{ return (_pos); }
      void				setPosition(irr::core::vector2df const &pos)
      {
	this->_pos = pos;
	resetAnchorPosition();
      }

      const irr::core::vector2df	getPrevPos() const				{ return this->_prevPos; }
      void				setPrevPos(irr::core::vector2df const &pos)	{ _prevPos = pos; }
      
      const std::string			&getMesh() const				{ return (_mesh); }
      void				setMesh(std::string const &mesh)		{ this->_mesh = mesh; }

      EntityType       			getType() const					{ return (_type); }
      EntityName       			getName() const					{ return (_name); }

      irr::f32				getRotation() const				{ return (_rotation); }
      void				setRotation(irr::f32 rotation)			{ this->_rotation = rotation; }

      bool				getDispo() const { return (_dispo); }
      void				setDispo(bool dispo) { _dispo = dispo; }

      Stock				&getStock() { return _stocks; }

      irr::core::vector2df const	&getAnchorPosition(irr::s32 idx) const
      {
	if (idx < static_cast<irr::s32>(this->_anchors.size()) && this->_anchors[idx])
	  return this->_anchors[idx]->getPos();
	throw std::out_of_range("Cannot find anchor" + std::to_string(idx));
      }

      bool				give(Entity &other, RessourceType type, irr::s32 nb);
      bool				take(Entity &other, RessourceType type, irr::s32 nb);

      irr::s32				getId() const					{ return (_id); }

      void				setNbAnchors(irr::s32 number)
      {
	this->_nbAnchors = number;
      }

      irr::s32				getNbAnchors() const
      {
	return this->_nbAnchors;
      }

      void				createAnchors();
      std::vector<smartAnchor>		&getAnchors() { return (_anchors); }

      Team				getTeam() const { return (_team); }
      void                              setTeam(Team team) { _team = team; }
      
      irr::core::vector2df const	&getAnchorPos(Unit &);
      irr::s32				getNbAnchorsFree() const;

      void				notifyDeath();
      void				markDead() { this->_markedForDeath = true; }
      irr::scene::ISceneNode		*getNode()
      {
	return this->_node;
      }

      std::shared_ptr<AoL::rendering::Animator>	getAnimator(void)
      {
	return (this->_animator);
      }

      void				setNode(irr::scene::ISceneNode *node)
      {
	this->_node = node;
      }

      void				setAnimator(std::shared_ptr<AoL::rendering::Animator>
						    animator)
      {
	this->_animator = animator;
      }

      bool				isMarked() const { return this->_markedForDeath; }
      bool				isSelected() const { return this->_selected; }
      void				setSelected(bool b)
      {
	_selected = b;
      }

      irr::s32	getGridScale() const { return (_gridScale); }
      void	setGridScale(irr::s32 scale) { _gridScale = scale; }

      irr::core::vector3df	getScale() const { return (_scale); }
      void			setScale(irr::core::vector3df scale) { _scale = scale; }

      AoL::Observer			&getObserver()
      {
	return _observer;
      }

    protected:
      AoL::Observer			_observer;
      irr::core::vector2df		_pos;
      irr::core::vector2df		_prevPos;
      std::string			_mesh;
      EntityType			_type;
      irr::f32				_rotation;
      irr::s32				_id;
      bool				_dispo;
      Stock				_stocks;
      irr::s32				_nbAnchors;
      std::vector<smartAnchor>		_anchors;
      irr::scene::ISceneNode		*_node;
      irr::s32				_gridScale;
      irr::core::vector3df	        _scale;
      std::shared_ptr<AoL::rendering::Animator>	_animator;
      EntityName			_name;
      AoL::Game::Team			_team;
      bool				_selected;
      bool				_markedForDeath;
    };
  }
}

# include "rendering/Animator.hpp"

#endif /* ENTITY_HPP_ */
