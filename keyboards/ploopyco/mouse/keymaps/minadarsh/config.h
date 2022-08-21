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

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 8
#define PLOOPY_DPI_OPTIONS \
    { 200, 1200, 1600, 2400, 3200 }
#define PLOOPY_DPI_DEFAULT 4
#define PLOOPY_DRAG_GESTURE_DPI 800   // speed for when gesture buttons are held
#define RECORD_SIZE 50                // how many samples will be used to determine movement speed
#define TRAVEL_DISTANCE 400           // how much movement is needed for gestures
#define DIR_COUNT_NUMBER 8            // how many slices has the numbers wheel gesture
#define DIR_COUNT_MEDIA 4             // how many slices has the media wheel gesture
#define CLICK_TIMEOUT 1000            // how many rounds to wait for being able to send keycode again (1 round = +/- 1ms)
#define NO_MOVE 150                   // distance within which tap keycode is sent
