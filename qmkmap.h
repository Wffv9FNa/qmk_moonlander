// qmkmap.h - minimal live-state drop-in for the custom Moonlander keymap.
//
// Streams LIVE STATE only (highest active layer index, held mods, lock LEDs) over QMK raw HID.
// It does NOT send the keymap - layout content comes from the build pipeline's keymap-drawer YAML.
//
// See INTEGRATION.md for how this wires into the existing keymap, and docs/protocol.md for the
// authoritative wire protocol this implements.

#pragma once

#include QMK_KEYBOARD_H

// --- Wire protocol (reports are exactly RAW_EPSIZE bytes; byte 0 = command/type tag) ----------
// Keep these in lock-step with docs/protocol.md. RAW_EPSIZE is 32 on this board (LUFA USB stack;
// see tmk_core/protocol/usb_descriptor.h). The report buffer is sized to RAW_EPSIZE, never a
// hard-coded 32, so it tracks the core definition.

// RAW_EPSIZE is defined in the USB protocol layer (tmk_core/protocol/usb_descriptor.h), which is
// not on the keymap include path, so it is not visible here from QMK_KEYBOARD_H alone. Provide a
// fallback that matches the only value this board uses: the LUFA/ChibiOS raw HID endpoint is 32
// bytes (raw_hid.h documents reports as "Always 32 bytes"; the 8-byte value is V-USB AVR only,
// which the Moonlander is not). If the real macro is ever in scope it takes precedence.
#ifndef RAW_EPSIZE
#    define RAW_EPSIZE 32
#endif

// Command bytes (host -> keyboard, via raw_hid_receive)
#define QMKMAP_QUERY_STATE  0x01

// Report types (keyboard -> host)
#define QMKMAP_STATE_REPORT 0x10

// STATE_REPORT field offsets (within the RAW_EPSIZE-byte report)
#define QMKMAP_OFF_TYPE     0  // 1 byte: QMKMAP_STATE_REPORT
#define QMKMAP_OFF_LAYER    1  // 1 byte: get_highest_layer(layer_state)
#define QMKMAP_OFF_MODS     2  // 1 byte: get_mods()
#define QMKMAP_OFF_LEDS     3  // 1 byte: host_keyboard_led_state().raw
// bytes 4..(RAW_EPSIZE-1): reserved / zero

// --- Public helpers the user calls from their existing hooks (one line each) ------------------
// MUST NOT redefine layer_state_set_user / housekeeping_task_user - these are called from inside
// the existing definitions in keymap.c.

// Call from inside layer_state_set_user(), before "return state;". Pushes a STATE_REPORT built
// from the supplied (incoming) layer state, so the host sees the layer change immediately.
void qmkmap_notify_layer(layer_state_t state);

// Call from inside housekeeping_task_user(), so it runs every loop. Internally debounced on the full
// reportable tuple {highest layer, held mods, lock LEDs}: it only pushes a STATE_REPORT when one of
// those bytes has changed since the last push, so it is safe to call at the scan rate. This is what
// surfaces held modifiers (Shift/Ctrl/Alt/GUI) and Caps/Num/Scroll lock changes that do not fire a
// layer event.
void qmkmap_task(void);

// raw_hid_receive is defined in qmkmap.c (currently unclaimed on this board; VIA is off, so the
// only other definition is the weak stub in quantum/raw_hid.c).
