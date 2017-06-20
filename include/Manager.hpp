#ifndef MANAGER_HPP_
# define MANAGER_HPP_

# include <string>
# include <vector>
# include "irrlicht/irrlicht.h"
# include "Scenes/Scenes.hpp"
# include "Logger.hpp"
# include "Stack.hpp"
# include "Timer.hpp"
# include "Game/Map.hpp"
# include "Game/Entity.hpp"
# include "Observer.hpp"
# include "Factory.hpp"

namespace AoL
{
  class	Core;
  
  class Manager
  {
    // Initialisation du Manager (on peut verifier les erreurs dinit)
    std::vector<irr::u32>		moduleErrors;
    std::vector<std::string>		reportedErrors;

    // Logger pour logger => duh.
    AoL::Logger				logger;
    
    AoL::Stack<Scenes::AScene>		scheduler;
    AoL::Factory			factory;
    Time::Timer				timer;
    Time::Fps				maxFps;
    Time::Fps				minFps;

    // Espace de memoire commun / Les fonctions y sont thread safe.
    // En revanche pour de meilleurs perf on peut set un flag qui desactive
    // les mutex. A utiliser avec precaution.
    // CommonMemory		data;
    AoL::Core				&core;
    AoL::rendering::Sound		mixer;
    
  public:
    Manager(AoL::Core &core);
    ~Manager() = default;

    AoL::rendering::Sound	&getMixer()
    {
      return this->mixer;
    }

    AoL::Factory		&getFactory() { return this->factory; }
    
    bool		deviceIsRunning() const;
    
    AoL::Core		&getCore() { return this->core; }
    void		render(AoL::Scenes::AScene *s);
    void		playScene(AoL::Scenes::AScene *s);
    void		runScene(AoL::Scenes::AScene *, float elapsed); // Recursive function
    void		renderScene(AoL::Scenes::AScene *); // Recursive function
    void		loop();

    irr::s32		getMaxFpsRate() const
    {
      return this->maxFps.getRate();
    }
    
    void		setLogfile(std::string const &filepath)
    {
      this->logger.setLogfile(filepath);
    };
    
    void		runCheckup()
    {
      for (auto &i: this->moduleErrors)
	i = 0;
    }

    void		associateObserver(AoL::Observer *obs);
    
    irr::u32		checkupErrors() const
    {
      irr::u32		tot = 0;

      for (auto const &i: this->moduleErrors)
	tot += i;
      return (tot);
    }
   
    std::string	const	&latestError() const
    {
      return (this->reportedErrors.back());
    }

    template		<enum Logger::Level level>
    void		log(std::string const &msg, std::string const &caller = "")
    {
      this->logger.log<level>(msg, caller);
    };

    void		endScene()
    {
      this->scheduler.pop();
    }
  };
}

#endif /* !MANAGER_HPP_ */
