#pragma once // Ensure this header is included only once during compilation (include guard)

// Basic Colors
#define CLR_OFF         {   0,   0,   0 } // Black / Off
#define CLR_WHT         {   0,   0, 255 } // White
#define CLR_SYDHARB     { 139,  61, 200 } // SydneyHarbour

// Reds / Pinks
#define CLR_RED         {   0, 255, 255 } // Red (RGB 255,0,0)
#define CLR_MAGENTA     { 213, 255, 255 } // Magenta (RGB 255,0,255)
#define CLR_TLMGNTA     { 217, 235, 252 } // Telemagenta
#define CLR_PSPYR       { 206, 198, 176 } // Pink Spyro (RGB ~156,39,176)
#define CLR_SALMN       {   2, 198, 244 } // Salmon Pink (RGB ~244,157,162)
#define CLR_PURPLE      { 200, 255, 255 } // Purple (RGB 255,0,255)
#define CLR_ORANGE      {  20, 255, 255 } // Orange (RGB 255,165,0)
#define CLR_VERMLN      {   7, 255, 255 } // Vermilion
#define CLR_ORNGRED     {  11, 255, 255 } // Orange-Red

// Browns
#define CLR_BEAVR       {  22, 108, 176 } // Beaver Brown (RGB ~159,129,112) - Adjusted HSV for better RGB match

// Yellows / Greens
#define CLR_YELLOW      {  43, 255, 255 } // Yellow (RGB 255,255,0)
#define CLR_GREEN       {  85, 255, 255 } // Green (RGB 0,255,0)
#define CLR_CHART       {  32, 248, 255 } // Chartreuse (RGB ~134,255,4)
#define CLR_SPGRN       {  74, 255, 206 } // Spring Green (RGB ~0,206,103)
#define CLR_SEGRN       {  87, 144, 175 } // Sea Green (RGB ~90,175,123)
#define CLR_AQUA        { 124, 255, 150 } // Aquamarine-like (RGB ~0,150,75)

// Blues / Cyans
#define CLR_ARTCWTR     { 126, 255, 255 } // ArcticWater
#define CLR_BLUE        { 170, 255, 255 } // Blue (RGB 0,0,255)
#define CLR_CYAN        { 128, 255, 255 } // Cyan (RGB 0,255,255)
#define CLR_CYPRO       { 131, 255, 255 } // Cyan Process (RGB ~0,183,235)
#define CLR_PRBLU       { 148, 220, 243 } // Persian Blue (RGB ~45,96,243)
#define CLR_WHTBLU      { 170, 100, 255 } // White Blue (RGB ~170,100,255)

// 72 bright HSV hues (S=255, V=255), unique names and no conflicts
#define CLR_H004   {   4, 255, 255 } // Red-Orange
#define CLR_H014   {  14, 255, 255 } // Orange
#define CLR_H018   {  18, 255, 255 } // Dark Orange
#define CLR_H021   {  21, 255, 255 } // Pumpkin
#define CLR_H025   {  25, 255, 255 } // Tangerine
#define CLR_H028   {  28, 255, 255 } // Amber
#define CLR_H032   {  32, 255, 255 } // Yellow-Orange
#define CLR_H036   {  36, 255, 255 } // Goldenrod
#define CLR_H039   {  39, 255, 255 } // Gold
#define CLR_H043   {  43, 255, 255 } // Yellow
#define CLR_H046   {  46, 255, 255 } // Lemon
#define CLR_H050   {  50, 255, 255 } // Canary
#define CLR_H053   {  53, 255, 255 } // Chartreuse-Yellow
#define CLR_H057   {  57, 255, 255 } // Chartreuse
#define CLR_H061   {  61, 255, 255 } // Yellow-Green
#define CLR_H064   {  64, 255, 255 } // Lime-Green
#define CLR_H068   {  68, 255, 255 } // Lime
#define CLR_H071   {  71, 255, 255 } // Lawn Green
#define CLR_H075   {  75, 255, 255 } // Spring Green
#define CLR_H078   {  78, 255, 255 } // Medium Spring
#define CLR_H082   {  82, 255, 255 } // Aquamarine
#define CLR_H086   {  86, 255, 255 } // Turquoise-Green
#define CLR_H089   {  89, 255, 255 } // Turquoise
#define CLR_H093   {  93, 255, 255 } // Medium Turquoise
#define CLR_H096   {  96, 255, 255 } // Cyan-Green
#define CLR_H100   { 100, 255, 255 } // Sea Green
#define CLR_H103   { 103, 255, 255 } // Light Sea Green
#define CLR_H107   { 107, 255, 255 } // Deep Sea
#define CLR_H111   { 111, 255, 255 } // Teal
#define CLR_H114   { 114, 255, 255 } // Blue-Green
#define CLR_H118   { 118, 255, 255 } // Aqua
#define CLR_H121   { 121, 255, 255 } // Cyan
#define CLR_H125   { 125, 255, 255 } // Electric Cyan
#define CLR_H129   { 129, 255, 255 } // Sky Blue
#define CLR_H132   { 132, 255, 255 } // Capri
#define CLR_H136   { 136, 255, 255 } // Dodger Blue
#define CLR_H139   { 139, 255, 255 } // Azure
#define CLR_H143   { 143, 255, 255 } // Blue
#define CLR_H146   { 146, 255, 255 } // Medium Blue
#define CLR_H150   { 150, 255, 255 } // Royal Blue
#define CLR_H154   { 154, 255, 255 } // Cobalt
#define CLR_H157   { 157, 255, 255 } // Indigo Blue
#define CLR_H161   { 161, 255, 255 } // Indigo
#define CLR_H164   { 164, 255, 255 } // Violet-Blue
#define CLR_H168   { 168, 255, 255 } // Violet
#define CLR_H171   { 171, 255, 255 } // Blue-Violet
#define CLR_H175   { 175, 255, 255 } // Purple
#define CLR_H179   { 179, 255, 255 } // Dark Purple
#define CLR_H182   { 182, 255, 255 } // Deep Purple
#define CLR_H186   { 186, 255, 255 } // Amethyst
#define CLR_H189   { 189, 255, 255 } // Orchid
#define CLR_H193   { 193, 255, 255 } // Medium Violet
#define CLR_H196   { 196, 255, 255 } // Fuchsia
#define CLR_H200   { 200, 255, 255 } // Hot Pink
#define CLR_H204   { 204, 255, 255 } // Pink
#define CLR_H207   { 207, 255, 255 } // Deep Pink
#define CLR_H211   { 211, 255, 255 } // Reddish Pink
#define CLR_H214   { 214, 255, 255 } // Rose
#define CLR_H218   { 218, 255, 255 } // Crimson
#define CLR_H221   { 221, 255, 255 } // Raspberry
#define CLR_H225   { 225, 255, 255 } // Cerise
#define CLR_H229   { 229, 255, 255 } // Red-Violet
#define CLR_H232   { 232, 255, 255 } // Dark Magenta
#define CLR_H236   { 236, 255, 255 } // Strong Magenta
#define CLR_H239   { 239, 255, 255 } // Electric Magenta
#define CLR_H243   { 243, 255, 255 } // Neon Magenta
#define CLR_H246   { 246, 255, 255 } // Fluorescent Pink
#define CLR_H250   { 250, 255, 255 } // Shocking Pink
#define CLR_H252   { 252, 255, 255 } // Red-Pink
