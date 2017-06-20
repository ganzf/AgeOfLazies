#include <stack>
#include "AoL.hpp"
#include "Print.hpp"
#include "Core/core.hpp"
#include "Scenes/Scenes.hpp"
#include "Manager.hpp"
#include "Constants.hpp"

irr::s32	main(void)
{
  try
    {
      AoL::Core	core;
      core.start(false);
    }
  catch (std::exception const &e)
    {
      Print::err(AoL::Constants::mainErrorMessage, e.what());
    }
  return (1);
}
