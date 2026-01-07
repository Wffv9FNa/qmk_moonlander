#ifndef TAP_DANCE_H                                   // Begin include guard for this header
#define TAP_DANCE_H                                   // Define TAP_DANCE_H to prevent multiple inclusion

#include "quantum.h"                                  // Core QMK quantum functions (types, layers, utilities)

/**
 * Enum for Tap Dance keycodes
 * Add entries here for any new tap dance actions.
 */

// +-----------------------+
// | Tap-dance identifiers |
// +-----------------------+
enum tap_dance_keycodes {
    TD_TGLL_4,                                       // Tap-dance key for toggling layer 4
    TD_PMONE,                                        // Tap-dance for private macro one
};

/**
 * Forward declarations for functions defined in tap_dance.c
 * These allow other files to reference tap dance handlers.
 */
void td_tgll_4_finished(tap_dance_state_t *state, void *user_data);
void td_pmone_finished(tap_dance_state_t *state, void *user_data);
// int cur_dance(tap_dance_state_t *state);           // Only needed if used outside tap_dance.c

#endif                                                // End include guard for TAP_DANCE_H

