#ifndef IMODULE_HPP_
# define IMODULE_HPP_

# include <vector>
# include "ButtonHolder.hpp"

namespace AoL
{
  namespace Gui
  {
    class	IModule
    {
    public:
      virtual ~IModule() {};
      virtual std::wstring const	       	&getText() const = 0;
      virtual std::string const			&getPicturePath() const = 0;
      virtual std::vector<ButtonHolder *>	&getButtonsHolder() = 0;
      virtual irr::u32				getNbButtonsHolder() const = 0;
      virtual void				dump() const = 0;
      virtual AoL::Gui::GUITypeId	       	getType() const = 0;
      virtual bool			       	isHide() const = 0;
      virtual void                              hide() = 0;
      virtual void                              display() = 0;
    };
  }
}

#endif //IMODULE_HPP
