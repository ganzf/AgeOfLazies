#include <fcntl.h>
#include "rendering/Sound.hpp"
#include "Constants.hpp"

AoL::rendering::SoundWindows::SoundWindows()
{
  std::cout << "Initialisation du son" << std::endl;
  if ((this->_engine = irrklang::createIrrKlangDevice()) == nullptr)
    throw std::runtime_error(AoL::Constants::Messages::errorSoundDevice);
  std::cout << "Fin de l'initialisation" << std::endl;
}

AoL::rendering::SoundWindows::~SoundWindows()
{
  if (this->_engine != nullptr)
    this->_engine->drop(); 
}

void		AoL::rendering::SoundWindows::play(std::string const &fileName, bool loop)
{
  std::cout << "jouer musique" << std::endl;
  this->_engine->play2D(fileName.c_str(), loop);
  std::cout << "Fin de jouer musique" << std::endl;
}

void		AoL::rendering::SoundWindows::pause() const
{
  _engine->setAllSoundsPaused(true);
}

void		AoL::rendering::SoundWindows::unpause() const
{
  _engine->setAllSoundsPaused(false);
}

void		AoL::rendering::SoundWindows::setVolume(irr::f32 vol) const
{
  _engine->setSoundVolume(vol);
}

void		AoL::rendering::SoundWindows::increaseVolume(irr::f32 vol) const
{
  if (_engine->getSoundVolume() + vol > 1)
    setVolume(1);
  else
    setVolume(_engine->getSoundVolume() + vol);
}

void		AoL::rendering::SoundWindows::decreaseVolume(irr::f32 vol) const
{
  if (_engine->getSoundVolume() - vol < 0)
    setVolume(1);
  else
    setVolume(_engine->getSoundVolume() - vol);
}

AoL::rendering::SoundLinux::SoundLinux()
{
  void *extradriverdata = 0;

  FMOD::System_Create(&this->_system);
  this->_system->init(32, FMOD_INIT_NORMAL, extradriverdata);
}

AoL::rendering::SoundLinux::~SoundLinux()
{
  this->_system->close();
  this->_system->release();
}

void		AoL::rendering::SoundLinux::play(std::string const &fileName, bool loop)
{
  this->_system->createStream(fileName.c_str(), FMOD_DEFAULT, 0, &this->_sound);
  if (!loop)
    this->_sound->setMode(FMOD_LOOP_OFF);
  this->_system->playSound(this->_sound, 0, false, &_channel);
}

void			AoL::rendering::SoundLinux::pause() const
{
  _channel->setPaused(true);
}

void			AoL::rendering::SoundLinux::unpause() const
{
  _channel->setPaused(false);
}

void			AoL::rendering::SoundLinux::setVolume(irr::f32 vol) const
{
  _channel->setVolume(vol);
}

void		AoL::rendering::SoundLinux::increaseVolume(irr::f32 vol) const
{
  irr::f32	currentVol;

  _channel->getVolume(&currentVol);
  if (currentVol + vol > 1)
    setVolume(1);
  else
    setVolume(currentVol + vol);
}

void		AoL::rendering::SoundLinux::decreaseVolume(irr::f32 vol) const
{
  irr::f32	currentVol;

  _channel->getVolume(&currentVol);
  if (currentVol - vol < 0)
    setVolume(0);
  else
    setVolume(currentVol - vol);
}
