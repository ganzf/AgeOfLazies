#include <fstream>
#include <string>
#include "rendering/Scene3d.hpp"
#include "Core/Core.hpp"
#include "rendering/Renderer.hpp"
#include "IdGenerator.hpp"
#include "rendering/Animator.hpp"
#include "Game/Map.hpp"

extern AoL::IdGenerator getId;

AoL::rendering::Scene3d::Scene3d(AoL::rendering::Renderer &renderer):
  renderer(renderer),
  scene(renderer.getSceneManager()),
  camera(scene, renderer.getWindow().getWin()->getDevice()),
  cursor(renderer.getWindow().getWin()->getDevice()->getCursorControl(), renderer.getWindow().getWin()->getDriver()),
  selector(cursor, scene->getSceneCollisionManager(), camera)
{
  teamColors.insert({{AoL::Game::Team::TEAM_ONE, std::string("B")},
	{AoL::Game::Team::TEAM_TWO, std::string("R")},
	{AoL::Game::Team::TEAM_THREE, std::string("G")},
	{AoL::Game::Team::TEAM_FOUR, std::string("Y")},
	{AoL::Game::Team::UNDEFINED, std::string("")}});
  irr::scene::ILightSceneNode *lumiere = this->scene->addLightSceneNode(0, irr::core::vector3df(0, 20, -30), irr::video::SColorf(1, 1, 1, 0), 10.0f); //SOLEIL
  lumiere->getLightData().Type = irr::video::ELT_DIRECTIONAL;
  this->scene->setAmbientLight(irr::video::SColorf(0.35, 0.35, 0.35, 0.0));
}

void		AoL::rendering::Scene3d::startPreloading()
{
  this->currentPreloadLine = 0;
  this->preloadFile.open("Assets/assetRequirements.txt");
  if (!preloadFile.is_open())
    throw std::runtime_error("Failed to locate assetRequirements.txt file. Please be more careful with your files.");
}

irr::s32	AoL::rendering::Scene3d::preload3dAssets()
{
  if (preloadFile.is_open())
    {
      if (!std::getline(this->preloadFile, preloadLine) || this->preloadLine.size() <= 5)
	preloadFile.close();
      else
	this->scene->getMesh(preloadLine.c_str());
    }
  else
    throw std::runtime_error("Failed to locate assetRequirements.txt file. Please be more careful with your files.");
  this->currentPreloadLine += 1;
  return this->currentPreloadLine;
}

bool		AoL::rendering::Scene3d::createTerrain(irr::core::vector3df dims, irr::core::vector2df const &islandSize)
{
  irr::scene::ITerrainSceneNode *terrain = this->scene->addTerrainSceneNode("Assets/terrain-heightmap.png",
									    0, -1,
									    dims,
									    irr::core::vector3df(0, 0, 0),
									    irr::core::vector3df(7, 0.2, 7),
									    irr::video::SColor(255, 100, 100, 100),
									    5,
									    irr::scene::ETPS_17, 4);
  if (!terrain)
    return (false);
  irr::scene::ITriangleSelector *TerrainSelector = this->scene->createTerrainTriangleSelector(terrain, 0);
  if (!TerrainSelector)
    return (false);
  terrain->setTriangleSelector(TerrainSelector);
  TerrainSelector->drop();
  this->selector.setTerrainSelector(terrain->getTriangleSelector());
  terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  terrain->setMaterialTexture(1, renderer.getWindow().getWin()->getDriver()->getTexture("Assets/terrain-texture.png"));
  terrain->setMaterialType(irr::video::EMT_DETAIL_MAP);
  terrain->scaleTexture(1.0, 80.0f);
  terrain->setMaterialFlag(irr::video::EMF_FOG_ENABLE, true);
  return (true);
}

