#ifndef PAUSEMODULE_HPP_
# define PAUSEMODULE_HPP_

# include "IModule.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  namespace Gui
  {
    class	PauseModule : public IModule
    {
    public:
      PauseModule(std::wstring const &text,
		 std::string const &picturePath);
      ~PauseModule();

      std::wstring const       		&getText() const;
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
      irr::u32				_nbButtonsHolder = 7;
      bool				_hide = true;
      AoL::Gui::GUITypeId	       	_type = AoL::Gui::GUITypeId::M_PAUSE;
    };
  }
}

#endif //PAUSEMODULE_HPP_
