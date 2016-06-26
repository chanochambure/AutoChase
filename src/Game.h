#ifndef LL_GAME_H_INCLUDED
#define LL_GAME_H_INCLUDED

//DEBUG OPTIONS
    #define GAME_DEBUG
    #ifdef GAME_DEBUG
        #define GAME_DEBUG_TIME 3
    #endif // GAME_DEBUG

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
//    #include "<GAME>/Constants.h"
    #include "Errors.h"

//OPTIONS

    //Language Options
    unsigned int language_map=_LANGUAGE_EN;

    //Functions
    void configure_language_options(unsigned int l_map)
    {
        if(2<l_map)
            errors.loading_interface_options.invalid_language_option=1;
        else
            language_map=l_map;
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
//    #include "<GAME>/AC3Main.h"

void destroy_all()
{
    destroy_loader();
    destroy_fonts();
    destroy_input();
    destroy_timer();
    destroy_display();
    destroy_log();
}

void init_all()
{
    init_log();
    #ifndef GAME_DEBUG
        destroy_log();
    #endif // GAME_DEBUG
    init_display();
    init_timer();
    init_input();
    init_fonts();
    init_loader();
    mixer->set_volume(_audio_volume);
}

//FILE READER
LL::FileStream interface_option_file; //GET OPTIONS

//OPTIONS
void load_interface_options()
{
    LL::StringSplitter load_split;
    load_split.set_string(encryptor_files->decrypt(interface_option_file[0]));
    load_split.split('$');
    if(load_split.size()==_DISPLAY_OPTIONS_TOTAL_DATA)
        configure_display_options(LL::to_int(load_split[0]),LL::to_int(load_split[1]),LL::to_int(load_split[2]));
    else
        errors.loading_interface_options.bad_decrypt_display=1;
    load_split.set_string(encryptor_files->decrypt(interface_option_file[1]));
    load_split.split('$');
    if(load_split.size()==_AUDIO_LANGUAGE_OPTIONS_TOTAL_DATA)
    {
        configure_audio_options(LL::to_int(load_split[0]));
        configure_language_options(LL::to_int(load_split[1]));
    }
    else
        errors.loading_interface_options.bad_decrypt_audio_language=1;
}

void save_interface_options()
{
    interface_option_file.clear_file();
    interface_option_file.insert_line(0,2);
    interface_option_file[0]=encryptor_files->encrypt(LL::to_string(_screen_size_x)+'$'+LL::to_string(_screen_size_y)+'$'+LL::to_string(_screen_mode)+'$');
    interface_option_file[1]=encryptor_files->encrypt(LL::to_string(_audio_volume*10)+'$'+LL::to_string(language_map)+'$');
    interface_option_file.save();
}

void apply_interface_options()
{
    destroy_all();
    init_all();
}

void apply_language_options()
{
    load_game_text();
}

void game_start()
{
    screen->set_real_size(REAL_SIZE_X_GAME,REAL_SIZE_Y_GAME);
   // <GAME>_control();
    screen->set_real_size(_REALSIZEX_TITLE,_REALSIZEY_TITLE);
}

//CONFIGURATION

void game_interface_options_menu_control()
{
    bool save_and_apply_interface_options=0;
    if(exit_program)save_and_apply_interface_options=start_interface_options_menu();
    if(save_and_apply_interface_options)
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
    if(exit_program)start_LL_Logo();
    if(exit_program)start_Opening();
    if(exit_program and start_title_menu())
    {
        while(exit_program and main_menu_option>=0)
        {
            start_main_menu();
            switch(main_menu_option)
            {
                case _MAIN_MENU_INIT_GAME:
                    game_start();
                    break;
                case _MAIN_MENU_OPTIONS_GAME:
                    game_interface_options_menu_control();
                    break;
                case _MAIN_MENU_EXIT_GAME:
                    exit_program=false;
            }
        }
    }
    screen->clear_to_color(BLACK);
    screen->refresh();
}

void exit_game(void)
{
    destroy_all();
    destroy_mixer();
    destroy_encryptor_special_files();
    destroy_encryptor_files();
    LL_AL5::uninstall_audio();
    LL_AL5::uninstall_primitives();
}

void init_game()
{
    //INIT - 1
        _screen_size_x=LL_AL5::desktop_size_x;
        _screen_size_y=LL_AL5::desktop_size_y;
        init_encryptor_files();
        init_encryptor_special_files();
    //LOAD
        interface_option_file.set_path(INTERFACE_OPTIONS_PATH);
        if(!(errors.loading_interface_options.loading_interface_options_file=!interface_option_file.load()))
            load_interface_options();
        if(errors.loading_interface_options.check())
            save_interface_options();
    //INIT - 2
        load_game_text();
        init_colors();
        init_mixer();
        init_all();
    //GAME
    if(exit_program)
        game_control();
    #ifdef GAME_DEBUG
        errors.check_all_system();
        LL_AL5::sleep(GAME_DEBUG_TIME);
    #endif // GAME_DEBUG
}

#endif // LL_GAME_H_INCLUDED