bool		AoL::rendering::Scene3d::activateFog(irr::s32 distance)
{
  irr::video::IVideoDriver* driver = this->renderer.getWindow().getWin()->getDevice()->getVideoDriver();
  if (!driver)
    return (false);
  driver->setFog(irr::video::SColor(0, 100, 120, 180), irr::video::EFT_FOG_LINEAR, 200, distance, .001f, false, false);
  return (true);
}

bool		AoL::rendering::Scene3d::addWater(irr::core::vector2df dims)
{
  irr::scene::IAnimatedMesh *water_mesh = this->scene->addHillPlaneMesh("Water",
									dims, //WIDTH / HEIGHT
									irr::core::dimension2d<irr::u32>(20, 20), 0, 0, //NB VERTICES X/Y //MATERIAL //DEFORMATION DE BASE
									irr::core::dimension2d<irr::f32>(0, 0), //COUNT HILLS
									irr::core::dimension2d<irr::f32>(80, 80)); //NB TEXTURE
  if (!water_mesh)
    return (false);
  irr::scene::ISceneNode *water = this->scene->addWaterSurfaceSceneNode(water_mesh->getMesh(0), 10.0f, 400.0f, 0.03); //SPEED //RYTHME ms //WAVE LENGTH
  if (!water)
    return (false);
  water->setPosition(irr::core::vector3df(2200, -30, 2200));
  water->setMaterialTexture(0, renderer.getWindow().getWin()->getDriver()->getTexture("Assets/water.png"));
  water->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  water->setMaterialFlag(irr::video::EMF_FOG_ENABLE, true);
  return (true);
}

void		AoL::rendering::Scene3d::setIslandScene(irr::core::vector2df const &islandSize)
{
  if (!this->createTerrain(irr::core::vector3df(-2000, -51, -2000), islandSize)
      || !this->activateFog(500)
      || !this->addWater(irr::core::vector2df(1000, 1000)))
    throw std::runtime_error("Couldn't create island scene.");
}

void				AoL::rendering::Scene3d::entityAddNode(AoL::Game::Entity &ent)
{
  irr::scene::IAnimatedMesh	*model;

  if (dynamic_cast<AoL::Game::Controlled *>(&ent) != nullptr)
    {
      model = this->scene->getMesh((ent.getMesh()
  				    + this->teamColors[ent.getTeam()]
  				    + std::string(".b3d")).c_str());
    }
  else
    model = this->scene->getMesh(ent.getMesh().c_str());

  if (!model)
    throw std::runtime_error("Error while loading model " + ent.getMesh());
  auto vec = ent.getPosition();
  irr::scene::IAnimatedMeshSceneNode *model_node =
    this->scene->addAnimatedMeshSceneNode(model, 0, ent.getId(),
					  irr::core::vector3df(vec.X, 0, vec.Y),
					  irr::core::vector3df(0.0, 0.0, 0.0),
					  irr::core::vector3df(3.0, 3.0, 3.0));

  model_node->setMaterialFlag(irr::video::EMF_FOG_ENABLE, true);
  ent.setNode(model_node);
  ent.setAnimator(std::make_shared<AoL::rendering::Animator>(model_node));
  if (ent.getType() == AoL::Game::EntityType::BUILDING)
    {
      ent.getAnimator()->setAnim(AoL::rendering::AnimFrames::BUILD_ANIM);
      ent.getAnimator()->setBuildingSpeed(ent.getName());
    }
  else
    {
      ent.getAnimator()->setAnim(AoL::rendering::AnimFrames::STAND);
      ent.getAnimator()->setAnimSpeed(AoL::rendering::AnimSpeed::STAND);
    }
}

void		AoL::rendering::Scene3d::entityAddSelector(AoL::Game::Entity &ent)
{
  irr::scene::ITriangleSelector *objSelector = this->scene->createTriangleSelectorFromBoundingBox(ent.getNode());
  if (!objSelector || !ent.getNode())
    throw std::runtime_error("Failure to create selector for object.");
  ent.getNode()->setTriangleSelector(objSelector);
  this->selector.addEntity(&ent, objSelector);
  objSelector->drop();
}

