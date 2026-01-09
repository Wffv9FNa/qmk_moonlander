#ifndef MYKEYS_KEYMAP_C                               // Begin include guard for this file (MYKEYS_KEYMAP_C)
#define MYKEYS_KEYMAP_C                               // Define symbol to prevent multiple inclusion of this file

// +----------+
// | INCLUDES |
// +----------+
#include QMK_KEYBOARD_H                               // Core QMK headers
#include "macros_private.h"                           // Private macros not in GIT (must be first for PRIVATE_SAFE_RANGE)
#if __has_include("keymap.h")
#include "keymap.h"                                   // Type definitions and layer enums
#endif
#include "tap_dance/tap_dance.h"                      // Tap dance actions
#include "rgb_config/rgb_config.h"                    // RGB configuration helpers
#include "rgb_config/rgb_indicators.h"                // RGB indicator logic
#include "exit_keys/exit_keys.h"                      // Exit key animation system
#include "keymap_japanese.h"                          // JP keymap definitions
#include "sendstring_uk.h"                            // Sendstring LUT Header
#ifdef AUDIO_ENABLE
#include "audio_config/audio_config.h"                // Audio configuration module
#endif

// +---------+
// | DEFINES |
// +---------+
#define MOON_LED_LEVEL LED_LEVEL                      // Alias board LED level control
#define ML_SAFE_RANGE PRIVATE_SAFE_RANGE              // Public keycodes start after private ones

// +--------------------------+
// | GLOBAL STATE & VARIABLES |
// +--------------------------+
extern bool socd_cleaner_enabled;                     // Access global SOCD enable state
bool td_layer4_activated = false;                     // Flag to track tap dance layer 4 activation

// Raw HID state - typedef is in keymap.h, included later via __has_include
rawhid_state_t rawhid_state;                          // Global instance of Raw HID state

extern rgb_config_t rgb_matrix_config;                // Global RGB matrix configuration
extern led_config_t g_led_config;                     // LED mapping for matrix coords -> indices

// +-------+
// | ENUMS |
// +-------+
enum custom_keycodes
{
  NEW_SAFE_RANGE                                      // First custom code (starts at SAFE_RANGE)
};

// +--------------------+
// | TAP DANCE ACTIONS  |
// +--------------------+
tap_dance_action_t tap_dance_actions[] = {
  [TD_TGLL_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tgll_4_finished  , NULL), // Tap-dance index for layer 4 toggle
  [TD_PMONE ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_pmone_finished   , NULL), // Tap-dance for private macro one
};

// +--------------------+
// | SOCD CONFIGURATION |
// +--------------------+
socd_cleaner_t socd_opposing_pairs[] = {
  {{KC_W, KC_S}, SOCD_CLEANER_LAST},                // Vertical pair: W vs S, prefer last input
  {{KC_A, KC_D}, SOCD_CLEANER_LAST},                // Horizontal pair: A vs D, prefer last input
};

// +---------------+
// | KEY OVERRIDES |
// +---------------+
// Change what a key sends when used with a modifier
const key_override_t nubs_key_override = ko_make_basic(MOD_MASK_CTRL, KC_NUBS, KC_GRV);  // Ctrl + NUBS = `

const key_override_t *key_overrides[] = {
    &nubs_key_override,                                                                  // Register Ctrl+NUBS override. This is a QMK array
};                                                                                       // array where we list all of our overrides.

// +---------+
// | KEYMAPS |
// +---------+
//clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*  _                             ___       _   _                       */
/* | |    __ _ _   _  ___ _ __   / _ \     | | | | ___  _ __ ___   ___  */
/* | |   / _` | | | |/ _ \ '__| | | | |    | |_| |/ _ \| '_ ` _ \ / _ \ */
/* | |__| (_| | |_| |  __/ |    | |_| |    |  _  | (_) | | | | | |  __/ */
/* |_____\__,_|\__, |\___|_|     \___/     |_| |_|\___/|_| |_| |_|\___| */
/*             |___/                                                    */
[_HM] = LAYOUT( //Home
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    TT(_HV),            TD_L4TG,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
      KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    TT(_MS),            TG(_KN),    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
      KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KC_NUBS,            KC_MEH ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
      L_SHFT ,    MT_CZ  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
      TT(_NM),    L_GUI  ,    CW_TOGG,    KC_NO  ,    TT(_WM),    /*XXXX*/    KC_ESC ,            KC_CAPS,    /*XXXX*/    TT(_NM),    KC_HYPR,    KC_LBRC,    KC_RBRC,    TT(_WM) ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_TAB ,            KC_NO  ,    KC_TAB ,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
  ),
