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
    string controls_options[TOTAL_CONTROLS_OPTIONS];
};

struct ACAreYouReadyText
{
    string ready;
    string go;
};

struct ACGameText
{
    string score_label;
    string record_label;
};

struct ACPauseText
{
    string pause_label;
    string continue_option;
    string exit_game_option;
    string new_game_option;
};

struct ACEndGameText
{
    string end_game_label;
    string exit_game_option;
    string new_game_option;
};

struct ACErrorText
{
    string controls_option;
    string create_player;
    string create_enemies;
};

struct AutoChaseText
{
    //ERRORS
    ACErrorText error_text;
    //MENUS
    ACMainMenuText main_menu;
    ACConfigurationMenuText configuration_menu;
    //GAMES
    ACAreYouReadyText are_you_ready;
    ACPauseText pause;
    ACGameText game;
    ACEndGameText end_game;
};

#endif // INCLUDED_AC_GAME_TEXT_H
