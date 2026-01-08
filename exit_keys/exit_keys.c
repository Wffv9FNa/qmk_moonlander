#include "exit_keys.h"

// +---------------------------+
// | EXIT KEY ANIMATION        |
// +---------------------------+
// This file contains the animation logic for highlighting layer exit keys
// with rainbow cycling effects. The configuration of which keys to animate
// is defined separately in exit_key_config.c.

// Access to QMK's LED configuration structure
extern led_config_t g_led_config;

// --- Private Helper Functions ---

// Animate a single exit key with rainbow HSV cycling
// Parameters:
//   row: Matrix row (255 = no key at this position)
//   col: Matrix column (255 = no key at this position)
//   hue: HSV hue value for current animation frame (0-255)
// Returns: true if animation was applied, false if LED doesn't exist
static bool animate_exit_key(uint8_t row, uint8_t col, uint8_t hue)
{
    if (row == 255 || col == 255) {
        return false;  // No exit key at this position
    }

    uint8_t led_index = g_led_config.matrix_co[row][col];
    if (led_index == NO_LED) {
        return false;  // LED doesn't exist at this position
    }

    HSV hsv = {.h = hue, .s = 255, .v = 255};
    RGB rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);
    return true;  // Animation applied successfully
}

// --- Public Interface ---

bool animate_layer_exit_keys(uint8_t layer, uint8_t hue)
{
    bool animated = false;

    // Get exit key positions from lookup table
    uint8_t r_exit = 255, c_exit = 255;
    uint8_t r_exit2 = 255, c_exit2 = 255;

    if (layer < EXIT_KEYS_NUM_LAYERS) {
        r_exit  = pgm_read_byte(&exit_keys[layer].r1);
        c_exit  = pgm_read_byte(&exit_keys[layer].c1);
        r_exit2 = pgm_read_byte(&exit_keys[layer].r2);
        c_exit2 = pgm_read_byte(&exit_keys[layer].c2);
    }

    // Animate both exit keys with same hue (synchronised animation)
    animated |= animate_exit_key(r_exit, c_exit, hue);
    animated |= animate_exit_key(r_exit2, c_exit2, hue);

    return animated;
}
