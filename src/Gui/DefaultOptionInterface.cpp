#include "Gui/DefaultOptionInterface.hpp"
#include "Print.hpp"

AoL::Gui::DefaultOptionInterface::DefaultOptionInterface()
{
  TextButton *buttonTitle = new TextButton(L"Option",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonTitle);
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

  ClickButton *buttonSongMinus = new ClickButton(L"-", "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_SONG_MINUS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonSongMinus);
  
  SimpleButton *buttonSong = new SimpleButton(L"Song : 75%",
					      "Assets/textures/rectangle.png",
					      "Assets/textures/rectangle.png",
					      AoL::Gui::GUITypeId::B_SONG);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonSong);
  
  ClickButton *buttonSongPlus = new ClickButton(L"+", "Assets/textures/rectangle.png",
						"Assets/textures/rectangle.png",
						AoL::Gui::GUITypeId::B_SONG_PLUS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonSongPlus);
  
  ClickButton *buttonKeys = new ClickButton(L"Key Binding",
					    "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_KEYS);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonKeys);

  ClickButton *buttonBack = new ClickButton(L"Back", "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_BACK);
  setButton(AoL::Gui::GUITypeId::M_OPTION, buttonBack);
}

AoL::Gui::DefaultOptionInterface::~DefaultOptionInterface()
{
  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[0]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 12; ++i)
    delete (buttonsHolder[i]->getButton());
}

