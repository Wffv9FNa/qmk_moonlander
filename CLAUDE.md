# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build Environment & Commands

### Build Environment Setup
The QMK development environment is launched through Windows Terminal with:
```
C:/QMK_MSYS/shell_connector.cmd
```

### Building Firmware

**Full Build Script** (use for production builds):
```bash
C:\Users\Daniel\bin\build_moonlander.sh
```

This performs the complete workflow:
1. **Syncs** all source files from this directory to `/b/QMK/qmk_firmware/keyboards/zsa/moonlander/keymaps/mykeys`
2. **Compiles** the firmware with `qmk compile`
3. **Generates** keymap visualization artifacts (YAML and SVG) using `keymap parse` and `keymap draw`
4. **Creates** timestamp-named files (e.g., `2026-01-08_14h30m15.bin`, `.yaml`, `.svg`)
5. **Archives** all artifacts to the `builds/` directory
6. **Cleans up** the QMK firmware directory

Use the build script when:
- You've made changes to source files in this repo
- You want complete documentation with visualizations
- You're preparing a build to flash to the keyboard

**Important**: The script uses rsync to sync files, excluding: `.git/`, `.cursor/`, `builds/`, `.vscode/`, `docs/`, `scratch/`, and related files.

**Quick Compile** (use for rapid iteration):
```bash
cd /b/QMK/qmk_firmware
qmk compile -kb zsa/moonlander -km mykeys
```

This only compiles the firmware (no sync, no artifacts). Use when:
- Files are already synced from a previous build script run
- You're doing rapid testing of small changes
- You don't need visualization artifacts
- You want the fastest compile-test cycle

## Architecture Overview

### Repository Structure
This is a **keymap-focused repository** for the ZSA Moonlander keyboard, not a full QMK firmware fork. It contains only the keymap files and configuration that get synced into a separate QMK firmware installation during the build process.

Key directories:
- `tap_dance/` - Tap dance action implementations
- `rgb_config/` - RGB LED configuration and layer colour mappings
- `indicator_leds/` - Hardware indicator LED control (6 LEDs on top of keyboard)
- `.local/` - **Project workspace** for plans, reference materials, code reviews, and other documentation
  - `.local/modules/getreuer/` - External QMK modules (git submodule from getreuer/qmk-modules)
  - `.local/qmk-firmware-files/` - QMK firmware headers needed for local development
- `builds/` - Output directory for compiled firmware and visualisations (excluded from git)
- `scratch/` - Temporary/experimental files

**Important**: When creating project plans, code reviews, or other documentation, store them in `.local/` rather than the repository root.

### Layer Architecture
The keymap uses an 8-bit layer state with 8 defined layers (see `keymap.h:66-75`):
- `_HM` (0) - Home/base layer
- `_MS` (1) - Mouse control (Orbital Mouse module)
- `_GM` (2) - Gaming layer with SOCD cleaner
- `_KN` (3) - Kana/Japanese input
- `_HV` (4) - HSV colour display layer
- `_FN` (5) - Function keys
- `_NM` (6) - Numpad
- `_WM` (7) - WordMon + arrow keys

Layers use toggle (TT), tap-dance (TD), or momentary layer switches. The exit key system (`exit_keys[]` in `keymap.c:84-93`) defines matrix coordinates for each layer's toggle/exit keys, enabling automatic layer exit on specific key presses.

### Module Integration
This keymap uses several external QMK modules from Pascal Getreuer's collection:
- **Orbital Mouse** (`OM_*` keycodes) - Advanced mouse control
- **Select Word** (`SELWORD`, `SELWBAK`, `SELLINE`) - Text selection macros
- **SOCD Cleaner** (`SOCDTOG`) - Simultaneous opposite cardinal direction handling for gaming
- **Turbo Click** (`TURBO`) - Rapid mouse click functionality
- **Achordion** - Home row mods optimisation (if enabled)
- Other available modules in `.local/modules/getreuer/`: custom_shift_keys, sentence_case, tap_flow, etc.

Modules are included via git submodule and accessed through `.local/modules/getreuer/`.

