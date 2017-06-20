#include <cstdlib>
#include <algorithm>
#include <utility>
#include "rendering/Context.hpp"
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedMenu.hpp"
#include "rendering/Gui/RenderedNewGame.hpp"
#include "rendering/Gui/RenderedAI.hpp"
#include "rendering/Gui/RenderedOption.hpp"
#include "rendering/Gui/RenderedKeysBinding.hpp"
#include "rendering/Gui/RenderedPressKey.hpp"
#include "rendering/Gui/RenderedStats.hpp"
#include "rendering/Gui/RenderedActions.hpp"
#include "rendering/Gui/RenderedInfos.hpp"
#include "rendering/Gui/RenderedPause.hpp"
#include "rendering/Gui/RenderedGeneralScore.hpp"
#include "rendering/Gui/RenderedEcoScore.hpp"
#include "rendering/Gui/RenderedFightScore.hpp"
#include "rendering/Gui/RenderedLazyScore.hpp"
#include "rendering/Gui/RenderedEndGame.hpp"
#include "rendering/Gui/RenderedLoadGame.hpp"
#include "rendering/Gui/RenderedEncyclopedie.hpp"
#include "Game/Entity.hpp"
#include "Game/Units/Collector.hpp"
#include "Game/Buildings/Forum.hpp"

AoL::rendering::Gui::Gui(AoL::rendering::Context &window)
{
  this->initializeDrivers(window);
  this->defineClasses();
}

void	AoL::rendering::Gui::initializeDrivers(AoL::rendering::Context &window)
{
  if ((this->_device = window.getWin()->getDevice()) == nullptr ||
      (this->_driver = window.getWin()->getDriver()) == nullptr ||
      (this->_env = this->_device->getGUIEnvironment()) == nullptr ||
      (this->_skin = this->_env->getSkin()) == nullptr ||
      (this->_inputHandler = window.getInputHandler()) == nullptr)
    {
      std::cerr << "Couldn't load textures" << std::endl;
      std::exit(1);
    }
  this->_inspectedElement = nullptr;
  this->_inspectedPlayer = nullptr;
}

void	AoL::rendering::Gui::defineClasses()
{
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_MENU,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedMenu(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_NEWGAME,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedNewGame(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_AI,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedAI(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_OPTION,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedOption(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_STAT,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedStats(*this, moduleHolder, this->_inspectedPlayer)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_ACTION,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedActions(*this, moduleHolder, this->_inspectedElement)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_INFO,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedInfos(*this, moduleHolder, this->_inspectedElement)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_GENERAL_SCORE,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedGeneralScore(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_ECO_SCORE,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedEcoScore(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_FIGHT_SCORE,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedFightScore(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_LAZY_SCORE,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedLazyScore(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_ENDGAME,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedEndGame(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_PAUSE,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedPause(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_KEYSBINDING,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedKeysBinding(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_PRESSKEY,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedPressKey(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_LOADGAME,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedLoadGame(*this, moduleHolder)); } ));
  this->_typeClass
    .emplace(AoL::Gui::GUITypeId::M_ENCYCLO,
	     ([this] (AoL::Gui::ModuleHolder *moduleHolder)
	      {
		this->_modules.
		  push_back(new AoL::rendering::RenderedEncyclopedie(*this, moduleHolder)); } ));
}

AoL::rendering::Gui::~Gui()
{
}

void		AoL::rendering::Gui::setFont(std::string const &path, irr::gui::EGUI_DEFAULT_FONT fontType)
{
  irr::gui::IGUIFont	*font = this->_env->getFont(path.c_str());

  if (font != nullptr)
    this->_skin->setFont(font, fontType);
}

void			AoL::rendering::Gui::setWindowDefaultColor(irr::video::SColor color)
{
  this->_skin->setColor(irr::gui::EGDC_WINDOW, color);
}

void			AoL::rendering::Gui::setTextDefaultColor(irr::video::SColor color)
{
  this->_skin->setColor(irr::gui::EGDC_BUTTON_TEXT, color);
}

void			AoL::rendering::Gui::setBackground(std::string const &path)
{
  irr::video::ITexture	*texture = this->_driver->getTexture(path.c_str());
  irr::gui::IGUIImage	*img = this->_env->addImage(irr::core::rect<irr::s32>(0, 0, AoL::Constants::Rendering::g_screen_width, AoL::Constants::Rendering::g_screen_height));
  img->setImage(texture);
  img->setScaleImage(true);
  this->_driver->removeTexture(texture);
}

void			AoL::rendering::Gui::modifyModuleAction(AoL::Game::Entity *entity, bool visible)
{
  this->_modules[AoL::Gui::GUITypeId::M_ACTION]->setVisible(visible);
  dynamic_cast<AoL::rendering::RenderedActions *>(this->_modules[AoL::Gui::GUITypeId::M_ACTION])->setEntity(entity);
}

void			AoL::rendering::Gui::modifyModuleInfo(AoL::Game::Entity *entity, bool visible)
{
  this->_modules[AoL::Gui::GUITypeId::M_INFO]->setVisible(visible);
  dynamic_cast<AoL::rendering::RenderedInfos *>(this->_modules[AoL::Gui::GUITypeId::M_INFO])->setEntity(entity);

}

void			AoL::rendering::Gui::modifyInspector(AoL::Game::Entity *entity)
{
  AoL::Game::Controlled	*controlled;

  this->_inspectedElement = entity;


  if (entity != nullptr)
  {
    this->modifyModuleInfo(entity, true);
    if (((controlled = dynamic_cast<AoL::Game::Controlled *>(entity)) == nullptr
	  || controlled->getTeam() == this->_inspectedPlayer->getTeam())
	&& (dynamic_cast<AoL::Game::Collector *>(entity) != nullptr
	  || dynamic_cast<AoL::Game::Forum *>(entity) != nullptr))
    {
      this->modifyModuleAction(entity, true);
      return ;
    }
  }
  else
    this->modifyModuleInfo(nullptr, false);
  this->modifyModuleAction(nullptr, false);
}

void			AoL::rendering::Gui::modifyPlayer(AoL::Game::Player *player)
{
  this->_inspectedPlayer = player;
}

void			AoL::rendering::Gui::setGui(AoL::Gui::IUserInterface &interface)
{
  auto			modulesHolder = interface.getModulesHolder();

  for (unsigned int i = 0; i < modulesHolder.size(); i++)
  {
    auto it = this->_typeClass.find(modulesHolder[i]->getType());

    if (it != this->_typeClass.end())
      it->second(modulesHolder[i]);
  }
}

void			AoL::rendering::Gui::guiEvents()
{
  if (this->_inputHandler->_mouseHandler.getEvent(AoL::UserInput::MouseAttributs::GUI))
  {
    irr::s32 actionId = this->_inputHandler->_mouseHandler.getIdGUI();
    for (irr::u32 i = 0; i < this->_modules.size(); i++)
      this->_modules[i]->verifyFunctionToBeCalled(static_cast<AoL::Gui::GUITypeId>(actionId));
  }
}

void			AoL::rendering::Gui::draw()
{
  this->_env->drawAll();
  auto entity = dynamic_cast<AoL::Game::Controlled *>(this->_inspectedElement);
  if (entity != nullptr && entity->getHP() <= 0)
    this->modifyInspector(nullptr);
  for (irr::u32 i = 0; i < this->_modules.size(); i++)
    this->_modules[i]->draw();
}

void			AoL::rendering::Gui::clear()
{
  this->_modules.clear();
  this->_inspectedElement = nullptr;
  this->_inspectedPlayer = nullptr;
  this->_env->clear();
}
