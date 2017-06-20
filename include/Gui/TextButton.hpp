#ifndef TEXTBUTTON_HPP_
# define TEXTBUTTON_HPP_

# include "IButton.hpp"

namespace AoL
{
  namespace Gui
  {
    class TextButton : public IButton
    {
    public:
      TextButton(std::wstring const &text, AoL::Gui::GUITypeId id)
	:_text(text), _picturePath(""),
         _picturePressedPath(""), _eventClick(nullptr),
	 _eventShow(nullptr), _id(id) {}
      virtual ~TextButton() {}
      
      std::wstring const       	&getText() const
      { return (_text); }
      void                      setText(std::wstring const &text)
      { _text = text; }
      std::string const		&getPicturePath() const
      { return (_picturePath); }
      std::string const         &getPicturePressedPath() const
      { return (_picturePressedPath); }
      void			setPicturePath(std::string const &picturePath)
      { _picturePath = picturePath; }
      std::function<void()> const	&getEventClick() const
      { return (_eventClick); }
      std::function<void()> const	&getEventShow() const
      { return (_eventShow); }
      void				setEventClick(std::function<void()>)
      {}
      void				setEventShow(std::function<void()> eventShow)
      { _eventShow = eventShow; }
      AoL::Gui::GUITypeId               getId() const
      { return (_id); }
      
    private:
      std::wstring		_text;
      std::string		_picturePath;
      std::string               _picturePressedPath;
      std::function<void()>	_eventClick = nullptr;
      std::function<void()>	_eventShow;
      AoL::Gui::GUITypeId      	_id;
    };
  }
}
#endif //TEXTBUTTON_HPP_
