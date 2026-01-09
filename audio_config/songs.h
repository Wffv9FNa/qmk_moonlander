#ifndef AUDIO_SONGS_H
#define AUDIO_SONGS_H

#ifdef AUDIO_ENABLE

// +------------------------+
// | Custom Song Definitions |
// +------------------------+
// Define your custom songs here using QMK note macros
// Note length prefixes: HD=half-dotted, W=whole, H=half, Q=quarter, E=eighth, ED=eighth-dotted
// Note format: _NOTE(pitch) where pitch is like _C4, _E5, _A6
//
// NOTE: QMK's song_list.h defines these songs as empty macros by default.
// We provide the actual note sequences here.

#define CAPS_ON_SOUND \
    E__NOTE(_E6), \
    E__NOTE(_A6), \
    ED_NOTE(_E7)

#define CAPS_OFF_SOUND \
    E__NOTE(_E7), \
    E__NOTE(_A6), \
    ED_NOTE(_E6)

#define CLOSE_ENCOUNTERS_5_NOTE  \
    Q__NOTE(_D5),                \
    Q__NOTE(_E5),                \
    Q__NOTE(_C5),                \
    Q__NOTE(_C4),                \
    Q__NOTE(_G4)

#define OVERWATCH_THEME \
    HD_NOTE(_A4 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_A4 ), \
    HD_NOTE(_B4 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_B4 ), \
    W__NOTE(_CS5)

// Add your custom songs here:
// Example (single-line definition to avoid comment warnings):
// #define MY_CUSTOM_SONG Q__NOTE(_C5), Q__NOTE(_E5), H__NOTE(_G5)

#endif // AUDIO_ENABLE
#endif // AUDIO_SONGS_H
