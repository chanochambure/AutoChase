#ifndef GAME_INTERFACE_OPTIONS_MENU_H_INCLUDED
#define GAME_INTERFACE_OPTIONS_MENU_H_INCLUDED

int interface_options_option=INTERFACE_OPTIONS_MENU_DISPLAY_SIZE;

bool has_changes=false;
bool has_language_changes=false;

class InterfaceOptionsMenu
{
    private:
        LL_AL5::Text _V_title;
        LL_AL5::Rectangle _V_line;
        LL_AL5::Text _V_options[INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS];
        LL_AL5::Text _V_footnote;
        LL_AL5::Text _V_controls;
        int _V_last_display_size_option;
        int _V_last_display_type_option;
        int _V_last_language_option;
        int _V_last_volume_option;
        int _V_display_size_option;
        int _V_display_type_option;
        int _V_language_option;
        int _V_volume_option;
        LL_AL5::Text _V_display_size_options[INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS];
        LL_AL5::Text _V_display_type_options[INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS];
        LL_AL5::Text _V_language_options[INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS];
        LL_AL5::Text _V_volume_options;
        LL_AL5::Text _V_volume_text;
    public:
        InterfaceOptionsMenu()
        {
            has_changes=false;
            has_language_changes=false;
            if(global_screen_option_size_x==LL_AL5::desktop_size_x and
               global_screen_option_size_y==LL_AL5::desktop_size_y)
                _V_display_size_option=0;
            else if(global_screen_option_size_x==SCREEN_X_640 and global_screen_option_size_y==SCREEN_Y_480)
                _V_display_size_option=1;
            else if(global_screen_option_size_x==SCREEN_X_800 and global_screen_option_size_y==SCREEN_Y_600)
                _V_display_size_option=2;
            else
            {
                _V_display_size_option=0;
                errors.modifying_interface_options.invalid_display_size_option=true;
            }
            _V_last_display_size_option=_V_display_size_option;
            if(global_screen_mode_option==SCREEN_FULLSCREEN_OPTION)
                _V_display_type_option=0;
            else if(global_screen_mode_option==SCREEN_WINDOWED_OPTION)
                _V_display_type_option=1;
            else
            {
                _V_display_type_option=0;
                errors.modifying_interface_options.invalid_display_type_option=true;
            }
            _V_last_display_type_option=_V_display_type_option;
            _V_last_language_option=_V_language_option=language_map;
            _V_last_volume_option=_V_volume_option=(NORMAL_VOLUME*global_volume_option);
            _V_title.set_font(comic_long);
            _V_title=game.interface_options_menu.title;
            _V_title.set_color(WHITE);
            _V_title.set_flag(ALLEGRO_ALIGN_LEFT);
            _V_title.set_pos(10,10);
            _V_line.set_color(WHITE);
            _V_line.set_filled_status(true);
            _V_line.set_pos_y(_V_title.get_pos_y()+(comic_long->get_size()*2));
            _V_line.set_size_x(REAL_SIZE_X_TITLE);
            _V_line.set_size_y(3);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS;++i)
            {
                _V_options[i].set_font(comic_normal);
                _V_options[i].set_color(WHITE);
                _V_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                _V_options[i].set_pos(20,(2*REAL_SIZE_Y_TITLE/3)+(i*comic_normal->get_size()));
            }
            _V_options[INTERFACE_OPTIONS_MENU_DISPLAY_SIZE]=game.interface_options_menu.select_display_size;
            _V_options[INTERFACE_OPTIONS_MENU_DISPLAY_TYPE]=game.interface_options_menu.select_display_type;
            _V_options[INTERFACE_OPTIONS_MENU_AUDIO_VOLUME]=game.interface_options_menu.set_audio_volume;
            _V_options[INTERFACE_OPTIONS_MENU_LANGUAGE]=game.interface_options_menu.select_language;
            _V_options[interface_options_option].set_color(ORANGE);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
            {
                _V_display_size_options[i].set_font(comic_small);
                if(_V_display_type_option)
                    _V_display_size_options[i].set_color(WHITE);
                else
                    _V_display_size_options[i].set_color(GRAY);
                _V_display_size_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                _V_display_size_options[i].set_pos(400+(i*200),(2*REAL_SIZE_Y_TITLE/3));
            }
            _V_display_size_options[0]=game.interface_options_menu.display_size_1;
            _V_display_size_options[1]=game.interface_options_menu.display_size_2;
            _V_display_size_options[2]=game.interface_options_menu.display_size_3;
            _V_display_size_options[_V_display_size_option].set_color(ORANGE);
            if(LL_AL5::desktop_size_x<SCREEN_X_640 or LL_AL5::desktop_size_y<SCREEN_Y_480)
            {
                _V_display_size_options[1].set_color(GRAY);
                _V_display_size_options[2].set_color(GRAY);
            }
            else if(LL_AL5::desktop_size_x<SCREEN_X_800 or LL_AL5::desktop_size_y<SCREEN_Y_600)
                _V_display_size_options[2].set_color(GRAY);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS;++i)
            {
                _V_display_type_options[i].set_font(comic_small);
                _V_display_type_options[i].set_color(WHITE);
                _V_display_type_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                _V_display_type_options[i].set_pos(400+(i*200),(2*REAL_SIZE_Y_TITLE/3)+(comic_normal->get_size()));
            }
            _V_display_type_options[0]=game.interface_options_menu.display_type_1;
            _V_display_type_options[1]=game.interface_options_menu.display_type_2;
            _V_display_type_options[_V_display_type_option].set_color(ORANGE);
            _V_volume_text.set_font(comic_small);
            _V_volume_text.set_color(WHITE);
            _V_volume_text.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_volume_text.set_pos((REAL_SIZE_X_TITLE/2),(2*REAL_SIZE_Y_TITLE/3)+(2*comic_normal->get_size()));
            _V_volume_text="\u25C4        \u25BA";
            _V_volume_options.set_font(comic_small);
            _V_volume_options.set_color(WHITE);
            _V_volume_options.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_volume_options.set_pos((REAL_SIZE_X_TITLE/2),(2*REAL_SIZE_Y_TITLE/3)+(2*comic_normal->get_size()));
            _V_volume_options=LL::to_string(_V_volume_option);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS;++i)
            {
                _V_language_options[i].set_font(comic_small);
                _V_language_options[i].set_color(WHITE);
                _V_language_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                _V_language_options[i].set_pos(400+(i*200),(2*REAL_SIZE_Y_TITLE/3)+(3*comic_normal->get_size()));
            }
            _V_language_options[0]=game.interface_options_menu.language_EN;
            _V_language_options[1]=game.interface_options_menu.language_ES;
            _V_language_options[2]=game.interface_options_menu.language_PR;
            _V_language_options[_V_language_option].set_color(ORANGE);
            _V_footnote.set_font(comic_small);
            _V_footnote=(game.organization+" - "+game.release_year);
            _V_footnote.set_color(WHITE);
            _V_footnote.set_flag(ALLEGRO_ALIGN_LEFT);
            _V_footnote.set_pos(10,REAL_SIZE_Y_TITLE-30);
            _V_controls.set_font(comic_small);
            _V_controls=game.interface_options_menu.controls;
            _V_controls.set_color(WHITE);
            _V_controls.set_flag(ALLEGRO_ALIGN_RIGHT);
            _V_controls.set_pos(REAL_SIZE_X_TITLE-(comic_small->get_size()*2),
                             REAL_SIZE_Y_TITLE-(comic_small->get_size()*2));
        }
        bool load_status()
        {
            return !(0<(errors.modifying_interface_options.check()));
        }
        void move_selection_left_right(int num_of_moves)
        {
            switch(interface_options_option)
            {
                case INTERFACE_OPTIONS_MENU_DISPLAY_SIZE:
                {
                    _V_display_size_options[_V_display_size_option].set_color(WHITE);
                    _V_display_size_option=LL::mod(_V_display_size_option+num_of_moves,
                                                INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                    while(GRAY==_V_display_size_options[_V_display_size_option].get_color())
                        _V_display_size_option=LL::mod(_V_display_size_option+num_of_moves,
                                                    INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                    _V_display_size_options[_V_display_size_option].set_color(ORANGE);
                    break;
                }
                case INTERFACE_OPTIONS_MENU_DISPLAY_TYPE:
                {
                    _V_display_type_options[_V_display_type_option].set_color(WHITE);
                    _V_display_type_option=LL::mod(_V_display_type_option+num_of_moves,
                                                INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS);
                    _V_display_type_options[_V_display_type_option].set_color(ORANGE);
                    for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
                    {
                        if(_V_display_type_option)
                            _V_display_size_options[i].set_color(WHITE);
                        else
                            _V_display_size_options[i].set_color(GRAY);
                    }
                    if(!_V_display_type_option)
                        _V_display_size_option=0;
                    _V_display_size_options[_V_display_size_option].set_color(ORANGE);
                    break;
                }
                case INTERFACE_OPTIONS_MENU_AUDIO_VOLUME:
                {
                    if(num_of_moves>0)
                        _V_volume_option=_V_volume_option+(_V_volume_option<MAX_VOLUME);
                    else
                        _V_volume_option=_V_volume_option-(_V_volume_option>0);
                    _V_volume_options=LL::to_string(_V_volume_option);
                    break;
                }
                case INTERFACE_OPTIONS_MENU_LANGUAGE:
                {
                    _V_language_options[_V_language_option].set_color(WHITE);
                    _V_language_option=LL::mod(_V_language_option+num_of_moves,INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS);
                    _V_language_options[_V_language_option].set_color(ORANGE);
                    break;
                }
            }
        }
        void move_selection_up_down(int num_of_moves)
        {
            _V_options[interface_options_option].set_color(WHITE);
            interface_options_option=LL::mod(interface_options_option+num_of_moves,
                                             INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS);
            _V_options[interface_options_option].set_color(ORANGE);
        }
        void left()
        {
            move_selection_left_right(-1);
        }
        void right()
        {
            move_selection_left_right(1);
        }
        void up()
        {
            move_selection_up_down(-1);
        }
        void down()
        {
            move_selection_up_down(1);
        }
        void set_changes()
        {
            if(_V_last_display_size_option!=_V_display_size_option)
            {
                if(_V_display_size_option==2)
                {
                    global_screen_option_size_x=SCREEN_X_800;
                    global_screen_option_size_y=SCREEN_Y_600;
                }
                else if(_V_display_size_option)
                {
                    global_screen_option_size_x=SCREEN_X_640;
                    global_screen_option_size_y=SCREEN_Y_480;
                }
                else
                {
                    global_screen_option_size_x=LL_AL5::desktop_size_x;
                    global_screen_option_size_y=LL_AL5::desktop_size_y;
                }
                has_changes=true;
            }
            if(_V_last_display_type_option!=_V_display_type_option)
            {
                if(_V_display_type_option)
                    global_screen_mode_option=SCREEN_WINDOWED_OPTION;
                else
                    global_screen_mode_option=SCREEN_FULLSCREEN_OPTION;
                has_changes=true;
            }
            if(_V_last_volume_option!=_V_volume_option)
            {
                global_volume_option=(_V_volume_option/NORMAL_VOLUME);
                has_changes=true;
            }
            if(_V_last_language_option!=_V_language_option)
            {
                language_map=_V_language_option;
                has_language_changes=true;
            }
            input->clear_events();
            input->clear_key_status();
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&_V_title);
            screen->draw(&_V_line);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_options[i]));
            screen->draw(&_V_footnote);
            screen->draw(&_V_controls);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_display_size_options[i]));
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_display_type_options[i]));
            screen->draw(&_V_volume_text);
            screen->draw(&_V_volume_options);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_language_options[i]));
            screen->refresh();
        }
        void error()
        {
            show_native_message(*screen,game.error_text.title,game.error_text.header_internal,
                                game.error_text.message_interface_options_internal_error,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
};

bool start_interface_options_menu()
{
    InterfaceOptionsMenu interface_options_menu;
    if(!interface_options_menu.load_status())
        interface_options_menu.error();
    else
    {
        input->clear_key_status();
        input->clear_events();
        while(game_running)
        {
            input->get_event();
            if(input->get_display_status())
                game_running=false;
            if((*input)[MENU_CANCEL])
                break;
            if((*input)[MENU_LEFT])
            {
                interface_options_menu.left();
                (*input)[MENU_LEFT]=false;
            }
            if((*input)[MENU_RIGHT])
            {
                interface_options_menu.right();
                (*input)[MENU_RIGHT]=false;
            }
            if((*input)[MENU_UP])
            {
                interface_options_menu.up();
                (*input)[MENU_UP]=false;
            }
            if((*input)[MENU_DOWN])
            {
                interface_options_menu.down();
                (*input)[MENU_DOWN]=false;
            }
            if((*input)[MENU_SELECT])
            {
                interface_options_menu.set_changes();
                break;
            }
            if(input->get_timer_event())
                interface_options_menu.draw();
        }
    }
    return (!(*input)[MENU_CANCEL]);
}

#endif // GAME_INTERFACE_OPTIONS_MENU_H_INCLUDED
