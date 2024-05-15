#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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

[_COLEMK] = LAYOUT(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC, KC_BSLS,
  KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, KC_BSLS, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_SLSH, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, FUNCTIO,
  KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RGUI, FUNCTIO, KC_RCTL),

[_QWERTY] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, KC_E   , KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______, _______,
  KC_CAPS, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, _______, KC_NUHS, _______,
  _______, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______, _______,
  _______, _______, _______,                            _______,                            _______, _______, _______, _______),

[_GAMING] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, XXXXXXX, _______,                            _______,                            _______, XXXXXXX, _______, _______),

[_FUNCTN] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  XXXXXXX,
  _______, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU, XXXXXXX,
  KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, GAMING,  XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRID, QK_BOOT,
  _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______,
  _______, _______, _______,                            _______,                            _______, _______, _______, _______)
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
  }
  return true;
}