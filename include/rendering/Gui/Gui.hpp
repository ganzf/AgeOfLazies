#ifndef GUI_HPP_
# define GUI_HPP_

# include <iostream>
# include <string>
# include <vector>
# include <memory>
# include <unordered_map>
# include "irrlicht/irrlicht.h"
# include "Gui/IUserInterface.hpp"
# include "Constants.hpp"
# include "rendering/Gui/ARenderedModule.hpp"

# define RED irr::video::SColor(255, 255, 0, 0)
# define GREEN irr::video::SColor(255, 0, 255, 0)
# define BLUE irr::video::SColor(255, 0, 0, 255)
# define YELLOW irr::video::SColor(255, 255, 255, 0)
# define BLACK irr::video::SColor(255, 0, 0, 0)
# define WHITE irr::video::SColor(255, 255, 255, 255)

# define SMALL irr::gui::EGDF_BUTTON
# define TITLE irr::gui::EGDF_DEFAULT

namespace AoL
{
  namespace	UserInput
  {
    class		InputHandler;
  }

  namespace Game
  {
    class	Entity;
    class	Player;
  }

  namespace rendering
  {
    class Context;


    class	Gui
    {
    public:
      Gui(AoL::rendering::Context &window);
      ~Gui();

    // Setters
    public:
      void					initializeDrivers(AoL::rendering::Context &window);
      void					defineClasses();
      void					setFont(std::string const &path, irr::gui::EGUI_DEFAULT_FONT fontType);
      void					setWindowDefaultColor(irr::video::SColor color);
      void					setTextDefaultColor(irr::video::SColor color);
      void					setGui(AoL::Gui::IUserInterface &interface);
      void					setBackground(std::string const &path);
      void					modifyInspector(AoL::Game::Entity *entity);
      void					modifyPlayer(AoL::Game::Player *entity);
      void					modifyModuleAction(AoL::Game::Entity *entity, bool visible);
      void					modifyModuleInfo(AoL::Game::Entity *entity, bool visible);



    public:
      void					draw();

      // Verifiers
    public:
      void					guiEvents();
      void					clear();

      // Getters
    public:
      irr::video::IVideoDriver			*getDriver() { return (this->_driver); }
      irr::gui::IGUIEnvironment			*getEnv() { return (this->_env); }
      irr::gui::IGUISkin			*getSkin() { return (this->_skin); }

    private:
      irr::IrrlichtDevice					*_device;
      irr::video::IVideoDriver					*_driver;
      irr::gui::IGUIEnvironment					*_env;
      irr::gui::IGUISkin					*_skin;
      std::shared_ptr<AoL::UserInput::InputHandler>		_inputHandler;
      AoL::Game::Entity						*_inspectedElement;
      AoL::Game::Player						*_inspectedPlayer;
      std::unordered_map<AoL::Gui::GUITypeId,
	std::function<void(AoL::Gui::ModuleHolder *)> >		_typeClass;
      std::vector<AoL::rendering::ARenderedModule *>		_modules;
    };
  }
}

#endif /* !GUI_HPP */
