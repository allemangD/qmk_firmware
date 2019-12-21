#pragma once
#include "allemangd.h"

#if defined(KEYMAP_SAFE_RANGE)
#    define PLACEHOLDER_SAFE_RANGE KEYMAP_SAFE_RANGE
#else
#    define PLACEHOLDER_SAFE_RANGE SAFE_RANGE
#endif

enum userspace_custom_keycodes {
    VRSN = PLACEHOLDER_SAFE_RANGE,  // Prints QMK Firmware and board info
    KC_QWERTY,                      // Sets default layer to QWERTY
    KC_COLEMAK,                     // Sets default layer to COLEMAK
    KC_DVORAK,                      // Sets default layer to DVORAK
    KC_WORKMAN,                     // Sets default layer to WORKMAN
    KC_DIABLO_CLEAR,                // Clears all Diablo Timers
    KC_MAKE,                        // Run keyboard's customized make command
    KC_RGB_T,                       // Toggles RGB Layer Indication mode
    RGB_IDL,                        // RGB Idling animations
    KC_CCCV,                        // Hold to copy, tap to paste
    EM_DIS,
    NEW_SAFE_RANGE                  // use "NEWPLACEHOLDER for keymap specific codes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define MOUSE MO(_MOUSE)
#define TG_MODS TG(_MODS)
#define TG_GAME TG(_GAMEPAD)
#define OS_LWR OSL(_LOWER)
#define OS_RSE OSL(_RAISE)

#define KC_SEC1 KC_SECRET_1
#define KC_SEC2 KC_SECRET_2
#define KC_SEC3 KC_SECRET_3
#define KC_SEC4 KC_SECRET_4
#define KC_SEC5 KC_SECRET_5

#define QWERTY KC_QWERTY
#define DVORAK KC_DVORAK
#define COLEMAK KC_COLEMAK
#define WORKMAN KC_WORKMAN

#define KC_RESET RESET
#define KC_RST KC_RESET

#ifdef SWAP_HANDS_ENABLE
#    define KC_C1R3 SH_T(KC_TAB)
#elif defined(DRASHNA_LP)
#    define KC_C1R3 TG(_GAMEPAD)
#else  // SWAP_HANDS_ENABLE
#    define KC_C1R3 KC_TAB
#endif  // SWAP_HANDS_ENABLE

#define BK_LWER LT(_LOWER, KC_BSPC)
#define ET_LWER LT(_LOWER, KC_ENTER)
#define DL_RAIS LT(_RAISE, KC_DEL)
#define SP_RAIS LT(_RAISE, KC_SPC)

#define AP_RGUI MT(MOD_RGUI, KC_APP)
#define AP_RCTL MT(MOD_RCTL, KC_APP)

#define IN_RALT MT(MOD_RALT, KC_INS)
#define DL_LALT MT(MOD_LALT, KC_DEL)

/* OSM keycodes, to keep things clean and easy to change */
#define KC_MLSF OSM(MOD_LSFT)
#define KC_MRSF OSM(MOD_RSFT)

#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_MEH OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define MG_NKRO MAGIC_TOGGLE_NKRO
