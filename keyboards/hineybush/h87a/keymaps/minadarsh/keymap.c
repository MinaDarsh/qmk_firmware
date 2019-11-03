/* Copyright 2018 Josh Hinnebusch

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
 * 
 * Modified by Mina Darsh/Hionimi to have Qwerty and Colemak-DH.
 * 
 */
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _COLEMAK,
    _FUNCTION,
    _ADJUST
};

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    KC_OWO,
    FUNCTION,
    ADJUST
};

#define FUNCTION MO(_FUNCTION)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*#### _QWERTY: QWERTY Layer.
    *    .-----------------------------------------------------------------------.
    *    |Esc|||||F1 |F2 |F3 |F4 |||F5 |F6 |F7 |F8 |||F9 |F10|F11|F12|PSc|SLk|Pau|
    *    |-----------------------------------------------------------|-----------|
    *    |~  |1  |2  |3  |4  |5  |6  |7  |8  |9  |0  |-  |=  |Backsp |Ins|Hom|PgU|
    *    |-----------------------------------------------------------|-----------|
    *    |Tab  |Q  |W  |E  |R  |T  |Y  |U  |I  |O  |P  |[  |]  |\    |Del|End|PgD|
    *    |-----------------------------------------------------------|-----------|
    *    |Caps  |A  |S  |D  |F  |G  |H  |J  |K  |L  |;  |'  |Return  |           |
    *    |-----------------------------------------------------------|-----------|
    *    |Shift   |Z  |X  |C  |V  |B  |N  |M  |,  |.  |/  |Shift     |   | Up|   |
    *    |-----------------------------------------------------------|-----------|
    *    |Ctrl |   |Alt  |      Space                |Fn   |   |Ctrl |Lft|Dwn|Rgt|
    *    *-----------------------------------------------------------------------*
    */
    [_QWERTY] = LAYOUT_tkl_ansi_wkl(
        KC_ESC,           KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SLCK, KC_PAUS,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,                   KC_UP,
        KC_LCTL,          KC_LALT,                            KC_SPC,                                      FUNCTION,         KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT),
    /*#### _COLEMAK: Colemak Layer.
    *    .-----------------------------------------------------------------------.
    *    |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |Q  |W  |F  |P  |B  |J  |L  |U  |Y  |;  |   |   |     |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |      |A  |R  |S  |T  |G  |K  |N  |E  |I  |O  |   |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |Z  |X  |C  |D  |V  |M  |H  |   |   |   |      |   |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |                           |     |   |     |   |   |   |
    *    *-----------------------------------------------------------------------*
    */
    [_COLEMAK] = LAYOUT_tkl_ansi_wkl(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   , KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, _______, _______, _______,          _______, _______, _______,
        _______, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   , KC_K   , KC_N   , KC_E   , KC_I   , KC_O   , _______,          _______,
        _______, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   , KC_M   , KC_H   , _______, _______, _______,                   _______,                   _______,
        _______,          _______,                            _______,                                     _______,          _______,          _______, _______, _______),
    /*#### _FUNCTION: Function Layer.
    *    .-----------------------------------------------------------------------.
    *    |   |||||   |   |   |   |||   |   |   |   |||   |   |   |   |   |   |MUT|
    *    .-----------------------------------------------------------|-----------|
    *    |   |   |   |   |   |   |   |   |   |   |   |   |   |       |PLY|NEX|VLU|
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |   |   |   |   |   |   |   |   |   |   |   |     |STP|PRV|VLD|
    *    |-----------------------------------------------------------|-----------|
    *    |      |   |   |   |   |   |   |   |   |   |   |   |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |   |   |   |   |   |   |   |   |   |   |      |   |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   | GUI |                           |     |   | ADJ |   |   |   |
    *    *-----------------------------------------------------------------------*
    */
    [_FUNCTION] = LAYOUT_tkl_ansi_wkl(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY, KC_MNXT, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MSTP, KC_MPRV, KC_VOLD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______,                   _______, 
        _______,          KC_LGUI,                            _______,                                     _______,           ADJUST,          _______, _______, _______),
    /*#### _ADJUST: Adjustment Layer.
    *    .-----------------------------------------------------------------------.
    *    |RST|||||   |   |   |TOG|||RMD|MOD|HUD|HUI|||SAD|SAI|VAD|VAI|   |   |   |
    *    .-----------------------------------------------------------|-----------|
    *    |   |   |   |   |   |   |   |   |   |   |   |   |   |       |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |QWR|   |   |   |   |   |   |   |OWO|   |   |   |     |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |      |   |   |   |   |   |   |   |   |   |   |   |        |           |
    *    |-----------------------------------------------------------|-----------|
    *    |        |   |   |COL|   |   |   |   |   |   |   |      |   |   |   |   |
    *    |-----------------------------------------------------------|-----------|
    *    |     |   |     |                           |     |   |     |   |   |   |
    *    *-----------------------------------------------------------------------*
    */
    [_ADJUST] = LAYOUT_tkl_ansi_wkl(
        RESET,            XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_RMOD,RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, QWERTY , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_OWO , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX,                   XXXXXXX, 
        XXXXXXX,          XXXXXXX,                            XXXXXXX,                                     _______,          _______,          XXXXXXX, XXXXXXX, XXXXXXX),
};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case KC_OWO:
      if (record->event.pressed) {
        SEND_STRING ("OWO\n");
        wait_ms(500);
        SEND_STRING ("What's this?\n");
      }
      return false;
      break;
  }
  return true;
}

void led_init_ports(void) {
  setPinOutput(D5);
  setPinOutput(E6);
}

void led_set_user(uint8_t usb_led) {

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    setPinOutput(D5);
    writePinLow(D5);
  } else {
    setPinInput(D5);
    writePinLow(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    setPinOutput(E6);
    writePinLow(E6);
  } else {
    setPinInput(E6);
    writePinLow(E6);
  }

}

