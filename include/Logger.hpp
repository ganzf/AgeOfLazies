#ifndef LOGGER_HPP_
# define LOGGER_HPP_

# include <unordered_map>
# include <string>
# include <iostream>
# include <chrono>
# include "Print.hpp"
# include "irrlicht/irrlicht.h"

namespace AoL
{
  class	Logger
  {
  public:
    enum Level
      {
	INFO = 0,
	DEBUG,
	WARNING,
	ERROR,
	FATAL
      };

  private:
    using timepoint = std::chrono::system_clock::time_point;

    std::string						filename;
    std::ofstream					file;
    Logger::timepoint					start;
    std::unordered_map<enum Logger::Level, irr::u32>	errors;

    std::string 		timespent()
    {
      auto int_ms = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now() - this->start);
      return (std::to_string(int_ms.count()) + "s");
    }

    std::string			errorsString()
    {
      std::string		res = "Errors :\t" +
	std::to_string(this->errors[Logger::ERROR]) +
	"\tFatal :\t" +
	std::to_string(this->errors[Logger::FATAL]);
      return (res);
    }

    void				changeLogfile(std::string const &filepath)
    {
      if (this->file.is_open())
	this->file.close();
      this->filename = filepath;
      file.open(this->filename.c_str());
      if (file.fail())
	throw std::runtime_error("Failure to open logfile " + this->filename);
    }

  public:
    Logger(std::string const &filename = "default_logs.txt")
    {
      this->start = std::chrono::system_clock::now();
      this->changeLogfile(filename);
    };
    ~Logger()
    {
      if (file.is_open())
	{
	  this->log<Logger::INFO>("__ End of program __", __FUNCTION__);
	  this->log<Logger::INFO>("__ Time spent       : " + this->timespent(), __FUNCTION__);
	  this->log<Logger::INFO>("__ Errors reported  : " + this->errorsString(), __FUNCTION__);
	  file.close();
	}
    };

    void	setLogfile(std::string const &filepath)
    {
      this->changeLogfile(filepath);
    }

    template	<enum Logger::Level level>
    void	log(std::string const &msg, std::string const &caller)
    {
      if (!this->file.is_open())
	return ;
      this->file << "(" << Print::Color::ColorSet::blue << "INFO" << Print::Color::ColorSet::reset <<  ")\t";
      this->file << caller << " : " << msg << std::endl;
      this->errors[Logger::INFO] += 1;
    }
  };
}

#endif /* !LOGGER_HPP_ */
