#ifndef TAP_DANCE_H                                   // Begin include guard for this header
#define TAP_DANCE_H                                   // Define TAP_DANCE_H to prevent multiple inclusion

#include "quantum.h"                                  // Core QMK quantum functions (types, layers, utilities)

/**
 * Enum for Tap Dance keycodes
 * Add entries here for any new tap dance actions.
 */

// +---------------------------+
// | Generic number/F-key map  |
// +---------------------------+
typedef struct {
    uint16_t single;                                 // Key to send on SINGLE_TAP
    uint16_t dtap;                                   // Key to send on DOUBLE_TAP
} td_num_map_t;

// +---------------------------+
// | Number/F-key mappings     |
// +---------------------------+
extern const td_num_map_t TD_NUM_MAP[];

// +-----------------------+
// | Tap-dance identifiers |
// +-----------------------+
enum tap_dance_keycodes {
    TD_TGLL_4,                                       // Tap-dance key for toggling layer 4
    TD_1_F1,                                         // Index 0 -> uses TD_NUM_MAP[0]
    TD_2_F2,                                         // Index 1 -> uses TD_NUM_MAP[1]
    TD_3_F3,                                         // Index 2 -> uses TD_NUM_MAP[2]
    TD_4_F4,                                         // Index 3 -> uses TD_NUM_MAP[3]
    TD_5_F5,                                         // Index 4 -> uses TD_NUM_MAP[4]
    TD_6_F6,                                         // Index 5 -> uses TD_NUM_MAP[5]
    TD_7_F7,                                         // Index 6 -> uses TD_NUM_MAP[6]
    TD_8_F8,                                         // Index 7 -> uses TD_NUM_MAP[7]
    TD_9_F9,                                         // Index 8 -> uses TD_NUM_MAP[8]
    TD_0_F10,                                        // Index 9 -> uses TD_NUM_MAP[9]
};

/**
 * Forward declarations for functions defined in tap_dance.c
 * These allow other files to reference tap dance handlers.
 */
void td_tgll_4_finished(tap_dance_state_t *state, void *user_data);
void td_num_fkey_finished(tap_dance_state_t *state, void *user_data);
// int cur_dance(tap_dance_state_t *state);           // Only needed if used outside tap_dance.c

#endif                                                // End include guard for TAP_DANCE_H

