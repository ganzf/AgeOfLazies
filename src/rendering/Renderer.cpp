# include "rendering/Renderer.hpp"
# include "Core/Core.hpp"
# include "Scenes/Scenes.hpp"

extern AoL::IdGenerator getId;

AoL::rendering::Renderer::Renderer(AoL::Core &core):
  core(core), window(*this), gui(this->window)
{
  this->window.getWin()->getDevice()->getCursorControl()->setVisible(false); // CURSEUR INVISIBLE
}

irr::scene::ISceneNode		*AoL::rendering::Renderer::createScene()
{
  irr::s32		id = getId();
  return this->window.getWin()->getDevice()->getSceneManager()->addEmptySceneNode(0, id);
}

void		AoL::rendering::Renderer::renderMap(AoL::Game::Map &m,
						    AoL::rendering::Scene3d &s)
{
  auto it = m.getAllEntities().begin();
  while (it != m.getAllEntities().end())
    {
      if (it->second)
	{
	  s.update(it->first, *it->second);
	  ++it;
	}
      else
	{
	  s.remove(it->first);
	  it = m.getAllEntities().erase(it);
	}
    }
  AoL::Game::Controlled *hoverControlled = m.getHoverControlled();
  if (hoverControlled)
    s.update(hoverControlled->getId(), *hoverControlled);
  s.render();
}

void		AoL::rendering::Renderer::renderScene(AoL::Scenes::AScene &scene)
{
  this->renderMap(scene.getMap(), scene.getScene3d());
}

AoL::rendering::Renderer::~Renderer()
{

}
