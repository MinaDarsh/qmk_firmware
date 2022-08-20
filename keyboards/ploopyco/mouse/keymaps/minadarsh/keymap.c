/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
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
#include <string.h>

// definitions

#ifndef PLOOPY_DRAGMEDIA_DPI
#define PLOOPY_DRAGMEDIA_DPI 800
#endif

#define RECORD_SIZE 50
#define TRAVEL_DISTANCE 400
#define DIR_COUNT_NUMBER 8
#define DIR_COUNT_MEDIA 4
#define CLICK_TIMEOUT 1000
#define NO_MOVE 300

// enumerators

enum extra_ploopy_keycodes {
  DRAG_MEDIA = PLOOPY_SAFE_RANGE,
  OMNI_WHEEL,
};

typedef enum {
  eModeNormal,
  eModeNumbers,
  eModeMedia,
} mouse_modus_enum;

mouse_modus_enum mouse_mode = eModeNormal;
uint32_t max_length = 0;

// functions

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_NO, KC_BTN1, KC_BTN3, KC_BTN2, DPI_CONFIG, DRAG_MEDIA, OMNI_WHEEL, RESET)
    // defaults: most left, left, middle, right, most right, lower side, upper side, underneath scoll
};

const uint8_t numbers_direction_map[DIR_COUNT_NUMBER] = {KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8};
const uint8_t media_direction_map[DIR_COUNT_MEDIA] = {KC_VOLU, KC_MNXT, KC_VOLD, KC_MPRV};

void keyboard_post_init_user(void) {
  #ifdef CONSOLE_ENABLE
    debug_enable=true;
  #endif
}

// convert x,y offset to a cardianal direction
// 1 = North, 2 = Northwest, 3 = West, etc.
int direction(int x, int y, int dir_count) {
    // calculate rotation offset
    float part_size = 2.0f / dir_count;
    float offset = 0.5f + (part_size / 2.0f);
    // get angle in radians assuming starting point is 0,0 (scale: -1*pi ~ 1*pi)
    float angle = atan2(y, x);
    // devide by pi for some more managable numbers (scale: -1 ~ 1)
    angle = angle / M_PI;
    // add an offset of 1 so we don't have negative results. (scale: 0 ~ 2)
    angle = angle + offset;
    while(angle < 0) angle = angle + 2;
    // scale to 8 equal parts and cast to int.
    int out = (int)(angle / part_size);
    if (out >= dir_count) out = 0;
    return out;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
  static int x_buff, y_buff, sample_count, loop_count, timeout = 0;
  static mouse_modus_enum old_mode = eModeNormal;

  if (mouse_mode != old_mode) {
    x_buff = 0;
    y_buff = 0;
    sample_count = 0;
    loop_count = 0;
    timeout = 0;
    old_mode = mouse_mode;
  }

  if (mouse_mode == eModeNormal) return mouse_report;

  if (timeout > 0) {
    timeout++;
    if (timeout >= CLICK_TIMEOUT) {
      timeout = 0;
      }
    } else {
      x_buff += mouse_report.x;
      y_buff += mouse_report.y;
      sample_count++;

      if (sample_count >= RECORD_SIZE) {
        loop_count++;

        uint32_t x_abs = abs(x_buff);
        uint32_t y_abs = abs(y_buff);
        uint32_t length = sqrt( (x_abs * x_abs) + (y_abs * y_abs) );
        if (length > max_length) max_length = length;

        // if (debug_enable) dprintf("x: %d y: %d\n", x_buff, y_buff);
        if (debug_enable) dprintf("len: %d\n", length);

        if (length > TRAVEL_DISTANCE) {
          uint8_t dir;
          if (mouse_mode == eModeNumbers) {
            dir = direction(x_buff, y_buff, DIR_COUNT_NUMBER);
            // if (debug_enable) dprintf("Number %d\n", numbers_direction_map[dir]);
            tap_code(numbers_direction_map[dir]);
          } else {
            dir = direction(x_buff, y_buff, DIR_COUNT_MEDIA);
            // if (debug_enable) dprintf("Media %d\n", media_direction_map[dir]);
            if ((dir == 0) || (dir == 2)) {
              int mult = 50 - loop_count;
              if (mult < 0) mult = 0;
              for (int i = 0; i < mult; i++) {
                tap_code(media_direction_map[dir]);
              }
            } else {
              tap_code(media_direction_map[dir]);
            }
          }
          x_buff = 0;
          y_buff = 0;
          loop_count = 0;
          timeout = 1;
        }

        sample_count = 0;
      }
    }

  mouse_report.x = 0;
  mouse_report.y = 0;
  return mouse_report;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if ( !(keycode == DRAG_MEDIA) && !(keycode == OMNI_WHEEL) ) return true;

  bool mode_changed = false;

  switch (mouse_mode) {
    case eModeMedia:
      if ((keycode == DRAG_MEDIA) && !record->event.pressed) {
        if (max_length < NO_MOVE) tap_code(KC_MPLY);
        mouse_mode = eModeNormal;
        mode_changed = true;
      }
      break;
    case eModeNumbers:
      if ((keycode == OMNI_WHEEL) && !record->event.pressed) {
        if (max_length < NO_MOVE) tap_code(KC_9);
        max_length = 0;
        mouse_mode = eModeNormal;
        mode_changed = true;
      }
      break;
    default:
      if (record->event.pressed) {
        if (keycode == OMNI_WHEEL) {
          mouse_mode = eModeNumbers;
          mode_changed = true;
        } else {
          mouse_mode = eModeMedia;
          mode_changed = true;
        }
      }
      break;
  }

  if (mode_changed) {
    if (mouse_mode != eModeNormal) {
      pointing_device_set_cpi(PLOOPY_DRAGMEDIA_DPI);
    } else {
      pointing_device_set_cpi(dpi_array[keyboard_config.dpi_config]);
    }

    // if (debug_enable) dprintf("Mode: %d\n", (int)mouse_mode);
  }
  return false;
}

void matrix_power_up(void) { pointing_device_task(); }
