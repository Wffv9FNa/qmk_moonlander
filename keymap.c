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
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
        KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    KC_NO  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
        KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    TT(2)  ,            KC_NO  ,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
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
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
        KC_GRV ,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_DEL ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_HOME,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PAST,    KC_F12 ,
        KC_BSPC,    KC_NO  ,    CT_S   ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NUBS,            KC_MEH ,    KC_END ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_PPLS,    KC_NO  ,
        L_SHFT ,    CT_Z   ,    KC_NO  ,    CT_C   ,    CT_V   ,    KC_NO  ,    /*XXXX*/            /*XXXX*/    KC_PSLS,    KC_1   ,    KC_2   ,    KC_3   ,    KC_PMNS,    R_SHFT ,
        TT(1)  ,    L_GUI  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/    KC_NO  ,            KC_TRNS,    /*XXXX*/    TT(1)  ,    KC_0   ,    KC_PDOT,    KC_PEQL,    KC_NO  ,
        /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_NO  ,            KC_NO  ,    KC_TAB ,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
    ),
/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  |___ \  */
/* | |   / _` | | | |/ _ \ '__|   __) | */
/* | |__| (_| | |_| |  __/ |     / __/  */
/* |_____\__,_|\__, |\___|_|    |_____| */
/*             |___/                    */
    [2] = LAYOUT( //Mouse
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
        KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        KC_DEL ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(2)  ,            KC_NO  ,    OM_W_U ,    OM_BTNS,    OM_U   ,    OM_DBLS,    KC_NO  ,    KC_NO  ,
        KC_BSPC,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    OM_W_D ,    OM_L   ,    OM_D   ,    OM_R   ,    OM_SLOW,    KC_NO  ,
        L_SHFT ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/            /*XXXX*/    OM_RELS,    OM_HLDS,    OM_SEL1,    OM_SEL2,    OM_SEL3,    R_SHFT ,
        KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/    KC_ESC ,            KC_CAPS,    /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
        /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_NO  ,            KC_NO  ,    KC_TAB ,    KC_NO       /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
    ),
/*  _                            _____  */
/* | |    __ _ _   _  ___ _ __  |___ /  */
/* | |   / _` | | | |/ _ \ '__|   |_ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [3] = LAYOUT( // WordMon + Arrows
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
        QK_BOOT,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
        KC_NO  ,    KC_NO  ,    SELWBK ,    CS_X   ,    SELWRD ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_HOME,    MINWIN ,    KC_UP  ,    MAXWIN ,    KC_NO  ,    KC_F12 ,
        CT_BSPC,    KC_NO  ,    S_LEFT ,    GC_Y   ,    S_RGHT ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_END ,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO  ,    KC_NO  ,
        KC_NO  ,    KC_NO  ,    CT_LEFT,    SELINE ,    CT_RGHT,    KC_NO  ,    /*XXXX*/            /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
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
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
        KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_F10 ,    KC_F11  ,
        KC_NO  ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    KC_NO  ,            KC_HOME,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_F12  ,
        KC_ESC ,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KC_NO  ,            KC_END ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
        L_SHFT ,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
        L_CTRL ,    KC_NO  ,    KC_NO  ,    TD_L4TG,    TURBO  ,    /*XXXX*/    SOCDTG ,            KC_CAPS,    /*XXXX*/    KC_HYPR,    KC_NO  ,    KC_LBRC,    KC_RBRC,    KC_NO   ,
        /*XXXXX*/   /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    KC_TAB ,    L_ALT  ,            L_GUI  ,    KC_NO  ,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
    ),

/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  | ___|  */
/* | |   / _` | | | |/ _ \ '__| |___ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [5] = LAYOUT( //Kana Layer
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
        KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    KC_NO  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
        KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    HIRAG  ,            KC_NO  ,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
        KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KATAK  ,            KC_MEH ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
        L_SHFT ,    MT_CZ  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
        KC_NO  ,    L_GUI  ,    CW_TOGG,    KC_NO  ,    IME_TOG,    /*XXXX*/    KC_CAPS,            KC_CAPS,    /*XXXX*/    KC_NO  ,    KC_HYPR,    KC_LBRC,    KC_RBRC,    KC_NO   ,
        /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_F13 ,            TG(5)  ,    KC_TAB ,    KC_ENT     /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
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
 * This function:
 * 1. Shows layer-specific colours for all keys using set_layer_color()
 * 2. Animates exit keys (the keys that got you to the current layer)
 * 3. Provides visual feedback for Caps Lock state
 * 4. Integrates with the custom RGB configuration system
 *
 * The exit key animation system helps users understand how to navigate
 * between layers by highlighting the "way back" keys with animated colours.
 *
 * COORDINATE SYSTEM:
 * The Moonlander uses a 12x7 matrix layout where:
 * - Rows 0-5: Left half of keyboard
 * - Rows 6-11: Right half of keyboard
 * - Columns 0-6: Keys from left to right on each half
 * - Some positions are empty (NO_LED) due to the split design
 *
 * @return true to allow QMK default RGB matrix processing to continue
 */
