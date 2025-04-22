CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
#RGB_MATRIX_CUSTOM_KB = yes
SPACE_CADET_ENABLE = no
CAPS_WORD_ENABLE = yes
AUDIO_ENABLE = yes
TAP_DANCE_ENABLE = yes

# Add tap dance source file
SRC += tap_dance/tap_dance.c

# Add RGB config source file
SRC += rgb_config/rgb_config.c