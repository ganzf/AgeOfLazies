#include <stack>
#include "AoL.hpp"
#include "Print.hpp"
#include "Core/Core.hpp"
#include "IdGenerator.hpp"

AoL::IdGenerator	getId;

irr::s32		main(void)
{
  try
    {
      AoL::Core	core;
      core.start(false);
    }
  catch (std::exception const &e)
    {
      Print::err(AoL::Constants::Messages::mainErrorMessage, e.what());
    }
  return (1);
}
