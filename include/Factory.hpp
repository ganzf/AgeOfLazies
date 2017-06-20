#ifndef FACTORY_HPP_
# define FACTORY_HPP_

# include "CommonData.hpp"
# include "Scenes/Scenes.hpp"
# include "Game/AllRessources.hpp"
# include "Game/AllBuildings.hpp"
# include "Game/AllUnits.hpp"
# include "Scenes/Intro.hpp"
# include "Scenes/MainMenu.hpp"
# include "Scenes/NewGameMenu.hpp"
# include "Scenes/OptionMenu.hpp"
# include "Scenes/StartScreen.hpp"
# include "Scenes/Game.hpp"
# include "Scenes/Test.hpp"
# include "Scenes/Score.hpp"
# include "Scenes/KeysBinding.hpp"
# include "Scenes/Victory.hpp"
# include "Scenes/Defeat.hpp"
# include "Scenes/LoadGameMenu.hpp"

namespace AoL
{
  class	Manager;
  class	Observer;
  
  class Factory
  {
    AoL::Manager	&manager;
    AoL::Observer	*observer;
    
  public:
    Factory(AoL::Manager &manager, AoL::Observer *observer = nullptr);
    ~Factory() = default;

    void		setObserver(AoL::Observer *obs)
    {
      this->observer = obs;
    }
    
    template	<typename Entity>
    Entity	*createEntity(irr::core::vector2df const &pos)
    {
      if (this->observer)
	return new Entity(pos.Y, pos.Y, *this->observer);
      throw std::runtime_error("Cannot create entity without observer");
    }
    template	<typename Entity>
    Entity	*createEntity(irr::f32 x, irr::f32 y)
    {
      if (this->observer)
	return new Entity(x, y, *this->observer);
      throw std::runtime_error("Cannot create entity without observer");
    }
    template	<typename Scene>
    Scene	*createScene(AoL::CommonData &options)
    {
      return new Scene(this->manager, options);
    }
  };
}
#endif /* !FACTORY_HPP_ */
