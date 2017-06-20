#include "Gui/DefaultMenuInterface.hpp"
#include "Print.hpp"

AoL::Gui::DefaultMenuInterface::DefaultMenuInterface()
{
  TextButton *buttonTitle = new TextButton(L"Main Menu",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_MENU, buttonTitle);

  ClickButton *buttonNew = new ClickButton(L"New Game", "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_NEWGAME);
  setButton(AoL::Gui::GUITypeId::M_MENU, buttonNew);

  ClickButton *buttonLoad = new ClickButton(L"Load Game", "Assets/textures/rectangle.png",
					      "Assets/textures/rectangle.png",
					      AoL::Gui::GUITypeId::B_LOADGAME);
  setButton(AoL::Gui::GUITypeId::M_MENU, buttonLoad);

  ClickButton *buttonOption = new ClickButton(L"Option", "Assets/textures/rectangle.png",
						"Assets/textures/rectangle.png",
						AoL::Gui::GUITypeId::B_OPTION);
  setButton(AoL::Gui::GUITypeId::M_MENU, buttonOption);
  
  ClickButton *buttonQuit = new ClickButton(L"Quit", "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_QUIT);
  setButton(AoL::Gui::GUITypeId::M_MENU, buttonQuit);
}

AoL::Gui::DefaultMenuInterface::~DefaultMenuInterface()
{
  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[0]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 5; ++i)
    delete (buttonsHolder[i]->getButton());
}

