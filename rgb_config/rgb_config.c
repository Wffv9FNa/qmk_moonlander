#include QMK_KEYBOARD_H                               // Core QMK definitions and APIs
#include "quantum.h"                                  // Quantum keycode and function layer utilities
#include "rgb_config.h"                               // RGB matrix configuration interface
#include "color_aliases.h"                            // Human-friendly HSV color name aliases

// New layout-based LED map, defined using COLOR_LAYOUT and HSV aliases
static const uint8_t PROGMEM ledmap_layout[][MATRIX_ROWS][MATRIX_COLS][3] = {
//clang-format off
/*  _                             ___       _   _                       */
/* | |    __ _ _   _  ___ _ __   / _ \     | | | | ___  _ __ ___   ___  */
/* | |   / _` | | | |/ _ \ '__| | | | |    | |_| |/ _ \| '_ ` _ \ / _ \ */
/* | |__| (_| | |_| |  __/ |    | |_| |    |  _  | (_) | | | | | |  __/ */
/* |_____\__,_|\__, |\___|_|     \___/     |_| |_|\___/|_| |_| |_|\___| */
/*             |___/                                                    */
    [0] = COLOR_LAYOUT( //Home
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               --- */
        CLR_YELLOW ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_OFF    ,        CLR_OFF    ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_YELLOW ,
        CLR_WHT    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_PSPYR  ,        CLR_OFF    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,
        CLR_WHT    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,        CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,    CLR_YELLOW ,
        CLR_RED    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_GREEN  ,    CLR_GREEN  ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_YELLOW ,    CLR_RED    ,
        CLR_PSPYR  ,    CLR_RED    ,    CLR_WHT    ,    CLR_PSPYR  ,    CLR_PSPYR  ,    /*XXXXXXXX*/    CLR_RED    ,        CLR_RED    ,    /*XXXXXXXX*/    CLR_PSPYR  ,    CLR_WHT    ,    CLR_WHT    ,    CLR_YELLOW ,    CLR_PSPYR  ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_WHT    ,    CLR_RED    ,    CLR_RED    ,        CLR_WHT    ,    CLR_WHT    ,    CLR_WHT         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            _      _   _                                 _  */
/* | |    __ _ _   _  ___ _ __  / |    | \ | |_   _ _ __ ___  _ __   __ _  __| | */
/* | |   / _` | | | |/ _ \ '__| | |    |  \| | | | | '_ ` _ \| '_ \ / _` |/ _` | */
/* | |__| (_| | |_| |  __/ |    | |    | |\  | |_| | | | | | | |_) | (_| | (_| | */
/* |_____\__,_|\__, |\___|_|    |_|    |_| \_|\__,_|_| |_| |_| .__/ \__,_|\__,_| */
/*             |___/                                         |_|                 */
[1] = COLOR_LAYOUT( //Numpad
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               --           */
        CLR_CYAN   ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_OFF    ,        CLR_OFF    ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_ORANGE ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_ORANGE ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_OFF    ,
        CLR_RED    ,    CLR_YELLOW ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_GREEN  ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_RED    ,
        CLR_OFF    ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,        CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_OFF    ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            ____          _                                */
/* | |    __ _ _   _  ___ _ __  |___ \        / \   _ __ _ __ _____      _____  */
/* | |   / _` | | | |/ _ \ '__|   __) |      / _ \ | '__| '__/ _ \ \ /\ / / __| */
/* | |__| (_| | |_| |  __/ |     / __/      / ___ \| |  | | | (_) \ V  V /\__ \ */
/* |_____\__,_|\__, |\___|_|    |_____|    /_/   \_\_|  |_|  \___/ \_/\_/ |___/ */
/*             |___/                                                            */
    [2] = COLOR_LAYOUT( // WordMon + Arrows
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               ---          */
        CLR_CYAN   ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_OFF    ,        CLR_OFF    ,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_OFF    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_CYGRN  ,    CLR_YELLOW ,    CLR_GREEN  ,    CLR_RED    ,    CLR_GREEN  ,    CLR_OFF    ,    CLR_MAGENTA,
        CLR_PURPLE ,    CLR_OFF    ,    CLR_ORNGRED,    CLR_GREEN  ,    CLR_ORNGRED,    CLR_OFF    ,    CLR_OFF    ,        CLR_CYGRN  ,    CLR_YELLOW ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_RED    ,    CLR_OFF    ,    CLR_PRBLU  ,    CLR_YELLOW ,    CLR_PRBLU  ,    CLR_OFF    ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_RED    ,
        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,        CLR_OFF    ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_GREEN  ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),

/*  _                            _____      __  __                       */
/* | |    __ _ _   _  ___ _ __  |___ /     |  \/  | ___  _   _ ___  ___  */
/* | |   / _` | | | |/ _ \ '__|   |_ \     | |\/| |/ _ \| | | / __|/ _ \ */
/* | |__| (_| | |_| |  __/ |     ___) |    | |  | | (_) | |_| \__ \  __/ */
/* |_____\__,_|\__, |\___|_|    |____/     |_|  |_|\___/ \__,_|___/\___| */
/*             |___/                                                     */
    [3] = COLOR_LAYOUT( // Mouse
    /*  =               1                 2               3             4               5               ---                 ---             6               7               8               9               0               ---       */
        CLR_OFF    ,    CLR_OFF    ,      CLR_OFF  ,      CLR_OFF  ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_MAGENTA,    CLR_OFF    ,      CLR_OFF  ,      CLR_OFF  ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_YELLOW ,    CLR_RED    ,    CLR_CYAN   ,    CLR_RED    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_MAGENTA,    CLR_OFF    ,      CLR_OFF  ,      CLR_OFF  ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_YELLOW ,    CLR_CYAN   ,    CLR_CYAN   ,    CLR_CYAN   ,    CLR_GREEN  ,    CLR_OFF    ,
        CLR_MAGENTA,    CLR_OFF    ,      CLR_OFF  ,      CLR_OFF  ,    CLR_OFF    ,    CLR_OFF    ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_MAGENTA,
        CLR_OFF    ,    CLR_OFF    ,      CLR_OFF  ,      CLR_OFF  ,    CLR_OFF    ,    /*XXXXXXXX*/    CLR_MAGENTA,        CLR_MAGENTA,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        /*XXXXXXXX*/   /*XXXXXXXXX*/       /*XXXXXXXX*/   /*XXXXXXX*/   CLR_MAGENTA,    CLR_MAGENTA,    CLR_OFF    ,        CLR_OFF    ,    CLR_MAGENTA,    CLR_OFF         /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),
/*  _                            _  _         ____                            */
/* | |    __ _ _   _  ___ _ __  | || |       / ___| __ _ _ __ ___   ___  ___  */
/* | |   / _` | | | |/ _ \ '__| | || |_     | |  _ / _` | '_ ` _ \ / _ \/ __| */
/* | |__| (_| | |_| |  __/ |    |__   _|    | |_| | (_| | | | | | |  __/\__ \ */
/* |_____\__,_|\__, |\___|_|       |_|       \____|\__,_|_| |_| |_|\___||___/ */
/*             |___/                                                          */
    [4] = COLOR_LAYOUT( // Gaming Layer with Macro RGB
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               ---           */
        CLR_OFF    ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_OFF    ,        CLR_YELLOW ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,    CLR_BLUE   ,
        CLR_OFF    ,    CLR_RED    ,    CLR_GREEN  ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_OFF    ,        CLR_BLUE   ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_BLUE   ,
        CLR_CYAN   ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_GREEN  ,    CLR_RED    ,    CLR_RED    ,    CLR_OFF    ,        CLR_BLUE   ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_CYAN   ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        CLR_CYAN   ,    CLR_OFF    ,    CLR_OFF    ,    CLR_ORANGE ,    CLR_MAGENTA,    /*XXXXXXXX*/    CLR_ORANGE ,        CLR_CYAN   ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,    CLR_OFF    ,
        /*XXXXXXXX*/   /*XXXXXXXX*/     /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_CYAN   ,    CLR_CYAN   ,    CLR_CYAN   ,        CLR_CYAN   ,    CLR_OFF    ,    CLR_CYAN        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
),


/*  _                            ____       _  __                  */
/* | |    __ _ _   _  ___ _ __  | ___|     | |/ /__ _ _ __   __ _  */
/* | |   / _` | | | |/ _ \ '__| |___ \     | ' // _` | '_ \ / _` | */
/* | |__| (_| | |_| |  __/ |     ___) |    | . \ (_| | | | | (_| | */
/* |_____\__,_|\__, |\___|_|    |____/     |_|\_\__,_|_| |_|\__,_| */
/*             |___/                                               */
    [5] = COLOR_LAYOUT( //Kana Layer
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               --- */
        CLR_ORANGE ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_OFF    ,        CLR_OFF    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_RED    ,    CLR_ORANGE ,
        CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_MAGENTA,        CLR_OFF    ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_ORANGE ,
        CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_MAGENTA,        CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_ORANGE ,    CLR_ORANGE ,
        CLR_CYAN   ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_PURPLE ,    CLR_PURPLE ,    CLR_ORANGE ,    CLR_ORANGE ,    CLR_ORANGE ,    CLR_CYAN   ,
        CLR_OFF    ,    CLR_CYAN   ,    CLR_PURPLE ,    CLR_OFF    ,    CLR_PSPYR  ,    /*XXXXXXXX*/    CLR_RED    ,        CLR_CYAN   ,    /*XXXXXXXX*/    CLR_OFF    ,    CLR_PURPLE ,    CLR_PURPLE ,    CLR_ORANGE ,    CLR_OFF    ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_PURPLE ,    CLR_CYAN   ,    CLR_WHTBLU ,        CLR_PURPLE ,    CLR_PURPLE ,    CLR_PURPLE      /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
),

/*  _                            __           ____   ____ ____  */
/* | |    __ _ _   _  ___ _ __  / /_         / ___|/ ___|  _ \ */
/* | |   / _` | | | |/ _ \ '__| | '_ \       | |  _| |   | |_) | */
/* | |__| (_| | |_| |  __/ |    | (_) |      | |_| | |___| |_) | */
/* |_____\__,_|\__, |\___|_|     \___/        \____|\____|____/ */
/*             |___/                                           */
    [6] = COLOR_LAYOUT( // HSV Color Display Layer - All 72 colors
    /*  =               1               2               3               4               5               ---                 ---             6               7               8               9               0               --- */
        CLR_RED    ,    CLR_H004   ,    CLR_VERMLN ,    CLR_ORNGRED,    CLR_ORANGE ,    CLR_H018   ,    CLR_H021   ,        CLR_H025   ,    CLR_H028   ,    CLR_H032   ,    CLR_H036   ,    CLR_H039   ,    CLR_H043   ,    CLR_H046   ,
        CLR_H050   ,    CLR_H053   ,    CLR_H057   ,    CLR_H061   ,    CLR_H064   ,    CLR_H068   ,    CLR_H071   ,        CLR_H075   ,    CLR_H078   ,    CLR_H082   ,    CLR_H086   ,    CLR_H089   ,    CLR_H093   ,    CLR_CYGRN  ,
        CLR_H100   ,    CLR_H103   ,    CLR_H107   ,    CLR_H111   ,    CLR_H114   ,    CLR_H118   ,    CLR_H121   ,        CLR_H125   ,    CLR_H129   ,    CLR_H132   ,    CLR_H136   ,    CLR_H139   ,    CLR_H143   ,    CLR_H146   ,
        CLR_H150   ,    CLR_H154   ,    CLR_H157   ,    CLR_H161   ,    CLR_H164   ,    CLR_H168   ,    /*XXXXXXXX*/        /*XXXXXXXX*/    CLR_H171   ,    CLR_H175   ,    CLR_H179   ,    CLR_H182   ,    CLR_H186   ,    CLR_H189   ,
        CLR_H193   ,    CLR_H196   ,    CLR_H200   ,    CLR_H204   ,    CLR_H207   ,    /*XXXXXXXX*/    CLR_H211   ,        CLR_H214   ,    /*XXXXXXXX*/    CLR_H218   ,    CLR_H221   ,    CLR_H225   ,    CLR_H229   ,    CLR_H232   ,
        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    CLR_H236   ,    CLR_H239   ,    CLR_H243   ,        CLR_H246   ,    CLR_H250   ,    CLR_H252        /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/    /*XXXXXXXX*/
    ),

};
//clang-format on
// Updated function to use the layout-based map and LED index mapping (now expecting HSV)
void set_layer_color(int layer)
{
    extern led_config_t g_led_config;                      // Ensure g_led_config is accessible (defined in keyboard .c file)
    extern rgb_config_t rgb_matrix_config;                 // Access rgb_matrix_config for brightness adjustment

    if (layer >= (sizeof(ledmap_layout) / sizeof(ledmap_layout[0]))) // Check if requested layer index is valid
    {
        rgb_matrix_set_color_all(0, 0, 0);                 // If invalid, turn off all LEDs
        return;                                            // Exit early
    }

    for (uint8_t i = 0; i < MATRIX_ROWS; i++)                                         // Loop through matrix rows
    {
        for (uint8_t j = 0; j < MATRIX_COLS; j++)                                     // Loop through matrix columns
        {
            uint8_t led_index = g_led_config.matrix_co[i][j];                         // Convert matrix coords to LED index
            if (led_index == NO_LED)                                                  // Skip if no LED assigned at this position
            {
                continue;                                                             // Move on to next key
            }

            HSV hsv = {                                                               // Get HSV values directly from LED layout map
                .h = pgm_read_byte(&ledmap_layout[layer][i][j][0]),
                .s = pgm_read_byte(&ledmap_layout[layer][i][j][1]),
                .v = pgm_read_byte(&ledmap_layout[layer][i][j][2]),
            };

            if (!hsv.h && !hsv.s && !hsv.v)                                           // If HSV is {0,0,0}, treat as LED off
            {
                rgb_matrix_set_color(led_index, 0, 0, 0);                             // Explicitly turn LED off
            }
            else
            {
                RGB rgb = hsv_to_rgb(hsv);                                            // Convert HSV values to RGB
                float brightness_factor = (float)rgb_matrix_config.hsv.v / UINT8_MAX; // Apply global brightness factor
                rgb_matrix_set_color(
                    led_index,
                    (uint8_t)(rgb.r * brightness_factor),
                    (uint8_t)(rgb.g * brightness_factor),
                    (uint8_t)(rgb.b * brightness_factor));                            // Set LED color with brightness applied
            }
        }
    }
}
