#pragma once

// Use custom magic number so that when switching branches, EEPROM always gets reset
#define EECONFIG_MAGIC_NUMBER (uint16_t)0x1337

#ifdef OLED_DRIVER_ENABLE
    #define OLED_FONT_H "users/allemangd/font.h"
//    #define OLED_FONT_WIDTH 5
//    #define OLED_FONT_HEIGHT 7
#endif // OLED_DRIVER_ENABLE

/* Set Polling rate to 1000Hz */
#define USB_POLLING_INTERVAL_MS 1

#ifndef ONESHOT_TAP_TOGGLE
#    define ONESHOT_TAP_TOGGLE 2
#endif  // !ONESHOT_TAP_TOGGLE

#ifndef ONESHOT_TIMEOUT
#    define ONESHOT_TIMEOUT 3000
#endif  // !ONESHOT_TIMEOUT

#ifndef QMK_KEYS_PER_SCAN
#    define QMK_KEYS_PER_SCAN 4
#endif  // !QMK_KEYS_PER_SCAN

// this makes it possible to do rolling combos (zx) with keys that
// convert to other keys on hold (z becomes ctrl when you hold it,
// and when this option isn't enabled, z rapidly followed by x
// actually sends Ctrl-x. That's bad.)
#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD
//#define TAPPING_FORCE_HOLD
//#define RETRO_TAPPING

#define FORCE_NKRO

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif

#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif  // TAPPING_TERM
#if defined(KEYBOARD_ergodox_ez)
#    define TAPPING_TERM 185
#elif defined(KEYBOARD_crkbd)
#    define TAPPING_TERM 200
#else
#    define TAPPING_TERM 175
#endif

#define TAP_CODE_DELAY 5

/* Disable unused and unneeded features to reduce on firmware size */
#ifdef LOCKING_SUPPORT_ENABLE
#    undef LOCKING_SUPPORT_ENABLE
#endif
#ifdef LOCKING_RESYNC_ENABLE
#    undef LOCKING_RESYNC_ENABLE
#endif
