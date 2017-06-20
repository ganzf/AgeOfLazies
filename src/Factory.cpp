#include "Factory.hpp"
#include "Manager.hpp"

AoL::Factory::Factory(AoL::Manager &manager, AoL::Observer *observer):
  manager(manager), observer(observer)
{
  
}
