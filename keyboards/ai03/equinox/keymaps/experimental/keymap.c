#include QMK_KEYBOARD_H

enum equinox_layers {
  _COLEMAK,
  _QWERTY,
  _GAMING,
  _FNKEYS,
  _SYMBOL,
  _ADJUST
};

enum equinox_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMING
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum {
    SINGLE_HOLD = 1,
    DOUBLE_HOLD = 2,
    TRIPLE_HOLD = 3
};

// Tap dance enums
enum {
    HLD_LAY = 0,
    DSL,
    CMN,
    CQT
};

uint8_t cur_dance(qk_tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void x_finished(qk_tap_dance_state_t *state, void *user_data);
void x_reset(qk_tap_dance_state_t *state, void *user_data);

/*
 * Keymaps and other stuff goes here.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DH
* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
* │  TAB   │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │  ;  │ BSPC │
* ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
* │Backspace│  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  ┋ENTER│
* ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
* │   LSHIFT   │  Z  │  X  │  C  │  D  │  V  │  M  │  H  │  ,  │  .  ┋ RSHIFT │
* ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
* │L_CTRL│     │ LALT │     SPC      ┋ SPC ┋      SPC     │HLDLAY│     │R_GUI │
* └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
*/
 [_COLEMAK] = LAYOUT_all( /* Colemak-DH Base */
   KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT), KC_BSPC,
   KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
   KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    TD(CMN), TD(DSL), KC_RSFT,
   KC_LCTL, XXXXXXX, KC_LALT,          KC_SPC,           KC_SPC,       KC_SPC,      HLD_LAY, XXXXXXX, RESET
 ),

/* Qwerty
* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
* │        │     │     │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │      │
* ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
* │         │     │  S  │  D  │  F  │     │  H  │  J  │  K  │  L  │  ;  ┋     │
* ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
* │      ┋     │     │     │     │  V  │  B  │  N  │  M  │     │     ┋        │
* ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
* │      │     │      │              ┋     ┋              │      │     │      │
* └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
*/
 [_QWERTY] = LAYOUT_all( /* Base */
   _______, _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
   _______, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    TD(CQT), _______,
   _______, _______, _______, _______, _______, KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______,
   _______, _______, _______,          _______,          _______,      _______,     _______, _______, _______
 ),

/* Qwerty (Gaming)
* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
* │        │     │     │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │      │
* ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
* │CAPS LOCK│     │  S  │  D  │  F  │     │  H  │  J  │  K  │  L  │  ;  ┋     │
* ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
* │      ┋     │     │     │     │  V  │  B  │  N  │  M  │     │     ┋        │
* ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
* │      │     │      │              ┋     ┋              │      │     │      │
* └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
*/
 [_GAMING] = LAYOUT_all( /* Base */
   _______, _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
   KC_CAPS, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    TD(CQT), _______,
   _______, _______, _______, _______, _______, KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______,
   _______, XXXXXXX, _______,          _______,          _______,      _______,     _______, XXXXXXX, XXXXXXX
 ),

/* Unused Function keys for use with AutoHotkey
* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
* │        │ F13 │ F14 │ F15 │ F16 │ F17 │ F18 │     │     │     │     │      │
* ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
* │         │ F19 │ F20 │ F21 │ F22 │ F23 │ F24 │     │     │     │     ┋     │
* ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
* │      ┋     │     │     │     │     │     │     │     │     │     ┋        │
* ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
* │      │     │      │              ┋     ┋              │      │     │      │
* └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
*/
 [_FNKEYS] = LAYOUT_all( /* Unused Function Keys */
   XXXXXXX, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   _______, XXXXXXX, _______,          XXXXXXX,          XXXXXXX,     XXXXXXX,      _______, XXXXXXX, XXXXXXX
 ),

/*
* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
* │  ESC   │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │      │
* ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
* │  GRAVE  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  \  │  =  │  [  │  ]  ┋     │
* ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
* │      ┋     │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Del │Pg Up│Pg Dn┋        │
* ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
* │      │     │      │              ┋     ┋              │      │     │      │
* └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
*/
 [_SYMBOL] = LAYOUT_all( /* Symbol Keys */
   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
   KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
   _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_PGUP, KC_PGDN, _______,
   _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
 ),

/* Keeping this layer non-transparent.
* ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
* │        │ QWT │     │     │Reset│     │     │Next │Vol -│Vol +│Prev │      │
* ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
* │CAPS LOCK│     │SOUND│     │     │     │     │Left │Down │ Up  │Right┋Play │
* ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
* │      ┋     │     │     │ COL │     │     │     │     │Home │ End ┋        │
* ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
* │      │     │      │              ┋     ┋              │      │     │      │
* └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
*/
 [_ADJUST] = LAYOUT_all( /* Board Functions and extra keycodes */
   XXXXXXX, QWERTY,  XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
   KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAMING,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY,
   _______, _______, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  XXXXXXX,
   _______, _______, _______,          XXXXXXX,          XXXXXXX,     XXXXXXX,      _______, _______, _______
 )
};

uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->pressed) {
            return SINGLE_HOLD;
        } else {
            return SINGLE_TAP;
        }
    }
    if (state->count == 2) {
        if (state->pressed) {
            return DOUBLE_HOLD;
        } else {
            return DOUBLE_TAP;
        }
    }
    if (state->count == 3) {
        if (state->pressed) {
            return TRIPLE_HOLD;
        } else {
            return TRIPLE_TAP;
        }
    }
    return 8;
}

// Create an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {
    .is_press_action = true,
    .state = 0
};

void x_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_HOLD: layer_on(_SYMBOL); break;
        case DOUBLE_HOLD: layer_on(_ADJUST); break;
        case TRIPLE_HOLD: layer_on(_FNKEYS);
    }
}

void x_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_HOLD: layer_off(_SYMBOL); break;
        case DOUBLE_HOLD: layer_off(_ADJUST); break;
        case TRIPLE_HOLD: layer_off(_FNKEYS);
    }
    xtap_state.state = 0;
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [HLD_LAY] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_finished, x_reset),
    [DSL] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_SLSH),
    [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
    [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_QUOT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case GAMING:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
      break;
  }
  return true;
}
