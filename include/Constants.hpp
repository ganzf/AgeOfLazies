#ifndef CONSTANTS_HPP_
# define CONSTANTS_HPP_

# include <string>
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Constants
  {
    namespace Messages
    {
      static const std::string mainErrorMessage = "An unexpected error occured. Please contact us at lazy@studio.com to report this error : Code ";
      static const std::string errorSoundDevice = "Error: can't create a Sound Device.";
      static const std::string errorWindowDevice = "Error: can't create the Window.";
      static const std::string errorGUI = "Error loading GUI properties";
    }

    namespace Rendering
    {
      static irr::core::vector3df	g_default_position = irr::core::vector3df(0, 0, 0);
      static irr::core::vector3df	g_default_rotation = irr::core::vector3df(5, 0, 0);

      static const irr::u32		g_screen_width = 1920;
      static const irr::u32		g_screen_height = 1080;
      static const irr::u32		g_bits = 16;
      static const bool			g_full_screen = true;
      static const bool			g_stencil_buffer = false;
      static const bool			g_vsync = false;

      static const bool			g_back_buffer = true;
      static const bool			g_zbuffer = true;
      static const irr::u8		g_alpha = 255;
      static const irr::video::SColor	g_clear_color = irr::video::SColor(g_alpha, 255, 255, 255);

      static const irr::f32		g_rotation_speed = 100.0f;
      static const irr::f32		g_move_speed = 0.1f;
      static const irr::s32		g_camera_id = 41;
      static const irr::u32		g_camera_size = 5;
      static const auto			g_default_value = nullptr;
    }
  }
}

#endif /* !CONSTANTS_HPP_ */
