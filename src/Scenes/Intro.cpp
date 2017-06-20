#include "Scenes/Intro.hpp"
#include "Scenes/MainMenu.hpp"
#include "Manager.hpp"
#include "Print.hpp"

AoL::Scenes::Intro::Intro(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Splashscreen", data, nullptr)
{
  // this->manager->playSound("../Assets/sound/OhBahNon.ogg", true);
  // this->manager._sound->play("../Assets/sound/OhBahNon.ogg", true);
  // this->manager._sound->play("triotrorroro");
  // Construction d'une scene doit etablir la keymap
}

bool		AoL::Scenes::Intro::isDone()
{
  return this->done;
}

int		AoL::Scenes::Intro::init()
{
  return (0);
}

irr::s32	AoL::Scenes::Intro::run(irr::f32 elapsed)
{
  (void)elapsed;
  if (this->manager.deviceIsRunning())
    {
      if (this->isPressed(AoL::UserInput::KeyValue::UP))
  	std::cout << "Flèche du haut appuyée" << std::endl;
      if (this->isPressed(AoL::UserInput::KeyValue::ESCAPE))
  	{
  	  this->done = true;
  	  return (0);
  	}
      if (this->isClicked(AoL::UserInput::LEFT_CLICK))
  	std::cout << "On appuie sur la touche gauche de la souris" << std::endl;
    }
  return (0);
}

AoL::Scenes::Intro::~Intro()
{

}
