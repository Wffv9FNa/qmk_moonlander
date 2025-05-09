#ifndef MYKEYS_KEYMAP_C
#define MYKEYS_KEYMAP_C

// +----------+
// | INCLUDES |
// +----------+
#include QMK_KEYBOARD_H
#include "i18n.h"
#include "audio.h"
#include "user_song_list.h"
#include "tap_dance/tap_dance.h"
#include "rgb_config/rgb_config.h"
#include "keymap_japanese.h"

// +---------+
// | DEFINES |
// +---------+
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

// +--------------------------+
// | GLOBAL STATE & VARIABLES |
// +--------------------------+
extern bool socd_cleaner_enabled; // Add this to access the global SOCD state

#ifdef AUDIO_ENABLE
// Audio song data
float caps_on_song[][2] = SONG(CAPS_ON_SOUND);
float caps_off_song[][2] = SONG(CAPS_OFF_SOUND);
float overwatch_song[][2] = SONG(OVERWATCH_THEME);
#endif

// Rawhid state structure
typedef struct
{
  bool rgb_control;
} rawhid_state_t;

rawhid_state_t rawhid_state;

// RGB Matrix configuration
extern rgb_config_t rgb_matrix_config;

// +-------+
// | ENUMS |
// +-------+
enum custom_keycodes
{
  NEW_SAFE_RANGE // This now implicitly starts at SAFE_RANGE
};

#if __has_include("keymap.h")
#include "keymap.h"
#endif

// +--------------------+
// | TAP DANCE ACTIONS  |
// +--------------------+
tap_dance_action_t tap_dance_actions[] = {
    [TD_TGLL_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tgll_4_finished, NULL),
    // Add the new tap dance action
};

// +--------------------+
// | SOCD CONFIGURATION |
// +--------------------+
socd_cleaner_t socd_opposing_pairs[] = {
    {{KC_W, KC_S}, SOCD_CLEANER_LAST},
    {{KC_A, KC_D}, SOCD_CLEANER_LAST},
};

// +---------+
// | KEYMAPS |
// +---------+
//clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  _                             ___   */
/* | |    __ _ _   _  ___ _ __   / _ \  */
/* | |   / _` | | | |/ _ \ '__| | | | | */
/* | |__| (_| | |_| |  __/ |    | |_| | */
/* |_____\__,_|\__, |\___|_|     \___/  */
/*             |___/                    */
    [0]=LAYOUT(
        KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    KC_NO  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
        KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    KC_NO  ,            KC_NO  ,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
        KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KC_NUBS,            KC_MEH ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
        L_SHFT ,    MT_CZ  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,                                    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
        TT(2)  ,    L_GUI  ,    CW_TOGG,    TD_L4TG,    TT(1)  ,                KC_CAPS,            KC_ESC ,                TT(3)  ,    KC_HYPR,    KC_LBRC,    KC_RBRC,    TT(1)   ,
                                                        KC_SPC ,    L_ALT  ,    KC_F13 ,            TG(5)  ,    KC_TAB ,    KC_ENT
    ),
