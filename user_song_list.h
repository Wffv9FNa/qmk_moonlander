#pragma once

#ifdef AUDIO_ENABLE
// Define custom songs
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
	Q__NOTE(_G4),

#define OVERWATCH_THEME \
    HD_NOTE(_A4 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_A4 ), \
    HD_NOTE(_B4 ), \
    Q__NOTE(_E4 ), \
    Q__NOTE(_B4 ), \
    W__NOTE(_CS5)

#endif
