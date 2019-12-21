#include "versor.h"
#include "allemangd.h"

/*
 * The `LAYOUT_crkbd_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

#define LAYOUT_base(\
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
) \
  LAYOUT_wrapper( \
     KC_TAB,     K01,     K02,     K03,     K04,     K05, _______, KC_PSCR,     K06,     K07,     K08,     K09,     K0A, KC_BSPC, \
     KC_ESC,     K11,     K12,     K13,     K14,     K15, _______, _______,     K16,     K17,     K18,     K19,     K1A, KC_MINS, \
    KC_LSFT, LGUI_T(K21), K22,     K23,     K24,     K25, _______, _______,     K26,     K27,     K28, K29, LGUI_T(K2A), KC_RSFT, \
    KC_LCTL, KC_LALT, KC_LGUI, KC_LCTL,       ET_LWER,     KC_DEL,  KC_INS,      SP_RAIS,      KC_APP, KC_RGUI, KC_RALT, KC_RCTL  \
)

#define LAYOUT_base_wrapper(...) LAYOUT_base(__VA_ARGS__)

//@formatter:off
const uint16_t PROGMEM
keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LOWER] =
LAYOUT_wrapper(
    _______, _________________LOWER_L1__________________, _______, _______, _________________LOWER_R1__________________, _______,
    _______, _________________LOWER_L2__________________, _______, _______, _________________LOWER_R2__________________,   MOUSE,
    _______, _________________LOWER_L3__________________, _______, _______, _________________LOWER_R3__________________, _______,
    _______, _______, _______, _______,      _______,     _______, _______,     _______,      _______, _______, _______, _______
),

[_RAISE] =
LAYOUT_wrapper(
     KC_GRV, _________________RAISE_L1__________________, _______, _______, _________________RAISE_R1__________________, _______,
      MOUSE, _________________RAISE_L2__________________, _______, _______, _________________RAISE_R2__________________, _______,
    _______, _________________RAISE_L3__________________, _______, _______, _________________RAISE_R3__________________, _______,
    _______, _______, _______, _______,      _______,     _______, _______,     _______,      _______, _______, _______, _______
),

[_ADJUST] =
LAYOUT_wrapper(
    KC_MAKE, _________________ADJUST_L1_________________, _______, _______, _________________ADJUST_R1_________________,   RESET,
    KC_VRSN, _________________ADJUST_L2_________________, _______, _______, _________________ADJUST_R2_________________, _______,
    MG_NKRO, _________________ADJUST_L3_________________, _______, _______, _________________ADJUST_R3_________________, _______,
    _______, _______, _______, _______,      _______,     _______, _______,     _______,      _______, _______, _______, _______
),

[_MOUSE] =
LAYOUT_wrapper(
    _______, __________________MOUSE_L1_________________, _______, _______, __________________MOUSE_R1_________________, _______,
    _______, __________________MOUSE_L2_________________, _______, _______, __________________MOUSE_R2_________________, _______,
    _______, __________________MOUSE_L3_________________, _______, _______, __________________MOUSE_R3_________________, _______,
    _______, _______, _______, _______,      _______,     _______, _______,     _______,      _______, _______, _______, _______
),

//region compatibility
[_QWERTY] = LAYOUT_base_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
),

[_COLEMAK] = LAYOUT_base_wrapper(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
),

[_DVORAK] = LAYOUT_base_wrapper(
    _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
    _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
    _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
),
//endregion
};
//formatter:on

uint16_t get_tapping_term(uint16_t keycode) {
    switch (keycode) {
    case ALT_T(KC_A):
        return TAPPING_TERM + 100;
    default:
        return TAPPING_TERM;
    }
}
