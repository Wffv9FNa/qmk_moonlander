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
SRC += rgb_config/rgb_indicators.c                # Include RGB indicators source file
SRC += exit_keys/exit_keys.c                      # Include exit key animation source file
SRC += exit_keys/exit_key_config.c                # Include exit key configuration source file
SRC += macros_private.c                           # Include private macro source file
SRC += audio_config/audio_config.c                # Include audio configuration source file
SRC += key_overrides/key_overrides.c              # Include key override definitions
SRC += indicator_leds/indicator_leds.c            # Include indicator LED control module

MOUSEKEY_ENABLE = yes                             # Enable mouse key emulation
DEFERRED_EXEC_ENABLE = yes                        # Enable deferred execution (needed for Turbo Click)
KEY_OVERRIDE_ENABLE = yes                         # Enable key override functionality
