#ifndef MESSAGE_HPP_
# define MESSAGE_HPP_

# include "irrlicht/irrlicht.h"
# include "Game/Entity.hpp"
# include "Game/Player.hpp"

namespace AoL
{
  // Liste des events possible inGame
  enum	MessageType : irr::s32
  {
    // For Units and maybe Ressources (no amount required)
    SPAWN,
    DEATH,
      LEVEL_UP,

    // For Buildings (no amount required)
    BUILT,
    DESTROYED,

    // For Collectors (amount necessary)
    COLLECT,
    COLLECT_DONE,
    DEPOSIT,
    DEPOSIT_DONE,

    // For all controlled (units and buildings alike) (no amount required)
    GAINCONTROL,
    RELEASECONTROL,

    // For Warriors (can be used with an amount for display of damage in game or in the console)
    ATTACK,
    KILL,

    // Takes a vector2df
      MOVE,

      CREATE_WARRIOR,
      CREATE_COLLECTOR,
      CREATE_GATHERER,
      CREATE_MINER,
      CREATE_GOLDMINER,
      CREATE_LUMBERJACK,

      CREATE_MININGCAMP,
      CREATE_HABITATION,
      CREATE_MILL,
      CREATE_LUMBERCAMP,
      CREATE_FORUM
  };

  class	Message
  {
    irr::s32			id;
    AoL::Game::Entity		&parent;
    AoL::MessageType		type;
    irr::s32			amount;
    AoL::Game::RessourceType	ressource;
    irr::core::vector2df	origin;

    public:
    Message(AoL::Game::Entity	&parent,
	AoL::MessageType	type,
	irr::s32		amount = 0):
      parent(parent),
      type(type),
      amount(amount)
    {
      static irr::s32	prevId = 0;
      id = prevId++;
    }

    Message(AoL::Game::Entity &parent, AoL::MessageType type, irr::core::vector2df const &):
      parent(parent), type(type)
    {}
    virtual ~Message() = default;

    void		setRessource(AoL::Game::RessourceType t)
    {
      this->ressource = t;
    }

    AoL::Game::RessourceType	getRessource()
    {
      return this->ressource;
    }

    AoL::Game::Entity	&getParent();

    irr::s32		getId() const
    {
      return this->id;
    }

    irr::s32		getAmount() const
    {
      return this->amount;
    }

    AoL::MessageType	getType() const
    {
      return this->type;
    }
  };
}

#endif /* !MESSAGE_HPP_ */
