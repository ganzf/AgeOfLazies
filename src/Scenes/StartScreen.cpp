#include "Scenes/StartScreen.hpp"
#include "Manager.hpp"
#include "Timer.hpp"
#include "Core/Core.hpp"

AoL::Scenes::StartScreen::StartScreen(AoL::Manager &manager, AoL::CommonData &data):
  AScene(manager, "Start Screen", data, nullptr)
{
  this->manager.getMixer().play("Assets/sound/aol.wav", false);
  this->initGui();
  this->scene3d.startPreloading();
}

void	AoL::Scenes::StartScreen::initGui()
{
  this->manager.getCore().getRenderer().getGui().setBackground("Assets/textures/StartScreen.png");
}

irr::s32	AoL::Scenes::StartScreen::run(irr::f32)
{
  static irr::s32 loading = 0;
  if (loading <= 40)
    loading = this->scene3d.preload3dAssets();
  if (this->isClicked(AoL::UserInput::LEFT_CLICK))
    {
      this->done = true;
      return (0);
    }
  return (0);
}

AoL::Scenes::StartScreen::~StartScreen()
{
  this->dropGui();
  this->manager.playScene(this->manager.getFactory().createScene<AoL::Scenes::MainMenu>(this->data));
}
