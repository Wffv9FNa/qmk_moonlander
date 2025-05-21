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
extern led_config_t g_led_config; // Added for LED physical index mapping

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
    [0] = LAYOUT( //Home
        KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    KC_NO  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
        KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    KC_NO  ,            KC_NO  ,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
        KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KC_NUBS,            KC_MEH ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
        L_SHFT ,    MT_CZ  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,                                    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
        TT(1)  ,    L_GUI  ,    CW_TOGG,    TD_L4TG,    TT(3)  ,                KC_ESC ,            KC_CAPS,                TT(1)  ,    KC_HYPR,    KC_LBRC,    KC_RBRC,    TT(3)   ,
                                                        KC_SPC ,    L_ALT  ,    KC_F13 ,            TG(5)  ,    KC_TAB ,    KC_ENT
    ),
/*  _                            _  */
/* | |    __ _ _   _  ___ _ __  / | */
/* | |   / _` | | | |/ _ \ '__| | | */
/* | |__| (_| | |_| |  __/ |    | | */
/* |_____\__,_|\__, |\___|_|    |_| */
/*             |___/                */
    [1] = LAYOUT( //Numpad
        KC_GRV ,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_TRNS,            KC_TRNS,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_TRNS,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_HOME,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PAST,    KC_F12 ,
        KC_TRNS,    KC_NO  ,    CT_S   ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_TRNS,            KC_NO  ,    KC_END ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_PPLS,    KC_NO  ,
        L_SHFT ,    CT_Z   ,    KC_NO  ,    CT_C   ,    CT_V   ,    KC_NO  ,                                    KC_PSLS,    KC_1   ,    KC_2   ,    KC_3   ,    KC_PMNS,    R_SHFT ,
        TT(1)  ,    KC_TRNS,    KC_NO  ,    KC_NO  ,    KC_TRNS,                KC_NO  ,            KC_TRNS,                TT(1)  ,    KC_0   ,    KC_PDOT,    KC_PEQL,    KC_NO  ,
                                                        KC_TRNS,    KC_NO  ,    KC_NO  ,            KC_TRNS,    KC_TRNS,    KC_TRNS
    ),
