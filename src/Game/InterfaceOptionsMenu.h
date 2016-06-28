#ifndef GAME_INTERFACE_OPTIONS_MENU_H_INCLUDED
#define GAME_INTERFACE_OPTIONS_MENU_H_INCLUDED

int interface_options_option=INTERFACE_OPTIONS_MENU_DISPLAY_SIZE;

bool has_changes=false;
bool has_language_changes=false;

class InterfaceOptionsMenu
{
    private:
        LL_AL5::Text title;
        LL_AL5::Rectangle line;
        LL_AL5::Text options[INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS];
        LL_AL5::Text footnote;
        LL_AL5::Text controls;
        int last_display_size_option;
        int last_display_type_option;
        int last_language_option;
        int last_volume_option;
        int display_size_option;
        int display_type_option;
        int language_option;
        int volume_option;
        LL_AL5::Text display_size_options[INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS];
        LL_AL5::Text display_type_options[INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS];
        LL_AL5::Text language_options[INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS];
        LL_AL5::Text volume_options;
        LL_AL5::Text volume_text;
    public:
        InterfaceOptionsMenu()
        {
            has_changes=false;
            has_language_changes=false;
            if(global_screen_option_size_x==LL_AL5::desktop_size_x and
               global_screen_option_size_y==LL_AL5::desktop_size_y)
                display_size_option=0;
            else if(global_screen_option_size_x==SCREEN_X_640 and global_screen_option_size_y==SCREEN_Y_480)
                display_size_option=1;
            else if(global_screen_option_size_x==SCREEN_X_800 and global_screen_option_size_y==SCREEN_Y_600)
                display_size_option=2;
            else
            {
                display_size_option=0;
                errors.modifying_interface_options.invalid_display_size_option=true;
            }
            last_display_size_option=display_size_option;
            if(global_screen_mode_option==SCREEN_FULLSCREEN_OPTION)
                display_type_option=0;
            else if(global_screen_mode_option==SCREEN_WINDOWED_OPTION)
                display_type_option=1;
            else
            {
                display_type_option=0;
                errors.modifying_interface_options.invalid_display_type_option=true;
            }
            last_display_type_option=display_type_option;
            last_language_option=language_option=language_map;
            last_volume_option=volume_option=(NORMAL_VOLUME*global_volume_option);
            title.set_font(comic_long);
            title=game.interface_options_menu.title;
            title.set_color(WHITE);
            title.set_flag(ALLEGRO_ALIGN_LEFT);
            title.set_pos(10,10);
            line.set_color(WHITE);
            line.set_filled_status(true);
            line.set_pos_y(title.get_pos_y()+(comic_long->get_size()*2));
            line.set_size_x(REAL_SIZE_X_TITLE);
            line.set_size_y(3);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS;++i)
            {
                options[i].set_font(comic_normal);
                options[i].set_color(WHITE);
                options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                options[i].set_pos(20,(2*REAL_SIZE_Y_TITLE/3)+(i*comic_normal->get_size()));
            }
            options[INTERFACE_OPTIONS_MENU_DISPLAY_SIZE]=game.interface_options_menu.select_display_size;
            options[INTERFACE_OPTIONS_MENU_DISPLAY_TYPE]=game.interface_options_menu.select_display_type;
            options[INTERFACE_OPTIONS_MENU_AUDIO_VOLUME]=game.interface_options_menu.set_audio_volume;
            options[INTERFACE_OPTIONS_MENU_LANGUAGE]=game.interface_options_menu.select_language;
            options[interface_options_option].set_color(ORANGE);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
            {
                display_size_options[i].set_font(comic_small);
                if(display_type_option)
                    display_size_options[i].set_color(WHITE);
                else
                    display_size_options[i].set_color(GRAY);
                display_size_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                display_size_options[i].set_pos(400+(i*200),(2*REAL_SIZE_Y_TITLE/3));
            }
            display_size_options[0]=game.interface_options_menu.display_size_1;
            display_size_options[1]=game.interface_options_menu.display_size_2;
            display_size_options[2]=game.interface_options_menu.display_size_3;
            display_size_options[display_size_option].set_color(ORANGE);
            if(LL_AL5::desktop_size_x<SCREEN_X_640 or LL_AL5::desktop_size_y<SCREEN_Y_480)
            {
                display_size_options[1].set_color(GRAY);
                display_size_options[2].set_color(GRAY);
            }
            else if(LL_AL5::desktop_size_x<SCREEN_X_800 or LL_AL5::desktop_size_y<SCREEN_Y_600)
                display_size_options[2].set_color(GRAY);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS;++i)
            {
                display_type_options[i].set_font(comic_small);
                display_type_options[i].set_color(WHITE);
                display_type_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                display_type_options[i].set_pos(400+(i*200),(2*REAL_SIZE_Y_TITLE/3)+(comic_normal->get_size()));
            }
            display_type_options[0]=game.interface_options_menu.display_type_1;
            display_type_options[1]=game.interface_options_menu.display_type_2;
            display_type_options[display_type_option].set_color(ORANGE);
            volume_text.set_font(comic_small);
            volume_text.set_color(WHITE);
            volume_text.set_flag(ALLEGRO_ALIGN_CENTER);
            volume_text.set_pos((REAL_SIZE_X_TITLE/2),(2*REAL_SIZE_Y_TITLE/3)+(2*comic_normal->get_size()));
            volume_text="\u25C4        \u25BA";
            volume_options.set_font(comic_small);
            volume_options.set_color(WHITE);
            volume_options.set_flag(ALLEGRO_ALIGN_CENTER);
            volume_options.set_pos((REAL_SIZE_X_TITLE/2),(2*REAL_SIZE_Y_TITLE/3)+(2*comic_normal->get_size()));
            volume_options=LL::to_string(volume_option);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS;++i)
            {
                language_options[i].set_font(comic_small);
                language_options[i].set_color(WHITE);
                language_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                language_options[i].set_pos(400+(i*200),(2*REAL_SIZE_Y_TITLE/3)+(3*comic_normal->get_size()));
            }
            language_options[0]=game.interface_options_menu.language_EN;
            language_options[1]=game.interface_options_menu.language_ES;
            language_options[2]=game.interface_options_menu.language_PR;
            language_options[language_option].set_color(ORANGE);
            footnote.set_font(comic_small);
            footnote=(game.organization+" - "+game.release_year);
            footnote.set_color(WHITE);
            footnote.set_flag(ALLEGRO_ALIGN_LEFT);
            footnote.set_pos(10,REAL_SIZE_Y_TITLE-30);
            controls.set_font(comic_small);
            controls=game.interface_options_menu.controls;
            controls.set_color(WHITE);
            controls.set_flag(ALLEGRO_ALIGN_RIGHT);
            controls.set_pos(REAL_SIZE_X_TITLE-(comic_small->get_size()*2),
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
                    display_size_options[display_size_option].set_color(WHITE);
                    display_size_option=LL::mod(display_size_option+num_of_moves,
                                                INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                    while(GRAY==display_size_options[display_size_option].get_color())
                        display_size_option=LL::mod(display_size_option+num_of_moves,
                                                    INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                    display_size_options[display_size_option].set_color(ORANGE);
                    break;
                }
                case INTERFACE_OPTIONS_MENU_DISPLAY_TYPE:
                {
                    display_type_options[display_type_option].set_color(WHITE);
                    display_type_option=LL::mod(display_type_option+num_of_moves,
                                                INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS);
                    display_type_options[display_type_option].set_color(ORANGE);
                    for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
                    {
                        if(display_type_option)
                            display_size_options[i].set_color(WHITE);
                        else
                            display_size_options[i].set_color(GRAY);
                    }
                    if(!display_type_option)
                        display_size_option=0;
                    display_size_options[display_size_option].set_color(ORANGE);
                    break;
                }
                case INTERFACE_OPTIONS_MENU_AUDIO_VOLUME:
                {
                    if(num_of_moves>0)
                        volume_option=volume_option+(volume_option<MAX_VOLUME);
                    else
                        volume_option=volume_option-(volume_option>0);
                    volume_options=LL::to_string(volume_option);
                    break;
                }
                case INTERFACE_OPTIONS_MENU_LANGUAGE:
                {
                    language_options[language_option].set_color(WHITE);
                    language_option=LL::mod(language_option+num_of_moves,INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS);
                    language_options[language_option].set_color(ORANGE);
                    break;
                }
            }
        }
        void move_selection_up_down(int num_of_moves)
        {
            options[interface_options_option].set_color(WHITE);
            interface_options_option=LL::mod(interface_options_option+num_of_moves,
                                             INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS);
            options[interface_options_option].set_color(ORANGE);
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
            if(last_display_size_option!=display_size_option)
            {
                if(display_size_option==2)
                {
                    global_screen_option_size_x=SCREEN_X_800;
                    global_screen_option_size_y=SCREEN_Y_600;
                }
                else if(display_size_option)
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
            if(last_display_type_option!=display_type_option)
            {
                if(display_type_option)
                    global_screen_mode_option=SCREEN_WINDOWED_OPTION;
                else
                    global_screen_mode_option=SCREEN_FULLSCREEN_OPTION;
                has_changes=true;
            }
            if(last_volume_option!=volume_option)
            {
                global_volume_option=(volume_option/NORMAL_VOLUME);
                has_changes=true;
            }
            if(last_language_option!=language_option)
            {
                language_map=language_option;
                has_language_changes=true;
            }
            input->clear_events();
            input->clear_key_status();
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&title);
            screen->draw(&line);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS;++i)
                screen->draw(&(options[i]));
            screen->draw(&footnote);
            screen->draw(&controls);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
                screen->draw(&(display_size_options[i]));
            for(unsigned int i=0;i<INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS;++i)
                screen->draw(&(display_type_options[i]));
            screen->draw(&volume_text);
            screen->draw(&volume_options);
            for(unsigned int i=0;i<INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS;++i)
                screen->draw(&(language_options[i]));
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
