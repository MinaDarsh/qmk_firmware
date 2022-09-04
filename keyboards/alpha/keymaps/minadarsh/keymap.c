#include QMK_KEYBOARD_H

enum alpha_layers {
  _COLEMAK,
  _SYMBOL1,
  _SYMBOL2,
  _SYMBOL3,
  _SETTNGS
};

// defined names for shorter keycode names in the keymap array
#define MC_CTLX MT(MOD_LCTL, KC_X)
#define MC_GUIC MT(MOD_LGUI, KC_C)
#define MC_ALTD MT(MOD_LALT, KC_D)
#define MC_SFTA MT(MOD_LSFT, KC_A)
#define MC_SFTO MT(MOD_RSFT, KC_O)

enum {
  CQT = 0,
  CMN,
  LYR
};

enum combo_events {
  COM_DOT,
	COM_COM,
  COM_ENT,
  COM_BSP,
  COM_SLH,
  COM_LYR,
  COM_TAB,
  COM_ESC,
  COM_GRV,
  COM_TIL,
  COM_RST,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM dot_combo[] = {KC_H, KC_Z, COMBO_END};
const uint16_t PROGMEM com_combo[] = {KC_M, KC_H, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_I, MC_SFTO, KC_E, COMBO_END};
const uint16_t PROGMEM bsp_combo[] = {MC_SFTA, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM slh_combo[] = {KC_M, KC_Z, COMBO_END};
const uint16_t PROGMEM lyr_combo[] = {KC_M, KC_H, KC_Z, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM til_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM rst_combo[] = {KC_Q, MC_CTLX, MC_SFTO, KC_Z, COMBO_END};

combo_t key_combos[] = {
  [COM_DOT] = COMBO(dot_combo, KC_DOT),
	[COM_COM] = COMBO(com_combo, TD(CMN)),
  [COM_ENT] = COMBO(ent_combo, KC_ENT),
  [COM_BSP] = COMBO(bsp_combo, KC_BSPC),
  [COM_SLH] = COMBO(slh_combo, KC_SLSH),
  [COM_LYR] = COMBO(lyr_combo, TD(LYR)),
  [COM_TAB] = COMBO(tab_combo, KC_TAB),
  [COM_ESC] = COMBO(esc_combo, KC_ESC),
  [COM_GRV] = COMBO(grv_combo, KC_GRV),
  [COM_TIL] = COMBO(til_combo, KC_TILD),
  [COM_RST] = COMBO(rst_combo, RESET)
};

bool td_was_held = false;
int old_state = 0;
static uint16_t timer;
static bool is_idle = true;

void layers_finished(qk_tap_dance_state_t *state, void *user_data);
void layers_reset(qk_tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak-DHk
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │ '(;)│
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │X/Ctl│C/Alt│  D  │  V  │    Spc    │M/GUI│  H  │  Z  │
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  main layer
 *
 *  quite a few Combos on this layer, namely:
 *    - Q and W form Tab
 *    - Q, W and F form Escape
 *    - A, R and S form Backspace
 *    - E, I and O form Enter
 *    - M/GUI and H form Comma
 *    - H and Z form Dot
 *    - M/GUI and Z form Forward Slash
 *    - M/GUI, H and Z form the Special Layer Key
 *    - Q, X, Z and O to enter bootloader mode
 *
 *  keys with a '/' are Mod-Tap keys, key before '/' is on tap, after is on hold
 *  keys with parenthesis are Tap-Dance keys (double-tap for second key)
 *  Comma is also a Tap-Dance key, you can Tap-Dance with Combos
 *  double tap M/GUI and H together to get Minus, this is shiftable
 */
	[_COLEMAK] = LAYOUT(
		KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT),
		MC_SFTA, KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    MC_SFTO,
	           MC_CTLX, MC_GUIC, MC_ALTD, KC_V,    KC_SPC,  KC_M,    KC_H,    KC_Z
  ),
/*
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Left │ Up  │Down │Right│ Ins │ Del │  \  │  =  │  [  │  ]  │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │Home │ End │Pg Up│Pg Dn│           │ keep these free!│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  numbers and unshifted characters
 */
	[_SYMBOL1] = LAYOUT(
		KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  KC_DEL,  KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC,
             KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______, _______, _______
  ),
/*
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Left │ Up  │Down │Right│ Ins │ Del │  |  │  +  │  {  │  }  │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │Home │ End │Pg Up│Pg Dn│           │ keep these free!│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  shifted characters and other outputs
 */
	[_SYMBOL2] = LAYOUT(
		KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  KC_DEL,  KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR,
             KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______, _______, _______, _______
  ),
/*
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │PScrn│ScLck│Pause│ N/A │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ N/A │ N/A │ N/A │ N/A │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │Prev │Vol -│Vol +│Next │   Play    │ keep these free!│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  function and media keys
 */
	[_SYMBOL3] = LAYOUT(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, _______, _______, _______
  ),
/*
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │RESET│ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │ N/A │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │ N/A │ N/A │ N/A │ N/A │    N/A    │ keep these free!│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  keyboard settings
 */
	[_SETTNGS] = LAYOUT(
		RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______
  )
};

void matrix_scan_user(void) {
  if (!td_was_held) {
    if (!is_idle) {
      if (timer_elapsed(timer) >= (uint16_t) LAYER_IDLE_TIMEOUT * 1000) {
        is_idle = true;
        if (!layer_state_is(_COLEMAK)) {
          layer_move(_COLEMAK);
          old_state = 0;
        }
      }
    }
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(LYR):
            return 250;
        case TD(CQT):
            return 175;
        case TD(CMN):
            return 175;
        default:
            return TAPPING_TERM;
    }
}

void layers_per_tap(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      layer_move(_SYMBOL1);
      break;
    case 2:
      layer_move(_SYMBOL2);
      break;
    case 3:
      layer_move(_SYMBOL3);
      break;
    case 4:
      layer_move(_SETTNGS);
      break;
    default:
      layer_move(_COLEMAK);
      old_state = 0;
  }
}

void layers_finished(qk_tap_dance_state_t *state, void *user_data) {
  if (state->pressed) {
    td_was_held = true;
  } else if (state->count == old_state) {
    layer_move(_COLEMAK);
    old_state = 0;
  } else {
    old_state = state->count;
  }
}

void layers_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (td_was_held == true) {
    layer_move(_COLEMAK);
    old_state = 0;
    td_was_held = false;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS),
  [LYR] = ACTION_TAP_DANCE_FN_ADVANCED(layers_per_tap, layers_finished, layers_reset)
};

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MC_SFTA:
      return true;
    case MC_SFTO:
      return true;
    default:
      return false;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  timer = timer_read();
  if (is_idle) {
    is_idle = false;
  }
  if (keycode != KC_SPC) return true;

  if ( !((get_mods() & MOD_BIT(KC_LSFT)) == MOD_BIT(KC_LSFT)) && !((get_mods() & MOD_BIT(KC_LCTL)) == MOD_BIT(KC_LCTL)) ) {
    unregister_code(KC_SLSH);
    return true;
  }
  if (record->event.pressed) {
    register_code(KC_SLSH);
  } else {
    unregister_code(KC_SLSH);
  }
  return false;
}
