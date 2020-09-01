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
#include QMK_KEYBOARD_H;

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
  GAMING,
  SYMBOL,
  ADJUST
};

enum {
  DSL = 0,
  CMN,
  CQT,
  EF1,
  1F2,
  2F3,
  3F4,
  4F5,
  5F6,
  6F7,
  7F8,
  8F9,
  910,
  011,
  E12,
  B12
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [DSL] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_SLSH),
  [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
  [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [EF1] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_F1),
  [1F2] = ACTION_TAP_DANCE_DOUBLE(KC_1, KC_F2),
  [2F3] = ACTION_TAP_DANCE_DOUBLE(KC_2, KC_F3),
  [3F4] = ACTION_TAP_DANCE_DOUBLE(KC_3, KC_F4),
  [4F5] = ACTION_TAP_DANCE_DOUBLE(KC_4, KC_F5),
  [5F6] = ACTION_TAP_DANCE_DOUBLE(KC_5, KC_F6),
  [6F7] = ACTION_TAP_DANCE_DOUBLE(KC_6, KC_F7),
  [7F8] = ACTION_TAP_DANCE_DOUBLE(KC_7, KC_F8),
  [8F9] = ACTION_TAP_DANCE_DOUBLE(KC_8, KC_F9),
  [910] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_F10),
  [011] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_F11),
  [E12] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_F12),
  [B12] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_F12)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DH
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │  TAB   │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │ '/; │ BSPC │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │Backspace│  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  ┋ENTER│
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │LSHIFT┋SYMBL│  Z  │  X  │  C  │  D  │  V  │  M  │  H  │ ,/- │ .// ┋ RSHIFT │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │L_CTRL│     │ LALT │     SPC      ┋ SPC ┋      SPC     │SYMBOL│     │R_GUI │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_COLEMAK] = LAYOUT_all( /* Colemak-DH Base */
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT), KC_BSPC,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, SYMBOL,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    TD(CMN), TD(DSL), KC_RSFT,
    KC_LCTL, XXXXXXX, KC_LALT,          KC_SPC,           KC_SPC,       KC_SPC,      SYMBOL,  XXXXXXX, KC_RGUI
  ),

/* Qwerty
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │        │     │     │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │         │     │  S  │  D  │  F  │     │  H  │  J  │  K  │  L  │ '/; ┋     │
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
 * │ ESC/F1 │1/F2 │2/F3 │3/F4 │4/F5 │5/F6 │6/F7 │7/F8 │8/F9 │9/F10│0/F11│BS/F12│
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │  GRAVE  │     │     │     │     │     │     │  \  │  =  │  [  │  ]  ┋E/F12│
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋ADJST│     │     │     │     │     │     │ Del │Pg Up│Pg Dn┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │ADJUST│     │      │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_SYMBOL] = LAYOUT_all( /* Symbol Keys */
    TD(EF1), TD(1F2), TD(2F3), TD(3F4), TD(4F5), TD(5F6), TD(6F7), TD(7F8), TD(8F9), TD(910), TD(011), TD(B12),
    KC_GRV,  _______, _______, _______, _______, _______, _______, KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC, TD(E12),
    _______, ADJUST,  _______, _______, _______, _______, _______, _______, KC_DEL,  KC_PGUP, KC_PGDN, _______,
    _______, _______, _______,          _______,          _______,     _______,      ADJUST,  _______, _______
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
    case SYMBOL:
      if (record->event.pressed) {
        layer_on(_SYMBOL);
      } else {
        layer_off(_SYMBOL);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
