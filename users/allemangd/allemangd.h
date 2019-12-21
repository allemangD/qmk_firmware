#pragma once

#include QMK_KEYBOARD_H

#include "version.h"
#include "eeprom.h"
#include "wrappers.h"
#include "keycodes.h"

/* Define layer names */
enum userspace_layers {
    _DVORAK = 0,
    _NUMLOCK = 0,
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};
