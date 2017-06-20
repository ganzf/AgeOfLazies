#ifndef MODULEHOLDER_HPP_
# define MODULEHOLDER_HPP_

# include "Gui/IModule.hpp"
# include "Gui/MenuModule.hpp"
# include "Gui/StatModule.hpp"
# include "Gui/ActionModule.hpp"
# include "Gui/InfoModule.hpp"
# include "Gui/MapModule.hpp"
# include "Gui/PauseModule.hpp"
# include "Gui/NewGameModule.hpp"
# include "Gui/AIModule.hpp"
# include "Gui/OptionModule.hpp"
# include "Gui/KeysBindingModule.hpp"
# include "Gui/PressKeyModule.hpp"
# include "Gui/GeneralScoreModule.hpp"
# include "Gui/EcoScoreModule.hpp"
# include "Gui/FightScoreModule.hpp"
# include "Gui/LazyScoreModule.hpp"
# include "Gui/EndGameModule.hpp"
# include "Gui/LoadGameModule.hpp"
# include "Gui/EncyclopedieModule.hpp"

namespace AoL
{
  namespace Gui
  {
    class	ModuleHolder
    {
    public:
      ModuleHolder(std::wstring const &name, irr::core::vector2df const &pos,
		   irr::f32 width, irr::f32 height, AoL::Gui::GUITypeId type)
	:_name(name), _pos(pos), _width(width),
	 _height(height), _module(nullptr),
	 _locked(false), _type(type) {}
      ~ModuleHolder()
      {
       	if (_module && _locked)
	  delete (_module);
      };

      std::wstring const       	&getName() const
      { return (_name); }
      void                      setModule(IModule *module)
      { _module = module; }
      IModule			*getModule() const
      { return (_module); }
      irr::core::vector2df const                &getPos() const
      { return (_pos); }
      irr::f32                  getWidth() const
      { return (_width); }
      irr::f32                  getHeight() const
      { return (_height); }
      bool			isLocked() const
      { return (_locked); }
      void			unlock()
      { _locked = false; }
      void			lock()
      { _locked = true; }
      AoL::Gui::GUITypeId      	getType() const
      { return (_type); }
      void                      dump() const
      {
	// std::cout << "=====Module " << _name << "=====" << std::endl
	// 	  << "x: " << _pos.X << " y: " << _pos.Y << std::endl
	// 	  << "width: " << _width << " height: " << _height << std::endl;
	// if (_module)
	//   _module->dump();
	// else
	//   std::cout << "text: EMPTY" << std::endl;
      }
    private:
      std::wstring              _name;
      irr::core::vector2df      _pos;
      irr::f32                  _width;
      irr::f32                  _height;
      IModule                   *_module;
      bool			_locked;
      AoL::Gui::GUITypeId	_type;
    };
  }
}
#endif //MODULEHOLDER_HPP_
