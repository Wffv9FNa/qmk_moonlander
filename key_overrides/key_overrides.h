#ifndef KEY_OVERRIDES_H
#define KEY_OVERRIDES_H

#include "quantum.h"

// +----------------------------------+
// | Key Overrides Module Header     |
// +----------------------------------+
// This module defines individual key overrides.
// The key_overrides[] array is registered in keymap.c
// due to QMK's introspection requirements.
//
// To add a new override:
// 1. Define it in key_overrides.c
// 2. Declare it here as extern
// 3. Add it to the key_overrides[] array in keymap.c

// +----------------------------+
// | Navigation & Editing      |
// +----------------------------+
extern const key_override_t nubs_key_override;

#endif // KEY_OVERRIDES_H
