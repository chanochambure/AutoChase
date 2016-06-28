#ifndef INCLUDED_GAME_H
#define INCLUDED_GAME_H

//DEBUG OPTIONS
#define DEBUG_OPTION
#ifdef DEBUG_OPTION
   #define DEBUG_OPTION_TIME 3
#endif // DEBUG_OPTION

//DEMO OPTIONS
#define GAME_DEMO
#ifdef GAME_DEMO
    #define GAME_DEMO_WAIT_TIME 20
#endif // GAME_DEMO

//LIBRARY INCLUDE
//API
#include "../LexRisLogic/Allegro5/Allegro.h"
//EXTRA
#include "../LexRisLogic/Convert.h"
#include "../LexRisLogic/Math.h"
#include "../LexRisLogic/Time.h"
#include "../LexRisLogic/Encryptor.h"
#include "../LexRisLogic/FileStream.h"
#include "../LexRisLogic/StringSplitter.h"

//HEADERS INCLUDE
#include "Constants.h"
//#include "<GAME>/Constants.h"
#include "Errors.h"

//OPTIONS
//Language Options
unsigned int language_map=LANGUAGE_EN;

void set_language(unsigned int new_language_map)
{
    if(new_language_map<TOTAL_LANGUAGES)
        language_map=new_language_map;
    else
        errors.loading_interface_options.invalid_language_option=true;
}

//HEADERS INCLUDE
#include "Language/Language.h"
#include "Objects/Objects.h"

//GAME INCLUDE
#include "Game/Loading.h"
#include "Game/LL_Logo.h"
#include "Game/Opening.h"
#include "Game/TitleMenu.h"
#include "Game/MainMenu.h"
//#include "<GAME>/Main.h"

//FILE READER
LL::FileStream interface_option_file;
LL::StringSplitter splitter;

//INTERFACE OPTIONS
void load_interface_options()
{
    splitter.set_string(encryptor_files->decrypt(interface_option_file[0]));
    splitter.split('$');
    if(splitter.size()==SCREEN_OPTIONS_TOTAL_DATA)
        configure_display_options(LL::to_int(splitter[0]),LL::to_int(splitter[1]),LL::to_int(splitter[2]));
    else
        errors.loading_interface_options.bad_decrypt_display=true;
    splitter.set_string(encryptor_files->decrypt(interface_option_file[1]));
    splitter.split('$');
    if(splitter.size()==AUDIO_LANGUAGE_OPTIONS_TOTAL_DATA)
    {
        configure_audio_options(LL::to_int(splitter[0]));
        set_language(LL::to_int(splitter[1]));
    }
    else
        errors.loading_interface_options.bad_decrypt_audio_language=true;
    splitter.clear();
}

void save_interface_options()
{
    interface_option_file.clear_file();
    interface_option_file.insert_line(0,2);
    interface_option_file[0]=encryptor_files->encrypt(LL::to_string(global_screen_option_size_x)+'$'+
                                                      LL::to_string(global_screen_option_size_y)+'$'+
                                                      LL::to_string(global_screen_mode_option)+'$');
    interface_option_file[1]=encryptor_files->encrypt(LL::to_string(global_volume_option*NORMAL_VOLUME)+'$'+
                                                      LL::to_string(language_map)+'$');
    interface_option_file.save();
}

void apply_interface_options()
{
    destroy_loader();
    destroy_objects();
    init_objects();
    init_loader();
}

void apply_language_options()
{
    load_game_text();
}

void game_start()
{
    screen->set_real_size(REAL_SIZE_X_GAME,REAL_SIZE_Y_GAME);
//    <GAME>_control();
    screen->set_real_size(REAL_SIZE_X_TITLE,REAL_SIZE_Y_TITLE);
}

//CONFIGURATION

void game_interface_options_menu_control()
{
    bool save_and_apply_interface_options=false;
    if(game_running)
        save_and_apply_interface_options=start_interface_options_menu();
    if(game_running and save_and_apply_interface_options)
    {
        if(has_changes)
            apply_interface_options();
        if(has_language_changes)
            apply_language_options();
        save_interface_options();
    }
}

void game_control()
{
    if(game_running)
    {
        start_LL_Logo();
        if(game_running)
        {
            start_Opening();
            if(game_running and start_title_menu())
            {
                while(game_running and main_menu_option>=0)
                {
                    start_main_menu();
                    switch(main_menu_option)
                    {
                        case MAIN_MENU_INIT_GAME:
                            game_start();
                            break;
                        case MAIN_MENU_OPTIONS_GAME:
                            game_interface_options_menu_control();
                            break;
                        case MAIN_MENU_EXIT_GAME:
                            game_running=false;
                    }
                }
            }
        }
    }
    screen->clear_to_color(BLACK);
    screen->refresh();
}

void exit_game(void)
{
    destroy_key_control();
    destroy_loader();
    destroy_objects();
    destroy_mixer();
    destroy_encryptor_files();
    LL_AL5::uninstall_audio();
    LL_AL5::uninstall_primitives();
}

void init_game()
{
    //INIT - 1
    global_screen_option_size_x=LL_AL5::desktop_size_x;
    global_screen_option_size_y=LL_AL5::desktop_size_y;
    init_encryptor_files();
    //LOAD
    interface_option_file.set_path(INTERFACE_OPTIONS_PATH);
    if(!(errors.loading_interface_options.loading_interface_options_file=!interface_option_file.load()))
        load_interface_options();
    if(errors.loading_interface_options.check())
        save_interface_options();
    //INIT - 2
    load_game_text();
    init_colors();
    init_key_control();
    init_mixer();
    init_objects();
    init_loader();
    //GAME
    if(game_running)
        game_control();
    #ifdef DEBUG_OPTION
        errors.check_all_system();
        LL_AL5::sleep(DEBUG_OPTION_TIME);
    #endif // DEBUG_OPTION
}

#endif // INCLUDED_GAME_H
