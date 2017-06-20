#include <iostream>
#include "Core/Core.hpp"
#include "Constants.hpp"

AoL::Core::Core():
  game(*this),
  renderer(*this)
{
  
}

irr::s32	AoL::Core::start(bool)
{
  game.runCheckup();
  if (game.checkupErrors() == 0)
    {
      try
	{
	  game.playScene(game.getFactory().createScene<AoL::Scenes::StartScreen>(this->data));
	}
      catch (std::exception const &mainError)
	{
	  Print::err(AoL::Constants::Messages::mainErrorMessage, mainError.what());
	}
      return (0);
    }
  else
    {
      Print::err(AoL::Constants::Messages::mainErrorMessage + game.latestError());
      return (game.checkupErrors());
    }
  return (0);
}

void	AoL::Core::clearScreen()
{
  this->renderer.clearScreen();
}

void	AoL::Core::refreshWindow()
{
  this->renderer.refreshWindow();
}

AoL::rendering::Renderer	&AoL::Core::getRenderer()
{
  return this->renderer;
}