bool rgb_matrix_indicators_user(void)
{
  // FUNCTION STRUCTURE:
  // 1. Check for external RGB control or disabled LEDs
  // 2. Handle Caps Lock override (red all keys)
  // 3. Apply base layer colours
  // 4. Animate exit keys with rainbow effect
  // 5. Update animation timing

  // Check if external RGB control is active (e.g., from host software)
  if (rawhid_state.rgb_control)
  {
    return false; // Let external control handle RGB
  }

  // Check if layer LED indicators are disabled in keyboard config
  if (keyboard_config.disable_layer_led)
  {
    return false; // Don't show layer colours
  }

  // Get the currently active layer (highest priority layer)
  uint8_t current_layer = biton32(layer_state);

  // Static variable to track animation progress across function calls
  // This creates a continuous rainbow effect on exit keys
  static uint8_t exit_key_hue = 0; // Hue for animating layer exit keys

  // Flag to track if we animated any exit keys this cycle
  // Used to determine if we should update the hue for next frame
  bool animated_this_cycle = false;

  // CAPS LOCK VISUAL FEEDBACK
  // When Caps Lock is active, override all other RGB effects with red
  // This provides immediate visual feedback that caps are on
  if (host_keyboard_led_state().caps_lock)
  {
    // Override all keys with bright red to clearly indicate Caps Lock state
    // This takes priority over layer colours and exit key animations
    rgb_matrix_set_color_all(255, 0, 0);  // Full brightness red for Caps Lock
    return true; // Exit early - no need for layer colours or animations
  }
  else
  {
    // LAYER COLOUR SYSTEM
    // First, apply the base colours for the current layer
    // This sets the overall colour scheme for all keys on this layer
    set_layer_color(current_layer);

    // EXIT KEY ANIMATION SYSTEM
    // Exit keys are the keys that got you to the current layer (TT(x) or TG(x))
    // We animate these keys to help users understand how to navigate back
    //
    // Coordinate system: [row][col] in the 12x7 Moonlander matrix
    // Magic number 255 is used as a "no exit key" marker since valid coordinates
    // are 0-11 for rows and 0-6 for columns, so 255 is safely out of range
    uint8_t r_exit = 255, c_exit = 255;   // Primary exit key position
    uint8_t r_exit2 = 255, c_exit2 = 255; // Secondary exit key (for layers with multiple entry points)

    // LAYER-SPECIFIC EXIT KEY MAPPING
    // Each layer defines where its exit keys are located in the matrix
    // These coordinates correspond to the physical positions of TT(x) or TG(x) keys
    switch (current_layer)
    {
    case 0:
      // Base layer has no exit keys (it's the destination, not a layer you enter)
      break;

    case 1: // Numpad layer
      // Layer 1 has two TT(1) keys for easy access from both sides
      r_exit = 4; c_exit = 0;    // Left TT(1) -> Left thumb cluster [4][0]
      r_exit2 = 10; c_exit2 = 2; // Right TT(1) -> Right thumb cluster [10][2]
      break;

    case 2: // Mouse layer
      // Single TT(2) key on the left side
      r_exit = 1; c_exit = 6;    // TT(2) -> Top right of left half [1][6]
      break;

    case 3: // WordMon + Arrows layer
      // Layer 3 has two TT(3) keys for ambidextrous access
      r_exit = 4; c_exit = 4;    // Left TT(3) -> Left thumb cluster [4][4]
      r_exit2 = 10; c_exit2 = 6; // Right TT(3) -> Right thumb cluster [10][6]
      break;

    case 4: // Gaming layer
      // Single TD_L4TG key (tap dance layer 4 toggle)
      r_exit = 4; c_exit = 3;    // TD_L4TG -> Left thumb cluster [4][3]
      break;

    case 5: // Kana layer
      // Single TG(5) key (toggle layer 5)
      r_exit = 11; c_exit = 4;   // TG(5) -> Right thumb cluster [11][4]
      break;

    default:
      // For any future layers not explicitly handled here
      // The set_layer_color() function will still apply base colours
      break;
    }

    // PRIMARY EXIT KEY ANIMATION
    // Apply rainbow animation to the main exit key for this layer
    if (r_exit != 255 && c_exit != 255) // Check if this layer has a primary exit key
    {
      // Convert matrix coordinates to LED index using QMK's LED mapping
      // g_led_config.matrix_co[row][col] returns the physical LED index
      uint8_t led_index = g_led_config.matrix_co[r_exit][c_exit];

      if (led_index != NO_LED) { // Check if there's actually an LED at this position
        // Create HSV colour with current hue, full saturation, full brightness
        // This ensures the animated key is always visible and colourful
        HSV hsv = {.h = exit_key_hue, .s = 255, .v = 255};

        // Convert HSV to RGB for the LED matrix
        RGB rgb = hsv_to_rgb(hsv);

        // Apply the animated colour to the specific LED
        rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);

        // Mark that we animated something this cycle
        animated_this_cycle = true;
      }
    }

    // SECONDARY EXIT KEY ANIMATION (for layers with multiple entry points)
    // Some layers (like Layer 1) have two ways to access them
    // We animate both exit keys to show all possible ways back
    if (r_exit2 != 255 && c_exit2 != 255) // Check if this layer has a secondary exit key
    {
      // Same process as primary exit key
      uint8_t led_index2 = g_led_config.matrix_co[r_exit2][c_exit2];

      if (led_index2 != NO_LED) {
        // Use the same hue value for both keys to keep them in sync
        HSV hsv = {.h = exit_key_hue, .s = 255, .v = 255};
        RGB rgb = hsv_to_rgb(hsv);
        rgb_matrix_set_color(led_index2, rgb.r, rgb.g, rgb.b);

        // Mark that we animated something this cycle
        // Note: This is already true if primary animated, but setting it again is safe
        animated_this_cycle = true;
      }
    }

    // ANIMATION TIMING AND PROGRESSION
    // Only update the hue if we actually animated something this cycle
    // This prevents unnecessary hue changes when no exit keys are visible
    if (animated_this_cycle)
    {
      // Increment hue by 2 degrees for next frame
      // At 60fps, this creates a smooth rainbow effect that cycles through
      // the full colour spectrum in about 3 seconds (360 / 2 * 60fps)
      exit_key_hue += 2;
    }
  }

  // Return true to allow QMK's default RGB matrix effects to continue
  // This enables additional effects like breathing, reactive typing, etc.
  // while maintaining our custom layer and exit key system
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