void		AoL::rendering::Scene3d::entityAddAnchors(AoL::Game::Entity &ent)
{
  ent.createAnchors();
  if (ent.getType() == AoL::Game::UNIT)
    return ;
  for ( irr::s32 idx = 0 ; idx < ent.getNbAnchors() ; idx++)
    {
      // irr::scene::ISceneNode *anchor  =
      // 	this->scene->addMeshSceneNode(this->scene->getMesh("Assets/spot.3ds"),
      // 				      ent.getNode(), getId());

      // irr::core::vector2df	const	&tmp2d = ent.getAnchorPosition(idx);
      // irr::core::vector3df		tmp3d;

      // tmp3d.X = (tmp2d.X - ent.getPosition().X) / 3.14;
      // tmp3d.Y = 0;
      // tmp3d.Z = (tmp2d.Y - ent.getPosition().Y) / 3.14;

      // anchor->setPosition(tmp3d);
      // anchor->setScale(ent.getNode()->getBoundingBox().getExtent() / 10);
      // anchor->setVisible(false);
    }
  // ent.getNode()->setScale(ent.getNode()->getScale() * (1 + 0.08 * ent.getNbAnchors() * 2));
}

void		AoL::rendering::Scene3d::add(AoL::Game::Entity *e,
					     bool addAnchors)
{
  if (e == nullptr)
    return ;
  this->safeLock.lock();
  this->entityAddNode(*e);
  this->entityAddSelector(*e);
  if (addAnchors)
    this->entityAddAnchors(*e);
  this->safeLock.unlock();
}

bool		AoL::rendering::Scene3d::contains(irr::s32 id)
{
  return this->scene->getSceneNodeFromId(id) != nullptr;
}

void		AoL::rendering::Scene3d::remove(irr::s32 id)
{
  if (this->contains(id))
    {
      this->scene->addToDeletionQueue(this->scene->getSceneNodeFromId(id));
      this->selector.removeEntity(id);
    }
}

void		AoL::rendering::Scene3d::render()
{
  this->scene->drawAll();
  this->drawGui();
  this->cursor.draw();

  int	fps = this->renderer.getWindow().getWin()->getDriver()->getFPS();
  int	lastFPS = 0;

  if (lastFPS != fps)
    {
      irr::core::stringw str = L"Age Of Lazies [";
      str += this->renderer.getWindow().getWin()->getDriver()->getName();
      str += "] FPS:";
      str += fps;

      this->renderer.getWindow().getWin()->getDevice()->setWindowCaption(str.c_str());
      lastFPS = fps;
    }
}

void				AoL::rendering::Scene3d::centerCameraOn(AoL::Game::Entity &ent)
{
  irr::core::vector2df		tmp = ent.getPosition();

  // On devrait modifier cette valeur par le zoom actuel idealement. Ou alors reset le zoom...
  tmp.X -= this->camera.getPosition().Y;
  tmp.Y -= this->camera.getPosition().Y;
  this->camera.setPosition(tmp);
}

void				AoL::rendering::Scene3d::centerCameraOn(irr::core::vector2df const &pos)
{
  irr::core::vector2df		tmp(pos.X, pos.Y);
  tmp.X -= 100;
  tmp.Y -= 100;
  this->camera.setPosition(tmp);
}

irr::core::vector3df		AoL::rendering::Scene3d::getRotationFromAngle(irr::f32 angle)
{
  irr::core::vector3df	vector;

  vector.Y = angle;
  vector.Z = 0;
  vector.X = 0;
  return (vector);
}

