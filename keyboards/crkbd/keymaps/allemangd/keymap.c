#include "allemangd.h"
#include "split_common/split_util.h"

extern uint8_t is_master;

//@formatter:off
#define LAYOUT_keymap(\
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
) \
LAYOUT_wrapper( \
   KC_TAB,     K01,     K02,     K03,     K04,     K05,                        K06,     K07,     K08,     K09,     K0A, KC_BSPC, \
   KC_ESC,     K11,     K12,     K13,     K14,     K15,                        K16,     K17,     K18,     K19,     K1A, KC_MINS, \
  KC_LSFT, LGUI_T(K21), K22,     K23,     K24,     K25,                        K26,     K27,     K28, K29, RGUI_T(K2A), KC_RSFT, \
                                   KC_LCTL, ET_LWER, DL_LALT,        IN_RALT, SP_RAIS, AP_RCTL                                   \
)

#define LAYOUT_keymap_wrapper(...)       LAYOUT_keymap(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_LOWER] = LAYOUT_wrapper(
    _______, _________________LOWER_L1__________________,                    _________________LOWER_R1__________________, _______,
    _______, _________________LOWER_L2__________________,                    _________________LOWER_R2__________________,   MOUSE,
    _______, _________________LOWER_L3__________________,                    _________________LOWER_R3__________________, _______,
                                     _______, _______, _______,        _______, _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
     KC_GRV, _________________RAISE_L1__________________,                    _________________RAISE_R1__________________, _______,
    _______, _________________RAISE_L2__________________,                    _________________RAISE_R2__________________, _______,
    _______, _________________RAISE_L3__________________,                    _________________RAISE_R3__________________, _______,
                                     _______, _______, _______,        _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    KC_MAKE, _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,   RESET,
    KC_VRSN, _________________ADJUST_L2_________________,                    _________________ADJUST_R2_________________, KC_PSCR,
    MG_NKRO, _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________,  UC_MOD,
                                     _______, _______, _______,        _______, _______, _______
  ),

  [_MOUSE] = LAYOUT_wrapper(
    _______, __________________MOUSE_L1_________________,                    __________________MOUSE_R1_________________, _______,
    _______, __________________MOUSE_L2_________________,                    __________________MOUSE_R2_________________, _______,
    _______, __________________MOUSE_L3_________________,                    __________________MOUSE_R3_________________, _______,
                                     _______, _______, _______,        _______, _______, _______
  ),

  [_DVORAK] = LAYOUT_keymap_wrapper(
    _________________DVORAK_L1_________________, _________________DVORAK_R1_________________,
    _________________DVORAK_L2_________________, _________________DVORAK_R2_________________,
    _________________DVORAK_L3_________________, _________________DVORAK_R3_________________
  ),

  [_QWERTY] = LAYOUT_keymap_wrapper(
    _________________QWERTY_L1_________________, _________________QWERTY_R1_________________,
    _________________QWERTY_L2_________________, _________________QWERTY_R2_________________,
    _________________QWERTY_L3_________________, _________________QWERTY_R3_________________
  ),

  [_COLEMAK] = LAYOUT_keymap_wrapper(
    _________________COLEMAK_L1________________, _________________COLEMAK_R1________________,
    _________________COLEMAK_L2________________, _________________COLEMAK_R2________________,
    _________________COLEMAK_L3________________, _________________COLEMAK_R3________________
  ),
};
//formatter:on

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Lyout"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(" QRTY"), false);
            break;
        case _COLEMAK:
            oled_write_P(PSTR(" COLE"), false);
            break;
        case _DVORAK:
            oled_write_P(PSTR(" DVRK"), false);
            break;
    }
}

void render_layer_state(void) {
    oled_write_P(PSTR("LAYER"), false);
    oled_write_P(PSTR("Lower"), layer_state_is(_LOWER));
    oled_write_P(PSTR("Raise"), layer_state_is(_RAISE));
    oled_write_P(PSTR("Mouse"), layer_state_is(_MOUSE));
}

void render_keylock_status(uint8_t led_usb_state) {
    oled_write_P(PSTR("Lock:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_usb_state & (1 << USB_LED_NUM_LOCK));
    oled_write_P(PSTR("C"), led_usb_state & (1 << USB_LED_CAPS_LOCK));
    oled_write_ln_P(PSTR("S"), led_usb_state & (1 << USB_LED_SCROLL_LOCK));
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("Mods:"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
}

void render_bootmagic_status(void) {
    oled_write_P(PSTR(" NKRO"), keymap_config.nkro);
}

void render_unicode_mode(void) {
#ifdef UNICODE_ENABLE
    oled_write_P(PSTR("Unic:"), false);
    oled_write_P(PSTR("  LNX"), get_unicode_input_mode() == UC_LNX);
    oled_write_P(PSTR("  WIN"), get_unicode_input_mode() == UC_WIN);
#endif
}

void render_logo(void) {
    for (char r = 0; r < 3; r++)
    for (char c = 0; c < 25; c++) {
        oled_write_char(0x80 + 0x20 * r + c, false);
    }
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    render_layer_state();
    render_mod_status(get_mods() | get_oneshot_mods());
    render_keylock_status(host_keyboard_leds());
    render_bootmagic_status();
#ifdef UNICODE_ENABLE
    render_unicode_mode();
#endif
}

void render_status_secondary(void) {
    /* Show Corne Logo  */
    render_logo();
}

void oled_task_keymap(void) {
    if (isLeftHand) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_status_secondary();
    }
}
#endif

bool process_record_keymap(uint16_t keycode, keyrecord_t* record) {
    if(keycode == RESET && !is_master) {
        return false;
    }
    return true;
}