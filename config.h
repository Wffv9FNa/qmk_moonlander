/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #pragma once                                       // Compiler include guard (header only included once)

 #define ORYX_CONFIGURATOR                          // Enable Oryx web configurator support
 #define USB_SUSPEND_WAKEUP_DELAY 0                 // Delay (ms) after USB suspend before wakeup (0 = none)
 #define CAPS_LOCK_STATUS                           // Track and expose Caps Lock state to firmware
 #define SERIAL_NUMBER "v9D0K/VqyORY"               // Unique keyboard serial number identifier
 #define LAYER_STATE_8BIT                           // Limit layer state tracking to 8 bits (saves memory)
 #define MOONLANDER_USER_LEDS                       // Take control of indicator LEDs from default firmware

 #define RGB_MATRIX_STARTUP_SPD 60                  // Default RGB matrix startup animation speed
 #undef RGB_MATRIX_MAXIMUM_BRIGHTNESS               // Remove default maximum brightness definition
 #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255          // Set max RGB brightness (0-255 scale)
 #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Set default RGB brightness to maximum

 #ifdef AUDIO_ENABLE
 # define STARTUP_SONG SONG(CLOSE_ENCOUNTERS_5_NOTE) // Play "Close Encounters" theme at startup
 #endif

 #define TAPPING_TERM 200                           // Time (ms) to distinguish tap vs hold
 #define TAP_TOGGLE_LAYER_TERM 200                  // Time (ms) window for tap-toggling layers
 #define TAPPING_TOGGLE 2                           // Number of taps required to toggle tap-toggle layers

