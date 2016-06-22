#ifndef GAMETEXT_H_INCLUDED
#define GAMETEXT_H_INCLUDED

//#include "<GAME>/GameText.h"

struct ErrorsText
{
    string title;
    string header_file;
    string header_internal;
    string message_interface_options_internal_error;
};

struct TitleMenuText
{
    string start_game;
};

#ifdef GAME_DEMO
struct DemoText
{
    string middle_text;
};
#endif // GAME_DEMO

struct MainMenuText
{
    string init_game;
    string options_game;
    string exit_game;
    string controls;
};

struct InterfaceOptionsMenuText
{
    string title;
    string select_display_size;
        string display_size_1;
        string display_size_2="640X480";
        string display_size_3="800X600";
    string select_display_type;
        string display_type_1;
        string display_type_2;
    string set_audio_volume;
    string select_language;
        string language_EN;
        string language_ES;
        string language_PR;
    string controls;
};

struct GameText
{
    //ERRORS
    ErrorsText error_text;
    //COMMON
    string title;
    string organization="LexRis Logic";
    string release_year="2016";
    string load;
    #ifdef GAME_DEMO
    //DEMO
    DemoText demo_text;
    #endif // GAME_DEMO
    //MENUS
    TitleMenuText title_menu;
    MainMenuText main_menu;
        InterfaceOptionsMenuText interface_options_menu;
    //AUTO CHASE 3
//    <GAME>Text <GAME>;
};

#endif // GAMETEXT_H_INCLUDED
