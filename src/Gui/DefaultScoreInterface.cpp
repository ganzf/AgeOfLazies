#include "Gui/DefaultScoreInterface.hpp"
#include "Print.hpp"

AoL::Gui::DefaultScoreInterface::DefaultScoreInterface()
{
  TextButton *buttonTitleG = new TextButton(L"General Score",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonTitleG);

  TextButton *buttonKey1G = new TextButton(L"GKEY1",
					  AoL::Gui::GUITypeId::B_STAT_KEY1);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonKey1G);

  TextButton *buttonValue1G = new TextButton(L"GValue1",
					    AoL::Gui::GUITypeId::B_STAT_VALUE1);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonValue1G);

  TextButton *buttonKey2G = new TextButton(L"GKEY2",
					  AoL::Gui::GUITypeId::B_STAT_KEY2);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonKey2G);

  TextButton *buttonValue2G = new TextButton(L"GValue2",
					    AoL::Gui::GUITypeId::B_STAT_VALUE2);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonValue2G);

  TextButton *buttonKey3G = new TextButton(L"GKEY3",
					  AoL::Gui::GUITypeId::B_STAT_KEY3);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonKey3G);

  TextButton *buttonValue3G = new TextButton(L"GValue3",
					    AoL::Gui::GUITypeId::B_STAT_VALUE3);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonValue3G);

  TextButton *buttonKey4G = new TextButton(L"GKEY4",
					  AoL::Gui::GUITypeId::B_STAT_KEY4);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonKey4G);

  TextButton *buttonValue4G = new TextButton(L"GValue4",
					    AoL::Gui::GUITypeId::B_STAT_VALUE4);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonValue4G);

  TextButton *buttonKey5G = new TextButton(L"GKEY5",
					  AoL::Gui::GUITypeId::B_STAT_KEY5);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonKey5G);

  TextButton *buttonValue5G = new TextButton(L"GValue5",
					    AoL::Gui::GUITypeId::B_STAT_VALUE5);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonValue5G);

  ClickButton *buttonBackG = new ClickButton(L"Back to Menu",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonBackG);

  ClickButton *buttonPrevG = new ClickButton(L"GPrevious",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_GENERAL_PREV);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonPrevG);
  ClickButton *buttonNextG = new ClickButton(L"GNext",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					     AoL::Gui::GUITypeId::B_GENERAL_NEXT);
  setButton(AoL::Gui::GUITypeId::M_GENERAL_SCORE, buttonNextG);


  
  TextButton *buttonTitleE = new TextButton(L"Economic Score",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonTitleE);

  TextButton *buttonKey1E = new TextButton(L"EKEY1",
					  AoL::Gui::GUITypeId::B_STAT_KEY1);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonKey1E);

  TextButton *buttonValue1E = new TextButton(L"EValue1",
					    AoL::Gui::GUITypeId::B_STAT_VALUE1);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonValue1E);

  TextButton *buttonKey2E = new TextButton(L"EKEY2",
					  AoL::Gui::GUITypeId::B_STAT_KEY2);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonKey2E);

  TextButton *buttonValue2E = new TextButton(L"EValue2",
					    AoL::Gui::GUITypeId::B_STAT_VALUE2);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonValue2E);

  TextButton *buttonKey3E = new TextButton(L"EKEY3",
					  AoL::Gui::GUITypeId::B_STAT_KEY3);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonKey3E);

  TextButton *buttonValue3E = new TextButton(L"EValue3",
					    AoL::Gui::GUITypeId::B_STAT_VALUE3);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonValue3E);

  TextButton *buttonKey4E = new TextButton(L"EKEY4",
					  AoL::Gui::GUITypeId::B_STAT_KEY4);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonKey4E);

  TextButton *buttonValue4E = new TextButton(L"EValue4",
					    AoL::Gui::GUITypeId::B_STAT_VALUE4);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonValue4E);

  TextButton *buttonKey5E = new TextButton(L"EKEY5",
					  AoL::Gui::GUITypeId::B_STAT_KEY5);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonKey5E);

  TextButton *buttonValue5E = new TextButton(L"EValue5",
					    AoL::Gui::GUITypeId::B_STAT_VALUE5);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonValue5E);

  ClickButton *buttonBackE = new ClickButton(L"Back to Menu",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonBackE);

  ClickButton *buttonPrevE = new ClickButton(L"EPrevious",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_ECO_PREV);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonPrevE);
  ClickButton *buttonNextE = new ClickButton(L"ENext",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_ECO_NEXT);
  setButton(AoL::Gui::GUITypeId::M_ECO_SCORE, buttonNextE);



  TextButton *buttonTitleF = new TextButton(L"Fight Score",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonTitleF);

  TextButton *buttonKey1F = new TextButton(L"FKEY1",
					  AoL::Gui::GUITypeId::B_STAT_KEY1);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonKey1F);

  TextButton *buttonValue1F = new TextButton(L"FValue1",
					    AoL::Gui::GUITypeId::B_STAT_VALUE1);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonValue1F);

  TextButton *buttonKey2F = new TextButton(L"FKEY2",
					  AoL::Gui::GUITypeId::B_STAT_KEY2);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonKey2F);

  TextButton *buttonValue2F = new TextButton(L"FValue2",
					    AoL::Gui::GUITypeId::B_STAT_VALUE2);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonValue2F);

  TextButton *buttonKey3F = new TextButton(L"FKEY3",
					  AoL::Gui::GUITypeId::B_STAT_KEY3);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonKey3F);

  TextButton *buttonValue3F = new TextButton(L"FValue3",
					    AoL::Gui::GUITypeId::B_STAT_VALUE3);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonValue3F);

  TextButton *buttonKey4F = new TextButton(L"FKEY4",
					  AoL::Gui::GUITypeId::B_STAT_KEY4);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonKey4F);

  TextButton *buttonValue4F = new TextButton(L"FValue4",
					    AoL::Gui::GUITypeId::B_STAT_VALUE4);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonValue4F);

  TextButton *buttonKey5F = new TextButton(L"FKEY5",
					  AoL::Gui::GUITypeId::B_STAT_KEY5);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonKey5F);

  TextButton *buttonValue5F = new TextButton(L"FValue5",
					    AoL::Gui::GUITypeId::B_STAT_VALUE5);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonValue5F);

  ClickButton *buttonBackF = new ClickButton(L"Back to Menu",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonBackF);

  ClickButton *buttonPrevF = new ClickButton(L"FPrevious",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_FIGHT_PREV);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonPrevF);
  ClickButton *buttonNextF = new ClickButton(L"FNext",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_FIGHT_NEXT);
  setButton(AoL::Gui::GUITypeId::M_FIGHT_SCORE, buttonNextF);


  TextButton *buttonTitleL = new TextButton(L"Lazy Score",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonTitleL);

  TextButton *buttonKey1L = new TextButton(L"LKEY1",
					  AoL::Gui::GUITypeId::B_STAT_KEY1);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonKey1L);

  TextButton *buttonValue1L = new TextButton(L"LValue1",
					    AoL::Gui::GUITypeId::B_STAT_VALUE1);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonValue1L);

  TextButton *buttonKey2L = new TextButton(L"LKEY2",
					  AoL::Gui::GUITypeId::B_STAT_KEY2);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonKey2L);

  TextButton *buttonValue2L = new TextButton(L"LValue2",
					    AoL::Gui::GUITypeId::B_STAT_VALUE2);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonValue2L);

  TextButton *buttonKey3L = new TextButton(L"LKEY3",
					  AoL::Gui::GUITypeId::B_STAT_KEY3);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonKey3L);

  TextButton *buttonValue3L = new TextButton(L"LValue3",
					    AoL::Gui::GUITypeId::B_STAT_VALUE3);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonValue3L);

  TextButton *buttonKey4L = new TextButton(L"LKEY4",
					  AoL::Gui::GUITypeId::B_STAT_KEY4);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonKey4L);

  TextButton *buttonValue4L = new TextButton(L"LValue4",
					    AoL::Gui::GUITypeId::B_STAT_VALUE4);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonValue4L);

  TextButton *buttonKey5L = new TextButton(L"LKEY5",
					  AoL::Gui::GUITypeId::B_STAT_KEY5);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonKey5L);

  TextButton *buttonValue5L = new TextButton(L"LValue5",
					    AoL::Gui::GUITypeId::B_STAT_VALUE5);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonValue5L);

  ClickButton *buttonBackL = new ClickButton(L"Back to Menu",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonBackL);

  ClickButton *buttonPrevL = new ClickButton(L"LPrevious",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_LAZY_PREV);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonPrevL);
  ClickButton *buttonNextL = new ClickButton(L"LNext",
					   "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_LAZY_NEXT);
  setButton(AoL::Gui::GUITypeId::M_LAZY_SCORE, buttonNextL);
}

AoL::Gui::DefaultScoreInterface::~DefaultScoreInterface()
{
  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[0]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 14; ++i)
    delete (buttonsHolder[i]->getButton());

  buttonsHolder = _modulesHolder[1]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 14; ++i)
    delete (buttonsHolder[i]->getButton());

  buttonsHolder = _modulesHolder[2]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 14; ++i)
    delete (buttonsHolder[i]->getButton());

  buttonsHolder = _modulesHolder[3]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 14; ++i)
    delete (buttonsHolder[i]->getButton());
}

