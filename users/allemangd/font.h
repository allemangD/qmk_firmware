#pragma once

#ifdef __AVR__
#    include <avr/io.h>
#    include <avr/pgmspace.h>
#elif defined(ESP8266)
#    include <pgmspace.h>
#else
#    define PROGMEM
#endif

// Corne 8x6 font with QMK Firmware Logo
// Online editor: https://helixfonteditor.netlify.com/

// clang-format off
const unsigned char font[] PROGMEM = {
#include "font/vertical.h"
};
