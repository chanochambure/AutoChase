#ifndef INCLUDED_AC_GAME_TEXT_H
#define INCLUDED_AC_GAME_TEXT_H

struct ACMainMenuText
{
    string play_game;
    string configuration;
    string exit;
    string controls;
};

struct ACConfigurationMenuText
{
    string title;
    string car_type;
    string car_color;
    string difficulty;
    string controls;
    string difficulties[TOTAL_DIFFICULTIES];
    string types[CAR_TYPE_TOTAL_OPTIONS];
    string colors[CAR_COLOR_TOTAL_OPTIONS];
};

struct AutoChaseText
{
    //COMMON
    //MENUS
    ACMainMenuText main_menu;
    ACConfigurationMenuText configuration_menu;
};

#endif // INCLUDED_AC_GAME_TEXT_H
