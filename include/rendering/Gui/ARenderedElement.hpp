#ifndef ARENDEREDELEMENT
# define ARENDEREDELEMENT

# include <functional>
# include "irrlicht/irrlicht.h"
# include "Gui/GuiId.hpp"
# include "rendering/Gui/InfoGetter.hpp"

namespace AoL
{
  namespace Gui
  {
    class   ButtonHolder;
  }
  namespace rendering
  {
    class	ARenderedModule;
    class	Gui;

    class	ARenderedElement
    {
    public:
      ARenderedElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder);
      ~ARenderedElement() {}

    public:
      AoL::Gui::GUITypeId	getType()
      { return (this->_elementType); }
      void			modifyText(std::wstring const &txt);
      void	setVisible(bool visible)
      { this->_element->setVisible(visible); }
      AoL::rendering::elementInformationGetter getInfo()
      { return (this->_elementInfo);  }

    public:
      virtual void		callFunction() {}
      virtual void		draw(AoL::rendering::Gui &) {}
      virtual void		setElement(AoL::rendering::ARenderedModule &moduleParent, AoL::Gui::ButtonHolder *buttonHolder) = 0;
      virtual void		setFunction(std::function<void()> const &) {}
      virtual void			setFirstImage(AoL::rendering::ARenderedModule &moduleParent, std::string const &path);

    protected:
      AoL::rendering::elementInformationGetter		_elementInfo;
      AoL::Gui::GUITypeId				_elementType;
      irr::video::ITexture				*_firstImage;
      irr::video::ITexture				*_secondImage;
      irr::gui::IGUIElement				*_element;
    };
  }
}

# endif // ARENDEREDELEMENT
