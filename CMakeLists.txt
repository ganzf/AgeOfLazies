cmake_minimum_required (VERSION 2.6)

# set du compilateur pour Linux
if (UNIX)
  set (CMAKE_CXX_COMPILER g++)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -std=c++14 -O2")
endif(UNIX)
project (IndieStudio)

# autorise CMake a creer des dossiers
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories(
  ${PROJECT_SOURCE_DIR}/include/
  )

add_executable (
AgeOfLazies
src/main.cpp
src/Manager.cpp 
src/rendering/Camera.cpp
src/rendering/Renderer.cpp
src/rendering/Window.cpp
src/rendering/Sound.cpp
src/rendering/Context.cpp
src/rendering/Scene3d.cpp
src/rendering/Gui/InfoGetter.cpp
src/rendering/Gui/Gui.cpp
src/rendering/Gui/ARenderedModule.cpp
src/rendering/Gui/RenderedMenu.cpp
src/rendering/Gui/RenderedNewGame.cpp
src/rendering/Gui/RenderedLoadGame.cpp
src/rendering/Gui/RenderedAI.cpp
src/rendering/Gui/RenderedOption.cpp
src/rendering/Gui/RenderedKeysBinding.cpp
src/rendering/Gui/RenderedPressKey.cpp
src/rendering/Gui/RenderedGeneralScore.cpp
src/rendering/Gui/RenderedEcoScore.cpp
src/rendering/Gui/RenderedFightScore.cpp
src/rendering/Gui/RenderedLazyScore.cpp
src/rendering/Gui/RenderedEndGame.cpp
src/rendering/Gui/RenderedStats.cpp
src/rendering/Gui/RenderedActions.cpp
src/rendering/Gui/RenderedInfos.cpp
src/rendering/Gui/RenderedPause.cpp
src/rendering/Gui/RenderedEncyclopedie.cpp
src/rendering/Gui/ARenderedElement.cpp
src/rendering/Gui/RenderedClickButton.cpp
src/rendering/Gui/RenderedSimpleButton.cpp
src/rendering/Gui/RenderedBarButton.cpp
src/rendering/Gui/RenderedXPBar.cpp
src/rendering/Gui/RenderedHPLife.cpp
src/rendering/Gui/RenderedTextButton.cpp
src/rendering/Animator.cpp
src/rendering/RTSCamera.cpp
src/core/Core.cpp
src/Game/MapGenerator.cpp
src/Game/Player.cpp
src/userInput/inputHandler.cpp
src/userInput/keyboardHandler.cpp
src/userInput/mouseHandler.cpp
src/Scenes/AScene.cpp 
src/Scenes/Logger.cpp 
src/Scenes/Intro.cpp 
src/Scenes/MainMenu.cpp 
src/Scenes/NewGameMenu.cpp 
src/Scenes/LoadGameMenu.cpp 
src/Scenes/OptionMenu.cpp 
src/Scenes/KeysBinding.cpp 
src/Scenes/Score.cpp 
src/Scenes/Game.cpp
src/Scenes/Victory.cpp
src/Scenes/Defeat.cpp
src/Gui/MenuInterface.cpp 
src/Gui/MenuModule.cpp
src/Game/Map.cpp 
src/Game/Entity.cpp
src/Game/Anchor.cpp
src/Game/Orders/Attack.cpp
src/Game/Orders/Deposit.cpp
src/Game/Orders/Collect.cpp
src/Game/Orders/Move.cpp
src/Game/Controlled.cpp
src/Game/Grid.cpp
src/Gui/DefaultMenuInterface.cpp
src/Gui/DefaultGameInterface.cpp
src/Gui/DefaultNewGameInterface.cpp
src/Gui/DefaultLoadGameInterface.cpp
src/Gui/DefaultEndGameInterface.cpp
src/Gui/DefaultOptionInterface.cpp
src/Gui/DefaultKeysBindingInterface.cpp
src/Gui/DefaultScoreInterface.cpp
src/Gui/MenuInterface.cpp
src/Gui/NewGameInterface.cpp
src/Gui/LoadGameInterface.cpp
src/Gui/OptionInterface.cpp
src/Gui/KeysBindingInterface.cpp
src/Gui/GameInterface.cpp
src/Gui/EndGameInterface.cpp
src/Gui/ScoreInterface.cpp
src/Gui/MenuModule.cpp
src/Gui/StatModule.cpp
src/Gui/ActionModule.cpp
src/Gui/InfoModule.cpp
src/Gui/MapModule.cpp
src/Gui/PauseModule.cpp
src/Gui/NewGameModule.cpp
src/Gui/LoadGameModule.cpp
src/Gui/AIModule.cpp
src/Gui/OptionModule.cpp
src/Gui/KeysBindingModule.cpp
src/Gui/PressKeyModule.cpp
src/Gui/GeneralScoreModule.cpp
src/Gui/EcoScoreModule.cpp
src/Gui/FightScoreModule.cpp
src/Gui/LazyScoreModule.cpp
src/Gui/EndGameModule.cpp
src/Gui/EncyclopedieModule.cpp
src/Observer.cpp
src/Message.cpp
src/Factory.cpp
src/Game/AiPlayer.cpp
src/Game/LuaFunc.cpp
src/Game/Stock.cpp
src/Scenes/StartScreen.cpp
)

if (WIN32)

  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Windows/Irrlicht.lib)
  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Windows/irrKlang.lib)
  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Windows/lua5.2.lib)
  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Windows/fmod64_vc.lib)
  set(CPACK_GENERATOR "NSIS")
  set(CPACK_NSIS_MODIFY_PATH ON)
set(CMAKE_INSTALL_PREFIX ".")
set(ORIGIN_PATH ".")
install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/libraries/Windows/dll/
  DESTINATION .
  COMPONENT Game
  )
endif(WIN32)

if (UNIX)
  set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${PROJECT_SOURCE_DIR}/libraries/Linux/libIrrlicht.so.1.8")
  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Linux/libIrrlicht.so.1.8)
  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Linux/libIrrKlang.so)
  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Linux/libfmod.so)
  target_link_libraries(AgeOfLazies ${PROJECT_SOURCE_DIR}/libraries/Linux/liblua5.2.so)
  target_link_libraries(AgeOfLazies pthread)
  set(CPACK_GENERATOR "TGZ")
  set(ORIGIN_PATH "AgeOfLazies")
install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/libraries/Linux/
  DESTINATION .
  COMPONENT Game
  )
endif(UNIX)

install(
TARGETS AgeOfLazies
DESTINATION ${ORIGIN_PATH}
COMPONENT Game
)

install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/Assets/
  DESTINATION ${ORIGIN_PATH}/Assets
  COMPONENT Game
)

install(
  DIRECTORY ${PROJECT_SOURCE_DIR}/LuaScripts/
  DESTINATION ${ORIGIN_PATH}/LuaScripts
  COMPONENT Game
)

set(CPACK_PACKAGE_NAME "AoL-setup")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Michael Boublil")
set(CPACK_PACKAGE_VENDOR "LazyStudio")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Age of Lazies")
set(CPACK_COMPONENTS_ALL Game)


include(CPack)

