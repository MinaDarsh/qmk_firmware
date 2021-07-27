/* Copyright 2020 Jason Williams (Wilba)
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

enum m50a_layers {
  _COLEMAK,
  _QWERTY,
  _GAMING,
  _RAISE,
  _LOWER,
  _ADJUST
};

enum m50a_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMING
};

enum {
  CMN = 0,
  CQT,
  GES,
  TES
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

void tabesc_finished(qk_tap_dance_state_t *state, void *user_data);
void tabesc_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DHk
 * ┌─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │Home │  │ Tab │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │'(;) │ Del │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Pg Up│  │ Esc │  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  │Enter│
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Pg Dn│  │LShft│  Z  │  X  │  C  │  D  │  V  │  M  │  H  │,(-) │  .  │  /  │RShft│
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │ End │  │LCtl │ App │ GUI │LAlt │Lower│Space┋Space│Raise│Left │Down │ Up  │Right│
 * └─────┘  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_COLEMAK] = LAYOUT(
    KC_HOME,   TD(TES), KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT), KC_DEL,
    KC_PGUP,   KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_PGDN,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_M,    KC_H,    TD(CMN), KC_DOT,  KC_SLSH, KC_RSFT,
    KC_END,    KC_LCTL, KC_APP,  KC_LGUI, KC_LALT, LOWER,       KC_SPC,       RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ┌─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  │     │     │     │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │  S  │  D  │  F  │     │  H  │  J  │  K  │  L  │ '(;)│     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │  V  │  B  │  N  │  M  │     │     │     │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │     │     ┋     │     │     │     │     │     │
 * └─────┘  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_QWERTY] = LAYOUT(
    _______,   _______, _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______,   _______, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    TD(CQT), _______,
    _______,   _______, _______, _______, _______, KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______,
    _______,   _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Qwerty (Gaming) capslock in original pos, normal Tap-Dance for tab-escape so tab can also be held.
 * ┌─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  1  │  │     │     │     │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  2  │  │CapsL│     │  S  │  D  │  F  │     │  H  │  J  │  K  │  L  │ '(;)│     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  3  │  │     │     │     │     │  V  │  B  │  N  │  M  │     │     │     │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  4  │  │     │     │     │     │     │     ┋     │     │     │     │     │     │
 * └─────┘  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_GAMING] = LAYOUT(
    KC_1,      TD(GES), _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    KC_2,      KC_CAPS, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    TD(CQT), _______,
    KC_3,      _______, _______, _______, _______, KC_V,    KC_B,    KC_N,    KC_M,    _______, _______, _______, _______,
    KC_4,      _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Raise
 * ┌─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │ N/A │ N/A │ N/A │ N/A │PScrn│Pause│  \  │  =  │  [  │  ]  │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │Prev │Vol -│Vol +│Next │Play │ N/A │ N/A │ N/A │ N/A │ N/A │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │     │     ┋     │     │     │     │     │     │
 * └─────┘  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_RAISE] = LAYOUT(
    _______,   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_PAUS, KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______,   _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______,   _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Lower
 * ┌─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  │  ~  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  |  │  +  │  {  │  }  │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ N/A │ N/A │ N/A │ N/A │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │     │     ┋     │     │     │     │     │     │
 * └─────┘  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_LOWER] = LAYOUT(
  _______,   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______,   _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR, _______,
  _______,   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  _______,   _______, _______, _______, _______, _______,      _______,     _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise) Blank keys are disabled here.
 * ┌─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  │Reset│Qwrty│EfInc│ESInc│BrInc│     │     │     │H1Inc│S1Inc│H2Inc│S2Inc│
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │AGSwp│EfDec│ESDec│BrDec│Game │     │TKNRO│H1Dec│S1Dec│H2Dec│S2Dec│
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │Colmk│     │     │     │     │     │     │     │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │     │     ┋     │     │     │     │     │     │
 * └─────┘  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
[_ADJUST] = LAYOUT(
    XXXXXXX,   RESET,   QWERTY,  EF_INC,  ES_INC,  BR_INC,  XXXXXXX, XXXXXXX, XXXXXXX, H1_INC,  S1_INC,  H2_INC,  S2_INC,
    XXXXXXX,   XXXXXXX, AG_TOGG, EF_DEC,  ES_DEC,  BR_DEC,  GAMING,  XXXXXXX, NK_TOGG, H1_DEC,  S1_DEC,  H2_DEC,  S2_DEC,
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void tabesc_per_tap(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count > 1) {
    register_code(KC_TAB);
    if (!state->pressed) {
      unregister_code(KC_TAB);
    }
  }
}

void tabesc_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->pressed) {
      register_code(KC_ESC);
    } else {
      register_code(KC_TAB);
    }
  }
}

void tabesc_reset(qk_tap_dance_state_t *state, void *user_data) {
  unregister_code(KC_ESC);
  unregister_code(KC_TAB);
}

qk_tap_dance_action_t tap_dance_actions[] = {
  /*
  There are two kinds of Tap-Dance Tab/Escapes here, one is for use in text,
  and one is for use in games. TES has the ability to use Tabs instantly without
  having to wait for TAPPING_TERM to pass and can be spammed, downside is that
  Tab can't be held properly in some games, and we don't need to spam it anyway
  as far as I know, so, just a regular DOUBLE Tap-Dance for the Gaming layer.
  */
  [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
  [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [GES] = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC),
  [TES] = ACTION_TAP_DANCE_FN_ADVANCED(tabesc_per_tap, tabesc_finished, tabesc_reset)
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

// Template for easy copying.

/*
 * ┌─────┐  ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │     │  │     │     │     │     │     │     │     │     │     │     │     │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │     │     │     │     │     │     │     │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │     │     │     │     │     │     │     │     │
 * ├─────┤  ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │     │  │     │     │     │     │     │     ┋     │     │     │     │     │     │
 * └─────┘  └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
 */
