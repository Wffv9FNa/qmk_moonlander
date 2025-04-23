#ifndef RGB_CONFIG_H
#define RGB_CONFIG_H

#include "quantum.h"

// Function to set the RGB layer color based on the ledmap
void set_layer_color(int layer);

// Macro to visually define LED colors based on physical layout (72 keys)
// Maps the 72 visual arguments to the correct [MATRIX_ROWS(12)][MATRIX_COLS(7)] structure
// The macro itself expands into HSV triplets {H, S, V}, which are expected by set_layer_color.
#define COLOR_LAYOUT( \
    c00, c01, c02, c03, c04, c05, c06,   c60, c61, c62, c63, c64, c65, c66, \
    c10, c11, c12, c13, c14, c15, c16,   c70, c71, c72, c73, c74, c75, c76, \
    c20, c21, c22, c23, c24, c25, c26,   c80, c81, c82, c83, c84, c85, c86, \
    c30, c31, c32, c33, c34, c35,             c91, c92, c93, c94, c95, c96, \
    c40, c41, c42, c43, c44,      c53,   kb3,      ca2, ca3, ca4, ca5, ca6, \
                        c50, c51, c52,   kb4, kb5, kb6                       \
) { /* Expands to [12][7][3] array storing {H,S,V} */ \
    /* ROW 0 */ { c00, c01, c02, c03, c04, c05, c06 }, \
    /* ROW 1 */ { c10, c11, c12, c13, c14, c15, c16 }, \
    /* ROW 2 */ { c20, c21, c22, c23, c24, c25, c26 }, \
    /* ROW 3 */ { c30, c31, c32, c33, c34, c35, {0,0,0} }, \
    /* ROW 4 */ { c40, c41, c42, c43, c44, {0,0,0}, {0,0,0} }, \
    /* ROW 5 */ { c50, c51, c52, c53, {0,0,0}, {0,0,0}, {0,0,0} }, \
    /* ROW 6 */ { c60, c61, c62, c63, c64, c65, c66 }, \
    /* ROW 7 */ { c70, c71, c72, c73, c74, c75, c76 }, \
    /* ROW 8 */ { c80, c81, c82, c83, c84, c85, c86 }, \
    /* ROW 9 */ { {0,0,0}, c91, c92, c93, c94, c95, c96 }, \
    /* ROW 10 */{ {0,0,0}, {0,0,0}, ca2, ca3, ca4, ca5, ca6 }, \
    /* ROW 11 */{ {0,0,0}, {0,0,0}, {0,0,0}, kb3, kb4, kb5, kb6 }  \
}

#endif // RGB_CONFIG_H