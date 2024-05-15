#include QMK_KEYBOARD_H

enum plain60_layers {
  _COLEMK,
  _QWERTY,
  _GAMING,
  _FUNCTN
};

enum plain60_keycodes {
  QWERTY = SAFE_RANGE,
  GAMING,
  FUNCTIO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	  [_COLEMK] = LAYOUT_tkl_ansi_tsangan(
	    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_PSCR, KC_SCRL, KC_PAUS,
	    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,
	    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,  KC_END,  KC_PGDN,
	    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_ENT,
	    KC_LSFT, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                                     KC_UP,
	    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                                      KC_RALT, FUNCTIO, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT),

	  [_QWERTY] = LAYOUT_tkl_ansi_tsangan(
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
	    _______, _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______, _______,          _______, _______, _______,
	    KC_CAPS, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, _______,
	    _______, KC_Z,    KC_X,    KC_C,    _______, KC_B,    KC_N,    KC_M,    _______, _______, _______, _______,                                     _______,
	    _______, _______, _______,                            _______,                                     _______, _______, _______,          _______, _______, _______),

	  [_GAMING] = LAYOUT_tkl_ansi_tsangan(
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                     _______,
	    _______, XXXXXXX, _______,                            _______,                                     _______, _______, _______,          _______, _______, _______),

	  [_FUNCTN] = LAYOUT_tkl_ansi_tsangan(
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______,
	    _______, EF_DEC,  EF_INC,  H1_DEC,  H1_INC,  H2_DEC,  H2_INC,  _______, _______, _______, _______, BR_DEC,  BR_INC,  _______,          _______, _______, _______,
	    _______, QWERTY,  _______, S1_DEC,  S1_INC,  S2_DEC,  S2_INC,  _______, _______, _______, _______, ES_DEC,  ES_INC,  _______,          _______, KC_MPLY, _______,
	    _______, _______, _______, _______, _______, GAMING,  _______, NK_TOGG, _______, _______, _______, _______, _______,
	    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                                     KC_VOLU,
	    _______, _______, _______,                            _______,                                     _______, _______, _______,          KC_MPRV, KC_VOLD, KC_MNXT)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case QWERTY:
    if (record->event.pressed) {
      if (!layer_state_is(_QWERTY)) {
        layer_on(_QWERTY);
      } else {
        layer_off(_QWERTY);
      }
    }
    return false;
  case GAMING:
    if (record->event.pressed) {
      if (!layer_state_is(_GAMING)) {
        layer_on(_GAMING);
      } else {
        layer_off(_GAMING);
      }
    }
    return false;
  case FUNCTIO:
    if (record->event.pressed) {
      layer_on(_FUNCTN);
    } else {
      layer_off(_FUNCTN);
    }
    return false;
  case KC_Z:
    if (get_mods() == MOD_BIT(KC_LSFT)) {
        if (record->event.pressed) {
            register_code(KC_SLSH);
        } else {
            unregister_code(KC_SLSH);
        }
        return false;
    }
    return true;
  }
  return true;
}