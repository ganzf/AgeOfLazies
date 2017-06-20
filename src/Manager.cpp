#include "Manager.hpp"
#include "Factory.hpp"
#include "Core/Core.hpp"

AoL::Manager::Manager(AoL::Core &core):
  factory(*this), maxFps(120), minFps(30), core(core)
{
  
}

void	AoL::Manager::playScene(AoL::Scenes::AScene *s)
{
  this->logger.log<Logger::INFO>("start of scene " + s->getName(), __FUNCTION__);
  s->init();
  this->scheduler.addScene(s);
  this->loop();
}

void	AoL::Manager::render(AoL::Scenes::AScene *scene)
{
  if (scene != nullptr)
    this->core.renderScene(*scene);
}

void	AoL::Manager::associateObserver(AoL::Observer *obs)
{
  this->factory.setObserver(obs);
}

bool	AoL::Manager::deviceIsRunning() const
{
  return this->core.isFine();
}

void	AoL::Manager::renderScene(AoL::Scenes::AScene *scene)
{
  if (scene == nullptr)
    return ;
  if (scene->isTransparent())
    {
      AoL::Scenes::AScene *parent = this->scheduler.getParent(scene);
      if (parent != nullptr)
	this->renderScene(parent);
    }
  this->render(scene);
}

// Rec Function
void	AoL::Manager::runScene(AoL::Scenes::AScene *scene,
			       irr::f32 elapsed)
{
  if (scene == nullptr)
    return ;
  if (scene->isTransparent())
    {
      AoL::Scenes::AScene *parent = this->scheduler.getParent(scene);
      if (parent != nullptr)
	this->runScene(parent, elapsed);
    }
  if (!scene->isPaused())
    scene->run(elapsed);
}

void	AoL::Manager::loop()
{
  AoL::Scenes::AScene	*currentScene = this->scheduler.top();

  this->timer.reset();
  while (currentScene->isDone() == false && this->deviceIsRunning())
    {
      this->core.getRenderer().getGui().guiEvents();
      auto currentFps = this->timer.getTime();
      if (currentFps >= this->maxFps())
	{
	  this->core.clearScreen();
	  if (currentScene->shouldUpdate())
	    {
	      this->runScene(currentScene, currentFps);
	    }
	  this->timer.reset();
	  this->renderScene(currentScene);
	  this->core.refreshWindow();
	  currentScene->resetEventQueue();
	}
    }
  this->endScene();
}
