#ifndef MYKEYS_KEYMAP_C
#define MYKEYS_KEYMAP_C

// +----------+
// | INCLUDES |
// +----------+
#include QMK_KEYBOARD_H
#include "i18n.h"
#include "audio.h"
#include "user_song_list.h"
#include "print.h"  // Add debug printing support
#include "tap_dance/tap_dance.h" // Include tap dance definitions
#include "rgb_config/rgb_config.h" // Include RGB config definitions

// +---------+
// | DEFINES |
// +---------+
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

// +--------------------------+
// | GLOBAL STATE & VARIABLES |
// +--------------------------+
extern bool socd_cleaner_enabled;  // Add this to access the global SOCD state

#ifdef AUDIO_ENABLE
// Audio song data
float caps_on_song[][2] = SONG(CAPS_ON_SOUND);
float caps_off_song[][2] = SONG(CAPS_OFF_SOUND);
float overwatch_song[][2] = SONG(OVERWATCH_THEME);
#endif

// Rawhid state structure
typedef struct {
    bool rgb_control;
} rawhid_state_t;

rawhid_state_t rawhid_state;

// RGB Matrix configuration (defined elsewhere)
extern rgb_config_t rgb_matrix_config;

// +-------+
// | ENUMS |
// +-------+
// Add custom keycodes enum
enum custom_keycodes {
    NEW_SAFE_RANGE // This now implicitly starts at SAFE_RANGE
};

// Optional include for custom keymap definitions
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// +--------------------+
// | TAP DANCE ACTIONS  |
// +--------------------+
// Define tap dance actions
tap_dance_action_t tap_dance_actions[] = {
    [TD_TGLL_4] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_tgll_4_finished, NULL)
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
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
KC_EQL,         	KC_1,           		KC_2,           KC_3,           KC_4,           KC_5,           TG(1),                        TG(1),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINS,
KC_DEL,         	KC_Q,           		KC_W,           KC_E,           KC_R,           KC_T,           TG(2),                        TG(2),          KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
KC_BSPC,        	KC_A,           		KC_S,           KC_D,           KC_F,           KC_G,           KC_NUBS,                      KC_MEH,         KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        MT(MOD_LGUI, KC_QUOTE),
KC_LEFT_SHIFT,  	MT(MOD_LCTL, KC_Z),	KC_X,       	  KC_C,           KC_V,           KC_B,                                         				        KC_N,           KC_M,           KC_COMM,        KC_DOT,         KC_SLSH,        KC_RIGHT_SHIFT,
MO(2),          	KC_LEFT_GUI,    		CW_TOGG,        TD(TD_TGLL_4),  MO(1),          						KC_CAPS,  KC_ESC,     								                            MO(3),          KC_HYPR,        KC_LBRC,        KC_RBRC,        MO(1),
																								                              KC_SPC, KC_LEFT_ALT, KC_F13,  KC_BSPC, KC_TAB, KC_ENT
),

    [1] = LAYOUT(
        KC_GRV,         KC_F1,          KC_F2,          		  KC_F3,          KC_F4,          		    KC_F5,          KC_TRNS,        			      KC_TRNS,        KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
        KC_TRNS,        KC_NO,          SELWBAK,              KC_NO,      	  SELWORD,                KC_NUBS,        KC_NO,          			      KC_NO,          KC_HOME,        KC_7,           KC_8,           KC_9,           KC_PAST,        KC_F12,
        KC_TRNS,        KC_NO,          LGUI(LCTL(KC_Y)),		  KC_NO,         	LCTL(LSFT(KC_X)),		    KC_NO,         	KC_TRNS,        			      KC_NO,          KC_END,         KC_4,           KC_5,           KC_6,           KC_PPLS,        KC_NO,
        KC_TRNS,        KC_LEFT_CTRL,   KC_NO,          		  KC_NO,          KC_NO,          		    KC_NO,                          			                      KC_PSLS,        KC_1,           KC_2,           KC_3,           KC_PMNS,        KC_TRNS,
        KC_NO,          KC_TRNS,        KC_NO,          		  KC_NO,          KC_TRNS,        									                    KC_NO,	  KC_TRNS,                            KC_NO,          KC_0,           KC_PDOT,        KC_PEQL,        KC_TRNS,
                                                                                                                    KC_TRNS, KC_NO, KC_NO,  	KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [2] = LAYOUT(
        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,              			            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_TRNS,        LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     KC_NO,          KC_TRNS,            			            KC_TRNS,        KC_HOME,        KC_NO,          KC_UP,          KC_NO,          KC_NO,          KC_NO,
        KC_TRNS,        LCTL(KC_A),     LCTL(KC_S),     KC_NO,          LCTL(KC_F),     KC_NO,          KC_NO,              			            KC_NO,          KC_END,         KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_NO,          KC_NO,
        KC_TRNS,        LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),                         			                            KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
        KC_TRNS,        KC_NO,          KC_NO,          KC_NO,          KC_NO,          								                    KC_NO,      KC_NO,          							        KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_TRNS,
																					                                                                  KC_NO, KC_NO, KC_TRNS,     	KC_NO, KC_TRNS, KC_NO
    ),

    [3] = LAYOUT(
        QK_BOOT,        KC_F1,          		  KC_F2,          		    KC_F3,          	    KC_F4,          		    KC_F5,          KC_NO,         							KC_NO,          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
        KC_NO,          KC_NO,          		  LSFT(KC_LEFT),  		    LCTL(LSFT(KC_X)),	    LSFT(KC_RGHT), 			    KC_NO,          KC_NO,         							KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_F12,
        KC_NO,          LCTL(KC_BSPC),  		  LCTL(KC_LEFT),  		    LGUI(LCTL(KC_Y)),	    LCTL(KC_RGHT), 			    KC_NO,          KC_NO,         							KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          LCTL(LSFT(KC_BSPC)),	LCTL(LSFT(KC_LEFT)),	  KC_NO,  			        LCTL(LSFT(KC_RIGHT)),	  KC_NO,                    							                	  KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,          KC_NO,
        KC_NO,          KC_NO,          		  KC_NO,          		    KC_NO,          	    KC_NO,          									              KC_NO,		 KC_NO,											              KC_TRNS,        SOCDTOG,        KC_NO,          KC_NO,          KC_NO,
																														                                                                KC_NO, KC_NO, KC_NO, 					KC_NO, KC_NO, KC_NO
    ),
    [4]=LAYOUT(
      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_NO,                              KC_NO,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
      KC_NO,          KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_NO,                              KC_NO,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
      KC_NO,          KC_A,           KC_S,           KC_D,           KC_F,           KC_G,           KC_NO,                              KC_NO,      KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
      KC_LEFT_SHIFT,  KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                                           KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,
      KC_LEFT_CTRL,   KC_NO,          KC_NO,          TD(TD_TGLL_4),  KC_NO,                                  KC_ESCAPE,      KC_CAPS,                                KC_NO,          KC_NO,          KC_TRNS,        KC_TRNS,        KC_NO,
                                                                                      KC_SPACE,   KC_TAB,    KC_LEFT_ALT,        KC_NO,   KC_NO,  KC_NO
),
};

