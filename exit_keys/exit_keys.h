#ifndef EXIT_KEYS_H
#define EXIT_KEYS_H

#include "quantum.h"

// +---------------------------+
// | EXIT KEY SYSTEM           |
// +---------------------------+
// This module manages visual animation of layer exit/toggle keys.
// Each layer can define up to two exit keys which are animated
// with a rainbow cycling effect to make them visually prominent.

// Data structure for exit key positions
typedef struct {
    uint8_t r1;     // Primary exit key row (255 = no key)
    uint8_t c1;     // Primary exit key column
    uint8_t r2;     // Secondary exit key row (255 = no key)
    uint8_t c2;     // Secondary exit key column
} exit_key_map_t;


#define EXIT_KEYS_NUM_LAYERS 8 // Number of layers in the keymap (must match layer enum in keymap.h)

// Animate layer exit keys with rainbow effect
// Parameters:
//   layer: Current layer index
//   hue: HSV hue value for current animation frame (0-255)
// Returns: true if any keys were animated, false if layer has no exit keys
bool animate_layer_exit_keys(uint8_t layer, uint8_t hue);

// Access to exit key configuration (defined in exit_key_config.c)
extern const exit_key_map_t exit_keys[EXIT_KEYS_NUM_LAYERS];

#endif // EXIT_KEYS_H
