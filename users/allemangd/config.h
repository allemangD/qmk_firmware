#pragma once

// Use custom magic number so that when switching branches, EEPROM always gets reset
#define EECONFIG_MAGIC_NUMBER (uint16_t)0x1337

#ifdef OLED_DRIVER_ENABLE
#   define OLED_FONT_H "users/allemangd/font.h"
#endif

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

#define IGNORE_MOD_TAP_INTERRUPT
#undef PERMISSIVE_HOLD

#define FORCE_NKRO

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif

#ifndef TAPPING_TERM
#   define TAPPING_TERM 160
#endif  // TAPPING_TERM

#define TAP_CODE_DELAY 16

#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_DELAY 50
#   define MOUSEKEY_INTERVAL 20

#   define MOUSEKEY_MAX_SPEED 5
#   define MOUSEKEY_TIME_TO_MAX 70

#   define MOUSEKEY_WHEEL_MAX_SPEED 4
#   define MOUSEKEY_WHEEL_TIME_TO_MAX 70
#endif

#ifdef UNICODE_ENABLE
#   define UNICODE_SELECTED_MODES UC_LNX, UC_WIN
#   define UNICODE_CYCLE_PERSIST true
#endif