/*  _                            _  */
/* | |    __ _ _   _  ___ _ __  / | */
/* | |   / _` | | | |/ _ \ '__| | | */
/* | |__| (_| | |_| |  __/ |    | | */
/* |_____\__,_|\__, |\___|_|    |_| */
/*             |___/                */
    [1] = LAYOUT(
        KC_GRV ,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_TRNS,            KC_TRNS,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_TRNS,    KC_NO  ,    SELWBK ,    KC_NO  ,    SELWRD ,    KC_NUBS,    KC_NO  ,            KC_NO  ,    KC_HOME,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PAST,    KC_F12 ,
        KC_TRNS,    KC_NO  ,    GC_Y   ,    KC_NO  ,    CS_X   ,    KC_NO  ,    KC_TRNS,            KC_NO  ,    KC_END ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_PPLS,    KC_NO  ,
        L_SHFT ,    L_CTRL ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,                                    KC_PSLS,    KC_1   ,    KC_2   ,    KC_3   ,    KC_PMNS,    R_SHFT ,
        KC_NO  ,    KC_TRNS,    KC_NO  ,    KC_NO  ,    KC_TRNS,                KC_NO  ,            KC_TRNS,                KC_NO  ,    KC_0   ,    KC_PDOT,    KC_PEQL,    KC_TRNS,
                                                        KC_TRNS,    KC_NO  ,    KC_NO  ,            KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  |___ \  */
/* | |   / _` | | | |/ _ \ '__|   __) | */
/* | |__| (_| | |_| |  __/ |     / __/  */
/* |_____\__,_|\__, |\___|_|    |_____| */
/*             |___/                    */
    [2] = LAYOUT(
        KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        KC_TRNS,    CT_Q   ,    CT_W   ,    CT_E   ,    CT_R   ,    KC_NO  ,    KC_TRNS,            KC_TRNS,    KC_HOME,    KC_NO  ,    KC_UP  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        KC_TRNS,    CT_A   ,    CT_S   ,    KC_NO  ,    CT_F   ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_END ,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO  ,    KC_NO  ,
        KC_TRNS,    CT_Z   ,    CT_X   ,    CT_C   ,    CT_V   ,    CT_B   ,                                    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_TRNS,
        KC_TRNS,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,                KC_NO  ,            KC_NO  ,                KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_TRNS,
                                                        KC_NO  ,    KC_NO  ,    KC_TRNS,            KC_NO  ,    KC_TRNS,    KC_NO
    ),
/*  _                            _____  */
/* | |    __ _ _   _  ___ _ __  |___ /  */
/* | |   / _` | | | |/ _ \ '__|   |_ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [3] = LAYOUT(
        QK_BOOT,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_NO  ,    KC_NO  ,    S_LEFT ,    CS_X   ,    S_RGHT ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_F12 ,
        KC_NO  ,    CT_BSPC,    CT_LEFT,    GC_Y   ,    CT_RGHT,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        KC_NO  ,    CS_BSPC,    CS_LEFT,    KC_NO  ,    CS_RGHT,    KC_NO  ,                                    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,                KC_NO  ,            KC_NO  ,                KC_TRNS,    SOCDTG ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
                                                        KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO
    ),
/*  _                            _  _    */
/* | |    __ _ _   _  ___ _ __  | || |   */
/* | |   / _` | | | |/ _ \ '__| | || |_  */
/* | |__| (_| | |_| |  __/ |    |__   _| */
/* |_____\__,_|\__, |\___|_|       |_|   */
/*             |___/                     */
    [4]=LAYOUT(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F5  ,    KC_NO  ,            KC_TRNS,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_NO  ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    KC_NO  ,            KC_HOME,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F12 ,
        KC_ESC ,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    SOCDTG ,            KC_END ,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        L_SHFT ,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        L_CTRL ,    KC_NO  ,    KC_NO  ,    TD_L4TG,    TURBO  ,                KC_NO  ,            KC_CAPS,                KC_NO  ,    KC_NO  ,    KC_TRNS,    KC_TRNS,    KC_NO  ,
                                                        KC_SPC ,    KC_TAB ,    L_ALT  ,            L_GUI  ,    KC_NO  ,    KC_ENT
    ),
/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  | ___|  */
/* | |   / _` | | | |/ _ \ '__| |___ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [5]=LAYOUT(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                JP_KANA,            KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                        KC_TRNS,    KC_TRNS,    KC_F13 ,            TG(5)  ,    KC_TRNS,    KC_TRNS
    ),
};
/*  _____                    _       _        */
/* |_   _|__ _ __ ___  _ __ | | __ _| |_ ___  */
/*   | |/ _ \ '_ ` _ \| '_ \| |/ _` | __/ _ \ */
/*   | |  __/ | | | | | |_) | | (_| | ||  __/ */
/*   |_|\___|_| |_| |_| .__/|_|\__,_|\__\___| */
/*                    |_|                     */
/*
    [X]=LAYOUT(
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,            KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                        KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
*/
//clang-format on

// +----------------+
// | USER FUNCTIONS |
// +----------------+
/**
 * @brief Initialize the keyboard after startup
 *
 * Runs once at keyboard initialization to set up initial LED state.
 */
void keyboard_post_init_user(void)
{
  rgb_matrix_enable();
}

/**
 * @brief Handle RGB matrix indicators for different keyboard states
 *
 * Controls LED colors based on active layer and Caps Lock state.
 * Returns true to allow default RGB matrix effects to continue processing.
 */
bool rgb_matrix_indicators_user(void)
{
  if (rawhid_state.rgb_control)
  {
    return false;
  }
  if (keyboard_config.disable_layer_led)
  {
    return false;
  }

  // Check if Caps Lock is on
  if (host_keyboard_led_state().caps_lock)
  {
    // Set all keys to red when Caps Lock is on
    rgb_matrix_set_color_all(255, 0, 0);
  }
  else
  {
    // Normal layer-based lighting when Caps Lock is off
    switch (biton32(layer_state))
    {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
      break;
    }
  }
  return true;
}

/**
 * @brief Process keycodes for custom handling
 *
 * First passes keys through SOCD cleaner, then applies custom
 * behavior for specific keycodes like playing audio on Caps Lock.
 * Returns true to allow QMK's default handling for most keys.
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  // First let the SOCD cleaner process the key
  bool socd_handled = process_record_socd_cleaner(keycode, record);
  if (!socd_handled)
  {
    return false;
  }

  switch (keycode)
  {
  case KC_CAPS:
    if (record->event.pressed)
    {
      bool new_caps_state = !host_keyboard_led_state().caps_lock;
#ifdef AUDIO_ENABLE
      if (new_caps_state)
      {
        PLAY_SONG(caps_on_song);
      }
      else
      {
        PLAY_SONG(caps_off_song);
      }
#endif
    }
    return true;

  case SOCDTOG:
    // Just return true to allow default SOCDTOG handling
    return true;
  }
  return true;
}

/**
 * @brief Layer change event handler
 *
 * Executes when layers are activated or deactivated.
 * Currently plays the Overwatch theme when layer 4 is activated.
 */
layer_state_t layer_state_set_user(layer_state_t state)
{
  // Check if audio is enabled
#ifdef AUDIO_ENABLE
  // Check if layer 4 is the highest active layer
  if (biton32(state) == 4)
  {
    // Play the Overwatch theme song
    PLAY_SONG(overwatch_song);
  }
#endif
  return state;
}

#ifdef OTHER_KEYMAP_C
#include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

#endif // MYKEYS_KEYMAP_C
