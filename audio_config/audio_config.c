#include "audio_config.h"

#ifdef AUDIO_ENABLE

#include "keymap.h"      // For layer enums

// +-------------------+
// | Song Declarations |
// +-------------------+
float caps_on_song[][2] = SONG(CAPS_ON_SOUND);
float caps_off_song[][2] = SONG(CAPS_OFF_SOUND);
float overwatch_song[][2] = SONG(OVERWATCH_THEME);

extern bool td_layer4_activated;   // External state flag for tap dance layer 4 activation

// +-------------------------+
// | Audio Event Handlers    |
// +-------------------------+

bool process_record_audio(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode)
    {
    case KC_CAPS:  // Caps Lock key pressed
        if (record->event.pressed)
        {
            bool new_caps_state = !host_keyboard_led_state().caps_lock;

            if (new_caps_state)
            {
                PLAY_SONG(caps_on_song);   // Caps Lock ON sound
            }
            else
            {
                PLAY_SONG(caps_off_song);  // Caps Lock OFF sound
            }
        }
        return true;  // Continue processing
    }

    return true;      // Not handled by audio, continue processing
}

layer_state_t layer_state_audio(layer_state_t state)
{
    // Play Overwatch theme when entering gaming layer via tap dance
    if (layer_state_cmp(state, _GM) && td_layer4_activated)
    {
        PLAY_SONG(overwatch_song);
        td_layer4_activated = false;  // Reset flag after playing
    }

    // Add more layer-specific sounds here:
    // if (layer_state_cmp(state, _MS)) { PLAY_SONG(mouse_layer_song); }

    return state;
}

#endif // AUDIO_ENABLE
