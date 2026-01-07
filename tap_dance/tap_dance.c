#include "quantum.h"                                 // Core QMK quantum functions (layers, matrix, keymaps)
#include <stdbool.h>                                 // Standard C header for boolean types
#include "tap_dance.h"                               // QMK tap dance feature support
#include "keymap.h"                                  // Keymap definitions and custom keycodes

// +-----------------------+
// | Tap Dance Definitions |
// +-----------------------+
typedef struct {
    bool is_press_action;                            // True if action triggers on press, false if on release
    int state;                                       // Current tap/hold state of this key
} tap;

enum {
    SINGLE_TAP = 1,                                  // One quick tap
    SINGLE_HOLD,                                     // One press and hold
    DOUBLE_TAP,                                      // Two quick taps
    DOUBLE_HOLD,                                     // Two presses held down
    DOUBLE_SINGLE_TAP,                               // Two distinct singles (e.g., "pp"), not a double-tap action
    TRIPLE_TAP,                                      // Three quick taps
    TRIPLE_HOLD,                                     // Three presses held down
    TAP_DANCE_UNHANDLED = 8                          // Placeholder for 4+ taps until explicit states are defined
};

// +--------------------+
// | Determine TD State |
// +--------------------+
int cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {                         // One press detected
        if (state->interrupted || !state->pressed)   // Released quickly or interrupted
            return SINGLE_TAP;                       // Count as single tap
        else
            return SINGLE_HOLD;                      // Still held -> single hold
    } else if (state->count == 2) {                  // Two presses detected
        /**
         * DOUBLE_SINGLE_TAP means: send the key twice as normal keystrokes,
         * instead of treating it as a special double-tap action/macro.
         * Example: typing the letter 'p' twice in "pepper" should produce "pp",
         * not trigger a double-tap shortcut.
         */
        if (state->interrupted) return DOUBLE_SINGLE_TAP; // Interrupted -> treat as two singles
        else if (state->pressed) return DOUBLE_HOLD;      // Still held -> double hold
        else return DOUBLE_TAP;                           // Otherwise -> double tap
    }
    if (state->count == 3) {                         // Three presses detected
        if (state->interrupted || !state->pressed) return TRIPLE_TAP; // Interrupted/released -> triple tap
        else return TRIPLE_HOLD;                     // Still held -> triple hold
    } else return TAP_DANCE_UNHANDLED;               // Fallback: 4+ taps not explicitly handled yet
}

// +-------------------+
// | TD_TGLL_4 Handler |
// +-------------------+
// External flag to signal tap dance layer 4 activation
// Added for Overwatch theme song to play when layer 4 is activated via tap dance
extern bool td_layer4_activated;

void td_tgll_4_finished(tap_dance_state_t *state, void *user_data) {
    int dance_state = cur_dance(state);              // Evaluate tap dance result
    switch (dance_state) {
        case DOUBLE_TAP:
            td_layer4_activated = true;              // Set flag before toggling
            layer_invert(_GM);                         // Toggle layer 4 on double tap
            break;

            default:
            /**
             * Do nothing for other states:
             *   SINGLE_TAP, SINGLE_HOLD,
             *   DOUBLE_HOLD, DOUBLE_SINGLE_TAP,
             *   TRIPLE_TAP, TRIPLE_HOLD,
             *   TAP_DANCE_UNHANDLED, etc.
             */
            break;
    }
}