void		AoL::rendering::Scene3d::update(irr::s32, AoL::Game::Entity &e)
{
  irr::core::vector3df	newpos;
  newpos.X = e.getPosition().X;
  newpos.Z = e.getPosition().Y;
  irr::f32	zOffset = 0;
  if (e.getName() == AoL::Game::EntityName::NWOOD)
    zOffset = e.getStock().getNb(AoL::Game::RessourceType::WOOD) / 16;
  newpos.Y = zOffset;
  if (e.getNode())
    {
      e.getNode()->setPosition(newpos);
      e.getNode()->setRotation(getRotationFromAngle(e.getRotation()));
    }
}

void		AoL::rendering::Scene3d::createGrid(AoL::Game::Grid const &grid)
{
  irr::core::vector2di	tmp(0, 0);
  irr::s32		scale = grid.getScale();
  irr::core::vector2di	tmpEnd(grid.getEnd());
  irr::s32		i = 0;

  tmpEnd.X /= scale;
  tmpEnd.Y /= scale;
  while (tmp.Y < tmpEnd.Y)
    {
      irr::scene::ISceneNode *cube = this->scene->addCubeSceneNode(20, 0, getId(),
								   irr::core::vector3df(tmp.X * scale - tmpEnd.X * scale / 2,
											-0,
											tmp.Y * scale - tmpEnd.Y * scale / 2));
      if (tmp.X == 0)
	this->scene->addCubeSceneNode(10, 0, getId(),
				      irr::core::vector3df(tmp.X * scale - tmpEnd.X * scale / 2,
							   5,
							   tmp.Y * scale - tmpEnd.Y * scale / 2));

      if (tmp.X == tmpEnd.X - 1)
	this->scene->addCubeSceneNode(10, 0, getId(),
				      irr::core::vector3df(tmp.X * scale - tmpEnd.X * scale / 2,
							   5,
							   tmp.Y * scale - tmpEnd.Y * scale / 2));

      if (tmp.Y == 0 && tmp.X < tmpEnd.X - 1)
	this->scene->addCubeSceneNode(10, 0, getId(),
				      irr::core::vector3df(tmp.X * scale - tmpEnd.X * scale / 2,
							   0,
							   tmp.Y * scale - tmpEnd.Y * scale / 2));

      if (tmp.Y == tmpEnd.Y - 1 && tmp.X < tmpEnd.X - 1)
	this->scene->addCubeSceneNode(10, 0, getId(),
				      irr::core::vector3df(tmp.X * scale - tmpEnd.X * scale / 2,
							   0,
							   tmp.Y * scale - tmpEnd.Y * scale / 2));

      if (tmp.X == tmpEnd.X)
	{
	  tmp.X = 0;
	  tmp.Y += 1;
	}
      else
	{
	  tmp.X++;
	}
      this->gridCubes[i] = cube;
      i++;
    }
}

void		AoL::rendering::Scene3d::updateGrid(AoL::Game::Grid const &grid)
{
  irr::core::vector2di	tmp(0, 0);
  irr::core::vector2di	tmpEnd(grid.getEnd());
  irr::s32		scale = grid.getScale();
  irr::s32		i = 0;

  tmpEnd.X /= scale;
  tmpEnd.Y /= scale;
  while (tmp.Y < tmpEnd.Y)
    {
      if (tmp.X == tmpEnd.X)
	{
	  tmp.X = 0;
	  tmp.Y += 1;
	}
      else
	{
	  if (grid.isOccupiedAt(irr::core::vector2df(tmp.X * scale - tmpEnd.X * scale / 2, tmp.Y * scale - tmpEnd.Y * scale / 2)) == true)
	    this->gridCubes[i]->setPosition(irr::core::vector3df(tmp.X * scale - tmpEnd.X * scale / 2, 0, tmp.Y * scale - tmpEnd.Y * scale / 2));
	  else
	    this->gridCubes[i]->setPosition(irr::core::vector3df(0, -0, 0));
	  tmp.X += 1;
	}
      i++;
    }
}

AoL::rendering::Scene3d::~Scene3d()
{
  this->scene->clear();
}

void		AoL::rendering::Scene3d::drawGui()
{
  this->renderer.getGui().draw();
}