### RGB Configuration System
RGB LED colours are defined per-layer using a custom macro system:
- `COLOR_LAYOUT()` macro in `rgb_config/rgb_config.h` maps the 72-key physical layout to the `[12][7][3]` matrix structure
- Each layer has a colour map defined using this macro
- `set_layer_color()` function applies the colour map when layers change
- The system accounts for the Moonlander's split layout and thumb clusters

### Indicator LED System
The Moonlander has 6 dedicated indicator LEDs (3 per half) separate from the per-key RGB matrix. These are controlled via `indicator_leds/`:
- Requires `MOONLANDER_USER_LEDS` in `config.h` to override default firmware behaviour
- Each LED can be configured to show: lock states (Caps/Num/Scroll), layer activity, Caps Word, SOCD status, or custom conditions
- Default configuration: L1=Caps Lock, L2=Gaming, L3=Kana, R1=Mouse, R2=Numpad/WordMon, R3=Caps Word
- Hardware control via `ML_LED_1(bool)` through `ML_LED_6(bool)` macros
- Updates run in `housekeeping_task_user()` for continuous state monitoring

### Tap Dance System
Tap dance actions are defined in `tap_dance/`:
- `TD_TGLL_4` - Toggles layer 4 (gaming) with tap count detection
- `TD_PMONE` - Private macro tap dance (implementation in `macros_private.c`)
- The `td_*_finished()` functions are forward-declared in `tap_dance.h` and registered in the `tap_dance_actions[]` array in `keymap.c:58-61`

### Private/Local Files
`macros_private.c` and `macros_private.h` contain user-specific macros and are excluded from version control (included in `.gitignore`). These define `PRIVATE_SAFE_RANGE` which other keycodes build upon via `ML_SAFE_RANGE`.

## Code Organisation Patterns

### Header Guards
All headers use traditional `#ifndef`/`#define`/`#endif` guards rather than `#pragma once`, following QMK conventions.

### Keycode Aliases
Short 7-character-or-less aliases are defined in `keymap.h` for readability in the keymap matrices:
- Modifier keys: `L_SHFT`, `R_SHFT`, `L_GUI`, `L_ALT`, `L_CTRL`
- Navigation: `CT_LEFT`, `CT_RGHT`, `CT_BSPC`
- Selection: `SELWRD`, `SELWBK`, `SELINE`, `CS_LEFT`, `CS_RGHT`
- Window management: `MINWIN`, `MAXWIN`, `GC_Y`, `CS_X`
- IME: `IME_TOG`, `KATAK`, `HIRAG`

### Literate Programming Style
The codebase uses section headers extensively (e.g., `// +----------+`, `// | INCLUDES |`, `// +----------+`) to create visual chapter breaks. Comments explain the "why" and narrative, not just the "what".

### PROGMEM Data
Layer-specific lookup tables (like `exit_keys[]`) use `PROGMEM` to store data in flash rather than RAM, critical for AVR microcontrollers with limited RAM.

## Key Features & Configuration

### Audio
`AUDIO_ENABLE = yes` in `rules.mk` enables sound effects:
- Startup song: Close Encounters theme
- Caps Lock on/off sounds
- Layer change sounds (Overwatch theme for gaming layer)

### Timing Configuration
From `config.h`:
- `TAPPING_TERM 200` - 200ms to distinguish tap vs hold
- `TAP_TOGGLE_LAYER_TERM 200` - 200ms window for tap-toggling layers
- `TAPPING_TOGGLE 2` - Requires 2 taps to toggle tap-toggle layers

### Key Overrides
The `key_overrides[]` system remaps keys when used with modifiers:
- Ctrl + NUBS → Backtick (`` ` ``)

### Caps Word
`CAPS_WORD_ENABLE = yes` enables the Caps Word feature (toggled with `CW_TOGG`), which automatically capitalises until a breaking character is pressed.

## Development Workflow

1. Edit keymap files in this repository
2. Run the build script: `C:\Users\Daniel\bin\build_moonlander.sh`
3. The script syncs files to the QMK firmware directory, compiles, and generates artifacts
4. Flash the `.bin` file from `builds/` to the keyboard
5. Review the generated `.svg` file to visualise the keymap layout

**Note**: Direct edits in the QMK firmware directory will be overwritten by the next sync. Always edit files in this repository.
