#pragma once                        // Ensure this header is only included once

#include "quantum.h"                // Core QMK definitions and helpers

enum custom_private_keycodes        // Custom keycodes for private macros
{
    P_CITRIX = SAFE_RANGE,          // First private keycode starts after SAFE_RANGE
    // Add other private keycodes here
    PRIVATE_SAFE_RANGE              // New safe range after private keycodes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record); // Function declaration for processing private macros
