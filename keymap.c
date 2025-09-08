#ifndef MYKEYS_KEYMAP_C                               // Begin include guard for this file (MYKEYS_KEYMAP_C)
#define MYKEYS_KEYMAP_C                               // Define symbol to prevent multiple inclusion of this file

// +----------+
// | INCLUDES |
// +----------+
#include QMK_KEYBOARD_H                               // Core QMK headers
#include "audio.h"                                    // Audio feature interface
#include "user_song_list.h"                           // User-defined song data
#include "tap_dance/tap_dance.h"                      // Tap dance actions
#include "rgb_config/rgb_config.h"                    // RGB configuration helpers
#include "keymap_japanese.h"                          // JP keymap definitions
#include "sendstring_uk.h"                            // Sendstring LUT Header
#include "macros_private.h"                           // Private macros not in GIT

// +---------+
// | DEFINES |
// +---------+
#define MOON_LED_LEVEL LED_LEVEL                      // Alias board LED level control
#define ML_SAFE_RANGE PRIVATE_SAFE_RANGE              // Public keycodes start after private ones

// +--------------------------+
// | GLOBAL STATE & VARIABLES |
// +--------------------------+
extern bool socd_cleaner_enabled;                     // Access global SOCD enable state

#ifdef AUDIO_ENABLE
float caps_on_song[][2] = SONG(CAPS_ON_SOUND);        // Audio pattern when Caps Lock turns on
float caps_off_song[][2] = SONG(CAPS_OFF_SOUND);      // Audio pattern when Caps Lock turns off
float overwatch_song[][2] = SONG(OVERWATCH_THEME);    // Overwatch theme to play on layer event
#endif

typedef struct                                        // Raw HID state shared with host
{
  bool rgb_control;                                   // When true, host owns RGB control
} rawhid_state_t;

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

#if __has_include("keymap.h")
#include "keymap.h"                                   // Optional per-user/per-layout overrides
#endif

