/*
Copyright 2019 allemangd

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

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER allemangd
#define PRODUCT versor
#define DESCRIPTION A handwired ortholinear keyboard

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 14

#define MATRIX_ROW_PINS { B10, B11, B12, A14 }
#define MATRIX_COL_PINS { B7, B6, B5, B4, B3, B2, B1, B0, A4, A5, A6, A7, A8, A15 }

#define DEBOUNCE 6
