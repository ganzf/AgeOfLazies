#include "Gui/DefaultKeysBindingInterface.hpp"
#include "Print.hpp"

AoL::Gui::DefaultKeysBindingInterface::DefaultKeysBindingInterface()
{
  TextButton *buttonTitle = new TextButton(L"KeysBinding",
					   AoL::Gui::GUITypeId::B_TITLE);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonTitle);

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

  ClickButton *buttonBack = new ClickButton(L"Back", "Assets/textures/rectangle.png",
					    "Assets/textures/rectangle.png",
					    AoL::Gui::GUITypeId::B_BACK2);
  setButton(AoL::Gui::GUITypeId::M_KEYSBINDING, buttonBack);

  SimpleButton *buttonPressKey = new SimpleButton(L"Press a Key",
						 "Assets/textures/rectangle.png",
						 "Assets/textures/rectangle.png",
						 AoL::Gui::GUITypeId::B_PRESSKEY);
  setButton(AoL::Gui::GUITypeId::M_PRESSKEY, buttonPressKey);
}

AoL::Gui::DefaultKeysBindingInterface::~DefaultKeysBindingInterface()
{
  std::vector<ButtonHolder *>	buttonsHolder = _modulesHolder[0]->getModule()->getButtonsHolder();
  for (irr::u32 i = 0; i < 10; ++i)
    delete (buttonsHolder[i]->getButton());
}

