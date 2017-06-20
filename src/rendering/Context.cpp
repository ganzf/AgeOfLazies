#include "rendering/Context.hpp"

AoL::rendering::Context::Context(AoL::rendering::Renderer &renderer):
  renderer(renderer),
  _inputHandler(std::make_shared<AoL::UserInput::InputHandler>()),
  _win(std::make_shared<AoL::rendering::Window>(*(this->_inputHandler)))
{

}

AoL::rendering::Context::~Context()
{
  
}
