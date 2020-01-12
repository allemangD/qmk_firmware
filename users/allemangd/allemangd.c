/*
Copyright 2017 Christopher Courtney <drashna@live.com> @drashna

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "allemangd.h"

#ifdef OLED_DRIVER_ENABLE
static uint32_t oled_timer;
#endif

__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return layer_state_set_keymap(state);
}


#ifdef OLED_DRIVER_ENABLE
__attribute__((weak)) void oled_task_keymap(void) {
}

void oled_task_user() {
    if (timer_elapsed32(oled_timer) > 30000) {
        oled_off();
        return;
    }

    oled_on();
    oled_task_keymap();
}
#endif

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    oled_timer = timer_read32();
#endif

    if (!process_record_keymap(keycode, record)) return false;

    return process_keycodes_user(keycode, record);
}