/*  _                            _      _   _                                 _  */
/* | |    __ _ _   _  ___ _ __  / |    | \ | |_   _ _ __ ___  _ __   __ _  __| | */
/* | |   / _` | | | |/ _ \ '__| | |    |  \| | | | | '_ ` _ \| '_ \ / _` |/ _` | */
/* | |__| (_| | |_| |  __/ |    | |    | |\  | |_| | | | | | | |_) | (_| | (_| | */
/* |_____\__,_|\__, |\___|_|    |_|    |_| \_|\__,_|_| |_| |_| .__/ \__,_|\__,_| */
/*             |___/                                         |_|                 */
  [_NM] = LAYOUT( //Numpad
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_GRV ,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
      KC_DEL ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_HOME,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PAST,    KC_F12 ,
      KC_BSPC,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_MEH ,    KC_END ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_PPLS,    KC_NO  ,
      L_SHFT ,    CT_Z   ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_PSLS,    KC_1   ,    KC_2   ,    KC_3   ,    KC_PMNS,    R_SHFT ,
      TT(_NM),    L_GUI  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/    KC_NO  ,            KC_TRNS,    /*XXXX*/    TT(_NM),    KC_0   ,    KC_DOT ,    KC_EQL ,    KC_NO  ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_NO  ,            KC_NO  ,    KC_TAB ,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
  ),
/*  _                            ____          _                                */
/* | |    __ _ _   _  ___ _ __  |___ \        / \   _ __ _ __ _____      _____  */
/* | |   / _` | | | |/ _ \ '__|   __) |      / _ \ | '__| '__/ _ \ \ /\ / / __| */
/* | |__| (_| | |_| |  __/ |     / __/      / ___ \| |  | | | (_) \ V  V /\__ \ */
/* |_____\__,_|\__, |\___|_|    |_____|    /_/   \_\_|  |_|  \___/ \_/\_/ |___/ */
/*             |___/                                                            */
  [_WM] = LAYOUT( // WordMon + Arrows
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      QK_BOOT,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
      KC_NO  ,    TD_PONE,    SELWBK ,    CS_X   ,    SELWRD ,    KC_NO  ,    KC_NO  ,            KC_PGUP,    KC_HOME,    MINWIN ,    KC_UP  ,    MAXWIN ,    KC_NO  ,    KC_F12 ,
      CT_BSPC,    KC_NO  ,    S_LEFT ,    GC_Y   ,    S_RGHT ,    KC_NO  ,    KC_NO  ,            KC_PGDN,    KC_END ,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO  ,    KC_NO  ,
      L_SHFT ,    KC_NO  ,    CT_LEFT,    SELINE ,    CT_RGHT,    KC_NO  ,    /*XXXX*/            /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    R_SHFT ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(_WM),    /*XXXX*/    KC_NO  ,            KC_NO  ,    /*XXXX*/    KC_TRNS,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(_WM),
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO       /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
),
/*  _                            _____      __  __                       */
/* | |    __ _ _   _  ___ _ __  |___ /     |  \/  | ___  _   _ ___  ___  */
/* | |   / _` | | | |/ _ \ '__|   |_ \     | |\/| |/ _ \| | | / __|/ _ \ */
/* | |__| (_| | |_| |  __/ |     ___) |    | |  | | (_) | |_| \__ \  __/ */
/* |_____\__,_|\__, |\___|_|    |____/     |_|  |_|\___/ \__,_|___/\___| */
/*             |___/                                                     */
  [_MS] = LAYOUT( //Mouse
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_DEL ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(_MS),            KC_NO  ,    OM_W_U ,    OM_BTNS,    OM_U   ,    OM_DBLS,    KC_NO  ,    KC_NO  ,
      KC_BSPC,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    OM_W_D ,    OM_L   ,    OM_D   ,    OM_R   ,    OM_SLOW,    KC_NO  ,
      L_SHFT ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/            /*XXXX*/    OM_RELS,    OM_HLDS,    OM_SEL1,    OM_SEL2,    OM_SEL3,    R_SHFT ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/    KC_ESC ,            KC_CAPS,    /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_NO  ,            KC_NO  ,    KC_TAB ,    KC_NO       /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
  ),
/*  _                            _  _         ____                            */
/* | |    __ _ _   _  ___ _ __  | || |       / ___| __ _ _ __ ___   ___  ___  */
/* | |   / _` | | | |/ _ \ '__| | || |_     | |  _ / _` | '_ ` _ \ / _ \/ __| */
/* | |__| (_| | |_| |  __/ |    |__   _|    | |_| | (_| | | | | | |  __/\__ \ */
/* |_____\__,_|\__, |\___|_|       |_|       \____|\__,_|_| |_| |_|\___||___/ */
/*             |___/                                                          */
      [_GM] = LAYOUT( // Gaming Layer
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    SOCDTG ,            TD_L4TG,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
      KC_ESC ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    KC_MEH ,            KC_HOME,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
      KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    TT(_FN),            KC_END ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
      L_SHFT ,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_UP  ,    R_SHFT  ,
      L_CTRL ,    KC_F5  ,    KC_I   ,    KC_M   ,    TURBO  ,    /*XXXX*/    KC_ESC ,            KC_CAPS,    /*XXXX*/    KC_HYPR,    KC_NO  ,    KC_LEFT,    KC_DOWN,    KC_RGHT ,
      /*XXXXX*/   /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    KC_TAB ,    L_ALT  ,            L_GUI  ,    KC_BSPC,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
  ),

