#ifndef INFO_GETTER_HPP_
# define INFO_GETTER_HPP_

# include "Gui/IUserInterface.hpp"
# include "Constants.hpp"

namespace AoL
{
  namespace rendering
  {
    struct	elementInformationGetter
    {
      elementInformationGetter(AoL::Gui::ButtonHolder *buttonHolder, AoL::rendering::elementInformationGetter const &moduleInfo);
      elementInformationGetter(AoL::Gui::ModuleHolder *moduleHolder);
      ~elementInformationGetter() {}

      irr::s32	getValueFromPercent(irr::f32 val1, irr::f32 val2)
      { return (val1 * val2 / 100); }

      irr::s32	posX;
      irr::s32	posY;
      irr::s32	width;
      irr::s32	height;
    };
  }

}

#endif
