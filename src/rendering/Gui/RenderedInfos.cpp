#include <algorithm>
#include <vector>
#include <unordered_map>
#include "Game/Player.hpp"
#include "Game/Ressources/Ressource.hpp"
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedInfos.hpp"
#include "rendering/Gui/RenderedSimpleButton.hpp"
#include "rendering/Gui/RenderedHPLife.hpp"
#include "rendering/Gui/RenderedXPBar.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"
#include "Game/Units/Collector.hpp"

AoL::rendering::RenderedInfos::RenderedInfos(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder, AoL::Game::Entity *entity)
  : ARenderedModule(gui, moduleHolder), _inspectedEntity(entity)
{
  this->_backgrImage->setVisible(true);
  this->_buttons.push_back(
      new RenderedHPLife(
	*this,
	moduleHolder->getModule()->getButtonsHolder()[0],
	this->_inspectedEntity)
      );
  this->_buttons.push_back(
      new RenderedXPBar(
	*this,
	moduleHolder->getModule()->getButtonsHolder()[1],
	this->_inspectedEntity)
      );
  this->setButtons(moduleHolder->getModule());
  this->setVisible(((entity)? true : false));
}

AoL::rendering::RenderedInfos::~RenderedInfos()
{}

void		AoL::rendering::RenderedInfos::setButtons(AoL::Gui::IModule *module)
{
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (irr::u32 i = 2; i < buttonHolder.size(); i++)
    this->_buttons.push_back(new RenderedSimpleButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedInfos::verifyFunctionToBeCalled(AoL::Gui::GUITypeId)
{}

std::vector<AoL::rendering::ARenderedElement *>::iterator	AoL::rendering::RenderedInfos::findButtonById(AoL::Gui::GUITypeId id)
{
  auto it = std::find_if(this->_buttons.begin(),
      this->_buttons.end(),
      [id](AoL::rendering::ARenderedElement *b)
      { return (b->getType() == id); });
  return (it);
}

void		AoL::rendering::RenderedInfos::setButtonVisibleById(AoL::Gui::GUITypeId id, bool visible)
{
  auto it = this->findButtonById(id);
  if (it != this->_buttons.end())
    (*it)->setVisible(visible);
}

void		AoL::rendering::RenderedInfos::setEntity(AoL::Game::Entity *entity)
{
  std::unordered_map<AoL::Game::EntityName, std::string>
    entityPicturePath =
    {
      {AoL::Game::EntityName::COLLECTOR,
	"Assets/textures/medievalCollector.png"},
      {AoL::Game::EntityName::FORUM,
	"Assets/textures/medievalForum.png"},
      {AoL::Game::EntityName::HABITATION,
	"Assets/textures/medievalHouse.png"},
      {AoL::Game::EntityName::LUMBERCAMP,
	"Assets/textures/medievalLumberCamp.png"},
      {AoL::Game::EntityName::MILL,
	"Assets/textures/medievalMill.png"},
      {AoL::Game::EntityName::MININGCAMP,
	"Assets/textures/medievalSmithy.png"},
      {AoL::Game::EntityName::WARRIOR,
	"Assets/textures/medievalWarrior.png"},
      {AoL::Game::EntityName::NFOOD,
	"Assets/textures/medievalFood.png"},
      {AoL::Game::EntityName::NWOOD,
	"Assets/textures/medievalTrees.png"},
      {AoL::Game::EntityName::NSTONE,
	"Assets/textures/medievalStone.png"},
      {AoL::Game::EntityName::NGOLD,
	"Assets/textures/medievalMine.png"},
    };

  this->_inspectedEntity = entity;
  if (entity != nullptr)
  {
    if (this->_inspectedEntity->getType() != AoL::Game::EntityType::RESSOURCE &&
	this->_inspectedEntity->getType() != AoL::Game::EntityType::BUILDING)
      this->setButtonVisibleById(AoL::Gui::GUITypeId::B_ATTACK, true);
    else
      this->setButtonVisibleById(AoL::Gui::GUITypeId::B_ATTACK, false);
    this->_buttons.back()->setFirstImage(*this, entityPicturePath[this->_inspectedEntity->getName()]);
  }
      dynamic_cast<AoL::rendering::RenderedBarButton *>((*this->findButtonById(AoL::Gui::GUITypeId::B_HEALTH)))->setEntity(entity);
      dynamic_cast<AoL::rendering::RenderedBarButton *>((*this->findButtonById(AoL::Gui::GUITypeId::B_XP)))->setEntity(entity);
}

void			AoL::rendering::RenderedInfos::setHPLife()
{
  auto controlled = dynamic_cast<AoL::Game::Controlled *>(this->_inspectedEntity);
  if (!controlled)
    return ;
  std::wstring		txt = std::to_wstring(controlled->getHP()) + L" / " + std::to_wstring(controlled->getMaxHP());
  irr::gui::IGUIFont	*bckp = this->getGUI().getSkin()->getFont();

  this->getGUI().setFont("Assets/fonts/font18.xml", TITLE);

  irr::core::rect<irr::s32>	rectangleText(
      this->_moduleInfo.posX + this->_buttons[0]->getInfo().posX,
      this->_moduleInfo.posY + this->_buttons[0]->getInfo().posY,
      this->_moduleInfo.posX + this->_buttons[0]->getInfo().posX + this->_buttons[0]->getInfo().width,
      this->_moduleInfo.posY + this->_buttons[0]->getInfo().posY + this->_buttons[0]->getInfo().height);

  this->getGUI().getSkin()->getFont()->draw(
      txt.c_str(),
      rectangleText,
      BLACK,
      true,
      true,
      &rectangleText);
  this->getGUI().getSkin()->setFont(bckp, TITLE);
}

void			AoL::rendering::RenderedInfos::setXP()
{
  auto controlled = dynamic_cast<AoL::Game::Unit *>(this->_inspectedEntity);
  if (!controlled)
    return ;
  std::wstring		txt = std::to_wstring(controlled->getCurrExp()) + L" / " + std::to_wstring(controlled->getLevelStep()) + L" (lvl: " + std::to_wstring(controlled->getLevel()) + L")";
  irr::gui::IGUIFont	*bckp = this->getGUI().getSkin()->getFont();

  this->getGUI().setFont("Assets/fonts/font12.xml", TITLE);

  irr::core::rect<irr::s32>	rectangleText(
      this->_moduleInfo.posX + this->_buttons[1]->getInfo().posX,
      this->_moduleInfo.posY + this->_buttons[1]->getInfo().posY,
      this->_moduleInfo.posX + this->_buttons[1]->getInfo().posX + this->_buttons[1]->getInfo().width,
      this->_moduleInfo.posY + this->_buttons[1]->getInfo().posY + this->_buttons[1]->getInfo().height);

  this->getGUI().getSkin()->getFont()->draw(
      txt.c_str(),
      rectangleText,
      BLACK,
      true,
      true,
      &rectangleText);
  this->getGUI().getSkin()->setFont(bckp, TITLE);
}

void		AoL::rendering::RenderedInfos::writeTeam()
{
  auto controlled = dynamic_cast<AoL::Game::Controlled *>(this->_inspectedEntity);
  if (!controlled)
    return ;


  std::unordered_map<AoL::Game::Team, irr::video::SColor> colorText =
  {
    {AoL::Game::Team::TEAM_ONE, BLUE},
    {AoL::Game::Team::TEAM_TWO, RED},
    {AoL::Game::Team::TEAM_THREE, GREEN},
    {AoL::Game::Team::TEAM_FOUR, YELLOW},
  };

  std::wstring		txt = L"Team: Player " + std::to_wstring(static_cast<irr::s32>(controlled->getTeam()) + 1);
  irr::gui::IGUIFont	*bckp = this->getGUI().getSkin()->getFont();

  this->getGUI().setFont("Assets/fonts/font18.xml", TITLE);

  irr::core::rect<irr::s32>	rectangleText(
      this->_moduleInfo.posX + 70 * this->_moduleInfo.width / 100,
      this->_moduleInfo.posY + 5 * this->_moduleInfo.height / 100,
      this->_moduleInfo.posX + 70 * this->_moduleInfo.width / 100 + 20 * this->_moduleInfo.width / 100,
      this->_moduleInfo.posY + 5 * this->_moduleInfo.height / 100 + 13 * this->_moduleInfo.height / 100);

  this->getGUI().getSkin()->getFont()->draw(
      txt.c_str(),
      rectangleText,
      colorText[controlled->getTeam()],
      true,
      true,
      &rectangleText);
  this->getGUI().getSkin()->setFont(bckp, TITLE);
}

void		AoL::rendering::RenderedInfos::draw()
{
  if (this->_inspectedEntity != nullptr)
  {
    if (this->_inspectedEntity->getType() != AoL::Game::EntityType::RESSOURCE)
    {
      (*this->findButtonById(AoL::Gui::GUITypeId::B_HEALTH))->draw(this->getGUI());

      if (this->_inspectedEntity->getType() != AoL::Game::EntityType::BUILDING)
      {
	(*this->findButtonById(AoL::Gui::GUITypeId::B_XP))->draw(this->getGUI());
	auto controlled = dynamic_cast<AoL::Game::Controlled *>(this->_inspectedEntity);
	if (controlled)
	  (*this->findButtonById(AoL::Gui::GUITypeId::B_ATTACK))->
	    modifyText(std::to_wstring(controlled->getAP()).c_str());
      }
    }
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_WOOD));
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_FOOD));
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_STONE));
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_GOLD));
    this->writeTeam();
    this->setHPLife();
    this->setXP();
  }
}

void		AoL::rendering::RenderedInfos::setButtonTextForType(std::vector<AoL::rendering::ARenderedElement *>::iterator it)
{
  std::wstring text = L"";
  std::unordered_map<AoL::Gui::GUITypeId, AoL::Game::RessourceType>	type =
  {
    {AoL::Gui::GUITypeId::B_WOOD, AoL::Game::RessourceType::WOOD},
    {AoL::Gui::GUITypeId::B_FOOD, AoL::Game::RessourceType::FOOD},
    {AoL::Gui::GUITypeId::B_STONE, AoL::Game::RessourceType::STONE},
    {AoL::Gui::GUITypeId::B_GOLD, AoL::Game::RessourceType::GOLD}
  };

  text += std::to_wstring(this->_inspectedEntity->getStock().getNb(type[(*it)->getType()]));
  text += L" / ";
  text += std::to_wstring(this->_inspectedEntity->getStock().getMax(type[(*it)->getType()]));
  (*it)->modifyText(text.c_str());
}

void		AoL::rendering::RenderedInfos::setVisible(bool visible)
{
  for (irr::u32 i = 2; i < this->_buttons.size(); i++)
    this->_buttons[i]->setVisible(visible);
}

