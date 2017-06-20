#include "Gui/DefaultLoadGameInterface.hpp"
#include "Print.hpp"

AoL::Gui::DefaultLoadGameInterface::DefaultLoadGameInterface()
{
  TextButton *buttonTitle = new TextButton(L"Load Game",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_LOADGAME, buttonTitle);

  ClickButton *buttonSaveMinus = new ClickButton(L"<", "Assets/textures/rectangle.png",
						    "Assets/textures/rectangle.png",
						    AoL::Gui::GUITypeId::B_SAVE_MINUS);
  setButton(AoL::Gui::GUITypeId::M_LOADGAME, buttonSaveMinus);

  SimpleButton *buttonSave = new SimpleButton(L"",
					      "Assets/textures/rectangle.png",
					      "Assets/textures/rectangle.png",
					      AoL::Gui::GUITypeId::B_SAVE);
  setButton(AoL::Gui::GUITypeId::M_LOADGAME, buttonSave);

  ClickButton *buttonSavePlus = new ClickButton(L">", "Assets/textures/rectangle.png",
						   "Assets/textures/rectangle.png",
						   AoL::Gui::GUITypeId::B_SAVE_PLUS);
  setButton(AoL::Gui::GUITypeId::M_LOADGAME, buttonSavePlus);

  TextButton *buttonSaveName = new TextButton(L"",  AoL::Gui::GUITypeId::B_SAVE_NAME);
  setButton(AoL::Gui::GUITypeId::M_LOADGAME, buttonSaveName);
  
  ClickButton *buttonBack = new ClickButton(L"Back", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_LOADGAME, buttonBack);
  
  ClickButton *buttonLoad = new ClickButton(L"Load", "Assets/textures/rectangle.png",
					       "Assets/textures/rectangle.png",
					       AoL::Gui::GUITypeId::B_LOADGAME);
  setButton(AoL::Gui::GUITypeId::M_LOADGAME, buttonLoad);
}

AoL::Gui::DefaultLoadGameInterface::~DefaultLoadGameInterface()
{
  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[0]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 12; ++i)
    delete (buttonsHolder[i]->getButton());

  buttonsHolder = _modulesHolder[1]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 10; ++i)
    delete (buttonsHolder[i]->getButton());
}

