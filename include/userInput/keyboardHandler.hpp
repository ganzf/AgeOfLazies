#ifndef KEYBOARDHANDLER_HPP_
# define KEYBOARDHANDLER_HPP_

# include <unordered_map>
# include <vector>
# include <stack>
# include "irrlicht/irrlicht.h"

namespace			AoL
{
  namespace			UserInput
  {

    enum class			KeyStatus : irr::s32
    {
	UNDEFINED = -1,
	PRESSED,
	RELEASED
    };

    enum class			KeyValue : irr::s8
    {
      UNDEFINED = -1,
	UP, DOWN, LEFT,	RIGHT,
	ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX,	SEVEN, EIGHT, NINE,
	ESCAPE,
	F1, F2,	F3, F4, F5, F6, F7, F8,
	A, B, C, D, E, F, G, H, I, J, K, L, M,
	N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	NBR_KEYS
	};

    const std::unordered_map<irr::EKEY_CODE, KeyValue> _convKey =
      {
	{irr::EKEY_CODE::KEY_UP, KeyValue::UP},
	{irr::EKEY_CODE::KEY_DOWN, KeyValue::DOWN},
	{irr::EKEY_CODE::KEY_LEFT, KeyValue::LEFT},
	{irr::EKEY_CODE::KEY_RIGHT, KeyValue::RIGHT},
	{irr::EKEY_CODE::KEY_KEY_0, KeyValue::ZERO},
	{irr::EKEY_CODE::KEY_KEY_1, KeyValue::ONE},
	{irr::EKEY_CODE::KEY_KEY_2, KeyValue::TWO},
	{irr::EKEY_CODE::KEY_KEY_3, KeyValue::THREE},
	{irr::EKEY_CODE::KEY_KEY_4, KeyValue::FOUR},
	{irr::EKEY_CODE::KEY_KEY_5, KeyValue::FIVE},
	{irr::EKEY_CODE::KEY_KEY_6, KeyValue::SIX},
	{irr::EKEY_CODE::KEY_KEY_7, KeyValue::SEVEN},
	{irr::EKEY_CODE::KEY_KEY_8, KeyValue::EIGHT},
	{irr::EKEY_CODE::KEY_KEY_9, KeyValue::NINE},
	{irr::EKEY_CODE::KEY_ESCAPE, KeyValue::ESCAPE},
	{irr::EKEY_CODE::KEY_F1, KeyValue::F1},
	{irr::EKEY_CODE::KEY_F2, KeyValue::F2},
	{irr::EKEY_CODE::KEY_F3, KeyValue::F3},
	{irr::EKEY_CODE::KEY_F4, KeyValue::F4},
	{irr::EKEY_CODE::KEY_F5, KeyValue::F5},
	{irr::EKEY_CODE::KEY_F6, KeyValue::F6},
	{irr::EKEY_CODE::KEY_F7, KeyValue::F7},
	{irr::EKEY_CODE::KEY_F8, KeyValue::F8},
	{irr::EKEY_CODE::KEY_KEY_A, KeyValue::A},
	{irr::EKEY_CODE::KEY_KEY_B, KeyValue::B},
	{irr::EKEY_CODE::KEY_KEY_C, KeyValue::C},
	{irr::EKEY_CODE::KEY_KEY_D, KeyValue::D},
	{irr::EKEY_CODE::KEY_KEY_E, KeyValue::E},
	{irr::EKEY_CODE::KEY_KEY_F, KeyValue::F},
	{irr::EKEY_CODE::KEY_KEY_G, KeyValue::G},
	{irr::EKEY_CODE::KEY_KEY_H, KeyValue::H},
	{irr::EKEY_CODE::KEY_KEY_I, KeyValue::I},
	{irr::EKEY_CODE::KEY_KEY_J, KeyValue::J},
	{irr::EKEY_CODE::KEY_KEY_K, KeyValue::K},
	{irr::EKEY_CODE::KEY_KEY_L, KeyValue::L},
	{irr::EKEY_CODE::KEY_KEY_M, KeyValue::M},
	{irr::EKEY_CODE::KEY_KEY_N, KeyValue::N},
	{irr::EKEY_CODE::KEY_KEY_O, KeyValue::O},
	{irr::EKEY_CODE::KEY_KEY_P, KeyValue::P},
	{irr::EKEY_CODE::KEY_KEY_Q, KeyValue::Q},
	{irr::EKEY_CODE::KEY_KEY_R, KeyValue::R},
	{irr::EKEY_CODE::KEY_KEY_S, KeyValue::S},
	{irr::EKEY_CODE::KEY_KEY_T, KeyValue::T},
	{irr::EKEY_CODE::KEY_KEY_U, KeyValue::U},
	{irr::EKEY_CODE::KEY_KEY_V, KeyValue::V},
	{irr::EKEY_CODE::KEY_KEY_W, KeyValue::W},
	{irr::EKEY_CODE::KEY_KEY_X, KeyValue::X},
	{irr::EKEY_CODE::KEY_KEY_Y, KeyValue::Y},
	{irr::EKEY_CODE::KEY_KEY_Z, KeyValue::Z},
      };

    class			KeyboardHandler : public irr::IEventReceiver
    {
    private:
      std::vector<KeyStatus>	_keys;

    public:
      KeyboardHandler(void);
      ~KeyboardHandler(void) = default;

      bool			OnEvent(const irr::SEvent& event);
      KeyStatus			isKeyPressed(KeyValue key);
    };
  }
}

#endif /* !KEYBOARDHANDLER_HPP */
