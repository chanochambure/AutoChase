#ifndef GAME_INTERFACE_OPTIONS_MENU_H_INCLUDED
#define GAME_INTERFACE_OPTIONS_MENU_H_INCLUDED

int interface_options_option=_INTERFACE_OPTIONS_MENU_DISPLAY_SIZE;

bool has_changes=0;
bool has_language_changes=0;

class InterfaceOptionsMenu
{
    private:
        LL_AL5::Text title;
        LL_AL5::Rectangle line;
        LL_AL5::Text options[_INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS];
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
        LL_AL5::Text display_size_options[_INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS];
        LL_AL5::Text display_type_options[_INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS];
        LL_AL5::Text language_options[_INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS];
        LL_AL5::Text volume_options;
        LL_AL5::Text volume_text;
    public:
        InterfaceOptionsMenu()
        {
            has_changes=0;
            has_language_changes=0;
            if(_screen_size_x==LL_AL5::desktop_size_x and _screen_size_y==LL_AL5::desktop_size_y)
                display_size_option=0;
            else if(_screen_size_x==_DISPLAY_X_640 and _screen_size_y==_DISPLAY_Y_480)
                display_size_option=1;
            else if(_screen_size_x==_DISPLAY_X_800 and _screen_size_y==_DISPLAY_Y_600)
                display_size_option=2;
            else
            {
                display_size_option=0;
                errors.modifying_interface_options.invalid_display_size_option=1;
            }
            last_display_size_option=display_size_option;
            if(_screen_mode==_GAME_FULLSCREEN)
                display_type_option=0;
            else if(_screen_mode==_GAME_WINDOWED)
                display_type_option=1;
            else
            {
                display_type_option=0;
                errors.modifying_interface_options.invalid_display_type_option=1;
            }
            last_display_type_option=display_type_option;
            last_language_option=language_option=language_map;
            last_volume_option=volume_option=(10*_audio_volume);
            title.set_font(comic_long);
            title=game.interface_options_menu.title;
            title.set_color(WHITE);
            title.set_flag(ALLEGRO_ALIGN_LEFT);
            title.set_pos(10,10);
            line.set_color(WHITE);
            line.set_filled_status(1);
            line.set_pos_y(title.get_pos_y()+(comic_long->get_size()*2));
            line.set_size_x(_REALSIZEX_TITLE);
            line.set_size_y(3);
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS;++i)
            {
                options[i].set_font(comic_normal);
                options[i].set_color(WHITE);
                options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                options[i].set_pos(20,(2*_REALSIZEY_TITLE/3)+(i*comic_normal->get_size()));
            }
            options[_INTERFACE_OPTIONS_MENU_DISPLAY_SIZE]=game.interface_options_menu.select_display_size;
            options[_INTERFACE_OPTIONS_MENU_DISPLAY_TYPE]=game.interface_options_menu.select_display_type;
            options[_INTERFACE_OPTIONS_MENU_AUDIO_VOLUME]=game.interface_options_menu.set_audio_volume;
            options[_INTERFACE_OPTIONS_MENU_LANGUAGE]=game.interface_options_menu.select_language;
            options[interface_options_option].set_color(ORANGE);
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
            {
                display_size_options[i].set_font(comic_small);
                display_size_options[i].set_color(WHITE);
                display_size_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                display_size_options[i].set_pos(400+(i*200),(2*_REALSIZEY_TITLE/3));
            }
            display_size_options[0]=game.interface_options_menu.display_size_1;
            display_size_options[1]=game.interface_options_menu.display_size_2;
            display_size_options[2]=game.interface_options_menu.display_size_3;
            display_size_options[display_size_option].set_color(ORANGE);
            if(LL_AL5::desktop_size_x<_DISPLAY_X_640 or LL_AL5::desktop_size_y<_DISPLAY_Y_480)
            {
                display_size_options[1].set_color(GRAY);
                display_size_options[2].set_color(GRAY);
            }
            else if(LL_AL5::desktop_size_x<_DISPLAY_X_800 or LL_AL5::desktop_size_y<_DISPLAY_Y_600)
                display_size_options[2].set_color(GRAY);
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS;++i)
            {
                display_type_options[i].set_font(comic_small);
                display_type_options[i].set_color(WHITE);
                display_type_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                display_type_options[i].set_pos(400+(i*200),(2*_REALSIZEY_TITLE/3)+(comic_normal->get_size()));
            }
            display_type_options[0]=game.interface_options_menu.display_type_1;
            display_type_options[1]=game.interface_options_menu.display_type_2;
            display_type_options[display_type_option].set_color(ORANGE);
            volume_text.set_font(comic_small);
            volume_text.set_color(WHITE);
            volume_text.set_flag(ALLEGRO_ALIGN_CENTER);
            volume_text.set_pos((_REALSIZEX_TITLE/2),(2*_REALSIZEY_TITLE/3)+(2*comic_normal->get_size()));
            volume_text="\u25C4        \u25BA";
            volume_options.set_font(comic_small);
            volume_options.set_color(WHITE);
            volume_options.set_flag(ALLEGRO_ALIGN_CENTER);
            volume_options.set_pos((_REALSIZEX_TITLE/2),(2*_REALSIZEY_TITLE/3)+(2*comic_normal->get_size()));
            volume_options=LL::to_string(volume_option);
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS;++i)
            {
                language_options[i].set_font(comic_small);
                language_options[i].set_color(WHITE);
                language_options[i].set_flag(ALLEGRO_ALIGN_LEFT);
                language_options[i].set_pos(400+(i*200),(2*_REALSIZEY_TITLE/3)+(3*comic_normal->get_size()));
            }
            language_options[0]=game.interface_options_menu.language_EN;
            language_options[1]=game.interface_options_menu.language_ES;
            language_options[2]=game.interface_options_menu.language_PR;
            language_options[language_option].set_color(ORANGE);
            footnote.set_font(comic_small);
            footnote=(game.organization+" - "+game.release_year);
            footnote.set_color(WHITE);
            footnote.set_flag(ALLEGRO_ALIGN_LEFT);
            footnote.set_pos(10,_REALSIZEY_TITLE-30);
            controls.set_font(comic_small);
            controls=game.interface_options_menu.controls;
            controls.set_color(WHITE);
            controls.set_flag(ALLEGRO_ALIGN_RIGHT);
            controls.set_pos(_REALSIZEX_TITLE-(comic_small->get_size()*2),_REALSIZEY_TITLE-(comic_small->get_size()*2));
        }
        bool load_status()
        {
            return !(0<(errors.modifying_interface_options.check()));
        }
        void left()
        {
            switch(interface_options_option)
            {
                case _INTERFACE_OPTIONS_MENU_DISPLAY_SIZE:
                    {
                        display_size_options[display_size_option].set_color(WHITE);
                        display_size_option=LL::mod(display_size_option-1,_INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                        while(GRAY==display_size_options[display_size_option].get_color())
                            display_size_option=LL::mod(display_size_option-1,_INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                        display_size_options[display_size_option].set_color(ORANGE);
                    }
                    break;
                case _INTERFACE_OPTIONS_MENU_DISPLAY_TYPE:
                    {
                        display_type_options[display_type_option].set_color(WHITE);
                        display_type_option=LL::mod(display_type_option-1,_INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS);
                        display_type_options[display_type_option].set_color(ORANGE);
                    }
                    break;
                case _INTERFACE_OPTIONS_MENU_AUDIO_VOLUME:
                    {
                        volume_option=volume_option-(volume_option>0);
                        volume_options=LL::to_string(volume_option);
                    }
                    break;
                case _INTERFACE_OPTIONS_MENU_LANGUAGE:
                    {
                        language_options[language_option].set_color(WHITE);
                        language_option=LL::mod(language_option-1,_INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS);
                        language_options[language_option].set_color(ORANGE);
                    }
                    break;
            }
        }
        void right()
        {
            switch(interface_options_option)
            {
                case _INTERFACE_OPTIONS_MENU_DISPLAY_SIZE:
                    {
                        display_size_options[display_size_option].set_color(WHITE);
                        display_size_option=LL::mod(display_size_option+1,_INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                        while(GRAY==display_size_options[display_size_option].get_color())
                            display_size_option=LL::mod(display_size_option+1,_INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS);
                        display_size_options[display_size_option].set_color(ORANGE);
                    }
                    break;
                case _INTERFACE_OPTIONS_MENU_DISPLAY_TYPE:
                    {
                        display_type_options[display_type_option].set_color(WHITE);
                        display_type_option=LL::mod(display_type_option+1,_INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS);
                        display_type_options[display_type_option].set_color(ORANGE);
                    }
                    break;
                case _INTERFACE_OPTIONS_MENU_AUDIO_VOLUME:
                    {
                        volume_option=volume_option+(volume_option<10);
                        volume_options=LL::to_string(volume_option);
                    }
                    break;
                case _INTERFACE_OPTIONS_MENU_LANGUAGE:
                    {
                        language_options[language_option].set_color(WHITE);
                        language_option=LL::mod(language_option+1,_INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS);
                        language_options[language_option].set_color(ORANGE);
                    }
                    break;
            }
        }
        void up()
        {
            options[interface_options_option].set_color(WHITE);
            interface_options_option=LL::mod(interface_options_option-1,_INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS);
            options[interface_options_option].set_color(ORANGE);
        }
        void down()
        {
            options[interface_options_option].set_color(WHITE);
            interface_options_option=LL::mod(interface_options_option+1,_INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS);
            options[interface_options_option].set_color(ORANGE);
        }
        void set_changes()
        {
            if(last_display_size_option!=display_size_option)
            {
                if(display_size_option==2)
                {
                    _screen_size_x=_DISPLAY_X_800;
                    _screen_size_y=_DISPLAY_Y_600;
                }
                else if(display_size_option)
                {
                    _screen_size_x=_DISPLAY_X_640;
                    _screen_size_y=_DISPLAY_Y_480;
                }
                else
                {
                    _screen_size_x=LL_AL5::desktop_size_x;
                    _screen_size_y=LL_AL5::desktop_size_y;
                }
                has_changes=1;
            }
            if(last_display_type_option!=display_type_option)
            {
                if(display_type_option)
                    _screen_mode=_GAME_WINDOWED;
                else
                    _screen_mode=_GAME_FULLSCREEN;
                has_changes=1;
            }
            if(last_volume_option!=volume_option)
            {
                _audio_volume=(volume_option/10.0);
                has_changes=1;
            }
            if(last_language_option!=language_option)
            {
                language_map=language_option;
                has_language_changes=1;
            }
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&title);
            screen->draw(&line);
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS;++i)
                screen->draw(&(options[i]));
            screen->draw(&footnote);
            screen->draw(&controls);
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS;++i)
                screen->draw(&(display_size_options[i]));
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS;++i)
                screen->draw(&(display_type_options[i]));
            screen->draw(&volume_text);
            screen->draw(&volume_options);
            for(unsigned int i=0;i<_INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS;++i)
                screen->draw(&(language_options[i]));
            screen->refresh();
        }
        void error()
        {
            show_native_message(*screen,game.error_text.title,game.error_text.header_internal,game.error_text.message_interface_options_internal_error,ALLEGRO_MESSAGEBOX_ERROR);
            exit_program=false;
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
        while(exit_program)
        {
            input->get_event();
            if(input->get_display_status())
                exit_program=false;
            if((*input)[MENU_CANCEL])
                break;
            if((*input)[MENU_LEFT])
            {
                interface_options_menu.left();
                (*input)[MENU_LEFT]=0;
            }
            if((*input)[MENU_RIGHT])
            {
                interface_options_menu.right();
                (*input)[MENU_RIGHT]=0;
            }
            if((*input)[MENU_UP])
            {
                interface_options_menu.up();
                (*input)[MENU_UP]=0;
            }
            if((*input)[MENU_DOWN])
            {
                interface_options_menu.down();
                (*input)[MENU_DOWN]=0;
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
