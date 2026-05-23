// qmkmap.c - minimal live-state drop-in for the custom Moonlander keymap.
//
// Responsibilities (Phase 0):
//   - qmkmap_send_state(): build the RAW_EPSIZE-byte STATE_REPORT from get_highest_layer(layer_state),
//     get_mods(), host_keyboard_led_state(); send via raw_hid_send.
//   - raw_hid_receive(): answer QUERY_STATE with one STATE_REPORT.
//   - qmkmap_notify_layer() / qmkmap_task(): thin wrappers that push state on change.
//
// MUST NOT define layer_state_set_user or housekeeping_task_user (already defined in keymap.c) -
// integration is via the one-line helper calls documented in INTEGRATION.md.

#include "qmkmap.h"
#include "raw_hid.h"
#include <string.h>  // memcpy for the matrix-bitmap snapshot
#if defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
#    include "socd_cleaner.h"
#endif

// Pressed-key matrix bitmap (bytes 5..15 of the STATE_REPORT). Row-major, LSB-first:
// bit = row*MATRIX_COLS + col -> byte qmkmap_matrix[bit/8], mask (1 << (bit%8)). Written only by
// qmkmap_record_key() (on press/release) and read by the report builder / change-detector. Static
// zero-init = all keys released at boot. Only physical matrix positions are stored; non-matrix
// events are ignored at the source, so every bit here maps to a real (row,col).
static uint8_t qmkmap_matrix[QMKMAP_MATRIX_BYTES] = {0};

// Build the module-flags byte. Bit 0 = SOCD cleaner enabled. When the SOCD module is not
// compiled in, the bit stays 0. Reserved bits (1..7) are always 0.
static uint8_t qmkmap_module_flags(void) {
    uint8_t flags = 0;
#if defined(COMMUNITY_MODULE_SOCD_CLEANER_ENABLE)
    if (socd_cleaner_enabled) {
        flags |= QMKMAP_FLAG_SOCD;
    }
#endif
    return flags;
}

// Build and send a single STATE_REPORT. "layer" lets callers pass an incoming layer_state value
// (e.g. from layer_state_set_user, where layer_state is not yet updated); pass layer_state for the
// current live value.
static void qmkmap_send_state_for(layer_state_t layer) {
    uint8_t report[RAW_EPSIZE] = {0};
    report[QMKMAP_OFF_TYPE]  = QMKMAP_STATE_REPORT;
    report[QMKMAP_OFF_LAYER] = get_highest_layer(layer);
    report[QMKMAP_OFF_MODS]  = get_mods();
    report[QMKMAP_OFF_LEDS]  = host_keyboard_led_state().raw;
    report[QMKMAP_OFF_FLAGS] = qmkmap_module_flags();
    // Bytes 5..15: snapshot the pressed-key matrix bitmap verbatim (row-major, LSB-first). The
    // backend is a pure passthrough of these 11 bytes; the frontend interprets them.
    memcpy(&report[QMKMAP_OFF_MATRIX], qmkmap_matrix, QMKMAP_MATRIX_BYTES);
    raw_hid_send(report, sizeof(report));
}

// Send a STATE_REPORT for the current live state.
static void qmkmap_send_state(void) {
    qmkmap_send_state_for(layer_state);
}

// Host -> keyboard. Answer QUERY_STATE with one STATE_REPORT. Other commands are ignored.
void raw_hid_receive(uint8_t *data, uint8_t length) {
    if (length < 1) {
        return;
    }
    switch (data[0]) {
        case QMKMAP_QUERY_STATE:
            qmkmap_send_state();
            break;
        default:
            break;
    }
}

// Call from inside the existing layer_state_set_user(), before "return state;". Pushes the state
// derived from the incoming layer value so the host follows layer changes promptly.
void qmkmap_notify_layer(layer_state_t state) {
    qmkmap_send_state_for(state);
}

// Record one physical key event into the pressed-key matrix bitmap. Call as the FIRST statement of
// process_record_user(), before any early "return false": consumed keys (SOCD/secrets/audio) are
// still physically down, so we must capture them before those paths bail. Sets the bit on press,
// clears it on release. Only real matrix positions are stored - encoder/dip-switch/synthetic events
// carry out-of-range row/col (e.g. KEYLOC_ENCODER_CW = 253) and are guarded out, so they can never
// corrupt a neighbouring bit. This is read-only on the event: it never changes QMK's processing.
void qmkmap_record_key(keyrecord_t *record) {
    uint8_t row = record->event.key.row;
    uint8_t col = record->event.key.col;
    if (row >= MATRIX_ROWS || col >= MATRIX_COLS) {
        return;  // not a physical matrix key (encoder, dip switch, synthetic event)
    }
    uint16_t bit  = (uint16_t)row * MATRIX_COLS + col;  // 0..83, row-major
    uint8_t  byte = bit / 8;
    uint8_t  mask = (uint8_t)(1u << (bit % 8));
    if (record->event.pressed) {
        qmkmap_matrix[byte] |= mask;
    } else {
        qmkmap_matrix[byte] &= (uint8_t)~mask;
    }
}

// Call from inside the existing housekeeping_task_user(), so it runs every loop. Debounced on the
// full reportable tuple {highest layer, held mods, lock LEDs, module flags}: it only emits a
// STATE_REPORT when one of those bytes has actually changed since the last push, so it is cheap to
// call at the scan rate. Crucially this includes get_mods(), so holding a bare modifier
// (Shift/Ctrl/Alt/GUI) - which changes neither the layer nor the lock LEDs - still pushes a report;
// and it includes the module-flags byte, so a SOCD-only toggle (which changes nothing else) still
// pushes a report. Without these bytes in the debounce, held modifiers and module-flag changes were
// never surfaced to the host.
void qmkmap_task(void) {
    // 0xFF: impossible initial value for the layer index, forces a push on the first call.
    static uint8_t last_layer = 0xFF;
    static uint8_t last_mods  = 0xFF;
    static uint8_t last_leds  = 0xFF;
    static uint8_t last_flags = 0xFF;
    // Mirror of the matrix bitmap as last sent. Zero-init matches the all-released matrix at boot;
    // the layer sentinel (0xFF) already forces the first call to push, so no separate matrix sentinel
    // is needed.
    static uint8_t last_matrix[QMKMAP_MATRIX_BYTES] = {0};
    uint8_t layer = get_highest_layer(layer_state);
    uint8_t mods  = get_mods();
    uint8_t leds  = host_keyboard_led_state().raw;
    uint8_t flags = qmkmap_module_flags();
    bool matrix_changed = memcmp(last_matrix, qmkmap_matrix, QMKMAP_MATRIX_BYTES) != 0;
    if (layer != last_layer || mods != last_mods || leds != last_leds || flags != last_flags || matrix_changed) {
        last_layer = layer;
        last_mods  = mods;
        last_leds  = leds;
        last_flags = flags;
        memcpy(last_matrix, qmkmap_matrix, QMKMAP_MATRIX_BYTES);
        qmkmap_send_state();
    }
}
