// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
     * │  Tab   │  Q  │  W  │  F  │  P  │  B  │  J  │  L  │  U  │  Y  │  '  │Bk Spc│
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
     * │Capslock │  A  │  R  │  S  │  T  │  G  │  K  │  N  │  E  │  I  │  O  ┋Enter│
     * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
     * │L_Shft┋  Z  │  X  │  C  │  D  │  V  │  ?  │  M  │  H  │  ,  │  .  ┋ R_Shft │
     * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
     * │L_Ctrl│L_GUI│ LAlt │    Space     ┋Space┋  Backspace   │  Fn  │R_GUI│ RAlt │
     * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
     */
    [0] = LAYOUT(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT, KC_BSPC,
        KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_K,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_SLSH, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,          KC_SPC,           KC_SPC,           KC_BSPC, MO(1),   KC_RGUI, KC_RALT
    ),
    /*
     * ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┐
     * │   `    │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │      │
     * ├────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐-----│
     * │   Esc   │Left │ Up  │Down │Right│PScrn│Pause│  \  │  =  │  [  │  ]  ┋     │
     * ├──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┤
     * │      ┋Prev │Vol -│Vol +│Next │Play │ScLck│Home │ End │Pg Up│Pg Dn┋        │
     * ├──────┼─────┼─────┴┬────┴─────┴───┬─┴───┬─┴─────┴─────┴┬────┴─┬───┴─┬──────┤
     * │      │     │      │              ┋     ┋              │      │     │      │
     * └──────┘-----└──────┴──────────────┴─────┴──────────────┴──────┘-----└──────┘
     */
    [1] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_ESC,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_PSCR, KC_PAUS, KC_BSLS, KC_EQL,  KC_LBRC, KC_RBRC, _______,
        _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY, KC_SCRL, KC_HOME, KC_END,  KC_PGUP, KC_PGDN, _______,
        _______, _______, _______,          _______,          _______,          KC_DEL,  _______, _______, _______
    )
};
