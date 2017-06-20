#include "Gui/DefaultEndGameInterface.hpp"
#include "Print.hpp"

AoL::Gui::DefaultEndGameInterface::DefaultEndGameInterface()
{
  ClickButton *buttonMenu = new ClickButton(L"Menu", "Assets/textures/rectangle.png",
					   "Assets/textures/rectangle.png",
					   AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_ENDGAME, buttonMenu);

  ClickButton *buttonScore = new ClickButton(L"Score", "Assets/textures/rectangle.png",
					      "Assets/textures/rectangle.png",
					      AoL::Gui::GUITypeId::B_SCORE);
  setButton(AoL::Gui::GUITypeId::M_ENDGAME, buttonScore);
}

AoL::Gui::DefaultEndGameInterface::~DefaultEndGameInterface()
{
  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[0]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 2; ++i)
    delete (buttonsHolder[i]->getButton());
}

