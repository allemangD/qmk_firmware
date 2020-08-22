/* Copyright 2020 David Allemang
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

#include "pseudosplit.h"
#include "allemangd.h"

//@formatter:off
#define LAYOUT_keymap(\
    K01, K02, K03, K04, K05,     K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15,     K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25,     K26, K27, K28, K29, K2A,  \
    K31, K32, K33, K34, K35,     K36, K37, K38, K39, K3A  \
) \
  LAYOUT_wrapper( \
    _______,     K01,     K02,     K03,     K04,     K05,           K06,     K07,     K08,     K09,     K0A, _______, \
     KC_TAB,     K11,     K12,     K13,     K14,     K15,           K16,     K17,     K18,     K19,     K1A, KC_BSPC, \
     KC_ESC,     K21,     K22,     K23,     K24,     K25,           K26,     K27,     K28,     K29,     K2A, KC_MINS, \
    KC_LSFT, LGUI_T(K31), K32,     K33,     K34,     K35,           K36,     K37,     K38, K39, RGUI_T(K3A), KC_RSFT, \
    _______,          KC_LGUI, KC_LCTL, ET_LWER, DL_LALT,       IN_RALT, SP_RAIS, AP_RCTL, KC_RGUI,          _______  \
)

#define LAYOUT_keymap_wrapper(...) LAYOUT_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_LOWER] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _________________LOWER_L1__________________, _________________LOWER_R1__________________, _______,
        _______, _________________LOWER_L2__________________, _________________LOWER_R2__________________,   MOUSE,
        _______, _________________LOWER_L3__________________, _________________LOWER_R3__________________, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______
    ),

    [_RAISE] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
         KC_GRV, _________________RAISE_L1__________________, _________________RAISE_R1__________________, _______,
        _______, _________________RAISE_L2__________________, _________________RAISE_R2__________________, _______,
        _______, _________________RAISE_L3__________________, _________________RAISE_R3__________________, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_MAKE, _________________ADJUST_L1_________________, _________________ADJUST_R1_________________,   RESET,
        KC_VRSN, _________________ADJUST_L2_________________, _________________ADJUST_R2_________________, KC_PSCR,
        MG_NKRO, _________________ADJUST_L3_________________, _________________ADJUST_R3_________________,  UC_MOD,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______
    ),

    [_MOUSE] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, __________________MOUSE_L1_________________, __________________MOUSE_R1_________________, _______,
        _______, __________________MOUSE_L2_________________, __________________MOUSE_R2_________________, _______,
        _______, __________________MOUSE_L3_________________, __________________MOUSE_R3_________________, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______,          _______
    ),

    [_DVORAK] = LAYOUT_keymap_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
        _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
        _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
    ),

    [_QWERTY] = LAYOUT_keymap_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
        _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
        _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
    ),

    [_COLEMAK] = LAYOUT_keymap_wrapper(
        ________________NUMBER_LEFT________________, ________________NUMBER_RIGHT_______________,
        _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
        _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
        _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
    ),
};
//@formatter:on