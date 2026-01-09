#ifndef RGB_INDICATORS_H
#define RGB_INDICATORS_H

#include "quantum.h"
#include <stdbool.h>

// +---------------------------+
// | RGB INDICATORS MODULE     |
// +---------------------------+
// This module handles dynamic RGB indicator behaviour at runtime.
// Separates dynamic effects from static layer colour configuration.
//
// Features:
// - Caps Lock visual override (all keys red)
// - Exit key rainbow animations
// - External RGB control detection
// - Coordination with layer colour system

// Main RGB indicator update function
// Called from rgb_matrix_indicators_user() hook
// Handles all dynamic RGB behaviour:
//   1. External RGB control detection
//   2. Caps Lock override
//   3. Layer colour application
//   4. Exit key animations
// Returns: true if indicators were updated, false if external control active
bool update_rgb_indicators(void);

// Configuration: Exit key animation speed
// Higher values = faster rainbow cycling (default: 2)
// At 60fps refresh rate, increment of 2 = ~3 second full cycle
extern uint8_t exit_key_animation_speed;

#endif // RGB_INDICATORS_H
