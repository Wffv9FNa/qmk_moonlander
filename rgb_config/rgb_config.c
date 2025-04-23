#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgb_config.h"
#include "color_aliases.h"

// Typedef for color triplet for readability
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

// New layout-based LED map, defined using COLOR_LAYOUT and RGB aliases (Attempt 2)
static const uint8_t PROGMEM ledmap_layout[][MATRIX_ROWS][MATRIX_COLS][3] = {
    [0] = COLOR_LAYOUT( /* Layer 0 */
    /*
    LEFT SIDE

    */
        CFG_RGB_CHA_ISH, CFG_RGB_BLU_ISH, CFG_RGB_GRN_ISH, CFG_RGB_GRN_ISH, CFG_RGB_GRN_ISH, CFG_RGB_BEA_ISH, CFG_RGB_BEA_ISH,
        CFG_RGB_WHT_ISH, CFG_RGB_GRN_ISH, CFG_RGB_GRN_ISH, CFG_RGB_SAL_ISH, CFG_RGB_BLU_ISH, CFG_RGB_BLU_ISH, CFG_RGB_CHA_ISH,
        CFG_RGB_WHT_ISH, CFG_RGB_GRN_ISH, CFG_RGB_GRN_ISH, CFG_RGB_BLU_ISH, CFG_RGB_RED_ISH, CFG_RGB_GRN_ISH, CFG_RGB_WHT_ISH,
        CFG_RGB_SAL_ISH, CFG_RGB_GRN_ISH, CFG_RGB_OFF    , CFG_RGB_SAL_ISH, CFG_RGB_SAL_ISH, CFG_RGB_GRN_ISH,
        CFG_RGB_BEA_ISH, CFG_RGB_BLU_ISH, CFG_RGB_BLU_ISH, CFG_RGB_BEA_ISH, CFG_RGB_CHA_ISH,
                                                                                                               CFG_RGB_BEA_ISH,
                                                                            CFG_RGB_AQ2_ISH, CFG_RGB_BLU_ISH,  CFG_RGB_GRN_ISH,
    /*
    RIGHT SIDE
    */
        CFG_RGB_WHT_ISH, CFG_RGB_GRN_ISH, CFG_RGB_WHT_ISH, CFG_RGB_BLU_ISH, CFG_RGB_BEA_ISH, CFG_RGB_BLU_ISH, CFG_RGB_CHA_ISH,
        CFG_RGB_WHT_ISH, CFG_RGB_GRN_ISH, CFG_RGB_SAL_ISH, CFG_RGB_WHT_ISH, CFG_RGB_CHA_ISH, CFG_RGB_GRN_ISH, CFG_RGB_SAL_ISH,
        CFG_RGB_AQ2_ISH, CFG_RGB_GRN_ISH, CFG_RGB_BEA_ISH, CFG_RGB_BLU_ISH, CFG_RGB_CHA_ISH, CFG_RGB_GRN_ISH, CFG_RGB_BLU_ISH,
                         CFG_RGB_GRN_ISH, CFG_RGB_CHA_ISH, CFG_RGB_CHA_ISH, CFG_RGB_CHA_ISH, CFG_RGB_GRN_ISH, CFG_RGB_WHT_ISH,
                                          CFG_RGB_CHA_ISH, CFG_RGB_BLU_ISH, CFG_RGB_BLU_ISH, CFG_RGB_GRN_ISH, CFG_RGB_WHT_ISH,
        CFG_RGB_BEA_ISH,
        CFG_RGB_GRN_ISH, CFG_RGB_GRN_ISH, CFG_RGB_GRN_ISH
    ),
    [1] = COLOR_LAYOUT( /* Layer 1 */
        CFG_RGB_OFF,     CFG_RGB_BEA_ISH, CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEA_ISH,
        CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEA_ISH, CFG_RGB_OFF,     CFG_RGB_OFF,
        CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_SAL_ISH, CFG_RGB_RED_ISH, CFG_RGB_OFF,     CFG_RGB_BEA_ISH,
        CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_CHA_ISH, CFG_RGB_RED_ISH, CFG_RGB_OFF,
        CFG_RGB_OFF,     CFG_RGB_BEA_ISH, CFG_RGB_BEA_ISH, CFG_RGB_OFF,     CFG_RGB_SPR_ISH,
                                                                                     CFG_RGB_BEA_ISH,
                                    CFG_RGB_RED_ISH, CFG_RGB_RED_ISH, CFG_RGB_RED_ISH,

        CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEA_ISH, CFG_RGB_OFF,     CFG_RGB_SPR_ISH, CFG_RGB_OFF,     CFG_RGB_SPR_ISH,
        CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_SAL_ISH, CFG_RGB_BEA_ISH, CFG_RGB_SPR_ISH, CFG_RGB_OFF,     CFG_RGB_OFF,
        CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEA_ISH, CFG_RGB_BEA_ISH, CFG_RGB_SPR_ISH, CFG_RGB_OFF,     CFG_RGB_OFF,
                     CFG_RGB_OFF,     CFG_RGB_CHA_ISH, CFG_RGB_OFF,     CFG_RGB_SPR_ISH, CFG_RGB_OFF,     CFG_RGB_CYA_ISH,
                                  CFG_RGB_BEA_ISH, CFG_RGB_RED_ISH, CFG_RGB_RED_ISH, CFG_RGB_RED_ISH, CFG_RGB_OFF,
                                                                                     CFG_RGB_OFF,
                                                                  CFG_RGB_RED_ISH, CFG_RGB_RED_ISH, CFG_RGB_RED_ISH
    ),
    [2] = COLOR_LAYOUT( /* Layer 2 */
        CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF,
        CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_CHA_ISH, CFG_RGB_OFF, CFG_RGB_OFF,
        CFG_RGB_CHA_ISH, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_CHA_ISH, CFG_RGB_CHA_ISH, CFG_RGB_CHA_ISH, CFG_RGB_OFF,
        CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF,
        CFG_RGB_RED_ISH, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF,
                                                                                     CFG_RGB_OFF,
                                    CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF,

        CFG_RGB_OFF, CFG_RGB_CHA_ISH, CFG_RGB_CHA_ISH, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_CHA_ISH,
        CFG_RGB_OFF, CFG_RGB_CHA_ISH, CFG_RGB_CHA_ISH, CFG_RGB_CHA_ISH, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF,
        CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_CHA_ISH, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF,
                     CFG_RGB_RED_ISH, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_RED_ISH, CFG_RGB_OFF,
                                  CFG_RGB_CYA_ISH, CFG_RGB_CYA_ISH, CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_RED_ISH,
                                                                                     CFG_RGB_OFF,
                                                                  CFG_RGB_OFF, CFG_RGB_OFF, CFG_RGB_OFF
    ),
    [3] = COLOR_LAYOUT( /* Layer 3 */
        CFG_RGB_PRBLU,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_OFF,
        CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_CHART,   CFG_RGB_CHART,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEAVR,
        CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_SALMN,   CFG_RGB_SALMN,   CFG_RGB_SALMN,   CFG_RGB_OFF,
        CFG_RGB_SALMN,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_OFF,     CFG_RGB_OFF,
        CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,
                                                                                     CFG_RGB_BEAVR,
                                    CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,

        CFG_RGB_OFF,     CFG_RGB_SALMN,   CFG_RGB_SALMN,   CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_SALMN,   CFG_RGB_SALMN,
        CFG_RGB_OFF,     CFG_RGB_SALMN,   CFG_RGB_SALMN,   CFG_RGB_SALMN,   CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_CHART,
        CFG_RGB_BEAVR,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_SALMN,
                     CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,
                                  CFG_RGB_BEAVR,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_SPGRN,   CFG_RGB_BEAVR,
                                                                                     CFG_RGB_OFF,
                                                                  CFG_RGB_OFF,     CFG_RGB_BEAVR,   CFG_RGB_OFF
    ),
    [4] = COLOR_LAYOUT( /* Layer 4 */
        CFG_RGB_WHT,     CFG_RGB_CHART,   CFG_RGB_OFF,     CFG_RGB_CHART,   CFG_RGB_CHART,   CFG_RGB_WHT,     CFG_RGB_WHT,
        CFG_RGB_OFF,     CFG_RGB_WHT,     CFG_RGB_PRBLU,   CFG_RGB_SALMN,   CFG_RGB_PRBLU,   CFG_RGB_BEAVR,   CFG_RGB_WHT,
        CFG_RGB_WHT,     CFG_RGB_CHART,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_CHART,   CFG_RGB_CHART,   CFG_RGB_CHART,
        CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,
        CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_OFF,     CFG_RGB_WHT,     CFG_RGB_WHT,
                                                                                     CFG_RGB_OFF,
                                    CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF,

        CFG_RGB_WHT,     CFG_RGB_SALMN,   CFG_RGB_WHT,     CFG_RGB_OFF,     CFG_RGB_WHT,     CFG_RGB_SALMN,   CFG_RGB_SALMN,
        CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_PRBLU,   CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_WHT,     CFG_RGB_WHT,
        CFG_RGB_WHT,     CFG_RGB_CHART,   CFG_RGB_PRBLU,   CFG_RGB_PRBLU,   CFG_RGB_WHT,     CFG_RGB_CHART,   CFG_RGB_OFF,
                     CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_WHT,
                                  CFG_RGB_PRBLU,   CFG_RGB_WHT,     CFG_RGB_WHT,     CFG_RGB_OFF,     CFG_RGB_PRBLU,
                                                                                     CFG_RGB_OFF,
                                                                  CFG_RGB_OFF,     CFG_RGB_OFF,     CFG_RGB_OFF
    ),
};

// Updated function to use the layout-based map and LED index mapping (using RGB)
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

            // Get the R, G, B values directly from the layout map
            uint8_t r = pgm_read_byte(&ledmap_layout[layer][i][j][0]);
            uint8_t g = pgm_read_byte(&ledmap_layout[layer][i][j][1]);
            uint8_t b = pgm_read_byte(&ledmap_layout[layer][i][j][2]);

            // Apply brightness
            float brightness_factor = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
            r = (uint8_t)(r * brightness_factor);
            g = (uint8_t)(g * brightness_factor);
            b = (uint8_t)(b * brightness_factor);

            // Set the color
            rgb_matrix_set_color(led_index, r, g, b);
        }
    }
}