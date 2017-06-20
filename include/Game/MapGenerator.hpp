#ifndef MAPGENERATOR_HPP_
# define MAPGENERATOR_HPP_

#include <unordered_map>
#include <vector>
#include <random>
#include <iostream>
#include <functional>
#include "Ressources/Ressource.hpp"
#include "../irrlicht/irrlicht.h"

namespace AoL
{
  namespace Game
  {
    struct			Tile
    {
      Tile(irr::core::vector2df const &pos): pos(pos) {this->type = AoL::Game::RessourceType::NOTHING; }
      irr::core::vector2df	pos;
      AoL::Game::RessourceType	type;
    };

    class			MapGenerator
    {
    private:
      std::vector<AoL::Game::Tile>		_map;
      irr::s32					_sizex;
      irr::s32					_sizey;
      irr::s32					_forestCreation;
      irr::s32					_foodCreation;
      irr::s32					_stoneCreation;
      irr::s32					_goldCreation;
      irr::s32					_spawnCreation;
      std::vector<irr::s32>			_spawnPoints;
      std::unordered_map<irr::s32, bool>	_check;
      std::vector<irr::s32>			_matrice;
      
      const std::vector<std::function<irr::s32 (MapGenerator &, irr::core::vector2df const &)>> _directionFuncs = 
      {
	&MapGenerator::moveRight,
	&MapGenerator::moveDownRight,
	&MapGenerator::moveDown,
	&MapGenerator::moveDownLeft,
	&MapGenerator::moveLeft,
	&MapGenerator::moveUpLeft,
	&MapGenerator::moveUp,
	&MapGenerator::moveUpRight,
      };

    public:
      MapGenerator(irr::s32 sizex, irr::s32 sizey) : _sizex(sizex), _sizey(sizey), _forestCreation(45), _foodCreation(65), _stoneCreation(95), _goldCreation(150), _spawnCreation(300)
      {
	_matrice.push_back(1);
	_matrice.push_back(2);
	_matrice.push_back(-1);
	_matrice.push_back(-2);
	_matrice.push_back(_sizex);
	_matrice.push_back(2 * _sizex);
	_matrice.push_back(_sizey);
	_matrice.push_back(2 * _sizey);
	_matrice.push_back(_sizex - 1);
	_matrice.push_back(_sizex + 1);
	_matrice.push_back(_sizex - 2);
	_matrice.push_back(_sizex + 2);
	_matrice.push_back(2 * _sizex + 2);
	_matrice.push_back(2 * _sizey + 2);
	_matrice.push_back(2 * _sizex - 2);
	_matrice.push_back(2 * _sizey - 2);
	_matrice.push_back(2 * _sizex + 1);
	_matrice.push_back(2 * _sizey + 1);
	_matrice.push_back(2 * _sizex - 1);
	_matrice.push_back(2 * _sizey - 1);
	_matrice.push_back(-_sizex);
	_matrice.push_back(-2 * _sizex);
	_matrice.push_back(-_sizey);
	_matrice.push_back(-2 * _sizey);
	_matrice.push_back(-_sizex - 1);
	_matrice.push_back(-_sizex + 1);
	_matrice.push_back(-_sizex - 2);
	_matrice.push_back(-_sizex + 2);
	_matrice.push_back(-2 * _sizex + 2);
	_matrice.push_back(-2 * _sizey + 2);
	_matrice.push_back(-2 * _sizex - 2);
	_matrice.push_back(-2 * _sizey - 2);
	_matrice.push_back(-2 * _sizex + 1);
	_matrice.push_back(-2 * _sizey + 1);
	_matrice.push_back(-2 * _sizex - 1);
	_matrice.push_back(-2 * _sizey - 1);
      }
      ~MapGenerator() {};
      irr::s32				genMap();
      
      std::vector<AoL::Game::Tile>	const &getMap() const
      {
	return this->_map;
      }

      irr::core::vector2df	getSpawnPoints(int idx) const
      {
	std::cout << _spawnPoints[0] << " | " << _spawnPoints[1] << " | " << _spawnPoints[2] << " | " << _spawnPoints[3] << std::endl;
	return (this->transformTo2dPos(this->_spawnPoints[idx]));
      }

    private:
      irr::s32			randomNumberGenerator(irr::s32 min, irr::s32 max) const;
      irr::core::vector2df	transformTo2dPos(irr::s32 idx) const;
      void			createRessources(irr::s32 idx, irr::s32 size, AoL::Game::RessourceType element);
      irr::s32			moveRight(irr::core::vector2df const &pos) const;
      irr::s32			moveDownRight(irr::core::vector2df const &pos) const;
      irr::s32			moveDown(irr::core::vector2df const &pos) const;
      irr::s32			moveDownLeft(irr::core::vector2df const &pos) const;
      irr::s32			moveLeft(irr::core::vector2df const &pos) const;
      irr::s32			moveUpLeft(irr::core::vector2df const &pos) const;
      irr::s32			moveUp(irr::core::vector2df const &pos) const;
      irr::s32			moveUpRight(irr::core::vector2df const &pos) const;
      void			print_map() const;
    }; 
  }
}

#endif /* !MAPGENERATOR_HPP_ */
