#ifndef CHECKBUTTON_HPP_
# define CHECKBUTTON_HPP_

# include "IButton.hpp"

namespace AoL
{
  namespace Gui
  {
    class CheckButton : public IButton
    {
    public:
      CheckButton(std::wstring const &text,
		  std::string const &picturePath,
		  std::string const &picturePressedPath,
		  irr::u32 id)
	:_text(text), _picturePath(picturePath),
         _picturePressedPath(picturePressedPath), _checked(false),
	 _eventClick(nullptr), _eventShow(nullptr), _id(id) {}
      virtual ~CheckButton() {}
  
      std::wstring const       	&getText() const
      { return (_text); }
      void                      setText(std::wstring const &text)
      { _text = text; }
      std::string const		&getPicturePath() const
      { return (_picturePath); }
      void                      setPicturePath(std::string const &picturePath)
      { _picturePath = picturePath; }
      std::string const         &getPicturePressedPath() const
      { return (_picturePressedPath); }
      std::function<void()> const	&getEventClick() const
      { return (_eventClick); }
      std::function<void()> const	&getEventShow() const
      { return (_eventShow); }
      void				setEventClick(std::function<void()> eventClick)
      { _checked = !_checked; _eventClick = eventClick; }
      void				setEventShow(std::function<void()> eventShow)
      { _eventShow = eventShow; }
      void			check()
      { _checked = true; }
      void			uncheck()
      { _checked = false; }
      bool			isChecked() const
      { return (_checked); }
      irr::u32                  getId() const
      { return (_id); }
      
    private:
      std::wstring		_text;
      std::string		_picturePath;
      std::string               _picturePressedPath;
      irr::u32			_checked;
      std::function<void()>	_eventClick;
      std::function<void()>	_eventShow;
      irr::u32                  _id;
    };
  }
}
#endif //CHECKBUTTON_HPP_
