#pragma once

#include <vector>
#include <string>
#include <locale>
#include <codecvt>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <stack>
#include "../irrlicht/irrlicht.h"

struct		Pos
{
  irr::s32	x;
  irr::s32	y;
};

struct		Entity
{
  irr::s32	hp;
  irr::s32	ap;
  irr::s32	damage;
  Pos		position;
};

struct		Player
{
  irr::s32	wood;
  irr::s32	stone;
  irr::s32	gold;
  irr::s32	food;
  std::string	name;
  std::vector<Entity> entities;
};

class		SaveGame
{
  irr::IrrlichtDevice	*_device;
  std::wstring_convert<std::codecvt_utf8<wchar_t>> _converter;
  irr::io::path		_file;
  std::vector<Player>	_load;
  irr::s32		_idxPlayer;
  irr::s32		_idxEntity;

  const std::vector<std::wstring>   _section =
  {
    L"AOL",
    L"SaveGame",
    L"player",
    L"infos",
    L"entities",
    L"Stats",
    L"Position",
  };

  const std::unordered_map<std::wstring, std::function<void (SaveGame &, std::stack<std::wstring> &, std::wstring const &)>>  _verifSection = 
  {
    {L"", &SaveGame::lookForAol},
    {L"AOL", &SaveGame::lookForSaveGame},
    {L"SaveGame", &SaveGame::lookForPlayer},
    {L"player", &SaveGame::lookForInfos},
    {L"infos", &SaveGame::lookForEntities},
    {L"entities", &SaveGame::lookForStats},
    {L"Stats", &SaveGame::lookForPosition},
    {L"Position", &SaveGame::sectionError},
  };

  const std::unordered_map<std::wstring, std::function<void (SaveGame &, irr::io::IXMLReader *)>> _funcSection = 
  {
    {L"player", &SaveGame::addPlayer},
    {L"entities", &SaveGame::addEntity},
    {L"infos", &SaveGame::getInfos},
    {L"Stats", &SaveGame::getStats},
    {L"Position", &SaveGame::getPosition},
  };

  public:
    SaveGame(irr::IrrlichtDevice *device) : _device(device), _file(""), _idxPlayer(-1), _idxEntity(-1) {};
    ~SaveGame() {};
    void		save(std::vector<Player> const &);
    void		load();
    void		setFile(std::string const &file) {_file = file.c_str(); }
    std::vector<Player> const &getElementLoaded() const { return _load; }

  private:
    void		lookForAol(std::stack<std::wstring> &, std::wstring const &);
    void		lookForSaveGame(std::stack<std::wstring> &, std::wstring const &);
    void		lookForPlayer(std::stack<std::wstring> &, std::wstring const &);
    void		lookForInfos(std::stack<std::wstring> &, std::wstring const &);
    void		lookForEntities(std::stack<std::wstring> &, std::wstring const &);
    void		lookForStats(std::stack<std::wstring> &, std::wstring const &);
    void		lookForPosition(std::stack<std::wstring> &, std::wstring const &);
    void		sectionError(std::stack<std::wstring> &, std::wstring const &);
    void		addPlayer(irr::io::IXMLReader *);
    void		addEntity(irr::io::IXMLReader *);
    void		getInfos(irr::io::IXMLReader *);
    void		getStats(irr::io::IXMLReader *);
    void		getPosition(irr::io::IXMLReader *);
};
