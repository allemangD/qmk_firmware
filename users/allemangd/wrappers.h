#pragma once

#include "allemangd.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif


#define LAYOUT_wrapper(...)                  LAYOUT(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

//@formatter:off
#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH

#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        ________________NUMBER_LEFT________________
#define _________________LOWER_L2__________________        ________________NUMBER_RIGHT_______________
#define _________________LOWER_L3__________________        ___________________BLANK___________________

#define _________________LOWER_R1__________________        _______, KC_SLSH,  KC_EQL, KC_BSLS, KC_QUES
#define _________________LOWER_R2__________________        _______, KC_LBRC, KC_LPRN, KC_RPRN, KC_RBRC
#define _________________LOWER_R3__________________        ___________________BLANK___________________


#define _________________RAISE_L1__________________        KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC
#define _________________RAISE_L2__________________        KC_PLUS, KC_MINS, KC_SLSH, KC_ASTR, KC_CIRC
#define _________________RAISE_L3__________________        KC_SCLN, _______, _______, KC_AMPR, KC_PIPE

#define _________________RAISE_R1__________________        _______, _______,   KC_UP, _______, _______
#define _________________RAISE_R2__________________        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______
#define _________________RAISE_R3__________________        _______, _______, _______, _______, _______


#define _________________ADJUST_L1_________________        _________________FUNC_LEFT_________________
#define _________________ADJUST_L2_________________        _________________FUNC_RIGHT________________
#define _________________ADJUST_L3_________________         KC_F11,  KC_F12, _______, _______, _______

#define _________________ADJUST_R1_________________        KC_MUTE, _______, KC_PGUP, _______, _______
#define _________________ADJUST_R2_________________        KC_VOLU, KC_HOME, KC_PGDN,  KC_END, _______
#define _________________ADJUST_R3_________________        KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT, _______


#define __________________MOUSE_L1_________________        _______, _______, KC_MS_U, _______, _______
#define __________________MOUSE_L2_________________        _______, KC_MS_L, KC_MS_D, KC_MS_R, _______
#define __________________MOUSE_L3_________________        _______, _______, _______, _______, _______

#define __________________MOUSE_R1_________________        KC_BTN3, KC_WH_L, KC_WH_U, KC_WH_R, _______
#define __________________MOUSE_R2_________________        KC_BTN5, KC_BTN1, KC_WH_D, KC_BTN2, _______
#define __________________MOUSE_R3_________________        KC_BTN4, _______, _______, _______, _______
//@formatter:on
