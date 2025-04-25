#include "quantum.h"
#include <stdbool.h>
#include "tap_dance.h"

// Tap Dance definitions
typedef struct {
    bool is_press_action;
    int state;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP, // Send two single taps
    TRIPLE_TAP,
    TRIPLE_HOLD
};

// Determine the current tap dance state
int cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    if (state->count == 3) {
        if (state->interrupted || !state->pressed) return TRIPLE_TAP;
        else return TRIPLE_HOLD;
    } else return 8; // Magic number. At some point this method will expand to work for more presses
}

// Tap dance handler function for TD_TGLL_4
void td_tgll_4_finished(tap_dance_state_t *state, void *user_data) {
    int dance_state = cur_dance(state);
    switch (dance_state) {
        case DOUBLE_TAP:
            layer_invert(4); // Toggle layer 4 on double tap
            break;
        // Add cases for other tap counts or actions if needed
        // case SINGLE_TAP:
        // case SINGLE_HOLD:
        // etc.
    }
}