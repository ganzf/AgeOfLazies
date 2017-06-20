#include <locale>
#include <codecvt>
#include <iostream>
#include "../../include/Save/SaveGame.hpp"

void		SaveGame::save(std::vector<Player> const &players)
{
  irr::io::IXMLWriter	*xwriter = _device->getFileSystem()->createXMLWriter(_file);

  if (!xwriter)
    throw std::exception();
  xwriter->writeXMLHeader();
  xwriter->writeElement(L"AOL");
  xwriter->writeLineBreak();
  xwriter->writeElement(L"SaveGame");
  xwriter->writeLineBreak();
  for (auto const &player: players)
  {
    xwriter->writeElement(L"player");
    xwriter->writeLineBreak();
    std::wstring name = _converter.from_bytes(player.name);
    xwriter->writeElement(L"infos", true,
	L"name", name.c_str(),
	L"wood", std::to_wstring(player.wood).c_str(),
	L"gold", std::to_wstring(player.gold).c_str(),
	L"stone", std::to_wstring(player.stone).c_str(),
	L"food", std::to_wstring(player.food).c_str());
    xwriter->writeLineBreak();
    xwriter->writeElement(L"entities");
    xwriter->writeLineBreak();
    for (auto const &entity: player.entities)
    {
      xwriter->writeElement(L"Stats", true,
	  L"hp", std::to_wstring(entity.hp).c_str(),
	  L"ap", std::to_wstring(entity.ap).c_str(),
	  L"damage", std::to_wstring(entity.damage).c_str());
      xwriter->writeLineBreak();
      xwriter->writeElement(L"Position", true,
	  L"posX", std::to_wstring(entity.position.x).c_str(),
	  L"posY", std::to_wstring(entity.position.y).c_str());
      xwriter->writeLineBreak();
    }
    xwriter->writeClosingTag(L"entities");
    xwriter->writeLineBreak();
    xwriter->writeClosingTag(L"player");
    xwriter->writeLineBreak();
  }
  xwriter->writeClosingTag(L"SaveGame");
  xwriter->writeLineBreak();
  xwriter->writeClosingTag(L"AOL");
  xwriter->drop();
}

void		SaveGame::addPlayer(irr::io::IXMLReader *)
{
  Player	newPlayer;

  _load.push_back(newPlayer);
  _idxPlayer += 1;
  _idxEntity = -1;
}

void		SaveGame::addEntity(irr::io::IXMLReader *)
{
}

void		SaveGame::getInfos(irr::io::IXMLReader *xreader)
{
  std::wstring	name = xreader->getAttributeValueSafe(L"name");
  std::wstring	wood = xreader->getAttributeValueSafe(L"wood");
  std::wstring	gold = xreader->getAttributeValueSafe(L"gold");
  std::wstring	stone = xreader->getAttributeValueSafe(L"stone");
  std::wstring	food = xreader->getAttributeValueSafe(L"food");

  if (name.empty() || wood.empty() || gold.empty() || stone.empty() || food.empty())
    throw std::exception();
  _load[_idxPlayer].wood = std::stoi(wood);
  _load[_idxPlayer].gold = std::stoi(gold);
  _load[_idxPlayer].stone = std::stoi(stone);
  _load[_idxPlayer].food = std::stoi(food);
  _load[_idxPlayer].name = _converter.to_bytes(name);
}

void		SaveGame::getStats(irr::io::IXMLReader *xreader)
{
  Entity	newEntity;
  std::wstring	hp = xreader->getAttributeValueSafe(L"hp");
  std::wstring	ap = xreader->getAttributeValueSafe(L"ap");
  std::wstring	damage = xreader->getAttributeValueSafe(L"damage");

  if (hp.empty() || ap.empty() || damage.empty())
    throw std::exception();
  _load[_idxPlayer].entities.push_back(newEntity);
  _idxEntity += 1;
  _load[_idxPlayer].entities[_idxEntity].hp = std::stoi(hp);
  _load[_idxPlayer].entities[_idxEntity].ap = std::stoi(ap);
  _load[_idxPlayer].entities[_idxEntity].damage = std::stoi(damage);
}

void		SaveGame::getPosition(irr::io::IXMLReader *xreader)
{
  std::wstring	posx = xreader->getAttributeValueSafe(L"posX");
  std::wstring	posy = xreader->getAttributeValueSafe(L"posY");

  if (posx.empty() || posy.empty())
    throw std::exception();
  _load[_idxPlayer].entities[_idxEntity].position.x = std::stoi(posx);
  _load[_idxPlayer].entities[_idxEntity].position.y = std::stoi(posy);
}

void		SaveGame::lookForAol(std::stack<std::wstring> &sectionStack, std::wstring const &section)
{
  if (section == L"AOL")
    sectionStack.push(section);
  else
    throw std::exception();
}

void		SaveGame::lookForSaveGame(std::stack<std::wstring> &sectionStack, std::wstring const &section)
{
  if (section == L"SaveGame")
    sectionStack.push(section);
  else
    throw std::exception();
}

void		SaveGame::lookForPlayer(std::stack<std::wstring> &sectionStack, std::wstring const &section)
{
  if (section == L"player")
    sectionStack.push(section);
  else
    throw std::exception();
}

void		SaveGame::lookForInfos(std::stack<std::wstring> &sectionStack, std::wstring const &section)
{
  if (section == L"infos")
    sectionStack.push(section);
  else if (section != L"player")
    throw std::exception();
}

void		SaveGame::lookForEntities(std::stack<std::wstring> &sectionStack, std::wstring const &section)
{
  if (section == L"entities")
    sectionStack.push(section);
  else
    throw std::exception();
}

void		SaveGame::lookForStats(std::stack<std::wstring> &sectionStack, std::wstring const &section)
{
  if (section == L"Stats")
    sectionStack.push(section);
  else
    throw std::exception();
}

void		SaveGame::lookForPosition(std::stack<std::wstring> &sectionStack, std::wstring const &section)
{
  if (section == L"Position")
    sectionStack.push(section);
  else
    throw std::exception();
}

void		SaveGame::sectionError(std::stack<std::wstring> &, std::wstring const &)
{
  throw std::exception();
}

void		SaveGame::load()
{
  irr::io::IXMLReader	*xreader = _device->getFileSystem()->createXMLReader(_file);
  irr::io::EXML_NODE	nodeType;
  std::stack<std::wstring>  sectionStack;

  if (!xreader)
    throw std::exception();
  while (xreader->read())
  {
    if (!sectionStack.empty())
      std::wcout << L"Top of section Stack : " << sectionStack.top() << std::endl;
    std::wcout << L"Current Section : " << xreader->getNodeName() << "\n" << std::endl;
    nodeType = xreader->getNodeType();
    if (nodeType == irr::io::EXN_ELEMENT)
    {
      if (std::find(_section.begin(), _section.end(), xreader->getNodeName()) == _section.end())
	throw std::exception();
      if (sectionStack.empty())
	this->_verifSection.at(L"")(*this, sectionStack, xreader->getNodeName());
      else
	this->_verifSection.at(sectionStack.top())(*this, sectionStack, xreader->getNodeName());
      if (_funcSection.find(sectionStack.top()) != _funcSection.end())
	this->_funcSection.at(sectionStack.top())(*this, xreader);
      if (sectionStack.top() == L"Position")
      {
	sectionStack.pop();
	sectionStack.pop();
      }
    }
    else if (nodeType == irr::io::EXN_ELEMENT_END)
      sectionStack.pop(); 
  }
}
