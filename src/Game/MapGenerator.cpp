#include <fstream>
#include <algorithm>
#include "../../include/Game/MapGenerator.hpp"

irr::s32		AoL::Game::MapGenerator::genMap()
{
  irr::s32		genOffset = 5;
  _spawnPoints.push_back(genOffset + (genOffset * _sizex));
  _spawnPoints.push_back((_sizex - genOffset) + (genOffset *_sizex));
  _spawnPoints.push_back(genOffset + ((_sizey - genOffset) * _sizex));
  _spawnPoints.push_back((_sizex - genOffset) + ((_sizey - genOffset) * _sizex));
  for (irr::s32 fullshuffle = 0; fullshuffle < 4; fullshuffle++)
    std::random_shuffle(_spawnPoints.begin(), _spawnPoints.end());
  for (irr::s32 i = 0; i < _sizex * _sizey; ++i)
  {
    if (this->randomNumberGenerator(0, _forestCreation) == 0)
      this->createRessources(i, this->randomNumberGenerator(2, 10), AoL::Game::RessourceType::WOOD);
    if (this->randomNumberGenerator(0, _foodCreation) == 0)
      this->createRessources(i, this->randomNumberGenerator(1, 4), AoL::Game::RessourceType::FOOD); 
    if (this->randomNumberGenerator(0, _stoneCreation) == 0)
      this->createRessources(i, this->randomNumberGenerator(1, 4), AoL::Game::RessourceType::STONE);
    if (this->randomNumberGenerator(0, _goldCreation) == 0)
      this->createRessources(i, this->randomNumberGenerator(1, 2), AoL::Game::RessourceType::GOLD);
  }
  return (0);
}

void		AoL::Game::MapGenerator::print_map() const
{
  std::ofstream	file("map");
  if (file.is_open())
  {
    for (irr::s32 i = 0; i < _sizex * _sizey; ++i)
    {
      if (i % _sizex == 0 && i != 0)
	file << std::endl;
      if (_map[i].type == AoL::Game::RessourceType::WOOD)
	file << "0";
      else if (_map[i].type == AoL::Game::RessourceType::FOOD)
	file << "1";
      else if (_map[i].type == AoL::Game::RessourceType::STONE)
	file << "2";
      else if (_map[i].type == AoL::Game::RessourceType::GOLD)
	file << "3";
      else
	file << " ";
    }
    file << std::endl;
  }
}

void		AoL::Game::MapGenerator::createRessources(irr::s32 idx, irr::s32 size, AoL::Game::RessourceType element)
{
  irr::s32		tmp = -1;
  irr::core::vector2df	pos = this->transformTo2dPos(idx);

  for (auto const &spawnPoint: this->_spawnPoints)
    for (auto const &matricePoint: this->_matrice)
      if (idx == spawnPoint + matricePoint)
	return ;
  if (size == 0 || idx >= _sizex * _sizey || _check[idx] == true)
    return ;
  if (idx >= static_cast<irr::s32>(_map.size()) || _map[idx].type != element)
    size -= 1;
  _map.push_back(Tile(pos));
  _map.back().type = element;
  _check[idx] = true;
  irr::s32		direction;
  while (tmp == -1)
  {
    direction = this->randomNumberGenerator(0, 5);
    tmp = this->_directionFuncs[direction](*this, pos);
  }
  this->createRessources(tmp, size, element); 
}

irr::s32		AoL::Game::MapGenerator::randomNumberGenerator(irr::s32 min, irr::s32 max) const
{
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(min, max);
  return dist6(rng);
}

irr::s32		AoL::Game::MapGenerator::moveRight(irr::core::vector2df const &pos) const
{
  if (pos.X + 1 >= _sizex)
    return (-1);
  else
    return (pos.X + 1 + pos.Y * _sizex);
}

irr::s32		AoL::Game::MapGenerator::moveDownRight(irr::core::vector2df const &pos) const
{
  if (pos.X + 1 >= _sizex || pos.Y + 1 >= _sizey)
    return (-1);
  return (pos.X + 1 + (pos.Y + 1) * _sizex);
}

irr::s32		AoL::Game::MapGenerator::moveDown(irr::core::vector2df const &pos) const
{
  if (pos.Y >= _sizey)
    return (-1);
  return (pos.X + (pos.Y + 1) * _sizex);
}

irr::s32		AoL::Game::MapGenerator::moveDownLeft(irr::core::vector2df const &pos) const
{
  if (pos.X == 0 || pos.Y + 1 >= _sizey)
    return (-1);
  return (pos.X - 1 + (pos.Y + 1) * _sizex);
}

irr::s32		AoL::Game::MapGenerator::moveLeft(irr::core::vector2df const &pos) const
{
  if (pos.X == 0)
    return (-1);
  return (pos.X - 1 + pos.Y * _sizex);
}

irr::s32		AoL::Game::MapGenerator::moveUpLeft(irr::core::vector2df const &pos) const
{
  if (pos.X == 0 || pos.Y == 0)
    return (0);
  return (pos.X - 1 + (pos.Y - 1) * _sizex);
}

irr::s32		AoL::Game::MapGenerator::moveUp(irr::core::vector2df const &pos) const
{
  if (pos.Y == 0)
    return (-1);
  return (pos.X + (pos.Y - 1) * _sizex);
}

irr::s32		AoL::Game::MapGenerator::moveUpRight(irr::core::vector2df const &pos) const
{
  if (pos.X + 1 >= _sizex || pos.Y == 0)
    return (-1);
  return (pos.X + 1 + (pos.Y - 1) * _sizex);
}

irr::core::vector2df AoL::Game::MapGenerator::transformTo2dPos(irr::s32 idx) const
{
  irr::core::vector2df	pos;

  pos.X = idx % _sizey;
  pos.Y = idx / _sizey;
  return (pos);
}
