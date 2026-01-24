/* Indicator LED Control Module - Implementation
 *
 * Controls the Moonlander's 6 dedicated indicator LEDs based on configurable
 * conditions. Each LED evaluates its mode on every update cycle and sets
 * its state accordingly.
 */

#include "indicator_leds.h"
#include "moonlander.h"  // ML_LED_1() through ML_LED_6() macros
#include "keymap.h"      // Layer definitions

// --- External State Access ---
extern bool socd_cleaner_enabled;  // From SOCD cleaner module

// --- Configuration Storage ---
static indicator_config_t indicator_configs[IND_LED_COUNT];

// --- Hardware Control Mapping ---
// Maps our enum indices to the ML_LED_n() hardware calls

static void set_led_state(indicator_led_t led, bool state) {
    switch (led) {
        case IND_LED_L1: ML_LED_1(state); break;
        case IND_LED_L2: ML_LED_2(state); break;
        case IND_LED_L3: ML_LED_3(state); break;
        case IND_LED_R1: ML_LED_4(state); break;
        case IND_LED_R2: ML_LED_5(state); break;
        case IND_LED_R3: ML_LED_6(state); break;
        default: break;
    }
}

// --- State Evaluation ---
// Evaluates a single indicator's configuration and returns desired state

static bool evaluate_indicator(indicator_led_t led) {
    indicator_config_t *cfg = &indicator_configs[led];

    switch (cfg->mode) {
        case IND_MODE_OFF:
            return false;

        case IND_MODE_ON:
            return true;

        case IND_MODE_CAPS_LOCK:
            return host_keyboard_led_state().caps_lock;

        case IND_MODE_NUM_LOCK:
            return host_keyboard_led_state().num_lock;

        case IND_MODE_SCROLL_LOCK:
            return host_keyboard_led_state().scroll_lock;

        case IND_MODE_LAYER_ACTIVE:
            // Check if the specified layer is the highest active layer
            return get_highest_layer(layer_state) == cfg->layer;

        case IND_MODE_LAYER_MASK:
            // Check if any layer in the mask is active
            return (layer_state & cfg->layer_mask) != 0;

        case IND_MODE_CAPS_WORD:
            return is_caps_word_on();

        case IND_MODE_SOCD_ENABLED:
            return socd_cleaner_enabled;

        case IND_MODE_CUSTOM:
            if (cfg->custom_fn) {
                return cfg->custom_fn();
            }
            return false;

        default:
            return false;
    }
}

// --- Public API Implementation ---

void indicator_leds_init(void) {
    // Set default configuration for each LED
    // Left side: keyboard state indicators
    indicator_configs[IND_LED_L1].mode = IND_MODE_CAPS_LOCK;

    indicator_configs[IND_LED_L2].mode = IND_MODE_LAYER_ACTIVE;
    indicator_configs[IND_LED_L2].layer = _GM;  // Gaming layer

    indicator_configs[IND_LED_L3].mode = IND_MODE_LAYER_ACTIVE;
    indicator_configs[IND_LED_L3].layer = _KN;  // Kana layer

    // Right side: utility indicators
    indicator_configs[IND_LED_R1].mode = IND_MODE_LAYER_ACTIVE;
    indicator_configs[IND_LED_R1].layer = _MS;  // Mouse layer

    indicator_configs[IND_LED_R2].mode = IND_MODE_LAYER_MASK;
    indicator_configs[IND_LED_R2].layer_mask = (1 << _NM) | (1 << _WM);  // Numpad or WordMon

    indicator_configs[IND_LED_R3].mode = IND_MODE_CAPS_WORD;

    // Ensure all LEDs start in correct state
    indicator_leds_update();
}

void indicator_leds_update(void) {
    for (indicator_led_t led = 0; led < IND_LED_COUNT; led++) {
        bool state = evaluate_indicator(led);
        set_led_state(led, state);
    }
}

void indicator_led_set_mode(indicator_led_t led, indicator_mode_t mode) {
    if (led < IND_LED_COUNT) {
        indicator_configs[led].mode = mode;
    }
}

void indicator_led_set_layer(indicator_led_t led, uint8_t layer) {
    if (led < IND_LED_COUNT) {
        indicator_configs[led].mode = IND_MODE_LAYER_ACTIVE;
        indicator_configs[led].layer = layer;
    }
}

void indicator_led_set_layer_mask(indicator_led_t led, uint8_t mask) {
    if (led < IND_LED_COUNT) {
        indicator_configs[led].mode = IND_MODE_LAYER_MASK;
        indicator_configs[led].layer_mask = mask;
    }
}

void indicator_led_set_custom(indicator_led_t led, bool (*fn)(void)) {
    if (led < IND_LED_COUNT) {
        indicator_configs[led].mode = IND_MODE_CUSTOM;
        indicator_configs[led].custom_fn = fn;
    }
}

void indicator_led_on(indicator_led_t led) {
    if (led < IND_LED_COUNT) {
        set_led_state(led, true);
    }
}

void indicator_led_off(indicator_led_t led) {
    if (led < IND_LED_COUNT) {
        set_led_state(led, false);
    }
}

void indicator_led_toggle(indicator_led_t led) {
    // Toggle based on current evaluated state (inverts next update)
    if (led < IND_LED_COUNT) {
        bool current = evaluate_indicator(led);
        set_led_state(led, !current);
    }
}

void indicator_leds_set_all(uint8_t mask) {
    for (indicator_led_t led = 0; led < IND_LED_COUNT; led++) {
        set_led_state(led, (mask & (1 << led)) != 0);
    }
}
