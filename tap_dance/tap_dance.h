#ifndef TAP_DANCE_H
#define TAP_DANCE_H

#include "quantum.h" // Include base QMK header for types

// Enum for Tap Dance keycodes
enum tap_dance_keycodes {
    TD_TGLL_4,
};

// Forward declarations for functions defined in tap_dance.c
void td_tgll_4_finished(tap_dance_state_t *state, void *user_data);
// int cur_dance(tap_dance_state_t *state); // Only needed if called outside tap_dance.c

// // Declare the tap dance actions array (defined in tap_dance.c) -> Moved back to keymap.c
// extern tap_dance_action_t tap_dance_actions[];

#endif // TAP_DANCE_H