#include "allemangd.h"

uint16_t copy_paste_timer;

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

// Defines actions for my global custom keycodes. Defined in allemangd.h file
// Then runs the _keymap's record handier if not processed here
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_QWERTY ... KC_WORKMAN:
        if (record->event.pressed) {
            uint8_t mods = mod_config(get_mods() | get_oneshot_mods());
            if (!mods) {
                set_single_persistent_default_layer(keycode - KC_QWERTY);
            } else if (mods & MOD_MASK_SHIFT) {
                set_single_persistent_default_layer(keycode - KC_QWERTY + 4);
            } else if (mods & MOD_MASK_CTRL) {
                set_single_persistent_default_layer(keycode - KC_QWERTY + 8);
            }
        }
        break;

    case KC_MAKE:
        if (!record->event.pressed) {
            SEND_STRING("make "
            QMK_KEYBOARD
            ":"
            QMK_KEYMAP
#if (defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU))
            ":dfu"
#elif defined(BOOTLOADER_HALFKAY)
            ":teensy"
#elif defined(BOOTLOADER_CATERINA)
            ":avrdude"
#else
            ":dfu-util"
#endif
            SS_TAP(X_ENTER));
        }
        return false;
        break;

    case KC_VRSN:  // Prints firmware version
        if (record->event.pressed) {
            send_string_with_delay_P(PSTR(QMK_KEYBOARD
            "/"
            QMK_KEYMAP
            " @ "
            QMK_VERSION
            ", Built on: "
            QMK_BUILDDATE), TAP_CODE_DELAY);
        }
        break;

//    case EM_DIS:
//# ifdef UNICODE_ENABLE
//    if (record->event.pressed) {
//        send_unicode_hex_string("0028 30CE 0CA0 75CA 0CA0 0029 30CE 5F61 253B 2501 253B");
//    }
//#endif
//        break;

    case KC_CCCV:  // One key copy/paste
        if (record->event.pressed) {
            copy_paste_timer = timer_read();
        } else {
            if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold, copy
                register_code(KC_LCTL);
                tap_code(KC_C);
                unregister_code(KC_LCTL);
            } else {  // Tap, paste
                register_code(KC_LCTL);
                tap_code(KC_V);
                unregister_code(KC_LCTL);
            }
        }
        break;
    }
    return process_record_keymap(keycode, record);
}
