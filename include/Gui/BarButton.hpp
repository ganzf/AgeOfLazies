#ifndef BARBUTTON_HPP_
# define BARBUTTON_HPP_

# include "IButton.hpp"

namespace AoL
{
  namespace Gui
  {
    class BarButton : public IButton
    {
    public:
      BarButton(std::wstring const &text,
		std::string const &picturePath,
		std::string const &picturePressedPath,
		AoL::Gui::GUITypeId id)
	:_text(text), _picturePath(picturePath),
         _picturePressedPath(picturePressedPath), _value(0),
	 _eventClick(nullptr), _eventShow(nullptr), _id(id) {}
      virtual ~BarButton() {}
  
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
      void				setEventClick(std::function<void()>)
      {}
      void				setEventShow(std::function<void()> eventShow)
      { _eventShow = eventShow; }
      void			setValue(irr::u32 value)
      { _value = value; }
      irr::u32			getValue() const
      { return (_value); }
      AoL::Gui::GUITypeId       getId()const
      { return (_id); }
    private:
      std::wstring		_text;
      std::string		_picturePath;
      std::string               _picturePressedPath;
      irr::u32			_value;
      std::function<void()>	_eventClick;
      std::function<void()>	_eventShow;
      AoL::Gui::GUITypeId      	_id;
    };
  }
}
#endif //BARBUTTON_HPP_
