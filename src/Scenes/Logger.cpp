#include "Logger.hpp"

namespace AoL
{
  template	<>
  void		Logger::log<Logger::DEBUG>(std::string const &msg, std::string const &caller)
  {
    if (!this->file.is_open())
      return ;
    this->file << "(" << Print::Color::ColorSet::blue << "DEBUG" << Print::Color::ColorSet::reset <<  ")\t";
    this->file << caller << " : " << msg << std::endl;
    this->errors[Logger::DEBUG] += 1;
  }

  template	<>
  void		Logger::log<Logger::WARNING>(std::string const &msg, std::string const &caller)
  {
    if (!this->file.is_open())
      return ;
    this->file << "(" << Print::Color::ColorSet::blue << "WARNING" << Print::Color::ColorSet::reset <<  ")\t";
    this->file << caller << " : " << msg << std::endl;
    this->errors[Logger::WARNING] += 1;
  }

  template	<>
  void		Logger::log<Logger::ERROR>(std::string const &msg, std::string const &caller)
  {
    if (!this->file.is_open())
      return ;
    this->file << "(" << Print::Color::ColorSet::blue << "ERROR" << Print::Color::ColorSet::reset <<  ")\t";
    this->file << caller << " : " << msg << std::endl;
    this->errors[Logger::ERROR] += 1;
  }

  template	<>
  void		Logger::log<Logger::FATAL>(std::string const &msg, std::string const &caller)
  {
    if (!this->file.is_open())
      return ;
    this->file << "(" << Print::Color::ColorSet::red << "FATAL" << Print::Color::ColorSet::reset <<  ")\t";
    this->file << caller << " : " << msg << std::endl;
    this->errors[Logger::FATAL] += 1;
    throw std::runtime_error("0.\n\tFatal error encountered. See log file for more infos.");
  }
}