// +--------------------+
// | TAP DANCE ACTIONS  |
// +--------------------+
tap_dance_action_t tap_dance_actions[] = {
  [TD_TGLL_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tgll_4_finished  , NULL), // Tap-dance index for layer 4 toggle
  [TD_1_F1  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 1 -> F1
  [TD_2_F2  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 2 -> F2
  [TD_3_F3  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 3 -> F3
  [TD_4_F4  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 4 -> F4
  [TD_5_F5  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 5 -> F5
  [TD_6_F6  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 6 -> F6
  [TD_7_F7  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 7 -> F7
  [TD_8_F8  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 8 -> F8
  [TD_9_F9  ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 9 -> F9
  [TD_0_F10 ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_num_fkey_finished, NULL), // Tap-dance index for 0 -> F10
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
[0] = LAYOUT( //Home
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    TT(6)  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
      KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    TT(3)  ,            KC_NO  ,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
      KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KC_NUBS,            KC_MEH ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
      L_SHFT ,    MT_CZ  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
      TT(1)  ,    L_GUI  ,    CW_TOGG,    TD_L4TG,    TT(2)  ,    /*XXXX*/    KC_ESC ,            KC_CAPS,    /*XXXX*/    TT(1)  ,    KC_HYPR,    KC_LBRC,    KC_RBRC,    TT(2)   ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_F13 ,            TG(5)  ,    KC_TAB ,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
  ),
/*  _                            _      _   _                                 _  */
/* | |    __ _ _   _  ___ _ __  / |    | \ | |_   _ _ __ ___  _ __   __ _  __| | */
/* | |   / _` | | | |/ _ \ '__| | |    |  \| | | | | '_ ` _ \| '_ \ / _` |/ _` | */
/* | |__| (_| | |_| |  __/ |    | |    | |\  | |_| | | | | | | |_) | (_| | (_| | */
/* |_____\__,_|\__, |\___|_|    |_|    |_| \_|\__,_|_| |_| |_| .__/ \__,_|\__,_| */
/*             |___/                                         |_|                 */
  [1] = LAYOUT( //Numpad
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_GRV ,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
      KC_DEL ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_HOME,    KC_7   ,    KC_8   ,    KC_9   ,    KC_PAST,    KC_F12 ,
      KC_BSPC,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NUBS,            KC_MEH ,    KC_END ,    KC_4   ,    KC_5   ,    KC_6   ,    KC_PPLS,    KC_NO  ,
      L_SHFT ,    CT_Z   ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/            /*XXXX*/    KC_PSLS,    KC_1   ,    KC_2   ,    KC_3   ,    KC_PMNS,    R_SHFT ,
      TT(1)  ,    L_GUI  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    /*XXXX*/    KC_NO  ,            KC_TRNS,    /*XXXX*/    TT(1)  ,    KC_0   ,    KC_DOT ,    KC_EQL ,    KC_NO  ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_NO  ,            KC_NO  ,    KC_TAB ,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
  ),
/*  _                            ____          _                                */
/* | |    __ _ _   _  ___ _ __  |___ \        / \   _ __ _ __ _____      _____  */
/* | |   / _` | | | |/ _ \ '__|   __) |      / _ \ | '__| '__/ _ \ \ /\ / / __| */
/* | |__| (_| | |_| |  __/ |     / __/      / ___ \| |  | | | (_) \ V  V /\__ \ */
/* |_____\__,_|\__, |\___|_|    |_____|    /_/   \_\_|  |_|  \___/ \_/\_/ |___/ */
/*             |___/                                                            */
  [2] = LAYOUT( // WordMon + Arrows
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      QK_BOOT,    KC_F1  ,    KC_F2  ,    KC_F3  ,    KC_F4  ,    KC_F5  ,    KC_NO  ,            KC_NO  ,    KC_F6  ,    KC_F7  ,    KC_F8  ,    KC_F9  ,    KC_F10 ,    KC_F11 ,
      KC_NO  ,    P_CITRIX,    SELWBK ,    CS_X   ,    SELWRD ,    KC_NO  ,    KC_NO  ,            KC_PGUP,    KC_HOME,    MINWIN ,    KC_UP  ,    MAXWIN ,    KC_NO  ,    KC_F12 ,
      CT_BSPC,    KC_NO  ,    S_LEFT ,    GC_Y   ,    S_RGHT ,    KC_NO  ,    KC_NO  ,            KC_PGDN,    KC_END ,    KC_LEFT,    KC_DOWN,    KC_RGHT,    KC_NO  ,    KC_NO  ,
      L_SHFT ,    KC_NO  ,    CT_LEFT,    SELINE ,    CT_RGHT,    KC_NO  ,    /*XXXX*/            /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    R_SHFT ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(2)  ,    /*XXXX*/    KC_NO  ,            KC_NO  ,    /*XXXX*/    KC_TRNS,    SOCDTG ,    KC_NO  ,    KC_NO  ,    TT(2)  ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO       /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
),
/*  _                            _____      __  __                       */
/* | |    __ _ _   _  ___ _ __  |___ /     |  \/  | ___  _   _ ___  ___  */
/* | |   / _` | | | |/ _ \ '__|   |_ \     | |\/| |/ _ \| | | / __|/ _ \ */
/* | |__| (_| | |_| |  __/ |     ___) |    | |  | | (_) | |_| \__ \  __/ */
/* |_____\__,_|\__, |\___|_|    |____/     |_|  |_|\___/ \__,_|___/\___| */
/*             |___/                                                     */
  [3] = LAYOUT( //Mouse
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_DEL ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(3)  ,            KC_NO  ,    OM_W_U ,    OM_BTNS,    OM_U   ,    OM_DBLS,    KC_NO  ,    KC_NO  ,
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
      [4] = LAYOUT( // Gaming Layer
    /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_EQL ,    TD_1F1 ,    TD_2F2 ,    TD_3F3 ,    TD_4F4 ,    TD_5F5 ,    KC_NO  ,            SOCDTG ,    TD_6F6 ,    TD_7F7 ,    TD_8F8 ,    TD_9F9 ,    TD_0F10,    KC_F11  ,
      KC_NO  ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    KC_NO  ,            KC_HOME,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_F12  ,
      KC_ESC ,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KC_NO  ,            KC_END ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
      L_SHFT ,    KC_Z   ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
      L_CTRL ,    KC_NO  ,    KC_NO  ,    TD_L4TG,    TURBO  ,    /*XXXX*/    KC_ESC ,            KC_CAPS,    /*XXXX*/    KC_HYPR,    KC_NO  ,    KC_LBRC,    KC_RBRC,    KC_NO   ,
      /*XXXXX*/   /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    KC_TAB ,    L_ALT  ,            L_GUI  ,    KC_NO  ,    KC_ENT      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
  ),

/*  _                            ____       _  __                  */
/* | |    __ _ _   _  ___ _ __  | ___|     | |/ /__ _ _ __   __ _  */
/* | |   / _` | | | |/ _ \ '__| |___ \     | ' // _` | '_ \ / _` | */
/* | |__| (_| | |_| |  __/ |     ___) |    | . \ (_| | | | | (_| | */
/* |_____\__,_|\__, |\___|_|    |____/     |_|\_\__,_|_| |_|\__,_| */
/*             |___/                                               */
  [5] = LAYOUT( //Kana Layer
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_EQL ,    KC_1   ,    KC_2   ,    KC_3   ,    KC_4   ,    KC_5   ,    KC_NO  ,            KC_NO  ,    KC_6   ,    KC_7   ,    KC_8   ,    KC_9   ,    KC_0   ,    KC_MINS ,
      KC_DEL ,    KC_Q   ,    KC_W   ,    KC_E   ,    KC_R   ,    KC_T   ,    HIRAG  ,            KC_NO  ,    KC_Y   ,    KC_U   ,    KC_I   ,    KC_O   ,    KC_P   ,    KC_BSLS ,
      KC_BSPC,    KC_A   ,    KC_S   ,    KC_D   ,    KC_F   ,    KC_G   ,    KATAK  ,            KC_MEH ,    KC_H   ,    KC_J   ,    KC_K   ,    KC_L   ,    KC_SCLN,    KC_QUOTE,
      L_SHFT ,    MT_CZ  ,    KC_X   ,    KC_C   ,    KC_V   ,    KC_B   ,    /*XXXX*/            /*XXXX*/    KC_N   ,    KC_M   ,    KC_COMM,    KC_DOT ,    KC_SLSH,    R_SHFT  ,
      KC_NO  ,    L_GUI  ,    CW_TOGG,    KC_NO  ,    IME_TOG,    /*XXXX*/    KC_ESC,             KC_CAPS,    /*XXXX*/    KC_NO  ,    KC_HYPR,    KC_LBRC,    KC_RBRC,    KC_NO   ,
      /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/    KC_SPC ,    L_ALT  ,    KC_F13 ,            TG(5)  ,    KC_TAB ,    KC_ENT     /*XXXX*/    /*XXXX*/    /*XXXX*/    /*XXXX*/
),

/*  _                            __           ____   ____ ____  */
/* | |    __ _ _   _  ___ _ __  / /_         / ___|/ ___|  _ \ */
/* | |   / _` | | | |/ _ \ '__| | '_ \       | |  _| |   | |_) | */
/* | |__| (_| | |_| |  __/ |    | (_) |      | |_| | |___| |_) | */
/* |_____\__,_|\__, |\___|_|     \___/        \____|\____|____/ */
/*             |___/                                           */
  [6] = LAYOUT( // HSV Color Display Layer
  /*  =           1           2           3           4           5           ---                 ---         6           7           8           9           0           ---       */
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    TT(6)  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,                                    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
      KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,                KC_NO  ,            KC_NO  ,                KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,    KC_NO  ,
                                                      KC_NO  ,    KC_NO  ,    KC_NO  ,            KC_NO  ,    KC_NO  ,    KC_NO
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
void init_td_num_user_data(void) { // Initialize tap dance user data
    tap_dance_actions[TD_1_F1 ].user_data = (void *)&TD_NUM_MAP[0]; // "1" / F1
    tap_dance_actions[TD_2_F2 ].user_data = (void *)&TD_NUM_MAP[1]; // "2" / F2
    tap_dance_actions[TD_3_F3 ].user_data = (void *)&TD_NUM_MAP[2]; // "3" / F3
    tap_dance_actions[TD_4_F4 ].user_data = (void *)&TD_NUM_MAP[3]; // "4" / F4
    tap_dance_actions[TD_5_F5 ].user_data = (void *)&TD_NUM_MAP[4]; // "5" / F5
    tap_dance_actions[TD_6_F6 ].user_data = (void *)&TD_NUM_MAP[5]; // "6" / F6
    tap_dance_actions[TD_7_F7 ].user_data = (void *)&TD_NUM_MAP[6]; // "7" / F7
    tap_dance_actions[TD_8_F8 ].user_data = (void *)&TD_NUM_MAP[7]; // "8" / F8
    tap_dance_actions[TD_9_F9 ].user_data = (void *)&TD_NUM_MAP[8]; // "9" / F9
    tap_dance_actions[TD_0_F10].user_data = (void *)&TD_NUM_MAP[9]; // "0" / F10
}

void keyboard_post_init_user(void) // Keyboard post initialization handler
{
    rgb_matrix_enable();           // Enable RGB matrix lighting after keyboard initialization
    init_td_num_user_data();       // Initialize tap dance user data
}

bool rgb_matrix_indicators_user(void) // RGB matrix indicators handler
{
  // FUNCTION STRUCTURE:
  //  1. Check for external RGB control or disabled LEDs
  //  2. Handle Caps Lock override (red all keys)
  //  3. Apply base layer colours
  //  4. Animate exit keys with rainbow effect
  //  5. Update animation timing
  // COORDINATE SYSTEM:
  //  The Moonlander uses a 12x7 matrix layout where:
  //  - Rows 0-5: Left half of keyboard
  //  - Rows 6-11: Right half of keyboard
  //  - Columns 0-6: Keys from left to right on each half
  //  - Some positions are empty (NO_LED) due to the split design


  if (rawhid_state.rgb_control)                     // Check if external RGB control is active (e.g., from host software)
  {
    return false;                                   // Let external control handle RGB
  }

  if (keyboard_config.disable_layer_led)            // Check if layer LED indicators are disabled in keyboard config
  {
    return false;                                   // Don't show layer colours
  }

  uint8_t current_layer = biton32(layer_state);     // Get the currently active layer (highest priority layer)

  static uint8_t exit_key_hue = 0;                  // Static variable to track animation progress across function calls (continuous rainbow effect on exit keys)
  bool animated_this_cycle = false;                 // Flag to track if we animated any exit keys this cycle (decides hue update)

  if (host_keyboard_led_state().caps_lock)          // CAPS LOCK VISUAL FEEDBACK: When active, override all effects with red
  {
    rgb_matrix_set_color_all(255, 0, 0);            // Override all keys with bright red to clearly indicate Caps Lock state
    return true;                                    // Exit early - no need for layer colours or animations
  }
  else
  {
    set_layer_color(current_layer);                 // LAYER COLOUR SYSTEM: Apply the base colours for the current layer

    uint8_t r_exit = 255, c_exit = 255;             // Primary exit key position (255 means "no exit key")
    uint8_t r_exit2 = 255, c_exit2 = 255;           // Secondary exit key position (for multiple entry points)

    switch (current_layer)                          // LAYER-SPECIFIC EXIT KEY MAPPING
    {
    case 0:                                         // Base layer has no exit keys (it's the destination layer)
      break;
    case 1:                                         // Numpad layer: two TT(1) keys for access
      r_exit = 4;  c_exit = 0;                      // Left TT(1) -> Left thumb cluster [4][0]
      r_exit2 = 10; c_exit2 = 2;                    // Right TT(1) -> Right thumb cluster [10][2]
      break;
    case 2:                                         // WordMon + Arrows layer: two TT(3) keys
      r_exit = 4;  c_exit = 4;                      // Left TT(3) -> Left thumb cluster [4][4]
      r_exit2 = 10; c_exit2 = 6;                    // Right TT(3) -> Right thumb cluster [10][6]
      break;
    case 3:                                         // Mouse layer: single TT(2) key
      r_exit = 1;  c_exit = 6;                      // TT(2) -> Top right of left half [1][6]
      break;
    case 4:                                         // Gaming layer: single TD_L4TG key
      r_exit = 4;  c_exit = 3;                      // TD_L4TG -> Left thumb cluster [4][3]
      break;
    case 5:                                         // Kana layer: single TG(5) key
      r_exit = 11; c_exit = 4;                      // TG(5) -> Right thumb cluster [11][4]
      break;
        case 6:                                     // HSV Color Display layer: single TT(6) key
      r_exit = 0; c_exit = 6;                       // TT(6) -> Top row [0][6]
      break;
    default:                                        // Future/unhandled layers still get base colours
      break;
    }

    if (r_exit != 255 && c_exit != 255)             // PRIMARY EXIT KEY ANIMATION: Apply rainbow animation if primary exit key exists
    {
      uint8_t led_index = g_led_config.matrix_co[r_exit][c_exit]; // Convert matrix coords to LED index
      if (led_index != NO_LED) {                                  // Check if LED actually exists at this position
        HSV hsv = {.h = exit_key_hue, .s = 255, .v = 255};        // Create HSV colour with current hue, full saturation, full brightness
        RGB rgb = hsv_to_rgb(hsv);                                // Convert HSV to RGB for LED matrix
        rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);     // Apply animated colour to LED
        animated_this_cycle = true;                               // Mark animation happened
      }
    }

    if (r_exit2 != 255 && c_exit2 != 255)           // SECONDARY EXIT KEY ANIMATION: Apply rainbow if secondary exit key exists
    {
      uint8_t led_index2 = g_led_config.matrix_co[r_exit2][c_exit2]; // Convert coords to LED index
      if (led_index2 != NO_LED) {
        HSV hsv = {.h = exit_key_hue, .s = 255, .v = 255};            // Use same hue as primary to keep animation synced
        RGB rgb = hsv_to_rgb(hsv);                                    // Convert HSV to RGB
        rgb_matrix_set_color(led_index2, rgb.r, rgb.g, rgb.b);        // Apply animated colour
        animated_this_cycle = true;                                   // Mark animation happened
      }
    }

    if (animated_this_cycle)                        // ANIMATION TIMING: Only update hue if we animated this cycle
    {
      exit_key_hue += 2;                            // Increment hue by 2 for next frame (~3 sec full cycle at 60fps)
    }
  }

  return true;                                      // Allow QMK's default RGB matrix effects (breathing, reactive, etc.)
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

  switch (keycode)                                                  // Handle specific keycodes
  {
  case KC_CAPS:                                                     // Caps Lock key pressed
    if (record->event.pressed)                                      // Only trigger on press (not release)
    {
      bool new_caps_state = !host_keyboard_led_state().caps_lock;   // Toggle Caps Lock state manually
#ifdef AUDIO_ENABLE
      if (new_caps_state)                                           // If Caps Lock just turned ON
      {
        PLAY_SONG(caps_on_song);                                    // Play "Caps On" sound for feedback
      }
      else                                                          // Otherwise, Caps Lock turned OFF
      {
        PLAY_SONG(caps_off_song);                                   // Play "Caps Off" sound for feedback
      }
#endif
    }
    return true;                                                    // Allow further processing of Caps Lock key

  case SOCDTOG:                                                     // SOCD toggle key (toggles SOCD cleaning on/off)
    return true;                                                    // Let QMK handle the default SOCDTOG behavior
  }

  return true;                                                      // Default: process all other keycodes normally
}

layer_state_t layer_state_set_user(layer_state_t state) // Layer change event handler
{
#ifdef AUDIO_ENABLE
  if (biton32(state) == 4)                          // Check if layer 4 is the highest active layer
  {
    PLAY_SONG(overwatch_song);                      // Play the Overwatch theme song when entering layer 4
  }
#endif
  return state;                                     // Always return the updated layer state
}

#ifdef OTHER_KEYMAP_C                               // If OTHER_KEYMAP_C is defined, pull in that keymap file
#include OTHER_KEYMAP_C                             // Include the alternate or extended keymap definition
#endif                                              // End conditional inclusion of OTHER_KEYMAP_C

#endif                                              // End include guard for this file (MYKEYS_KEYMAP_C)
