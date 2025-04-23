#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgb_config.h"
#include "color_aliases.h"

// Typedef for color triplet for readability (represents HSV)
typedef uint8_t ColorTriplet[3];

/* RGB color aliases based on comments in color_aliases.h */
/* Prefixed with CFG_ to avoid conflicts with QMK core definitions */
#define CFG_RGB_OFF   {  0,  0,  0} /* Black / Off */
#define CFG_RGB_WHT   {255,255,255} /* White (Approximated from HSV) */
#define CFG_RGB_RED   {245,  3,  3} /* Red (From comment) */
#define CFG_RGB_SALMN {244,157,162} /* Salmon Pink (From comment) */
#define CFG_RGB_CHART {134,255,  4} /* Chartreuse (From comment) */
#define CFG_RGB_SPGRN {  0,206,103} /* Spring Green (From comment) */
#define CFG_RGB_SEGRN { 90,175,123} /* Sea Green (From comment) */
#define CFG_RGB_AQUA  {  0,150, 75} /* Aquamarine-like (From comment) */
#define CFG_RGB_CYPRO {  0,183,235} /* Cyan Process (From comment) */
#define CFG_RGB_PRBLU { 45, 96,243} /* Persian Blue (From comment) */
#define CFG_RGB_BEAVR {159,129,112} /* Beaver Brown (From comment) */

/* Additional RGB values found in originallayout.c mapped to closest alias */
#define CFG_RGB_BLU_ISH CFG_RGB_PRBLU   /* {148, 220, 243} */
#define CFG_RGB_GRN_ISH CFG_RGB_SEGRN   /* { 87, 144, 175} */
#define CFG_RGB_CHA_ISH CFG_RGB_CHART   /* { 32, 248, 255} */
#define CFG_RGB_SAL_ISH CFG_RGB_SALMN   /* {  2, 198, 244} */
#define CFG_RGB_AQ2_ISH CFG_RGB_AQUA    /* {124, 255, 150} */
#define CFG_RGB_BEA_ISH CFG_RGB_BEAVR   /* {208, 198, 176} */
#define CFG_RGB_WHT_ISH CFG_RGB_WHT     /* {  0,   0, 255} */
#define CFG_RGB_RED_ISH CFG_RGB_RED     /* {  0, 245, 245} */
#define CFG_RGB_SPR_ISH CFG_RGB_SPGRN   /* { 74, 255, 206} */
#define CFG_RGB_CYA_ISH CFG_RGB_CYPRO   /* {131, 255, 255} */

