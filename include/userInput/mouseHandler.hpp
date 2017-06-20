#ifndef MOUSEHANDLER_HPP_
# define MOUSEHANDLER_HPP_

# include <vector>
# include "irrlicht/irrlicht.h"

namespace			AoL
{
  namespace			UserInput
  {
    enum			MouseAttributs
      {
	UNDEFINED = -1,
	LEFT_CLICK, RIGHT_CLICK, MIDDLE_CLICK,
	WHEEL_UP, WHEEL_DOWN,
	GUI,
	NBR_ATTRIBUTS
      };
      
    class				MouseHandler : public irr::IEventReceiver
    {
    private:
      std::vector<irr::s32>    		_mouse;
      irr::s32				_idGUI;
      irr::core::vector2di		_position;
      
    public:
      MouseHandler(void);
      ~MouseHandler(void);

      bool				OnEvent(const irr::SEvent& event);
      void				resetEventQueue();
      irr::core::vector2di	const	&getPosition() const;

      /* GETTERS */
      bool				getEvent(MouseAttributs event);
      irr::s32				getIdGUI()
      { 
	_mouse[MouseAttributs::GUI] = 0;
	return (_idGUI); 
      }
    };
  }
}

#endif /* MOUSEHANDLER_HPP_ */

