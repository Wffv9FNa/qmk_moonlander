#ifndef MYKEYS_KEYMAP_H                              // Header guard to prevent multiple inclusion
#define MYKEYS_KEYMAP_H                              // Define the header guard symbol

#include "macros_private.h"                          // Include private macro definitions

// Custom Keycode Aliases (7 characters or less)
// +--------------+
// | NORMAL KEYS  |
// +--------------+
#define L_SHFT   KC_LEFT_SHIFT            // Left Shift
#define R_SHFT   KC_RIGHT_SHIFT           // Right Shift
#define L_GUI    KC_LEFT_GUI              // Left GUI (Windows/Command)
#define L_ALT    KC_LEFT_ALT              // Left Alt
#define L_CTRL   KC_LEFT_CTRL             // Left Control
#define KC_ESC   KC_ESCAPE                // Escape
#define KC_SPC   KC_SPACE                 // Space
// +---------------------+
// | MOD-TAP / COMPOSITE |
// +---------------------+
#define MT_CZ    MT(MOD_LCTL, KC_Z)       // ModTap: Ctrl when held, Z when tapped
// +--------------------+
// | TEXT SELECTION     |
// +--------------------+
#define SELWBK   SELWBAK                  // Select Word Back
#define SELWRD   SELWORD                  // Select Word
#define SELINE   SELLINE                  // Select Line
#define S_LEFT   LSFT(KC_LEFT)            // Shift + Left (extend selection)
#define S_RGHT   LSFT(KC_RGHT)            // Shift + Right (extend selection)
#define CS_LEFT  LCTL(LSFT(KC_LEFT))      // Ctrl + Shift + Left (select by word)
#define CS_RGHT  LCTL(LSFT(KC_RIGHT))     // Ctrl + Shift + Right (select by word)
// +--------------------+
// | CURSOR / NAV      |
// +--------------------+
#define CT_LEFT  LCTL(KC_LEFT)            // Ctrl + Left (jump by word)
#define CT_RGHT  LCTL(KC_RGHT)            // Ctrl + Right (jump by word)
#define CT_BSPC  LCTL(KC_BSPC)            // Ctrl + Backspace (delete previous word)
// +--------------------+
// | EDIT / SHORTCUTS  |
// +--------------------+
#define CT_Z     LCTL(KC_Z)               // Ctrl + Z
// +--------------------+
// | WINDOW MANAGEMENT |
// +--------------------+
#define MINWIN   LGUI(KC_DOWN)            // Minimise window
#define MAXWIN   LGUI(KC_UP)              // Maximise window
#define GC_Y     LGUI(LCTL(KC_Y))         // GUI + Ctrl + Y (Move window previous)
#define CS_X     LCTL(LSFT(KC_X))         // Ctrl + Shift + X (Move window next)
// +--------------------+
// | INPUT METHOD / IME |
// +--------------------+
#define IME_TOG  LGUI(KC_SPC)             // Windows + Spacebar (toggle IME)
#define KATAK    LCTL(LSFT(KC_F17))       // Katakana conversion
#define HIRAG    LCTL(LSFT(KC_F18))       // Hiragana conversion
// +--------------------+
// | GAME / SYSTEM     |
// +--------------------+
#define SOCDTG   SOCDTOG                  // SOCD toggle
// +----------------------+
// | TAP DANCE KEYCODES  |
// +----------------------+
#define TD_L4TG  TD(TD_TGLL_4)            // TapDance Layer 4 Toggle
#define TD_PONE  TD(TD_PMONE)             // TapDance private macro one
// +--------+
// | Layers |
// +--------+
enum layers {
    _HM = 0, // Home
    _MS,     // Mouse
    _GM,     // Gaming
    _KN,     // Kana
    _HV,     // HSV Color Display
    _FN,     // Function Keys
    _NM,     // Numpad
    _WM      // WordMon + Arrows
};

// +--------------------+
// | TYPE DEFINITIONS  |
// +--------------------+
// Raw HID state shared with host
// Full definition here so modules can access members
typedef struct rawhid_state_s {
    bool rgb_control;  // When true, host owns RGB control
} rawhid_state_t;

// External declarations for global state
extern rawhid_state_t rawhid_state;

#endif // MYKEYS_KEYMAP_H
