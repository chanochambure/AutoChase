#ifndef INCLUDED_AC_CONFIGURATION_MENU_H
#define INCLUDED_AC_CONFIGURATION_MENU_H

int ac_configuration_menu_option=AC_CONFIGURATION_MENU_CAR_TYPE;

class ACConfigurationMenu
{
    private:
        LL_AL5::Image _V_background;
        LL_AL5::Image _V_demo_car;
        LL_AL5::Image _V_arrow;
        LL_AL5::Text _V_title;
        LL_AL5::Text _V_options[AC_CONFIGURATION_MENU_TOTAL_OPTIONS];
        LL_AL5::Text _V_footnote;
        LL_AL5::Text _V_controls;
        LL_AL5::Text _V_car_text;
        LL_AL5::Text _V_difficulty_text;
        int _V_last_car_type;
        int _V_last_car_color;
        int _V_last_difficulty;
        int _V_last_controls_option;
    public:
        ACConfigurationMenu()
        {
            _V_last_car_type=ac_car_type;
            _V_last_car_color=ac_car_color;
            _V_last_difficulty=ac_difficulty;
            _V_last_controls_option=ac_controls;
            _V_background.set_path(BACKGROUND_CONFIGRATION_MENU_IMAGE_PATH);
            errors.auto_chase_errors.loading_images_ac.background_configuration_menu_image=!_V_background.load();
            _V_arrow.set_path(ARROW_MENU_IMAGE_PATH);
            errors.auto_chase_errors.loading_images_ac.arrow_menu_image=!_V_arrow.load();
            _V_arrow.set_pos(AC_CONFIGURATION_MENU_OPTIONS_POS_X,
                            AC_CONFIGURATION_MENU_OPTIONS_POS_Y-(comic_big->get_size()/3)+
                             (ac_configuration_menu_option*comic_big->get_size()));
            _V_title.set_font(comic_big);
            _V_title=game.autochase_text.configuration_menu.title;
            _V_title.set_color(BLACK);
            _V_title.set_flag(ALLEGRO_ALIGN_LEFT);
            _V_title.set_pos(20,20);
            for(unsigned int i=0;i<AC_CONFIGURATION_MENU_TOTAL_OPTIONS;++i)
            {
                _V_options[i].set_font(comic_big);
                _V_options[i].set_color(BLACK);
                _V_options[i].set_flag(ALLEGRO_ALIGN_RIGHT);
                _V_options[i].set_pos(AC_CONFIGURATION_MENU_OPTIONS_POS_X,
                                      AC_CONFIGURATION_MENU_OPTIONS_POS_Y+(i*comic_big->get_size()));
            }
            _V_options[AC_CONFIGURATION_MENU_CAR_TYPE]=game.autochase_text.configuration_menu.car_type;
            _V_options[AC_CONFIGURATION_MENU_CAR_COLOR]=game.autochase_text.configuration_menu.car_color;
            _V_options[AC_CONFIGURATION_MENU_CONTROLS_OPTION]=
                                        game.autochase_text.configuration_menu.controls_options[ac_controls];
            _V_options[AC_CONFIGURATION_MENU_DIFFICULTY]=game.autochase_text.configuration_menu.difficulty;
            _V_footnote.set_font(comic_long);
            _V_footnote=(game.organization+" - "+game.release_year);
            _V_footnote.set_color(BLACK);
            _V_footnote.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_footnote.set_pos(REAL_SIZE_X_GAME/2,REAL_SIZE_Y_GAME-30);
            _V_controls.set_font(comic_long);
            _V_controls=game.autochase_text.configuration_menu.controls;
            _V_controls.set_color(BLACK);
            _V_controls.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_controls.set_pos(REAL_SIZE_X_GAME/2,REAL_SIZE_Y_GAME-70);
            _V_car_text.set_font(comic_long);
            _V_car_text.set_color(BLACK);
            _V_car_text.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_car_text.set_pos(AC_CONFIGURATION_MENU_CAR_POS_X,AC_CONFIGURATION_MENU_CAR_POS_Y);
            _V_difficulty_text.set_font(comic_long);
            _V_difficulty_text.set_color(BLACK);
            _V_difficulty_text.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_difficulty_text.set_pos(AC_CONFIGURATION_MENU_DIFFICULTY_POS_X,AC_CONFIGURATION_MENU_DIFFICULTY_POS_Y);
            _V_difficulty_text=game.autochase_text.configuration_menu.difficulties[ac_difficulty];
            _V_demo_car.set_pos(AC_CONFIGURATION_MENU_DEMO_CAR_POS_X,AC_CONFIGURATION_MENU_DEMO_CAR_POS_Y);
            load_changes();
        }
        bool load_status()
        {
            return !(errors.auto_chase_errors.loading_images_ac.background_configuration_menu_image) and
                    !(errors.auto_chase_errors.loading_images_ac.arrow_menu_image) and
                    !(errors.auto_chase_errors.loading_images_ac.demo_car_image);
        }
        void move_selection_left_right(int num_of_moves)
        {
            switch(ac_configuration_menu_option)
            {
                case AC_CONFIGURATION_MENU_CAR_TYPE:
                {
                    ac_car_type=LL::mod(ac_car_type+num_of_moves,CAR_TYPE_TOTAL_OPTIONS);
                    load_changes();
                    break;
                }
                case AC_CONFIGURATION_MENU_CAR_COLOR:
                {
                    ac_car_color=LL::mod(ac_car_color+num_of_moves,CAR_COLOR_TOTAL_OPTIONS);
                    load_changes();
                    break;
                }
                case AC_CONFIGURATION_MENU_CONTROLS_OPTION:
                {
                    ac_controls=LL::mod(ac_controls+num_of_moves,TOTAL_CONTROLS_OPTIONS);
                    _V_options[AC_CONFIGURATION_MENU_CONTROLS_OPTION]=
                                        game.autochase_text.configuration_menu.controls_options[ac_controls];
                    break;
                }
                case AC_CONFIGURATION_MENU_DIFFICULTY:
                {
                    ac_difficulty=LL::mod(ac_difficulty+num_of_moves,TOTAL_DIFFICULTIES);
                    _V_difficulty_text=game.autochase_text.configuration_menu.difficulties[ac_difficulty];
                    break;
                }
            }
        }
        void move_selection_up_down(int num_of_moves)
        {
            ac_configuration_menu_option=LL::mod(ac_configuration_menu_option+num_of_moves,
                                                 AC_CONFIGURATION_MENU_TOTAL_OPTIONS);
            _V_arrow.set_pos(AC_CONFIGURATION_MENU_OPTIONS_POS_X,
                            AC_CONFIGURATION_MENU_OPTIONS_POS_Y-(comic_big->get_size()/3)+
                             (ac_configuration_menu_option*comic_big->get_size()));
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
        void load_changes()
        {
            _V_car_text=game.autochase_text.configuration_menu.types[ac_car_type]+":"+
                        game.autochase_text.configuration_menu.colors[ac_car_color];
            switch(ac_car_type)
            {
                case CAR_TYPE_AUTO:
                {
                    _V_demo_car.set_path(CAR_TYPE_AUTO_IMAGE_PATH);
                    break;
                }
                case CAR_TYPE_AC_CAR:
                {
                    _V_demo_car.set_path(CAR_TYPE_AC_CAR_IMAGE_PATH);
                    break;
                }
                case CAR_TYPE_FORMULA:
                {
                    _V_demo_car.set_path(CAR_TYPE_FORMULA_IMAGE_PATH);
                    break;
                }
            }
            LL_AL5::Color paint_color;
            switch(ac_car_color)
            {
                case CAR_COLOR_BLACK:
                {
                    paint_color=BLACK;
                    break;
                }
                case CAR_COLOR_BLUE:
                {
                    paint_color=BLUE;
                    break;
                }
                case CAR_COLOR_GREEN:
                {
                    paint_color=GREEN;
                    break;
                }
                case CAR_COLOR_RED:
                {
                    paint_color=RED;
                    break;
                }
                case CAR_COLOR_YELLOW:
                {
                    paint_color=YELLOW;
                    break;
                }
                case CAR_COLOR_WHITE:
                {
                    paint_color=WHITE;
                    break;
                }
            }
            if(!(errors.auto_chase_errors.loading_images_ac.demo_car_image=!_V_demo_car.load()))
            {
                _V_demo_car.lock();
                _V_demo_car.set_target();
                for(unsigned int x=0;x<_V_demo_car.get_size_x();++x)
                {
                    for(unsigned int y=0;y<_V_demo_car.get_size_y();++y)
                    {
                        if(TURQUOISE==_V_demo_car.get_pixel_color(x,y))
                            al_put_pixel(x,y,paint_color);
                    }
                }
                _V_demo_car.unlock();
                screen->set_target();
            }
        }
        bool has_changes()
        {
            return (_V_last_car_type!=ac_car_type) or
                    (_V_last_car_color!=ac_car_color) or
                    (_V_last_difficulty!=ac_difficulty) or
                    (_V_last_controls_option!=ac_controls);
        }
        void draw()
        {
            screen->clear_to_color(WHITE);
            screen->draw(&_V_background);
            screen->draw(&_V_arrow);
            screen->draw(&_V_title);
            for(unsigned int i=0;i<AC_CONFIGURATION_MENU_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_options[i]));
            screen->draw(&_V_demo_car);
            screen->draw(&_V_car_text);
            screen->draw(&_V_difficulty_text);
            screen->draw(&_V_footnote);
            screen->draw(&_V_controls);
            screen->refresh();
        }
        void error()
        {
            if(errors.auto_chase_errors.loading_images_ac.background_configuration_menu_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    BACKGROUND_CONFIGRATION_MENU_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            if(errors.auto_chase_errors.loading_images_ac.arrow_menu_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    ARROW_MENU_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
};

bool start_configuration_menu()
{
    ACConfigurationMenu ac_configuration_menu;
    if(!ac_configuration_menu.load_status())
        ac_configuration_menu.error();
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
                ac_configuration_menu.left();
                (*input)[MENU_LEFT]=false;
            }
            if((*input)[MENU_RIGHT])
            {
                ac_configuration_menu.right();
                (*input)[MENU_RIGHT]=false;
            }
            if((*input)[MENU_UP])
            {
                ac_configuration_menu.up();
                (*input)[MENU_UP]=false;
            }
            if((*input)[MENU_DOWN])
            {
                ac_configuration_menu.down();
                (*input)[MENU_DOWN]=false;
            }
            if(input->get_timer_event())
                ac_configuration_menu.draw();
        }
    }
    return (ac_configuration_menu.has_changes());
}

#endif // INCLUDED_AC_CONFIGURATION_MENU_H
