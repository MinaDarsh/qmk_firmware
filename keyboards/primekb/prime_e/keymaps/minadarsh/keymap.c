/* Copyright 2018 Holten Campbell
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

enum prime_e_layers {
  _COLEMAK,
  _QWERTY,
  _SYMBOL,
  _SYMBL2,
  _ADJUST
};

enum prime_e_keycodes {
  COLEMAK = SAFE_RANGE,
  QWERTY
};

enum {
  CMN = 0,
  CQT,
  LYR
};

bool td_was_held = false;
bool td_is_on_sm2 = false;
bool td_is_on_adj = false;
static uint16_t timer;
static bool is_idle;

void layers_finished(qk_tap_dance_state_t *state, void *user_data);
void layers_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
		KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,          KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT), KC_LBRC, KC_RBRC,
		KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,          KC_K,    KC_N,    KC_E,    KC_I,    KC_O,         KC_ENT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,          TD(LYR), KC_M,    KC_H,    TD(CMN), KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL, KC_LGUI,                   KC_LALT, KC_SPC,	      KC_BSPC, KC_RALT,                            KC_RGUI, KC_RCTL
    ),

    [_QWERTY] = LAYOUT(
		_______, _______, _______, KC_E,    KC_R,    KC_T,          KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______, _______,
		_______, _______, KC_S,    KC_D,    KC_F,    _______,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,      _______,
		_______, _______, _______, _______, KC_V,    KC_B,          _______, KC_N,    KC_M,    _______, _______, _______, _______,
		_______, _______,                   _______, _______,	      _______, _______,                            _______, _______
    ),

    [_SYMBOL] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_LPRN, KC_RPRN,
  	_______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PSCR,       KC_PAUS, KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC,      _______,
  	_______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,       _______, KC_SLCK, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______,
  	_______, _______,                   _______, _______,	      KC_DEL,  _______,                            _______, _______
    ),

    [_SYMBL2] = LAYOUT(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______,
    KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,         KC_F6,   KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR,      _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,        _______, KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, _______,                   _______, _______,	      KC_DEL,  _______,                            _______, _______
    ),

    [_ADJUST] = LAYOUT(
    RESET,   QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, NK_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX,       _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,	      XXXXXXX, XXXXXXX,                            XXXXXXX, XXXXXXX
    )
};

void matrix_scan_user() {
  if (!is_idle) {
    if (timer_elapsed(timer) >= (uint16_t) LAYER_IDLE_TIMEOUT * 1000) {
      is_idle = true;
      if (layer_state_is(_SYMBOL) || layer_state_is(_SYMBL2) || layer_state_is(_ADJUST)) {
        if (!td_was_held) {
          layer_off(_SYMBOL);
          layer_off(_SYMBL2);
          layer_off(_ADJUST);
          td_is_on_sm2 = false;
          td_is_on_adj = false;
        }
      }
    }
  }
}

void matrix_init_user(void) {
  setPinOutput(B1);
  writePinLow(B1);
  setPinOutput(B2);
  writePinLow(B2);
  setPinOutput(B3);
  writePinLow(B3);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  if (get_highest_layer(state) > 1) {
    writePinHigh(B1);
  } else {
    writePinLow(B1);
  }if (get_highest_layer(state) > 2) {
    writePinHigh(B2);
  } else {
    writePinLow(B2);
  }if (get_highest_layer(state) > 3) {
    writePinHigh(B3);
  } else {
    writePinLow(B3);
  }
  return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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

qk_tap_dance_action_t tap_dance_actions[] = {
  [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
  [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
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
  }
  return true;
}
