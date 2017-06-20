#ifndef SOUND_HPP_
# define SOUND_HPP_

# include <iostream>
# include "irrlicht/irrTypes.h"
# include "irrklang/irrKlang.h"
# include "fmodex/fmod.hpp"

namespace AoL
{
  namespace rendering
  {
    class	ISound
    {
    public:
      virtual ~ISound() {}
      virtual void     	play(std::string const &fileName, bool loop = false) = 0;
      virtual void	pause() const = 0;
      virtual void	unpause() const = 0;
      virtual void	setVolume(irr::f32 volume) const = 0;
      virtual void	increaseVolume(irr::f32 volume) const = 0;
      virtual void	decreaseVolume(irr::f32 volume) const = 0;
    };

    class	SoundLinux : public ISound
    {
    public:
      SoundLinux();
      ~SoundLinux();
      FMOD::System	*getSoundDevice() { return (this->_system); }
      void	    	play(std::string const &fileName, bool loop = false);
      void		pause() const;
      void     		unpause() const;
      void     		setVolume(irr::f32 volume) const;
      void	increaseVolume(irr::f32 volume) const;
      void	decreaseVolume(irr::f32 volume) const;
      
    private:
      FMOD::Channel		*_channel;
      FMOD::System		*_system;
      FMOD::Sound		*_sound;
    };

    class	SoundWindows : public ISound
    {
    public:
      SoundWindows();
      ~SoundWindows();
      irrklang::ISoundEngine	*getSoundDevice() { return (this->_engine); }
      void		    	play(std::string const &fileName, bool loop = false);
      void			pause() const;
      void			unpause() const;
      void			setVolume(irr::f32 volume) const;
      void	increaseVolume(irr::f32 volume) const;
      void	decreaseVolume(irr::f32 volume) const;
      
    private:
      irrklang::ISoundEngine	*_engine;
    };
    
# ifdef __linux
    using Sound = AoL::rendering::SoundLinux;
# elif _WIN32
    using Sound = AoL::rendering::SoundWindows;
# endif
    
  }
}



#endif