// +----------------+
// | USER FUNCTIONS |
// +----------------+
void keyboard_post_init_user(void) {
    rgb_matrix_enable();
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }

  // Check if Caps Lock is on
  if (host_keyboard_led_state().caps_lock) {
    // Set all keys to red when Caps Lock is on
    rgb_matrix_set_color_all(255, 0, 0);
  } else {
    // Normal layer-based lighting when Caps Lock is off
    switch (biton32(layer_state)) {
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
     default:
      if (rgb_matrix_get_flags() == LED_FLAG_NONE)
        rgb_matrix_set_color_all(0, 0, 0);
      break;
    }
  }
  return true;
}

// Track Caps Lock state
static bool caps_lock_on = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // First let the SOCD cleaner process the key
    bool socd_handled = process_record_socd_cleaner(keycode, record);
    if (!socd_handled) {
        return false;
    }

    switch (keycode) {
        case KC_CAPS:
            if (record->event.pressed) {
                bool new_caps_state = !host_keyboard_led_state().caps_lock;
                #ifdef AUDIO_ENABLE
                if (new_caps_state) {
                    PLAY_SONG(caps_on_song);
                } else {
                    PLAY_SONG(caps_off_song);
                }
                #endif
                caps_lock_on = new_caps_state;
            }
            return true;

        case SOCDTOG:
            // Just return true to allow default SOCDTOG handling
            return true;
    }
    return true;
}

// Add this function definition
layer_state_t layer_state_set_user(layer_state_t state) {
  // Check if audio is enabled
#ifdef AUDIO_ENABLE
  // Check if layer 4 is the highest active layer
  if (biton32(state) == 4) {
    // Play the Overwatch theme song
    PLAY_SONG(overwatch_song);
  }
#endif
  return state;
}

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

#endif // MYKEYS_KEYMAP_C
