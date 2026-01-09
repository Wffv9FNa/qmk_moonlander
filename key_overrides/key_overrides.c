#include "key_overrides.h"

// +---------------------------+
// | Key Override Definitions  |
// +---------------------------+
// Change what a key sends when used with a modifier
//
// Syntax: ko_make_basic(modifier_mask, trigger_key, replacement_key)
//
// Common modifier masks:
//   MOD_MASK_CTRL  - Any Ctrl
//   MOD_MASK_SHIFT - Any Shift
//   MOD_MASK_ALT   - Any Alt
//   MOD_MASK_GUI   - Any GUI/Win/Cmd
//   MOD_MASK_CSAG  - Ctrl+Shift+Alt+GUI (all modifiers)
//
// Example: ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL)
//          Ctrl+Backspace sends Delete
//
// Note: After defining an override here:
// 1. Declare it as extern in key_overrides.h
// 2. Add it to the key_overrides[] array in keymap.c

// +----------------------------+
// | Navigation & Editing      |
// +----------------------------+
const key_override_t nubs_key_override =
    ko_make_basic(MOD_MASK_CTRL, KC_NUBS, KC_GRV);  // Ctrl + NUBS sends `

// +----------------------------+
// | Add your overrides here   |
// +----------------------------+
// Example: Ctrl+Backspace sends Delete
// const key_override_t ctrl_backspace_override =
//     ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);
