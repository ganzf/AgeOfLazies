#include "Game/Stock.hpp"
#include "Game/AllRessources.hpp"

AoL::Game::Stock::Stock(std::pair<irr::s32, irr::s32> const &wood, std::pair<irr::s32, irr::s32> const &food,
      std::pair<irr::s32, irr::s32> const &stone, std::pair<irr::s32, irr::s32> const &gold) :
  _stock{wood, food, stone, gold}
{
  
}

AoL::Game::Stock::Stock(const Stock &ref): _stock(ref()) {}

AoL::Game::Stock &AoL::Game::Stock::operator = (const Stock &ref)
{
  this->_stock = ref();
  return *this;
}
AoL::Game::Stock::~Stock() {}

std::vector<std::pair<irr::s32,irr::s32>>	const &AoL::Game::Stock::operator () () const
{
  return this->_stock;
}

irr::s32	AoL::Game::Stock::getNb(AoL::Game::RessourceType type) const
{
  if (type > this->_stock.size() - 1 || type < 0)
    return 0;
  return (this->_stock[type].first);
}

irr::s32	AoL::Game::Stock::getMax(AoL::Game::RessourceType type) const
{
  if (type > this->_stock.size() - 1 || type < 0)
    return 0;
  return (this->_stock[type].second);
}

void		AoL::Game::Stock::changeNb(AoL::Game::RessourceType type, irr::s32 nb)
{
  Scopelock	lock(this->stockMutex, __FUNCTION__);

  if (type > this->_stock.size() - 1 || type < 0)
    return ;
  (this->_stock[type].first += nb);
}

void		AoL::Game::Stock::changeMax(AoL::Game::RessourceType type, irr::s32 max)
{
  Scopelock	lock(this->stockMutex, __FUNCTION__);
  
  if (type > this->_stock.size() - 1|| type < 0)
    return ;
  (this->_stock[type].second += max);
}
