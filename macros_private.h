#pragma once                        // Ensure this header is only included once

#include "quantum.h"                // Core QMK definitions and helpers

enum custom_private_keycodes        // Custom keycodes for private macros
{
    PRIVATE_SAFE_RANGE = SAFE_RANGE,              // New safe range after private keycodes
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record); // Function declaration for processing private macros
void private_macro_one(void); // Function declaration for private macro one (defined in macros_private.c)
