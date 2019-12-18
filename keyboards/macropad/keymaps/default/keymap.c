/* Copyright 2019 allemangd
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// info on keycodes here:
//
// https://beta.docs.qmk.fm/features/keycodes_basic
// https://beta.docs.qmk.fm/features/feature_advanced_keycodes#working-with-layers
// https://beta.docs.qmk.fm/features/feature_macros

[_BASE] =

LAYOUT(
    MO(_FN),   KC_F1,   KC_F2,   KC_F3,   KC_F4,
      KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,
     KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_F14

),

[_FN] =
LAYOUT(
    _______, _______, _______, _______,   RESET,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______
)
};

#define _O SS_TAP(X_F23)
#define _X SS_TAP(X_F24)
#define SEQ SS_TAP(X_F22)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // also send F24 so AHK knows it's from this board.

    if (record->event.pressed) {
        SEND_STRING(SS_DOWN(X_F24));
    } else {
        SEND_STRING(SS_UP(X_F24));
    }

    return true;
}
