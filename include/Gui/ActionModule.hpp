#ifndef ACTIONMODULE_HPP_
# define ACTIONMODULE_HPP_

# include "IModule.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Gui
  {
    /*
    ** |======================|
    ** | ====  ==== ==== ==== |
    ** | |01|  |02| |03| |04| |
    ** | ====  ==== ==== ==== |
    ** | ====  ==== ==== ==== |
    ** | |05|  |06| |07| |08| |
    ** | ====  ==== ==== ==== |
    ** |======================|
    */
    class	ActionModule : public IModule
    {
    public:
      ActionModule(std::wstring const &text,
		 std::string const &picturePath);
      ~ActionModule();

      std::wstring const	       	&getText() const;
      std::string const			&getPicturePath() const;
      std::vector<ButtonHolder *>	&getButtonsHolder();
      irr::u32				getNbButtonsHolder() const;
      AoL::Gui::GUITypeId	       	getType() const;
      bool				isHide() const;
      void				dump() const;
      void                              hide() { _hide = true; }
      void                              display() { _hide = false; }
      
    private:
      std::wstring			_text;
      std::string			_picturePath;
      std::vector<ButtonHolder *>	_buttonsHolder;
      irr::u32				_nbButtonsHolder = 8;
      bool				_hide = true;
      AoL::Gui::GUITypeId		_type = AoL::Gui::GUITypeId::M_ACTION;
    };
  }
}

#endif //ACTIONMODULE_HPP_
