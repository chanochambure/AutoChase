#ifndef INCLUDED_AC_MAIN_H
#define INCLUDED_AC_MAIN_H

#include "MainMenu.h"

//Main Data
int ac_difficulty=DIFFICULTY_EASY;
int ac_car_type=CAR_TYPE_AUTO;
int ac_car_color=CAR_COLOR_BLACK;
int ac_records[TOTAL_DIFFICULTIES]={0,0,0};

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
                ac_difficulty=LL::to_int(splitter[0]);
                ac_car_type=LL::to_int(splitter[1]);
                ac_car_color=LL::to_int(splitter[2]);
            }
            splitter.set_string(encryptor_files->decrypt(file[1]));
            splitter.split('$');
            if(!(errors.auto_chase_errors.loading_data_ac.missing_data_records=
                 (splitter.size()!=TOTAL_DIFFICULTIES)))
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
                                     LL::to_string(ac_car_color)+'$');
    for(int i=0;i<TOTAL_DIFFICULTIES;++i)
        file[1]+=(LL::to_string(ac_records[i])+'$');
    file[1]=encryptor_files->encrypt(file[1]);
    file.save();
}

void autochase_control()
{
    load_data();
    if(errors.auto_chase_errors.loading_data_ac.check())
        save_data();
    ac_main_menu_option=AC_MAIN_MENU_PLAY_GAME;
    while(game_running and ac_main_menu_option!=AC_MAIN_MENU_EXIT_GAME)
    {
        start_ac_main_menu();
        switch(main_menu_option)
        {
        }
    }
}

#endif // INCLUDED_AC_MAIN_H