// New layout-based LED map, defined using COLOR_LAYOUT and HSV aliases
static const uint8_t PROGMEM ledmap_layout[][MATRIX_ROWS][MATRIX_COLS][3] = {

/*  _                             ___   */
/* | |    __ _ _   _  ___ _ __   / _ \  */
/* | |   / _` | | | |/ _ \ '__| | | | | */
/* | |__| (_| | |_| |  __/ |    | |_| | */
/* |_____\__,_|\__, |\___|_|     \___/  */
/*             |___/                    */
    [0] = COLOR_LAYOUT( /* Layer 0 */
        /* Left Hand */
        CLR_CHART,  CLR_PRBLU,  CLR_SEGRN,  CLR_SEGRN,  CLR_SEGRN,  CLR_BEAVR,  CLR_BEAVR,                      CLR_WHT  ,  CLR_SEGRN,  CLR_WHT  ,  CLR_PRBLU,  CLR_BEAVR,  CLR_PRBLU,  CLR_CHART,
        CLR_WHT  ,  CLR_SEGRN,  CLR_SEGRN,  CLR_CHART,  CLR_PRBLU,  CLR_PRBLU,  CLR_CHART,                      CLR_WHT  ,  CLR_SEGRN,  CLR_SALMN,  CLR_WHT  ,  CLR_CHART,  CLR_SEGRN,  CLR_SALMN,
        CLR_WHT  ,  CLR_SEGRN,  CLR_SEGRN,  CLR_PRBLU,  CLR_RED  ,  CLR_SEGRN,  CLR_WHT  ,                      CLR_AQUA ,  CLR_SEGRN,  CLR_BEAVR,  CLR_PRBLU,  CLR_CHART,  CLR_SEGRN,  CLR_SALMN,
        CLR_SALMN,  CLR_SEGRN,  CLR_OFF  ,  CLR_SALMN,  CLR_SALMN,  CLR_SEGRN,                                              CLR_SEGRN,  CLR_CHART,  CLR_CHART,  CLR_CHART,  CLR_SEGRN,  CLR_WHT  ,
        CLR_BEAVR,  CLR_PRBLU,  CLR_PRBLU,  CLR_BEAVR,  CLR_CHART,              CLR_BEAVR,                      CLR_BEAVR,              CLR_CHART,  CLR_PRBLU,  CLR_PRBLU,  CLR_SEGRN,  CLR_WHT  ,
                                                        CLR_AQUA ,  CLR_PRBLU,  CLR_SEGRN,                      CLR_SEGRN,  CLR_SEGRN,  CLR_BEAVR
    ),
/*  _                            _  */
/* | |    __ _ _   _  ___ _ __  / | */
/* | |   / _` | | | |/ _ \ '__| | | */
/* | |__| (_| | |_| |  __/ |    | | */
/* |_____\__,_|\__, |\___|_|    |_| */
/*             |___/                */
    [1] = COLOR_LAYOUT(
// +--------------+
// | LAYER 1 LEFT |
// +--------------+
        CLR_OFF, CLR_BEAVR, CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_BEAVR,
        CLR_OFF, CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_BEAVR, CLR_OFF,   CLR_OFF,
        CLR_OFF, CLR_OFF,   CLR_OFF,   CLR_SALMN, CLR_RED,   CLR_OFF,   CLR_BEAVR,
        CLR_OFF, CLR_OFF,   CLR_OFF,   CLR_CHART, CLR_RED,   CLR_OFF,
        CLR_OFF, CLR_BEAVR, CLR_BEAVR, CLR_OFF,   CLR_SPGRN,
                                                                        CLR_BEAVR,
                                    CLR_RED,   CLR_RED,   CLR_RED,
// +---------------+
// | LAYER 1 Right |
// +---------------+
        CLR_OFF, CLR_OFF,   CLR_BEAVR, CLR_OFF,   CLR_SPGRN, CLR_OFF,   CLR_SPGRN,
        CLR_OFF, CLR_OFF,   CLR_SALMN, CLR_BEAVR, CLR_SPGRN, CLR_OFF,   CLR_OFF,
        CLR_OFF, CLR_OFF,   CLR_BEAVR, CLR_BEAVR, CLR_SPGRN, CLR_OFF,   CLR_OFF,
                     CLR_OFF,   CLR_CHART, CLR_OFF,   CLR_SPGRN, CLR_OFF,   CLR_CYPRO,
                                  CLR_BEAVR, CLR_RED,   CLR_RED,   CLR_RED,   CLR_OFF,
                                                                        CLR_OFF,
                                                                  CLR_RED,   CLR_RED,   CLR_RED
    ),
/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  |___ \  */
/* | |   / _` | | | |/ _ \ '__|   __) | */
/* | |__| (_| | |_| |  __/ |     / __/  */
/* |_____\__,_|\__, |\___|_|    |_____| */
/*             |___/                    */
    [2] = COLOR_LAYOUT(
// +--------------+
// | LAYER 2 LEFT |
// +--------------+
        CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,
        CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_CHART, CLR_OFF,   CLR_OFF,
        CLR_CHART, CLR_OFF,   CLR_OFF,   CLR_CHART, CLR_CHART, CLR_CHART, CLR_OFF,
        CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,
        CLR_RED,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,
                                                                        CLR_OFF,
                                    CLR_OFF,   CLR_OFF,   CLR_OFF,
// +---------------+
// | LAYER 2 Right |
// +---------------+
        CLR_OFF,   CLR_CHART, CLR_CHART, CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_CHART,
        CLR_OFF,   CLR_CHART, CLR_CHART, CLR_CHART, CLR_OFF,   CLR_OFF,   CLR_OFF,
        CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_CHART, CLR_OFF,   CLR_OFF,   CLR_OFF,
                     CLR_RED,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_RED,   CLR_OFF,
                                  CLR_CYPRO, CLR_CYPRO, CLR_OFF,   CLR_OFF,   CLR_RED,
                                                                        CLR_OFF,
                                                                  CLR_OFF,   CLR_OFF,   CLR_OFF
    ),
/*  _                            _____  */
/* | |    __ _ _   _  ___ _ __  |___ /  */
/* | |   / _` | | | |/ _ \ '__|   |_ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [3] = COLOR_LAYOUT(
// +--------------+
// | LAYER 3 LEFT |
// +--------------+
        CLR_PRBLU, CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_BEAVR, CLR_OFF,
        CLR_OFF,   CLR_BEAVR, CLR_CHART, CLR_CHART, CLR_OFF,   CLR_OFF,   CLR_BEAVR,
        CLR_OFF,   CLR_OFF,   CLR_BEAVR, CLR_SALMN, CLR_SALMN, CLR_SALMN, CLR_OFF,
        CLR_SALMN, CLR_OFF,   CLR_OFF,   CLR_BEAVR, CLR_OFF,   CLR_OFF,
        CLR_OFF,   CLR_BEAVR, CLR_OFF,   CLR_OFF,   CLR_OFF,
                                                                        CLR_BEAVR,
                                    CLR_OFF,   CLR_OFF,   CLR_OFF,
// +---------------+
// | LAYER 3 Right |
// +---------------+
        CLR_OFF,   CLR_SALMN, CLR_SALMN, CLR_OFF,   CLR_BEAVR, CLR_SALMN, CLR_SALMN,
        CLR_OFF,   CLR_SALMN, CLR_SALMN, CLR_SALMN, CLR_OFF,   CLR_BEAVR, CLR_CHART,
        CLR_BEAVR, CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_BEAVR, CLR_SALMN,
                     CLR_OFF,   CLR_BEAVR, CLR_OFF,   CLR_OFF,   CLR_OFF,   CLR_OFF,
                                  CLR_BEAVR, CLR_OFF,   CLR_OFF,   CLR_SPGRN, CLR_BEAVR,
                                                                        CLR_OFF,
                                                                  CLR_OFF,   CLR_BEAVR, CLR_OFF
    ),
/*  _                            _  _    */
/* | |    __ _ _   _  ___ _ __  | || |   */
/* | |   / _` | | | |/ _ \ '__| | || |_  */
/* | |__| (_| | |_| |  __/ |    |__   _| */
/* |_____\__,_|\__, |\___|_|       |_|   */
/*             |___/                     */
    [4] = COLOR_LAYOUT(
// +--------------+
// | LAYER 4 LEFT |
// +--------------+
        CLR_WHT, CLR_CHART, CLR_OFF,   CLR_CHART, CLR_CHART, CLR_WHT,   CLR_WHT,
        CLR_OFF, CLR_WHT,   CLR_PRBLU, CLR_SALMN, CLR_PRBLU, CLR_BEAVR, CLR_WHT,
        CLR_WHT, CLR_CHART, CLR_OFF,   CLR_OFF,   CLR_CHART, CLR_CHART, CLR_CHART,
        CLR_WHT, CLR_WHT,   CLR_WHT,   CLR_WHT,   CLR_WHT,   CLR_WHT,
        CLR_WHT, CLR_WHT,   CLR_OFF,   CLR_WHT,   CLR_WHT,
                                                                        CLR_OFF,
                                    CLR_OFF,   CLR_OFF,   CLR_OFF,
// +---------------+
// | LAYER 4 Right |
// +---------------+
        CLR_WHT, CLR_SALMN, CLR_WHT,   CLR_OFF,   CLR_WHT,   CLR_SALMN, CLR_SALMN,
        CLR_WHT, CLR_WHT,   CLR_PRBLU, CLR_OFF,   CLR_OFF,   CLR_WHT,   CLR_WHT,
        CLR_WHT, CLR_CHART, CLR_PRBLU, CLR_PRBLU, CLR_WHT,   CLR_CHART, CLR_OFF,
                     CLR_WHT,   CLR_WHT,   CLR_WHT,   CLR_WHT,   CLR_WHT,   CLR_WHT,
                                  CLR_PRBLU, CLR_WHT,   CLR_WHT,   CLR_OFF,   CLR_PRBLU,
                                                                        CLR_OFF,
                                                                  CLR_OFF,   CLR_OFF,   CLR_OFF
    ),
};

