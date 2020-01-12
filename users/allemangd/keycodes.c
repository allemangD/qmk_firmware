#include "keycodes.h"

#define PRESS (record->event.pressed)
#define RELEASE (!record->event.pressed)

bool process_keycodes_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_DVORAK ... KC_GAMEPAD:
        return PRESS && switch_layout(keycode);
    case KC_MAKE:
        return PRESS && make();
    case KC_VRSN:
        return PRESS && vrsn();
    case KC_CCCV:
        return copypaste(record);
    default:
        return true;
    }
}


bool switch_layout(uint16_t keycode) {
    set_single_persistent_default_layer(keycode - KC_DVORAK);
    return true;
}

bool vrsn() {
    SEND_STRING(QMK_KEYBOARD
    ""
    QMK_KEYMAP
    " ("
    QMK_VERSION
    " @ "
    QMK_BUILDDATE
    ")");
    return true;
}

bool make() {
    SEND_STRING("make "
    QMK_KEYBOARD
    ":"
    QMK_KEYMAP
#if defined(BOOTLOADER_DFU) || defined(BOOTLOADER_LUFA_DFU) || defined(BOOTLOADER_QMK_DFU)
    ":dfu"
#elifdef BOOTLOADER_HALFKAY
    ":teensy"
#elif BOOTLOADER_CATERINA
    ":avrdude"
#else
    ":dfu-util"
#endif
    SS_TAP(X_ENTER));
    return false;
}

bool copypaste(keyrecord_t *record) {
    if (!record->event.pressed) {
        if (record->event.time > TAPPING_TERM) {
            SEND_STRING(SS_LCTL("c"));
        } else {
            SEND_STRING(SS_LCTL("v"));
        }
    }
    return false;
}
