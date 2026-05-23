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

// Build and send a single STATE_REPORT. "layer" lets callers pass an incoming layer_state value
// (e.g. from layer_state_set_user, where layer_state is not yet updated); pass layer_state for the
// current live value.
static void qmkmap_send_state_for(layer_state_t layer) {
    uint8_t report[RAW_EPSIZE] = {0};
    report[QMKMAP_OFF_TYPE]  = QMKMAP_STATE_REPORT;
    report[QMKMAP_OFF_LAYER] = get_highest_layer(layer);
    report[QMKMAP_OFF_MODS]  = get_mods();
    report[QMKMAP_OFF_LEDS]  = host_keyboard_led_state().raw;
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

// Call from inside the existing housekeeping_task_user(), so it runs every loop. Debounced on the
// full reportable tuple {highest layer, held mods, lock LEDs}: it only emits a STATE_REPORT when one
// of those bytes has actually changed since the last push, so it is cheap to call at the scan rate.
// Crucially this includes get_mods(), so holding a bare modifier (Shift/Ctrl/Alt/GUI) - which
// changes neither the layer nor the lock LEDs - still pushes a report. Without the mods byte in the
// debounce, held modifiers were never surfaced to the host.
void qmkmap_task(void) {
    // 0xFF: impossible initial value for the layer index, forces a push on the first call.
    static uint8_t last_layer = 0xFF;
    static uint8_t last_mods  = 0xFF;
    static uint8_t last_leds  = 0xFF;
    uint8_t layer = get_highest_layer(layer_state);
    uint8_t mods  = get_mods();
    uint8_t leds  = host_keyboard_led_state().raw;
    if (layer != last_layer || mods != last_mods || leds != last_leds) {
        last_layer = layer;
        last_mods  = mods;
        last_leds  = leds;
        qmkmap_send_state();
    }
}
