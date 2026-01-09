#include QMK_KEYBOARD_H                  // Keyboard-specific definitions (includes moonlander.h)
#include "rgb_indicators.h"
#include "rgb_config/rgb_config.h"       // For set_layer_color()
#include "exit_keys/exit_keys.h"         // For animate_layer_exit_keys()
#include "keymap.h"                      // For rawhid_state_t and rawhid_state

// Configuration
uint8_t exit_key_animation_speed = 2;    // Default: ~3 sec cycle at 60fps

// +---------------------------+
// | Caps Lock Override        |
// +---------------------------+
// Applies visual override when Caps Lock is active
// Sets all keys to bright red to provide clear visual feedback
//
// Returns: true if override was applied, false otherwise
static inline bool apply_caps_lock_override(void)
{
    if (host_keyboard_led_state().caps_lock)
    {
        rgb_matrix_set_color_all(255, 0, 0);  // Bright red for Caps Lock
        return true;  // Override applied
    }
    return false;  // No override needed
}

// +---------------------------+
// | Main Indicator Function   |
// +---------------------------+
bool update_rgb_indicators(void)
{
    // FUNCTION STRUCTURE:
    //  1. Check for external RGB control or disabled LEDs
    //  2. Handle Caps Lock override (red all keys)
    //  3. Apply base layer colours
    //  4. Animate exit keys with rainbow effect
    //  5. Update animation timing

    // Check for external RGB control
    if (rawhid_state.rgb_control || keyboard_config.disable_layer_led)
    {
        return false;  // External control active or LEDs disabled
    }

    // Apply Caps Lock override if active
    if (apply_caps_lock_override())
    {
        return true;  // Caps Lock overrides all other effects
    }

    // Apply layer-specific colours
    uint8_t current_layer = biton32(layer_state);
    set_layer_color(current_layer);

    // Animate exit keys with rainbow cycling
    static uint8_t exit_key_hue = 0;
    if (animate_layer_exit_keys(current_layer, exit_key_hue))
    {
        exit_key_hue += exit_key_animation_speed;  // Increment hue for next frame
    }

    return true;
}
