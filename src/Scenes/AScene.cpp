#include "Scenes/Scenes.hpp"
#include "Manager.hpp"
#include "Core/Core.hpp"

AoL::Scenes::AScene::AScene(AoL::Manager &manager,
			    std::string const &name,
			    AoL::CommonData &data,
			    AoL::Gui::IUserInterface *gui):
  name(name),
  manager(manager),
  gui(gui),
  transparent(false),
  paused(false),
  done(false),
  lifespan(0.0),
  updateRate(120),
  map(data.getMapSize()),
  scene3d(manager.getCore().getRenderer()),
  data(data),
  observer(*this)
{

}

void	AoL::Scenes::AScene::dropGui()
{
  this->manager.getCore().getRenderer().getGui().clear();
}

bool	AoL::Scenes::AScene::shouldUpdate()
{
  auto currentFps = this->timer.getTime();

  if (this->lifespan > 0.0 && this->timer.getTotalTime() > this->lifespan)
    {
      this->done = true;
      return (false);
    }
  
  if (currentFps >= this->updateRate())
    {
      this->timer.reset();
      return true;
    }
  return false;
}

bool	AoL::Scenes::AScene::isPressed(AoL::UserInput::KeyValue v)
{
  // tant qu'a faire on met directement une reference sur keyboardHandler au besoin.
  // mais sinon nik.
  // if (this->manager.getCore().getInputHandler()->_keyboardHandler.isKeyPressed(v)
  return (this->manager.getCore().keyIsPressed(v));
}

void	AoL::Scenes::AScene::resetEventQueue()
{
  this->manager.getCore().resetEventQueue();
}

bool	AoL::Scenes::AScene::isClicked(AoL::UserInput::MouseAttributs v)
{
  return (this->manager.getCore().isClicked(v));
}

AoL::Scenes::AScene::~AScene()
{
  this->dropGui();
}
