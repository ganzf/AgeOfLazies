#include "Gui/DefaultGameInterface.hpp"

AoL::Gui::DefaultGameInterface::DefaultGameInterface()
{
  
  SimpleButton *buttonWood = new SimpleButton(L"0", "Assets/textures/Wood.png",
					      "Assets/textures/Wood.png",
					      AoL::Gui::GUITypeId::B_WOOD);
  setButton(AoL::Gui::GUITypeId::M_STAT, buttonWood);
  SimpleButton *buttonFood = new SimpleButton(L"0", "Assets/textures/Food.png",
					      "Assets/textures/Food.png",
					      AoL::Gui::GUITypeId::B_FOOD);
  setButton(AoL::Gui::GUITypeId::M_STAT, buttonFood);

  SimpleButton *buttonStone = new SimpleButton(L"0", "Assets/textures/Stone.png",
					       "Assets/textures/Stone.png",
					       AoL::Gui::GUITypeId::B_STONE);
  setButton(AoL::Gui::GUITypeId::M_STAT, buttonStone);

  SimpleButton *buttonGold = new SimpleButton(L"0", "Assets/textures/Gold.png",
					      "Assets/textures/Gold.png",
					      AoL::Gui::GUITypeId::B_GOLD);
  setButton(AoL::Gui::GUITypeId::M_STAT, buttonGold);

  SimpleButton *buttonPeople = new SimpleButton(L"0", "Assets/textures/Ppl.png",
						"Assets/textures/Ppl.png",
						AoL::Gui::GUITypeId::B_PEOPLE);
  setButton(AoL::Gui::GUITypeId::M_STAT, buttonPeople);

  ClickButton *buttonTimer = new ClickButton(L"Timer", "Assets/textures/Time.png",
					    "Assets/textures/Time.png",
					    AoL::Gui::GUITypeId::B_TIMER);
  setButton(AoL::Gui::GUITypeId::M_STAT, buttonTimer);
  ClickButton *buttonMenu = new ClickButton(L"Menu", "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_PAUSE);
  setButton(AoL::Gui::GUITypeId::M_STAT, buttonMenu);

  ClickButton *buttonAction1 = new ClickButton(L"Action1", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION1);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction1);

  ClickButton *buttonAction2 = new ClickButton(L"Action2", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION2);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction2);

  ClickButton *buttonAction3 = new ClickButton(L"Action3", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION3);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction3);

  ClickButton *buttonAction4 = new ClickButton(L"Action4", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION4);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction4);

  ClickButton *buttonAction5 = new ClickButton(L"Action5", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION5);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction5);

  ClickButton *buttonAction6 = new ClickButton(L"Action6", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION6);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction6);

  ClickButton *buttonAction7 = new ClickButton(L"Action7", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION7);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction7);

  ClickButton *buttonAction8 = new ClickButton(L"Action8", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_ACTION8);
  setButton(AoL::Gui::GUITypeId::M_ACTION, buttonAction8);

   BarButton *buttonHealth = new BarButton(L"Health", "Assets/textures/lifeBar.png",
						 "Assets/textures/greenColor.png",
						 AoL::Gui::GUITypeId::B_HEALTH);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonHealth);
   BarButton *buttonXP = new BarButton(L"XP", "Assets/textures/xpContainer.png",
						 "Assets/textures/purpleColor.png",
						 AoL::Gui::GUITypeId::B_XP);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonXP);
   SimpleButton *buttonAttack = new SimpleButton(L"Attack", "Assets/textures/atk.png",
						 "Assets/textures/atk.png",
						 AoL::Gui::GUITypeId::B_ATTACK);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonAttack);

   SimpleButton *buttonWood2 = new SimpleButton(L"0", "Assets/textures/Wood.png",
						 "Assets/textures/Wood.png",
						 AoL::Gui::GUITypeId::B_WOOD);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonWood2);

   SimpleButton *buttonFood2 = new SimpleButton(L"0", "Assets/textures/Food.png",
						 "Assets/textures/Food.png",
						 AoL::Gui::GUITypeId::B_FOOD);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonFood2);

   SimpleButton *buttonGold2 = new SimpleButton(L"0", "Assets/textures/Gold.png",
					       "Assets/textures/Gold.png",
					      AoL::Gui::GUITypeId::B_GOLD);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonGold2);

   SimpleButton *buttonStone2 = new SimpleButton(L"0", "Assets/textures/Stone.png",
					      "Assets/textures/Stone.png",
					      AoL::Gui::GUITypeId::B_STONE);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonStone2);

   SimpleButton *buttonPicture = new SimpleButton(L"", "Assets/textures/rectangle.png",
						  "Assets/textures/rectangle.png",
						  AoL::Gui::GUITypeId::B_PICTURE);
   setButton(AoL::Gui::GUITypeId::M_INFO, buttonPicture);

  SimpleButton *buttonMap = new SimpleButton(L"Map", "Assets/textures/rectangle.png",
					     "Assets/textures/rectangle.png",
					     AoL::Gui::GUITypeId::B_MAP);
  setButton(AoL::Gui::GUITypeId::M_MAP, buttonMap);


  TextButton *buttonTitlePause = new TextButton(L"PAUSE",
						AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_PAUSE, buttonTitlePause);

  ClickButton *buttonContinue = new ClickButton(L"Continue", "Assets/textures/rectangle.png",
						"Assets/textures/rectangle.png",
						AoL::Gui::GUITypeId::B_CONTINUE);
  setButton(AoL::Gui::GUITypeId::M_PAUSE, buttonContinue);

  ClickButton *buttonSave = new ClickButton(L"Save Game", "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_SAVE);
  setButton(AoL::Gui::GUITypeId::M_PAUSE, buttonSave);

  ClickButton *buttonLoadGame = new ClickButton(L"LoadGame", "Assets/textures/rectangle.png",
						"Assets/textures/rectangle.png",
						AoL::Gui::GUITypeId::B_LOADGAME);
  setButton(AoL::Gui::GUITypeId::M_PAUSE, buttonLoadGame);

  ClickButton *buttonOption = new ClickButton(L"Option", "Assets/textures/rectangle.png",
					      "Assets/textures/rectangle.png",
					      AoL::Gui::GUITypeId::B_OPTION);
  setButton(AoL::Gui::GUITypeId::M_PAUSE, buttonOption);

  ClickButton *buttonSurrend = new ClickButton(L"Surrend", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_SURREND);
  setButton(AoL::Gui::GUITypeId::M_PAUSE, buttonSurrend);

  ClickButton *buttonQuit = new ClickButton(L"Quit", "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_QUIT);
  setButton(AoL::Gui::GUITypeId::M_PAUSE, buttonQuit);

  TextButton *buttonTitleOption = new TextButton(L"Option",
						 AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonTitleOption);

  ClickButton *buttonFullScreenOff = new ClickButton(L"-", "Assets/textures/rectangle.png",
						     "Assets/textures/rectangle.png",
						     AoL::Gui::GUITypeId::B_FULLSCREEN_OFF);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonFullScreenOff);

  SimpleButton *buttonFullScreen = new SimpleButton(L"Full Screen : On", "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_FULLSCREEN);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonFullScreen);

  ClickButton *buttonFullScreenOn = new ClickButton(L"+", "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_FULLSCREEN_ON);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonFullScreenOn);

  ClickButton *buttonResoMinus = new ClickButton(L"-", "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_RESO_MINUS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonResoMinus);

  SimpleButton *buttonReso = new SimpleButton(L"Format : 1920x1080",
					      "Assets/textures/rectangle.png",
					      "Assets/textures/rectangle.png",
					      AoL::Gui::GUITypeId::B_RESO);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonReso);

  ClickButton *buttonResoPlus = new ClickButton(L"+", "Assets/textures/rectangle.png",
						"Assets/textures/rectangle.png",
						AoL::Gui::GUITypeId::B_RESO_PLUS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonResoPlus);

  ClickButton *buttonSongMinus = new ClickButton(L"-", "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_SONG_MINUS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonSongMinus);

  SimpleButton *buttonSong = new SimpleButton(L"Sound : 75%",
					      "Assets/textures/rectangle.png",
					      "Assets/textures/rectangle.png",
					      AoL::Gui::GUITypeId::B_SONG);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonSong);

  ClickButton *buttonSongPlus = new ClickButton(L"+", "Assets/textures/rectangle.png",
						"Assets/textures/rectangle.png",
						AoL::Gui::GUITypeId::B_SONG_PLUS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonSongPlus);

  ClickButton *buttonKeys = new ClickButton(L"Keys Binding",
					    "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_KEYS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonKeys);

  ClickButton *buttonBackOption = new ClickButton(L"Back", "Assets/textures/rectangle.png",
						  "Assets/textures/rectangle.png",
						  AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonBackOption);

  TextButton *buttonTitleKey = new TextButton(L"KeysBinding",
					      AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonTitleKey);

  SimpleButton *buttonKeyName1 = new SimpleButton(L"Go Up",
						  "Assets/textures/rectangle.png",
						  "Assets/textures/rectangle.png",
						  AoL::Gui::GUITypeId::B_KEY_NAME1);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyName1);

  ClickButton *buttonKeyValue1 = new ClickButton(L"Z",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_KEY_VALUE1);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyValue1);

  SimpleButton *buttonKeyName2 = new SimpleButton(L"Go Down",
						  "Assets/textures/rectangle.png",
						  "Assets/textures/rectangle.png",
						  AoL::Gui::GUITypeId::B_KEY_NAME2);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyName2);

  ClickButton *buttonKeyValue2 = new ClickButton(L"S",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_KEY_VALUE2);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyValue2);

  SimpleButton *buttonKeyName3 = new SimpleButton(L"Go Left",
						  "Assets/textures/rectangle.png",
						  "Assets/textures/rectangle.png",
						  AoL::Gui::GUITypeId::B_KEY_NAME3);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyName3);

  ClickButton *buttonKeyValue3 = new ClickButton(L"Q",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_KEY_VALUE3);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyValue3);

  SimpleButton *buttonKeyName4 = new SimpleButton(L"Go Right",
						  "Assets/textures/rectangle.png",
						  "Assets/textures/rectangle.png",
						  AoL::Gui::GUITypeId::B_KEY_NAME4);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyName4);

  ClickButton *buttonKeyValue4 = new ClickButton(L"D",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_KEY_VALUE4);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyValue4);


  SimpleButton *buttonKeyName5 = new SimpleButton(L"Cheat",
						  "Assets/textures/rectangle.png",
						  "Assets/textures/rectangle.png",
						  AoL::Gui::GUITypeId::B_KEY_NAME5);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyName5);


  ClickButton *buttonKeyValue5 = new ClickButton(L"L",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_KEY_VALUE5);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonKeyValue5);

  ClickButton *buttonBackKey = new ClickButton(L"Back", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_BACK2);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonBackKey);

  TextButton *buttonTitleEncyclo = new TextButton(L"Encyclopedie",
						AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonTitleEncyclo);

  TextButton *buttonText = new TextButton(L"",
					  AoL::Gui::GUITypeId::B_TEXT);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonText);

  TextButton *buttonInfoName = new TextButton(L"",
					      AoL::Gui::GUITypeId::B_INFO_NAME);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfoName);

  SimpleButton *buttonInfoIcon = new SimpleButton(L"", "", "",
						   AoL::Gui::GUITypeId::B_INFO_ICON);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfoIcon);
  

  SimpleButton *buttonInfoPicture = new SimpleButton(L"", "", "",
						   AoL::Gui::GUITypeId::B_INFO_PICTURE);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfoPicture);

  SimpleButton *buttonLogo = new SimpleButton(L"Lazypedia", "Assets/textures/rectangle.png",
						     "Assets/textures/rectangle.png",
						     AoL::Gui::GUITypeId::B_ENCYCLO);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonLogo);
  

  ClickButton *buttonInfo1 = new ClickButton(L"History", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO1);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo1);

  ClickButton *buttonInfo2 = new ClickButton(L"Laziness", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO2);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo2);

  ClickButton *buttonInfo3 = new ClickButton(L"Collector", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO3);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo3);

  ClickButton *buttonInfo4 = new ClickButton(L"Warrior", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO4);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo4);

  ClickButton *buttonInfo5 = new ClickButton(L"Gatherer", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO5);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo5);

  ClickButton *buttonInfo6 = new ClickButton(L"Lumberjack", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO6);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo6);

  ClickButton *buttonInfo7 = new ClickButton(L"Miner", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO7);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo7);

  ClickButton *buttonInfo8 = new ClickButton(L"Gold Digger", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO8);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo8);

  ClickButton *buttonInfo9 = new ClickButton(L"Forum", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO9);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo9);

  ClickButton *buttonInfo10 = new ClickButton(L"Habitation", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO10);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo10);

  ClickButton *buttonInfo11 = new ClickButton(L"Mill", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO11);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo11);

  ClickButton *buttonInfo12 = new ClickButton(L"Forge", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO12);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo12);

  ClickButton *buttonInfo13 = new ClickButton(L"Lumbercamp", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO13);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo13);

  ClickButton *buttonInfo14 = new ClickButton(L"Ressources", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_INFO14);
  setButton(AoL::Gui::GUITypeId::M_ENCYCLO, buttonInfo14);
}

AoL::Gui::DefaultGameInterface::~DefaultGameInterface()
{
  for (irr::u32 j = 0; j < _nbModulesHolder; ++j)
    {
      if (_modulesHolder[j]->getModule())
	{
	  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[j]->getModule()->getButtonsHolder();
	  irr::u32 size =  _modulesHolder[j]->getModule()->getNbButtonsHolder();
	  for (irr::u32 i = 0; i < size; ++i)
	    delete (buttonsHolder[i]->getButton());
	}
    }
}

