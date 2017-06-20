#ifndef WINDOW_HPP_
# define WINDOW_HPP_

# include <cstring>
# include "userInput/inputHandler.hpp"
# include "irrlicht/irrlicht.h"
# include "irrklang/irrKlang.h"

# ifdef _IRR_WINDOWS_
#  pragma comment(lib, "Irrlicht.lib")
#  pragma comment(lib, "irrKlang.lib")
#  pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
# endif

namespace			AoL
{
  namespace			rendering
  {
    class			Window
    {
    private:
      irr::IrrlichtDevice		*_device;
      irr::video::IVideoDriver		*_driver;

    public:
      Window(AoL::UserInput::InputHandler &inputHandler);
      virtual ~Window(void);

    public:
      /* GETTERS */
      irr::IrrlichtDevice	*getDevice(void)
      { return (this->_device); }
      irr::video::IVideoDriver	*getDriver(void)
      { return (this->_driver); }
    };
  }
}

#endif
