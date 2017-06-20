#include "rendering/Window.hpp"
#include "Constants.hpp"

AoL::rendering::Window::Window(AoL::UserInput::InputHandler &inputHandler)
{
  if ((this->_device = irr::createDevice(irr::video::EDT_OPENGL,
					 irr::core::dimension2d<irr::u32>(AoL::Constants::Rendering::g_screen_width,
									  AoL::Constants::Rendering::g_screen_height),
					 AoL::Constants::Rendering::g_bits,
					 AoL::Constants::Rendering::g_full_screen,
					 AoL::Constants::Rendering::g_stencil_buffer,
					 AoL::Constants::Rendering::g_vsync,
					 &inputHandler)) == nullptr)
    throw std::runtime_error(AoL::Constants::Messages::errorWindowDevice);
  this->_driver = this->_device->getVideoDriver();
}

AoL::rendering::Window::~Window(void)
{
  if (this->_device != nullptr)
    this->_device->drop();
}
