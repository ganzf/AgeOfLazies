#ifndef KEYSBINDING_HPP_
# define KEYSBINDING_HPP_

# include "Gui/KeysBindingInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"

# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {    
    class		KeysBinding : public AScene
    {
    public:
      KeysBinding(AoL::Manager &, AoL::CommonData &);
      ~KeysBinding();
      
      virtual irr::s32			run(irr::f32 elapsed);
      virtual bool			isDone();
      virtual void			reset() {}
      virtual void			initGui();
      virtual irr::s32			init() { return 0; };
    private:
      AoL::rendering::Sound  mixer;
    };
  }  
}

#endif /* !KEYSBINDING_HPP_ */
