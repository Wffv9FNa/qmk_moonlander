#include QMK_KEYBOARD_H
#include "quantum.h"
#include "rgb_config.h"
#include "color_aliases.h"

// New layout-based LED map, defined using COLOR_LAYOUT and HSV aliases
static const uint8_t PROGMEM ledmap_layout[][MATRIX_ROWS][MATRIX_COLS][3] = {
//clang-format off
/*  _                             ___   */
/* | |    __ _ _   _  ___ _ __   / _ \  */
/* | |   / _` | | | |/ _ \ '__| | | | | */
/* | |__| (_| | |_| |  __/ |    | |_| | */
/* |_____\__,_|\__, |\___|_|     \___/  */
/*             |___/                    */
    [0] = COLOR_LAYOUT( //Home
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               --- */
        CLR_YELLOW ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_OFF    ,        CLR_OFF    ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_YELLOW ,
        CLR_WHT    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_OFF    ,        CLR_OFF    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,
        CLR_WHT    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,        CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,    CLR_YELLOW ,
        CLR_RED    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_RED    ,
        CLR_PSPYR  ,    CLR_RED    ,    CLR_WHT    ,    CLR_PSPYR  ,    CLR_PSPYR  ,    /*XXXXXXXX*/    CLR_RED    ,        CLR_RED    ,    /*XXXXXXXX*/    CLR_PSPYR  ,    CLR_WHT    ,    CLR_WHT    ,    CLR_YELLOW ,    CLR_PSPYR  ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_WHT    ,    CLR_RED    ,    CLR_RED    ,        CLR_WHT    ,    CLR_WHT    ,    CLR_WHT         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            _  */
/* | |    __ _ _   _  ___ _ __  / | */
/* | |   / _` | | | |/ _ \ '__| | | */
/* | |__| (_| | |_| |  __/ |    | | */
/* |_____\__,_|\__, |\___|_|    |_| */
/*             |___/                */
    [1] = COLOR_LAYOUT( //Numpad
    /*  =               1               2               3               4               5               --                  --              6               7               8               9               0               --           */
        CLR_OFF    ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_OFF    ,        CLR_OFF    ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_OFF    ,    CLR_RED    ,    CLR_OFF    ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_CYAN   ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_OFF    ,    CLR_YELLOW ,    CLR_OFF    ,    CLR_YELLOW ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_CYAN   ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_GREEN  ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,        CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_OFF    ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  |___ \  */
/* | |   / _` | | | |/ _ \ '__|   __) | */
/* | |__| (_| | |_| |  __/ |     / __/  */
/* |_____\__,_|\__, |\___|_|    |_____| */
/*             |___/                    */
    [2] = COLOR_LAYOUT( //Arrows
    /*  =               1               2               3               4               5               --                  --              6               7               8               9               0               --           */
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_YELLOW ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_CYAN   ,    CLR_OFF    ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_OFF    ,    CLR_YELLOW ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_CYAN   ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_YELLOW ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,        CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            _____  */
/* | |    __ _ _   _  ___ _ __  |___ /  */
/* | |   / _` | | | |/ _ \ '__|   |_ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [3] = COLOR_LAYOUT( //WordMon
    /*  =               1               2               3               4               5               --                  --              6               7               8               9               0               --           */
        CLR_CYAN   ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_OFF    ,        CLR_OFF    ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_OFF    ,    CLR_RED    ,    CLR_YELLOW ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_RED    ,    CLR_RED    ,    CLR_YELLOW ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_RED    ,    CLR_RED    ,    CLR_OFF    ,    CLR_RED    ,    CLR_OFF    ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,        CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_GREEN  ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            _  _    */
/* | |    __ _ _   _  ___ _ __  | || |   */
/* | |   / _` | | | |/ _ \ '__| | || |_  */
/* | |__| (_| | |_| |  __/ |    |__   _| */
/* |_____\__,_|\__, |\___|_|       |_|   */
/*             |___/                     */
    [4] = COLOR_LAYOUT( //Games
    /*  =               1               2               3               4               5               --                  --              6               7               8               9               0               --           */
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_MAGENTA,    CLR_OFF    ,        CLR_OFF    ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_WHT    ,    CLR_RED    ,    CLR_WHT    ,    CLR_WHT    ,    CLR_WHT    ,    CLR_OFF    ,        CLR_BLUE   ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_MAGENTA,
        CLR_YELLOW ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_WHT    ,    CLR_WHT    ,    CLR_MAGENTA,        CLR_BLUE   ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_YELLOW ,    CLR_WHT    ,    CLR_WHT    ,    CLR_WHT    ,    CLR_WHT    ,    CLR_WHT    ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_YELLOW ,
        CLR_YELLOW ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/    CLR_YELLOW ,        CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_YELLOW ,    CLR_YELLOW ,    CLR_YELLOW ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            ____   */
/* | |    __ _ _   _  ___ _ __  | ___|  */
/* | |   / _` | | | |/ _ \ '__| |___ \  */
/* | |__| (_| | |_| |  __/ |     ___) | */
/* |_____\__,_|\__, |\___|_|    |____/  */
/*             |___/                    */
    [5] = COLOR_LAYOUT( //Japanese
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               --- */
        CLR_YELLOW ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_OFF    ,        CLR_OFF    ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_YELLOW ,
        CLR_WHT    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,        CLR_OFF    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,
        CLR_WHT    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,        CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,    CLR_YELLOW ,
        CLR_RED    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_RED    ,
        CLR_PSPYR  ,    CLR_RED    ,    CLR_WHT    ,    CLR_PSPYR  ,    CLR_PSPYR  ,    /*XXXXXXXX*/    CLR_RED    ,        CLR_RED    ,    /*XXXXXXXX*/    CLR_PSPYR  ,    CLR_WHT    ,    CLR_WHT    ,    CLR_YELLOW ,    CLR_PSPYR  ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_WHT    ,    CLR_RED    ,    CLR_RED    ,        CLR_WHT    ,    CLR_WHT    ,    CLR_WHT         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
};
//clang-format on
// Updated function to use the layout-based map and LED index mapping (now expecting HSV)
void set_layer_color(int layer)
{
    // Ensure g_led_config is accessible (defined in keyboard's .c file)
    extern led_config_t g_led_config;
    // Need access to rgb_matrix_config for brightness adjustment
    extern rgb_config_t rgb_matrix_config;

    // Check if the requested layer exists in our map
    if (layer >= (sizeof(ledmap_layout) / sizeof(ledmap_layout[0])))
    {
        rgb_matrix_set_color_all(0, 0, 0);
        return;
    }

    for (uint8_t i = 0; i < MATRIX_ROWS; i++)
    {
        for (uint8_t j = 0; j < MATRIX_COLS; j++)
        {
            uint8_t led_index = g_led_config.matrix_co[i][j];
            if (led_index == NO_LED)
            {
                continue;
            }

            // Get the H, S, V values directly from the layout map
            HSV hsv = {
                .h = pgm_read_byte(&ledmap_layout[layer][i][j][0]),
                .s = pgm_read_byte(&ledmap_layout[layer][i][j][1]),
                .v = pgm_read_byte(&ledmap_layout[layer][i][j][2]),
            };

            // Set the color (applying brightness)
            if (!hsv.h && !hsv.s && !hsv.v)
            {
                // If color is {0,0,0}, explicitly turn LED off
                rgb_matrix_set_color(led_index, 0, 0, 0);
            }
            else
            {
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
