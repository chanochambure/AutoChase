#ifndef INCLUDED_GAME_COLORS_H
#define INCLUDED_GAME_COLORS_H

//BASICS
LL_AL5::Color WHITE;
LL_AL5::Color SIMPLE_WHITE;
LL_AL5::Color RED;
LL_AL5::Color GREEN;
LL_AL5::Color BLUE;
LL_AL5::Color BLACK;
LL_AL5::Color ORANGE;
LL_AL5::Color YELLOW;
LL_AL5::Color GRAY;
LL_AL5::Color BLACK_GRAY;
LL_AL5::Color TURQUOISE;

void init_colors()
{
    WHITE=LL_AL5::Color(255,255,255);
    SIMPLE_WHITE=LL_AL5::Color(245,245,245);
    RED=LL_AL5::Color(255,0,0);
    GREEN=LL_AL5::Color(0,255,0);
    BLUE=LL_AL5::Color(0,0,255);
    BLACK=LL_AL5::Color(0,0,0);
    ORANGE=LL_AL5::Color(255,128,0);
    YELLOW=LL_AL5::Color(255,255,0);
    GRAY=LL_AL5::Color(128,128,128);
    BLACK_GRAY=LL_AL5::Color(51,51,51);
    TURQUOISE=LL_AL5::Color(0,255,255);
}

#endif // INCLUDED_GAME_COLORS_H
