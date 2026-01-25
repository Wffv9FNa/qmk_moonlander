/* Indicator LED Control Module
 *
 * This module provides control over the Moonlander's 6 dedicated indicator LEDs
 * (3 per half), separate from the per-key RGB matrix. Each LED can be configured
 * to indicate various keyboard states such as Caps Lock, active layers, Caps Word,
 * or custom conditions.
 *
 * Requires: #define MOONLANDER_USER_LEDS in config.h
 */

#ifndef INDICATOR_LEDS_H
#define INDICATOR_LEDS_H

#include "quantum.h"
#include <stdbool.h>
#include <stdint.h>

// --- LED Position Mapping ---
// The Moonlander has 6 indicator LEDs arranged as 3 per half

typedef enum {
    IND_LED_L1 = 0,  // Left side, leftmost
    IND_LED_L2,      // Left side, middle
    IND_LED_L3,      // Left side, rightmost
    IND_LED_R1,      // Right side, leftmost
    IND_LED_R2,      // Right side, middle
    IND_LED_R3,      // Right side, rightmost
    IND_LED_COUNT
} indicator_led_t;

// --- Indicator Modes ---
// Each LED can be configured to show one of these states

typedef enum {
    IND_MODE_OFF,           // Always off
    IND_MODE_ON,            // Always on
    IND_MODE_CAPS_LOCK,     // Caps Lock state (from host)
    IND_MODE_NUM_LOCK,      // Num Lock state (from host)
    IND_MODE_SCROLL_LOCK,   // Scroll Lock state (from host)
    IND_MODE_LAYER_ACTIVE,  // Specific layer is active (highest layer matches)
    IND_MODE_LAYER_MASK,    // Any of masked layers is active
    IND_MODE_LAYER_CODE,    // Layer display using spread code (0=R3, 1=R2, 2=R1)
    IND_MODE_CAPS_WORD,     // Caps Word feature is active
    IND_MODE_CAPS_ANY,      // Either Caps Lock or Caps Word is active
    IND_MODE_SOCD_ENABLED,  // SOCD cleaner is enabled
    IND_MODE_CUSTOM,        // Custom callback function determines state
} indicator_mode_t;

// --- Configuration Structure ---

typedef struct {
    indicator_mode_t mode;
    union {
        uint8_t layer;           // For IND_MODE_LAYER_ACTIVE
        uint8_t layer_mask;      // For IND_MODE_LAYER_MASK (bitmask of layers 0-7)
        uint8_t led_position;    // For IND_MODE_LAYER_CODE (0=R3/LSB, 1=R2, 2=R1/MSB)
        bool (*custom_fn)(void); // For IND_MODE_CUSTOM
    };
} indicator_config_t;

// --- Public API ---

// Initialise indicator LED system with default configuration
void indicator_leds_init(void);

// Update all indicator LEDs based on current state
// Call from housekeeping_task_user() or matrix_scan_user()
void indicator_leds_update(void);

// Configure a specific indicator's mode
void indicator_led_set_mode(indicator_led_t led, indicator_mode_t mode);

// Configure an indicator to show when a specific layer is active
void indicator_led_set_layer(indicator_led_t led, uint8_t layer);

// Configure an indicator to show when any of the masked layers is active
void indicator_led_set_layer_mask(indicator_led_t led, uint8_t mask);

// Configure an indicator to use a custom callback function
void indicator_led_set_custom(indicator_led_t led, bool (*fn)(void));

// Direct control (overrides configuration temporarily until next update)
void indicator_led_on(indicator_led_t led);
void indicator_led_off(indicator_led_t led);
void indicator_led_toggle(indicator_led_t led);

// Set all indicators at once using a bitmask (bit 0 = L1, bit 5 = R3)
void indicator_leds_set_all(uint8_t mask);

#endif // INDICATOR_LEDS_H
