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
  _NUMPAD,
  _SYMBOL,
  _SYMBL2,
  _ADJUST
};

enum equinox_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY,
  GAMING,
  NUMPAD,
  LEAVENM
};

enum {
  CMN = 0,
  CQT,
  TES,
  LYR,
};

bool td_was_held = false;
bool td_is_on_sm2 = false;
bool td_is_on_adj = false;
static uint16_t timer;
static bool is_idle;

void layers_finished(qk_tap_dance_state_t *state, void *user_data);
void layers_reset(qk_tap_dance_state_t *state, void *user_data);
void tabesc_finished(qk_tap_dance_state_t *state, void *user_data);
void tabesc_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DHk
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │Tab(Esc)│  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │ '(;)│Bk Spc│
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │Backspace│  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  ┋Enter│
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │LShift┋  Z  │  X  │  C  │  D  │  V  │  ?  │  M  │  H  │ ,(-)│  .  ┋ RShift │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │L_Ctrl│     │ LAlt │    Space*    ┋Space┋  Backspace*  │QFTDLK│     │R_GUI │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 * * If split, change the middle button if applicable.
 */
  [_COLEMAK] = LAYOUT_all( /* Colemak-DH Base */
    TD(TES), KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT), KC_BSPC,
    KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_SLSH, KC_M,    KC_H,    TD(CMN), KC_DOT,  KC_RSPC,
    KC_LCTL, XXXXXXX, KC_LALT,          KC_SPC,           KC_SPC,       KC_BSPC,     TD(LYR), XXXXXXX, KC_RGUI
  ),

/* Qwerty
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │        │     │     │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │         │     │  S  │  D  │  F  │     │  H  │  J  │  K  │  L  │ '(;)┋     │
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋     │     │     │  V  │  B  │     │  N  │  M  │     │     ┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │      │     │      │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_QWERTY] = LAYOUT_all( /* Base */
    _______, _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    _______, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    TD(CQT), _______,
    _______, _______, _______, _______, KC_V,    KC_B,    _______, KC_N,    KC_M,    _______, _______, _______,
    _______, _______, _______,          _______,          _______,      _______,     _______, _______, _______
  ),

/* Qwerty (Gaming)
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │        │     │     │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │Caps Lock│     │  S  │  D  │  F  │     │  H  │  J  │  K  │  L  │ '(;)┋     │
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋     │     │     │  V  │  B  │     │  N  │  M  │     │     ┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │      │     │      │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_GAMING] = LAYOUT_all( /* Base */
    TD(TES),  _______, _______, KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
    KC_CAPS, _______, KC_S,    KC_D,    KC_F,    _______, KC_H,    KC_J,    KC_K,    KC_L,    TD(CQT), _______,
    KC_LSFT, _______, _______, _______, KC_V,    KC_B,    _______, KC_N,    KC_M,    _______, _______, KC_RSFT,
    _______, _______, _______,          _______,          _______,      _______,     _______, _______, _______
  ),

/*
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │  Esc   │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │   Del   │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │  \  │  =  │  [  │  ]  ┋     │
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │Home │ End │Pg Up│Pg Dn┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │      │     │      │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_SYMBOL] = LAYOUT_all( /* Symbol Keys */
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  ),

/*
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │ Grave  │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │   Del   │Left │ Up  │Down │Right│     │     │  |  │  +  │  {  │  }  ┋Play │
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋Prev │Vol -│Vol +│Next │     │     │     │     │PScrn│Pause┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │      │     │      │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_SYMBL2] = LAYOUT_all( /* Shifted Symbol, Media and other Keys */
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX, KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR, KC_MPLY,
    _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_PAUS, _______,
    _______, _______, _______,          _______,          _______,     _______,      _______, _______, _______
  ),

/* Keeping this layer non-transparent.
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │ Reset  │Qwrty│GENrm│     │     │Nm/TK│     │     │     │     │     │      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │         │AGSwp│GESwp│     │     │Game │     │TNKRO│     │     │     ┋     │
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋     │     │Colmk│     │     │     │     │     │     │     ┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │      │     │      │
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_ADJUST] = LAYOUT_all( /* Board Functions */
    RESET,   QWERTY,  GE_NORM, XXXXXXX, XXXXXXX, NUMPAD,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, AG_TOGG, GE_SWAP, XXXXXXX, XXXXXXX, GAMING,  XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,          XXXXXXX,     XXXXXXX,      _______, XXXXXXX, XXXXXXX
  ),

