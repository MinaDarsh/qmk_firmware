/* Copyright 2019 Ryota Goto
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum equinox_layers {
  _COLEMAK,
  _QWERTY,
  _GAMING,
  _SYMBOL,
  _ADJUST
};

enum equinox_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMING
};

enum {
  DSL = 0,
  CMN,
  CQT,
  LYR
};

void layers_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_on(_SYMBOL);
  }
  else if (state->count == 2) {
    layer_on(_ADJUST);
  }
}

void layers_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    layer_off(_SYMBOL);
  }
  else if (state->count == 2) {
    layer_off(_ADJUST);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [DSL] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_SLSH),
  [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
  [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [LYR] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, layers_finished, layers_reset, 250)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DH
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │  TAB   │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │  ;  │ BSPC │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │Backspace│  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  ┋ENTER│
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │LSHIFT┋SYMBL│  Z  │  X  │  C  │  D  │  V  │  M  │  H  │  ,  │  .  ┋ RSHIFT │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │L_CTRL│     │ LALT │     SPC      ┋ SPC ┋      SPC     │SYMBOL│     │R_GUI │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_COLEMAK] = LAYOUT_all( /* Colemak-DH Base */
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT), KC_BSPC,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, TD(LYR), KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    TD(CMN), TD(DSL), KC_RSFT,
    KC_LCTL, XXXXXXX, KC_LALT,          KC_SPC,           KC_SPC,       KC_SPC,      TD(LYR), XXXXXXX, KC_RGUI
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

/*
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │  ESC   │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │  GRAVE  │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  \  │  =  │  [  │  ]  ┋     │
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋ADJST│ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Del │Pg Up│Pg Dn┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │ADJUST│     │      │
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
 * │CAPS LOCK│     │     │     │     │Game │     │Left │Down │ Up  │Right┋Play │
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋     │     │     │ COL │     │     │     │     │Home │ End ┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │      │     │      │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_ADJUST] = LAYOUT_all( /* Board Functions and extra keycodes */
    XXXXXXX, QWERTY,  XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
    KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAMING,  XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY,
    _______, _______, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_END,  _______,
    _______, _______, _______,          XXXXXXX,          XXXXXXX,     XXXXXXX,      _______, _______, _______
  )
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