/*  _                            ____       _  __                  */
/* | |    __ _ _   _  ___ _ __  | ___|     | |/ /__ _ _ __   __ _  */
/* | |   / _` | | | |/ _ \ '__| |___ \     | ' // _` | '_ \ / _` | */
/* | |__| (_| | |_| |  __/ |     ___) |    | . \ (_| | | | | (_| | */
/* |_____\__,_|\__, |\___|_|    |____/     |_|\_\__,_|_| |_|\__,_| */
/*             |___/                                               */
  [_KN] = LAYOUT( //Kana Layer
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    KC_NO  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
      KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    HIRAG  ,            TG(_KN),    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
      KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KATAK  ,            KC_MEH ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
      L_SHFT ,    MT_CZ  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
      TT(_NM),    L_GUI  ,    IME_TOG,    KC_NO  ,    TT(_WM),    /*XXXX*/    KC_ESC,             KC_CAPS,    /*XXXX*/    TT(_NM),    KC_HYPR,    KC_LBRC,    KC_RBRC,    TT(_WM) ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_F13 ,            KC_NO  ,    KC_TAB ,    KC_ENT     /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
),

/*  _                             __     ____   ____ ____   */
/* | |    __ _ _   _  ___ _ __   / /_   |  _ \ / ___| __ )  */
/* | |   / _` | | | |/ _ \ '__| | '_ \  | |_) | |  _|  _ \  */
/* | |__| (_| | |_| |  __/ |    | (_) | |  _ <| |_| | |_) | */
/* |_____\__,_|\__, |\___|_|     \___/  |_| \_\\____|____/  */
/*             |___/                                        */
  [_HV] = LAYOUT( // HSV Color Display Layer
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(_HV),            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,                                    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,                KC_NO  ,            KC_NO  ,                KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
                                                      KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO
  ),

/*  _                            _____   _____                 _   _              */
/* | |    __ _ _   _  ___ _ __  |___  | |  ___|   _ _ __   ___| |_(_) ___  _ __   */
/* | |   / _` | | | |/ _ \ '__|    / /  | |_ | | | | '_ \ / __| __| |/ _ \| '_ \  */
/* | |__| (_| | |_| |  __/ |      / /   |  _|| |_| | | | | (__| |_| | (_) | | | | */
/* |_____\__,_|\__, |\___|_|     /_/    |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_| */
/*             |___/                                                              */
  [_FN]=LAYOUT( // Function Keys Layer
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
    KC_GRV ,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_TRNS,            KC_TRNS,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_F12 ,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    TT(_FN),            KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                                    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,                KC_TRNS,            KC_TRNS,                KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                                    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,    KC_TRNS,    KC_TRNS
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

// Tap dance handler for private macro one
void td_pmone_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 2 && !state->pressed) { // Double tap
        private_macro_one();
    }
}

void keyboard_post_init_user(void) // Keyboard post initialization handler
{
    rgb_matrix_enable();           // Enable RGB matrix lighting after keyboard initialization
#ifdef AUDIO_ENABLE
    if (!is_audio_on()) {
        audio_on();                // Enable audio if it was disabled in EEPROM
    }
    audio_config_init();           // Play startup song (works around DAC timing issues)
#endif
}

// --- RGB Indicator Function ---

bool rgb_matrix_indicators_user(void)
{
    return update_rgb_indicators();                   // Delegate to RGB indicators module
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  bool socd_handled = process_record_socd_cleaner(keycode, record); // First let the SOCD cleaner process the key (handles opposite direction inputs)
  if (!socd_handled)                                                // If SOCD cleaner blocked the input
  {
    return false;                                                   // Stop processing this key event
  }

  if (!process_record_secrets(keycode, record)) {  // Process private macros
    return false;
  }

#ifdef AUDIO_ENABLE
  if (!process_record_audio(keycode, record)) {
    return false;
  }
#endif

  switch (keycode)                                                  // Handle specific keycodes
  {
  case SOCDTOG:                                                     // SOCD toggle key (toggles SOCD cleaning on/off)
    return true;                                                    // Let QMK handle the default SOCDTOG behavior
  }

  return true;                                                      // Default: process all other keycodes normally
}

layer_state_t layer_state_set_user(layer_state_t state) // Layer change event handler
{
#ifdef AUDIO_ENABLE
  state = layer_state_audio(state);
#endif
  return state;                                     // Always return the updated layer state
}

#ifdef OTHER_KEYMAP_C                               // If OTHER_KEYMAP_C is defined, pull in that keymap file
#include OTHER_KEYMAP_C                             // Include the alternate or extended keymap definition
#endif                                              // End conditional inclusion of OTHER_KEYMAP_C

#endif                                              // End include guard for this file (MYKEYS_KEYMAP_C)
