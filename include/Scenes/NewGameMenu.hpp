#ifndef NEWGAMEMENU_HPP_
# define NEWGAMEMENU_HPP_

# include <vector>

# include "Gui/NewGameInterface.hpp"
# include "Gui/SimpleButton.hpp"
# include "Scenes.hpp"
# include "irrlicht/irrlicht.h"
# include "rendering/Sound.hpp"

namespace AoL
{
  namespace Scenes
  {    
    struct		MapOption
    {
      std::wstring		textButton;
      irr::core::vector2df	mapSize;
    };

    struct		LazyOption
    {
      std::wstring	textButton;
      irr::s32		Laziness;
    };

    static const std::vector<LazyOption>	_lazyOption =
    {
      {L"Laziness: Dev Team", 0},
      {L"Laziness: Beginner", 1},
      {L"Laziness: Medium", 2},
      {L"Laziness: Advanced", 3},
      {L"Laziness: Koala", 4},
    };

    static const std::vector<MapOption>		_mapOption =
    {
      {L"Size: Reachable", {20, 20}},
      {L"Size: Still too much", {25, 25}},
      {L"Size: Meh", {30, 30}},
      {L"Size: REALLY ?!", {40, 40}},
      {L"Size: WAY TOO HUGE", {70, 70}},
      {L"Size: LAZY CRY", {80, 80}},
    };

    class		NewGameMenu : public AScene
    {
      public:
      NewGameMenu(AoL::Manager &, AoL::CommonData &);
      ~NewGameMenu();

	virtual irr::s32			run(irr::f32 elapsed);
	virtual bool			isDone();
	virtual void			reset() {}
	virtual void			initGui();
	virtual irr::s32			init() { return 0; };
	void				playGame();
	std::string		       	updateAI(irr::u32 index, std::string ai);

      private:
	AoL::rendering::Sound		mixer;
	irr::s32			_idxMap;
	irr::s32			_idxLazy;
    };
  }  
}

#endif /* !NEWGAMEMENU_HPP_ */
