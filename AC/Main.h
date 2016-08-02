#ifndef INCLUDED_AC_MAIN_H
#define INCLUDED_AC_MAIN_H

//Main Data
int ac_difficulty=DIFFICULTY_EASY;
int ac_car_type=CAR_TYPE_AUTO;
int ac_car_color=CAR_COLOR_BLACK;
int ac_records[TOTAL_DIFFICULTIES]={0,0,0};
int ac_controls=AC_ARROWS_CONTROLS_OPTION;

void load_data()
{
    LL::FileStream file;
    file.set_path(DATA_AC_PATH);
    if(!(errors.auto_chase_errors.loading_data_ac.loading_data_file=!file.load()))
    {
        if(!(errors.auto_chase_errors.loading_data_ac.missing_data=(file.size()!=DATA_AC_TOTAL_DATA)))
        {
            splitter.set_string(encryptor_files->decrypt(file[0]));
            splitter.split('$');
            if(!(errors.auto_chase_errors.loading_data_ac.missing_data_configuration=
                 (splitter.size()!=DATA_AC_TOTAL_CONFIGURATION)))
            {
                ac_difficulty=LL::mod(LL::to_int(splitter[0]),TOTAL_DIFFICULTIES);
                ac_car_type=LL::mod(LL::to_int(splitter[1]),CAR_TYPE_TOTAL_OPTIONS);
                ac_car_color=LL::mod(LL::to_int(splitter[2]),CAR_COLOR_TOTAL_OPTIONS);
                ac_controls=LL::mod(LL::to_int(splitter[3]),TOTAL_CONTROLS_OPTIONS);
            }
            splitter.set_string(encryptor_files->decrypt(file[1]));
            splitter.split('$');
            if(!(errors.auto_chase_errors.loading_data_ac.missing_data_records=(splitter.size()!=TOTAL_DIFFICULTIES)))
            {
                for(int i=0;i<TOTAL_DIFFICULTIES;++i)
                    ac_records[i]=LL::to_int(splitter[i]);
            }
        }
    }
}

void save_data()
{
    LL::FileStream file;
    file.set_path(DATA_AC_PATH);
    file.insert_line(0,DATA_AC_TOTAL_DATA);
    file[0]=encryptor_files->encrypt(LL::to_string(ac_difficulty)+'$'+
                                     LL::to_string(ac_car_type)+'$'+
                                     LL::to_string(ac_car_color)+'$'+
                                     LL::to_string(ac_controls)+'$');
    for(int i=0;i<TOTAL_DIFFICULTIES;++i)
        file[1]+=(LL::to_string(ac_records[i])+'$');
    file[1]=encryptor_files->encrypt(file[1]);
    file.save();
}

#include "MainMenu.h"
#include "Game.h"
#include "ConfigurationMenu.h"

void autochase_control()
{
    load_data();
    if(errors.auto_chase_errors.loading_data_ac.check())
        save_data();
    LL_AL5::Audio theme_audio;
    theme_audio.set_path(AC_THEME_AUDIO_PATH);
    if((errors.auto_chase_errors.loading_audios_ac.ac_theme_audio=!theme_audio.load()))
    {
        LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    AC_THEME_AUDIO_PATH,ALLEGRO_MESSAGEBOX_ERROR);
        game_running=false;
    }
    else
    {
        theme_audio.set_playmode(ALLEGRO_PLAYMODE_LOOP);
        theme_audio.play();
    }
    LL_AL5::Audio game_audio;
    game_audio.set_path(AC_GAME_AUDIO_PATH);
    if((errors.auto_chase_errors.loading_audios_ac.ac_game_audio=!game_audio.load()))
    {
        LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    AC_GAME_AUDIO_PATH,ALLEGRO_MESSAGEBOX_ERROR);
        game_running=false;
    }
    else
        game_audio.set_playmode(ALLEGRO_PLAYMODE_LOOP);
    ac_main_menu_option=AC_MAIN_MENU_PLAY_GAME;
    while(game_running and ac_main_menu_option!=AC_MAIN_MENU_EXIT_GAME)
    {
        start_ac_main_menu();
        switch(ac_main_menu_option)
        {
            case AC_MAIN_MENU_PLAY_GAME:
            {
                theme_audio.stop();
                game_audio.play();
                start_ac_game();
                game_audio.stop();
                theme_audio.play();
                break;
            }
            case AC_MAIN_MENU_CONFIGURATION:
            {
                if(start_configuration_menu())
                    save_data();
                break;
            }
        }
    }
}

#endif // INCLUDED_AC_MAIN_H
