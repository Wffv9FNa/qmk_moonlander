#ifndef AUDIO_CONFIG_H
#define AUDIO_CONFIG_H

#include "quantum.h"

#ifdef AUDIO_ENABLE

// Process audio events for specific keycodes
// Returns: false if keycode was handled, true to continue processing
bool process_record_audio(uint16_t keycode, keyrecord_t *record);

// Handle layer change audio events
// Returns: modified layer_state
layer_state_t layer_state_audio(layer_state_t state);

#endif // AUDIO_ENABLE
#endif // AUDIO_CONFIG_H
