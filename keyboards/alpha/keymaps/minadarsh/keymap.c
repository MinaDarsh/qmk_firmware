#include QMK_KEYBOARD_H

enum alpha_layers {
  _COLEMAK,
  _RAISE,
  _LOWER,
  _ADJUST,
};

// defined names for shorter keycode names in the keymap array
#define MC_CTLX MT(MOD_LCTL, KC_X)
#define MC_CTLZ MT(MOD_RCTL, KC_Z)
#define MC_GUIC MT(MOD_LGUI, KC_C)
#define MC_ALTD MT(MOD_LALT, KC_D)
#define MC_SFTA MT(MOD_LSFT, KC_A)
#define MC_SFTO MT(MOD_RSFT, KC_O)
#define MC_V_RS LT(_RAISE, KC_V)
#define MC_M_LW LT(_LOWER, KC_M)

enum {
  CQT = 0,
  CMN,
};

enum combo_events {
  COM_DOT,
  COM_COM,
  COM_ENT,
  COM_BSP,
  COM_SLH,
  COM_TAB,
  COM_ESC,
  COM_GRV,
  COM_TIL,
  COM_RST,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM dot_combo[] = {KC_H, MC_CTLZ, COMBO_END};
const uint16_t PROGMEM com_combo[] = {MC_M_LW, KC_H, COMBO_END};
const uint16_t PROGMEM ent_combo[] = {KC_I, MC_SFTO, KC_E, COMBO_END};
const uint16_t PROGMEM bsp_combo[] = {MC_SFTA, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM slh_combo[] = {MC_M_LW, MC_CTLZ, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_Q, KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM grv_combo[] = {KC_1, KC_2, COMBO_END};
const uint16_t PROGMEM til_combo[] = {KC_EXLM, KC_AT, COMBO_END};
const uint16_t PROGMEM rst_combo[] = {KC_Q, MC_CTLX, MC_SFTO, MC_CTLZ, COMBO_END};

combo_t key_combos[] = {
  [COM_DOT] = COMBO(dot_combo, KC_DOT),
  [COM_COM] = COMBO(com_combo, TD(CMN)),
  [COM_ENT] = COMBO(ent_combo, KC_ENT),
  [COM_BSP] = COMBO(bsp_combo, KC_BSPC),
  [COM_SLH] = COMBO(slh_combo, KC_SLSH),
  [COM_TAB] = COMBO(tab_combo, KC_TAB),
  [COM_ESC] = COMBO(esc_combo, KC_ESC),
  [COM_GRV] = COMBO(grv_combo, KC_GRV),
  [COM_TIL] = COMBO(til_combo, KC_TILD),
  [COM_RST] = COMBO(rst_combo, RESET)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Colemak-DHk
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │ '(;)│
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │A/LSF│  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │O/RSF│
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │X/Ctl│C/GUI│D/Alt│V/RSE│    Spc    │M/LWR│  H  │Z/CTL│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  main layer
 *
 *  quite a few Combos on this layer, namely:
 *    - Q and W form Tab
 *    - Q, W and F form Escape
 *    - A, R and S form Backspace
 *    - E, I and O form Enter
 *    - M and H form Comma
 *    - H and Z/CTL form Dot
 *    - M and Z/CTL form Forward Slash
 *    - Q, X, Z/CTL and O to enter bootloader mode
 *
 *  keys with a '/' are Mod-Tap keys, key before '/' is on tap, after is on hold
 *  keys with parenthesis are Tap-Dance keys (double-tap for second key)
 *  Comma is also a Tap-Dance key, you can Tap-Dance with Combos
 *  double tap M/GUI and H together to get Minus, this is shiftable
 */
  [_COLEMAK] = LAYOUT(
    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    TD(CQT),
    MC_SFTA, KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    MC_SFTO,
             MC_CTLX, MC_GUIC, MC_ALTD, MC_V_RS, KC_SPC,  MC_M_LW, KC_H,    MC_CTLZ
  ),
/*
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Left │ Up  │Down │Right│ Ins │ Del │  \  │  =  │  [  │  ]  │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │Home │ End │     │V/RSE│           │M/LWR│Pg Up│Pg Dn│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  numbers and unshifted characters
 *  
 *  one combo on this layer:
 *    - 1 and 2 form Grave
 */
  [_RAISE] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  KC_DEL,  KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC,
             KC_HOME, KC_END,  XXXXXXX, _______, _______, _______, KC_PGUP, KC_PGDN
  ),
/*
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │  !  │  @  │  #  │  $  │  %  │  ^  │  &  │  *  │  (  │  )  │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │Left │ Up  │Down │Right│ Ins │ Del │  |  │  +  │  {  │  }  │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │Home │ End │     │V/RSE│           │M/LWR│Pg Up│Pg Dn│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  shifted characters and other outputs
 *  
 *  one combo on this layer:
 *    - ! and @ form Tilde
 */
  [_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS,  KC_DEL,  KC_PIPE, KC_PLUS, KC_LCBR, KC_RCBR,
             KC_HOME, KC_END,  XXXXXXX, _______, _______, _______, KC_PGUP, KC_PGDN
  ),
/*
 * ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
 * │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │PScrn│ScLck│Pause│ N/A │
 * ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
 * │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ N/A │ N/A │ N/A │ N/A │
 * └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬──┴──┬──┘
 *    │Prev │Next │Play │V/RSE│           │M/LWR│Vol -│Vol +│
 *    └─────┴─────┴─────┴─────┴───────────┴─────┴─────┴─────┘
 *  function and media keys
 */
  [_ADJUST] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PSCR, KC_SLCK, KC_PAUS, XXXXXXX,
    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
             KC_MPRV, KC_MNXT, KC_MPLY, _______, _______, _______, KC_VOLD, KC_VOLU
  )
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [CQT] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_SCLN),
  [CMN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_MINS)
};

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MC_SFTA:
        case MC_SFTO:
            return 150;
        default:
            return TAPPING_TERM;
    }
}
#endif

#ifdef PERMISSIVE_HOLD_PER_KEY
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
#endif

#ifdef HOLD_ON_OTHER_KEY_PRESS_PER_KEY
bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_SFTA:
      return true;
    case MC_SFTO:
      return true;
    default:
      return false;
    }
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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
