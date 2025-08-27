CONSOLE_ENABLE = no                               # Disable console (saves space, no debug printing)
COMMAND_ENABLE = no                               # Disable QMK command feature
ORYX_ENABLE = yes                                 # Enable Oryx configurator compatibility
#RGB_MATRIX_CUSTOM_KB = yes                       # Enable keyboard-level RGB hook (rgb_matrix_indicators_kb)
SPACE_CADET_ENABLE = no                           # Disable Space Cadet shift key functionality
CAPS_WORD_ENABLE = yes                            # Enable Caps Word feature
AUDIO_ENABLE = yes                                # Enable audio (for sounds on events)
TAP_DANCE_ENABLE = yes                            # Enable tap dance functionality

SRC += tap_dance/tap_dance.c                      # Include tap dance source file
SRC += rgb_config/rgb_config.c                    # Include RGB configuration source file

MOUSEKEY_ENABLE = yes                             # Enable mouse key emulation
DEFERRED_EXEC_ENABLE = yes                        # Enable deferred execution (needed for Turbo Click)
KEY_OVERRIDE_ENABLE = yes                         # Enable key override functionality