/* Who says 40% can't have a numpad?
 * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
 * │  Tab   │     │     │     │     │LveNm│NmLck│Num 7│Num 8│Num 9│Num +│      │
 * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
 * │Backspace│     │     │     │     │     │NmAst│Num 4│Num 5│Num 6│Num -┋NEntr│
 * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
 * │      ┋     │     │     │     │     │     │NmSlh│Num 1│Num 2│Num 3┋        │
 * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
 * │      │     │      │              ┋     ┋              │Num 0 │     │Num Dt│
 * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
 */
  [_NUMPAD] = LAYOUT_all( /* Numpad */
    KC_TAB,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LEAVENM, KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, _______,
    KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_P4,   KC_P5,   KC_P6,   KC_PMNS, KC_PENT,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_P1,   KC_P2,   KC_P3,   _______,
    _______, XXXXXXX, _______,          _______,          _______,     _______,      KC_P0,   XXXXXXX, KC_PDOT
  )
};

void matrix_scan_user() {
  if (!is_idle) {
    if (timer_elapsed(timer) >= (uint16_t) LAYER_IDLE_TIMEOUT * 1000) {
      is_idle = true;
      if (layer_state_is(_SYMBOL) || layer_state_is(_SYMBL2) || layer_state_is(_ADJUST) || layer_state_is(_NUMPAD)) {
        if (!td_was_held) {
          layer_off(_SYMBOL);
          layer_off(_SYMBL2);
          layer_off(_ADJUST);
          layer_off(_NUMPAD);
          td_is_on_sm2 = false;
          td_is_on_adj = false;
        }
      }
    }
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(CMN):
            return 175;
        case TD(CQT):
            return 175;
        case TD(TES):
            return 175;
        case TD(LYR):
            return 250;
        default:
            return TAPPING_TERM;
    }
}

void layers_per_tap(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (!layer_state_is(_SYMBOL)) {
      layer_on(_SYMBOL);
      layer_off(_SYMBL2);
      layer_off(_ADJUST);
    } else {
      layer_off(_SYMBOL);
    }
  }
  else if (state->count == 2) {
    if (!layer_state_is(_SYMBL2) && td_is_on_sm2 == false) {
      layer_off(_SYMBOL);
      layer_on(_SYMBL2);
      layer_off(_ADJUST);
    } else {
      layer_off(_SYMBOL);
      layer_off(_SYMBL2);
      td_is_on_sm2 = false;
    }
  }
  else if (state->count == 3) {
    if (!layer_state_is(_ADJUST) && td_is_on_adj == false) {
      layer_off(_SYMBL2);
      layer_on(_ADJUST);
    } else {
      layer_off(_SYMBOL);
      layer_off(_SYMBL2);
      layer_off(_ADJUST);
      td_is_on_adj = false;
    }
  }
  else if (state->count == 4) {
    layer_off(_ADJUST);
    td_is_on_sm2 = false;
    td_is_on_adj = false;
  }
}

void layers_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->pressed) {
    td_was_held = true;
    td_is_on_sm2 = false;
    td_is_on_adj = false;
  } else {
    td_was_held = false; // not sure if necessary
    if (state->count == 1 && layer_state_is(_SYMBOL)) {
      td_is_on_sm2 = false;
      td_is_on_adj = false;
    }
    else if (state->count == 2 && layer_state_is(_SYMBL2)) {
      td_is_on_sm2 = true;
      td_is_on_adj = false;
    }
    else if (state->count == 3 && layer_state_is(_ADJUST)) {
      td_is_on_sm2 = false;
      td_is_on_adj = true;
    }
  }
}

void layers_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (td_was_held == true) {
    layer_off(_SYMBOL);
    layer_off(_SYMBL2);
    layer_off(_ADJUST);
  }
  td_was_held = false;
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
  [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
  [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [TES] = ACTION_TAP_DANCE_FN_ADVANCED(tabesc_per_tap, tabesc_finished, tabesc_reset),
  [LYR] = ACTION_TAP_DANCE_FN_ADVANCED(layers_per_tap, layers_finished, layers_reset)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  timer = timer_read();
  if (is_idle) {
    is_idle = false;
  }
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
    case NUMPAD:
      if (record->event.pressed) {
        layer_off(_ADJUST); // stuff else goes wrong if we toggle and then try to switch to numpad
        layer_on(_NUMPAD);
      }
      return false;
      break;
    case LEAVENM:
      if (record->event.pressed) {
        layer_off(_NUMPAD);
      }
      return false;
      break;
  }
  return true;
}
