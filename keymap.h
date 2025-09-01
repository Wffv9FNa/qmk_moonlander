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
#define TD_1F1   TD(TD_1_F1)              // Tap: 1, Double: F1
#define TD_2F2   TD(TD_2_F2)              // Tap: 2, Double: F2
#define TD_3F3   TD(TD_3_F3)              // Tap: 3, Double: F3
#define TD_4F4   TD(TD_4_F4)              // Tap: 4, Double: F4
#define TD_5F5   TD(TD_5_F5)              // Tap: 5, Double: F5
#define TD_6F6   TD(TD_6_F6)              // Tap: 6, Double: F6
#define TD_7F7   TD(TD_7_F7)              // Tap: 7, Double: F7
#define TD_8F8   TD(TD_8_F8)              // Tap: 8, Double: F8
#define TD_9F9   TD(TD_9_F9)              // Tap: 9, Double: F9
#define TD_0F10  TD(TD_0_F10)             // Tap: 0, Double: F10
#define TD_BSTK  TD(TD_BSLTIK)            // Tap Dance: Backslash/Backtick
