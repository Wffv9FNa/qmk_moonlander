#include "exit_keys.h"
#include "keymap.h"  // For layer enums

// +---------------------------+
// | EXIT KEY CONFIGURATION    |
// +---------------------------+
// This file defines which keys should be animated on each layer.
// These typically correspond to layer toggle/tap-toggle keys.
//
// Matrix coordinates are (row, column) - use 255 for "no key"
//
// Configuration format:
//   [LAYER_NAME] = {r1, c1, r2, c2}
//     r1, c1: Primary exit key position
//     r2, c2: Secondary exit key position (optional, use 255 if none)

const exit_key_map_t PROGMEM exit_keys[EXIT_KEYS_NUM_LAYERS] = {
    [_HM] = {255, 255, 255, 255},  // Home: no exit keys (base layer)
    [_MS] = {  1,   6, 255, 255},  // Mouse: TT(_MS) key at (1,6)
    [_GM] = {  6,   0, 255, 255},  // Gaming: TD_L4TG key at (6,0)
    [_KN] = {  7,   0, 255, 255},  // Kana: TG(_KN) key at (7,0)
    [_HV] = {  0,   6, 255, 255},  // HSV Display: TT(_HV) key at (0,6)
    [_FN] = {  2,   6, 255, 255},  // Function: TT(_FN) key at (2,6)
    [_NM] = {  4,   0,  10,   2},  // Numpad: TT(_NM) keys at (4,0) and (10,2)
    [_WM] = {  4,   4,  10,   6},  // WordMon: TT(_WM) keys at (4,4) and (10,6)
};