// Updated function to use the layout-based map and LED index mapping (now expecting HSV)
void set_layer_color(int layer) {
    // Ensure g_led_config is accessible (defined in keyboard's .c file)
    extern led_config_t g_led_config;
    // Need access to rgb_matrix_config for brightness adjustment
    extern rgb_config_t rgb_matrix_config;

    // Check if the requested layer exists in our map
    if (layer >= (sizeof(ledmap_layout) / sizeof(ledmap_layout[0]))) {
        rgb_matrix_set_color_all(0, 0, 0);
        return;
    }

    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        for (uint8_t j = 0; j < MATRIX_COLS; j++) {
            uint8_t led_index = g_led_config.matrix_co[i][j];
            if (led_index == NO_LED) {
                continue;
            }

            // Get the H, S, V values directly from the layout map
            HSV hsv = {
                .h = pgm_read_byte(&ledmap_layout[layer][i][j][0]),
                .s = pgm_read_byte(&ledmap_layout[layer][i][j][1]),
                .v = pgm_read_byte(&ledmap_layout[layer][i][j][2]),
            };

            // Set the color (applying brightness)
            if (!hsv.h && !hsv.s && !hsv.v) {
                // If color is {0,0,0}, explicitly turn LED off
                rgb_matrix_set_color(led_index, 0, 0, 0);
            } else {
                // Convert HSV to RGB *after* retrieving from map
                RGB rgb = hsv_to_rgb(hsv);
                // Apply brightness factor from global config
                float brightness_factor = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
                rgb_matrix_set_color(led_index,
                                     (uint8_t)(rgb.r * brightness_factor),
                                     (uint8_t)(rgb.g * brightness_factor),
                                     (uint8_t)(rgb.b * brightness_factor));
            }
        }
    }
}