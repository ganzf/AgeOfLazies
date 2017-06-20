#include <vector>
#include <algorithm>
#include "Game/Player.hpp"
#include "Game/Ressources/Ressource.hpp"
#include "rendering/Gui/Gui.hpp"
#include "rendering/Gui/RenderedStats.hpp"
#include "rendering/Gui/RenderedClickButton.hpp"
#include "rendering/Gui/RenderedSimpleButton.hpp"
#include "rendering/Gui/RenderedTextButton.hpp"

AoL::rendering::RenderedStats::RenderedStats(AoL::rendering::Gui &gui, AoL::Gui::ModuleHolder *moduleHolder, AoL::Game::Player *player)
  : ARenderedModule(gui, moduleHolder), _inspectedPlayer(player)
{
  this->setButtons(moduleHolder->getModule());
}

AoL::rendering::RenderedStats::~RenderedStats()
{}

void		AoL::rendering::RenderedStats::setButtons(AoL::Gui::IModule *module)
{
  irr::u32	i = 0;
  std::vector<AoL::Gui::ButtonHolder *>	buttonHolder = module->getButtonsHolder();

  for (i = 0; i < buttonHolder.size() - 1; i++)
    this->_buttons.push_back(new RenderedSimpleButton(*this, buttonHolder[i]));
  this->_buttons.push_back(new RenderedClickButton(*this, buttonHolder[i]));
}

void		AoL::rendering::RenderedStats::verifyFunctionToBeCalled(AoL::Gui::GUITypeId functionId)
{
  for (irr::u32 i = 0; i < this->_buttons.size(); i++)
    if (this->_buttons[i]->getType() == functionId)
      this->_buttons[i]->callFunction();
}

void		AoL::rendering::RenderedStats::setPlayer(AoL::Game::Player *player)
{
  this->_inspectedPlayer = player;
}

void		AoL::rendering::RenderedStats::draw()
{
  if (this->_inspectedPlayer != nullptr)
  {
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_WOOD));
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_FOOD));
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_STONE));
    this->setButtonTextForType(this->findButtonById(AoL::Gui::GUITypeId::B_GOLD));
    this->setButtonTextForPeople(this->findButtonById(AoL::Gui::GUITypeId::B_PEOPLE));
    this->setTimer(this->findButtonById(AoL::Gui::GUITypeId::B_TIMER));
  }
}

std::vector<AoL::rendering::ARenderedElement *>::iterator	AoL::rendering::RenderedStats::findButtonById(AoL::Gui::GUITypeId id)
{
  auto it = std::find_if(this->_buttons.begin(),
      this->_buttons.end(),
      [id](AoL::rendering::ARenderedElement *b)
      { return (b->getType() == id); });
  return (it);
}

void		AoL::rendering::RenderedStats::setTimer(std::vector<AoL::rendering::ARenderedElement *>::iterator it)
{
  std::wstring txt = L"Years left: " + std::to_wstring(this->_inspectedPlayer->getTimerDefeat() / 60 - static_cast<irr::s32>(this->_inspectedPlayer->getTimer().getTime()) / 60);
  (*it)->modifyText(txt.c_str());
}

void		AoL::rendering::RenderedStats::setButtonTextForType(std::vector<AoL::rendering::ARenderedElement *>::iterator it)
{
  if (it == this->_buttons.end())
    return ;

  std::unordered_map<AoL::Gui::GUITypeId, AoL::Game::RessourceType>	type =
  {
    {AoL::Gui::GUITypeId::B_WOOD, AoL::Game::RessourceType::WOOD},
    {AoL::Gui::GUITypeId::B_FOOD, AoL::Game::RessourceType::FOOD},
    {AoL::Gui::GUITypeId::B_STONE, AoL::Game::RessourceType::STONE},
    {AoL::Gui::GUITypeId::B_GOLD, AoL::Game::RessourceType::GOLD}
  };

  std::wstring text = std::to_wstring(this->_inspectedPlayer->getStock().getNb(type[(*it)->getType()]));
  (*it)->modifyText(text.c_str());
}

void	AoL::rendering::RenderedStats::setButtonTextForPeople(std::vector<AoL::rendering::ARenderedElement *>::iterator it)
{
  if (it == this->_buttons.end())
    return ;

  std::wstring text = L"";

  text += std::to_wstring(this->_inspectedPlayer->getUnits().size());
  text += L" / ";
  text += std::to_wstring(this->_inspectedPlayer->getPopulation());
  (*it)->modifyText(text.c_str());
}

