#ifndef INCLUDED_GAME_COLORS_H
#define INCLUDED_GAME_COLORS_H

//BASICS
LL_AL5::Color WHITE;
LL_AL5::Color RED;
LL_AL5::Color GREEN;
LL_AL5::Color BLUE;
LL_AL5::Color BLACK;
LL_AL5::Color ORANGE;
LL_AL5::Color GRAY;
LL_AL5::Color BLACK_GRAY;

void init_colors()
{
    WHITE=al_map_rgb(255,255,255);
    RED=al_map_rgb(255,0,0);
    GREEN=al_map_rgb(0,255,0);
    BLUE=al_map_rgb(0,0,255);
    BLACK=al_map_rgb(0,0,0);
    ORANGE=al_map_rgb(255,128,0);
    GRAY=al_map_rgb(128,128,128);
    BLACK_GRAY=al_map_rgb(51,51,51);
}

#endif // INCLUDED_GAME_COLORS_H
