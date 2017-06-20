#include "Gui/DefaultNewGameInterface.hpp"
#include "Print.hpp"

AoL::Gui::DefaultNewGameInterface::DefaultNewGameInterface()
{
  TextButton *buttonTitle = new TextButton(L"New Game",
					    AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonTitle);
  ClickButton *buttonMapSizeMinus = new ClickButton(L"<", "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_MAPSIZE_MINUS);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonMapSizeMinus);

  SimpleButton *buttonMapSize = new SimpleButton(L"Size: Reachable",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_MAPSIZE);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonMapSize);

  ClickButton *buttonMapSizePlus = new ClickButton(L">", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_MAPSIZE_PLUS);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonMapSizePlus);
  
  ClickButton *buttonDifficultyMinus = new ClickButton(L"<", "Assets/textures/rectangle.png",
						       "Assets/textures/rectangle.png",
						       AoL::Gui::GUITypeId::B_DIFFICULTY_MINUS);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonDifficultyMinus);
  
  SimpleButton *buttonDifficulty = new SimpleButton(L"Laziness: DevTeam",
						    "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_DIFFICULTY);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonDifficulty);
  
  ClickButton *buttonDifficultyPlus = new ClickButton(L">", "Assets/textures/rectangle.png",
						      "Assets/textures/rectangle.png",
						      AoL::Gui::GUITypeId::B_DIFFICULTY_PLUS);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonDifficultyPlus);
  
  ClickButton *buttonTimeMaxMinus = new ClickButton(L"<", "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_TIMEMAX_MINUS);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonTimeMaxMinus);
  
  SimpleButton *buttonTimeMax = new SimpleButton(L"Time : 10 years",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_TIMEMAX);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonTimeMax);

  ClickButton *buttonTimeMaxPlus = new ClickButton(L">", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_TIMEMAX_PLUS);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonTimeMaxPlus);

  ClickButton *buttonBack = new ClickButton(L"Back", "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonBack);

  ClickButton *buttonStart = new ClickButton(L"Start", "Assets/textures/rectangle.png",
					     "Assets/textures/rectangle.png",
					     AoL::Gui::GUITypeId::B_START);
  setButton(AoL::Gui::GUITypeId::M_NEWGAME, buttonStart);

  TextButton *buttonTitle2 = new TextButton(L"AI",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonTitle2);

  ClickButton *buttonAI1Minus = new ClickButton(L"<", "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_AI1_MINUS);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI1Minus);

  SimpleButton *buttonAI1 = new SimpleButton(L"Lazy1 : None",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_AI1);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI1);

  ClickButton *buttonAI1Plus = new ClickButton(L">", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_AI1_PLUS);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI1Plus);
  
  ClickButton *buttonAI2Minus = new ClickButton(L"<", "Assets/textures/rectangle.png",
						       "Assets/textures/rectangle.png",
						       AoL::Gui::GUITypeId::B_AI2_MINUS);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI2Minus);
  
  SimpleButton *buttonAI2 = new SimpleButton(L"Lazy2 : None",
						    "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_AI2);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI2);
  
  ClickButton *buttonAI2Plus = new ClickButton(L">", "Assets/textures/rectangle.png",
						      "Assets/textures/rectangle.png",
						      AoL::Gui::GUITypeId::B_AI2_PLUS);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI2Plus);
  
  ClickButton *buttonAI3Minus = new ClickButton(L"<", "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_AI3_MINUS);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI3Minus);
  
  SimpleButton *buttonAI3 = new SimpleButton(L"Lazy3 : None",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_AI3);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI3);

  ClickButton *buttonAI3Plus = new ClickButton(L">", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_AI3_PLUS);
  setButton(AoL::Gui::GUITypeId::M_AI, buttonAI3Plus);

}

AoL::Gui::DefaultNewGameInterface::~DefaultNewGameInterface()
{
  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[0]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 12; ++i)
    delete (buttonsHolder[i]->getButton());

  buttonsHolder = _modulesHolder[1]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 10; ++i)
    delete (buttonsHolder[i]->getButton());
}