/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  |___ \  */
/* | |   / _` | | | |/ _ \ '__|   __) | */
/* | |__| (_| | |_| |  __/ |     / __/  */
/* |_____\__,_|\__, |\___|_|    |_____| */
/*             |___/                    */
    [2] = LAYOUT( //Arrows
        KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        KC_TRNS,    CT_Q   ,    CT_W   ,    CT_E   ,    CT_R   ,    KC_NO  ,    KC_TRNS,            KC_NO  ,    KC_HOME,    KC_NO  ,    KC_UP  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
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
    [3] = LAYOUT( // WordMon + Arrows
        QK_BOOT,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_NO  ,    KC_NO  ,    SELWBK ,    CS_X   ,    SELWRD ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_HOME,    KC_NO  ,    KC_UP  ,    KC_NO  ,    KC_NO  ,    KC_F12 ,
        CT_BSPC,    KC_NO  ,    S_LEFT ,    GC_Y   ,    S_RGHT ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_END ,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO  ,    KC_NO  ,
        KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/            /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(3)  ,    /*XXXX*/    KC_NO  ,            KC_NO  ,    /*XXXX*/    KC_TRNS,    SOCDTG ,    KC_NO  ,    KC_NO  ,    TT(3)  ,
        /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO       /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
),
/*  _                            _  _    */
/* | |    __ _ _   _  ___ _ __  | || |   */
/* | |   / _` | | | |/ _ \ '__| | || |_  */
/* | |__| (_| | |_| |  __/ |    |__   _| */
/* |_____\__,_|\__, |\___|_|       |_|   */
/*             |___/                     */
    [4] = LAYOUT( // Gaming Layer
    /*  =           1           2           3           4           5           ---                 ---         6           7            8            9         0           --- */
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F5  ,    KC_NO  ,            KC_TRNS,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_NO  ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    KC_NO  ,            KC_HOME,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F12 ,
        KC_ESC ,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KC_NO  ,            KC_END ,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        L_SHFT ,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        L_CTRL ,    KC_NO  ,    KC_NO  ,    TD_L4TG,    TURBO  ,    /*XXXX*/    SOCDTG ,            KC_CAPS,    /*XXXXX*/   KC_NO  ,    KC_NO  ,    KC_TRNS,    KC_TRNS,    KC_NO  ,
        /*XXXXX*/   /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    KC_TAB ,    L_ALT  ,            L_GUI  ,    KC_NO   ,   KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
),

/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  | ___|  */
/* | |   / _` | | | |/ _ \ '__| |___ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [5] = LAYOUT( //Kana Layer
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    HIRAG  ,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KATAK  ,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,            KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
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

  uint8_t current_layer = biton32(layer_state);
  static uint8_t exit_key_hue = 0; // Hue for animating layer exit keys
  bool animated_this_cycle = false;

  // Check if Caps Lock is on
  if (host_keyboard_led_state().caps_lock)
  {
    // Set all keys to red when Caps Lock is on
    rgb_matrix_set_color_all(255, 0, 0);  // Full brightness red for Caps Lock
  }
  else
  {
    // Set base static colors for the current layer first
    set_layer_color(current_layer);

    // Define exit key positions (row, col) for layers > 0
    // These are the positions on the *target layer* that correspond to the
    // TT(x) or TG(x) keys used to activate the layer from layer 0.
    uint8_t r_exit = 255, c_exit = 255;   // Primary exit key
    uint8_t r_exit2 = 255, c_exit2 = 255; // Secondary exit key (for Layer 1 which has two TT(1) keys)

    switch (current_layer)
    {
    case 0:
      // No specific exit key animation on the base layer
      break;
    case 1: // Numpad layer
      r_exit = 4; c_exit = 0;    // Left TT(1) -> Mapped to c40 position [4][0]
      r_exit2 = 10; c_exit2 = 2; // Right TT(1) -> Mapped to ca2 position [10][2]
      break;
    case 3: // WordMon + Arrows layer
      r_exit = 4; c_exit = 4;    // Left TT(3) -> Mapped to c44 position [4][4]
      r_exit2 = 10; c_exit2 = 6; // Right TT(3) -> Mapped to ca6 position [10][6]
      break;
    case 4: // Gaming layer
      r_exit = 4; c_exit = 3;    // Left TD_L4TG -> Mapped [4][3]
      break;
    case 5: // Kana layer
      r_exit = 11; c_exit = 4;   // TG(5) on right thumb cluster -> Mapped to kb4 position [11][4]
      break;
    default:
      // For any other layers not explicitly handled, rely on set_layer_color.
      // If rgb_matrix_get_flags() == LED_FLAG_NONE was part of set_layer_color's
      // handling for unknown layers, that will still apply.
      break;
    }

    // Apply animation to the primary exit key if defined for the current layer
    if (r_exit != 255 && c_exit != 255) // r_exit, c_exit are MAPPED coordinates for g_led_config.matrix_co
    {
      uint8_t led_index = g_led_config.matrix_co[r_exit][c_exit];
      if (led_index != NO_LED) {
        HSV hsv = {.h = exit_key_hue, .s = 255, .v = 255};  // Force maximum brightness
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);
        animated_this_cycle = true;
      }
    }

    // Apply animation to the secondary exit key if defined (for Layer 1)
    if (r_exit2 != 255 && c_exit2 != 255) // r_exit2, c_exit2 are MAPPED coordinates
    {
      uint8_t led_index2 = g_led_config.matrix_co[r_exit2][c_exit2];
      if (led_index2 != NO_LED) {
        HSV hsv = {.h = exit_key_hue, .s = 255, .v = 255};  // Force maximum brightness
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(led_index2, rgb.r, rgb.g, rgb.b);
        animated_this_cycle = true; // Already true if primary animated, but safe
      }
    }

    if (animated_this_cycle)
    {
      exit_key_hue += 2; // Increment hue for next frame, speed factor of 2
    }
  }
  return true; // Allow QMK default RGB matrix processing to continue if needed
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
