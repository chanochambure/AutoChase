#ifndef INCLUDED_AC_MAIN_MENU_H
#define INCLUDED_AC_MAIN_MENU_H

int ac_main_menu_option=AC_MAIN_MENU_PLAY_GAME;

class ACMainMenu
{
    private:
        LL_AL5::Image _V_background;
        LL_AL5::Image _V_arrow;
        LL_AL5::Text _V_options[AC_MAIN_MENU_TOTAL_OPTIONS];
        LL_AL5::Text _V_footnote;
        LL_AL5::Text _V_controls;
    public:
        ACMainMenu()
        {
            _V_background.set_path(BACKGROUND_MAIN_MENU_IMAGE_PATH);
            errors.auto_chase_errors.loading_images_ac.background_main_menu_image=!_V_background.load();
            _V_arrow.set_path(ARROW_MENU_IMAGE_PATH);
            errors.auto_chase_errors.loading_images_ac.arrow_menu_image=!_V_arrow.load();
            _V_arrow.set_pos(AC_MAIN_MENU_OPTIONS_POS_X,
                        AC_MAIN_MENU_OPTIONS_POS_Y+(ac_main_menu_option*comic_long->get_size()));
            for(unsigned int i=0;i<AC_MAIN_MENU_TOTAL_OPTIONS;++i)
            {
                _V_options[i].set_font(comic_long);
                _V_options[i].set_color(BLACK);
                _V_options[i].set_flag(ALLEGRO_ALIGN_RIGHT);
                _V_options[i].set_pos(AC_MAIN_MENU_OPTIONS_POS_X,
                                      AC_MAIN_MENU_OPTIONS_POS_Y+(i*comic_long->get_size()));
            }
            _V_options[AC_MAIN_MENU_PLAY_GAME]=game.autochase_text.main_menu.play_game;
            _V_options[AC_MAIN_MENU_CONFIGURATION]=game.autochase_text.main_menu.configuration;
            _V_options[AC_MAIN_MENU_CREDITS]=game.autochase_text.main_menu.credits_option;
            _V_options[AC_MAIN_MENU_EXIT_GAME]=game.autochase_text.main_menu.exit;
            _V_footnote.set_font(comic_normal);
            _V_footnote=(game.organization+" - "+game.release_year);
            _V_footnote.set_color(BLACK);
            _V_footnote.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_footnote.set_pos(REAL_SIZE_X_GAME/2,REAL_SIZE_Y_GAME-30);
            _V_controls.set_font(comic_normal);
            _V_controls=game.autochase_text.main_menu.controls;
            _V_controls.set_color(BLACK);
            _V_controls.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_controls.set_pos(REAL_SIZE_X_GAME/2,REAL_SIZE_Y_GAME-70);
        }
        bool load_status()
        {
            return !(errors.auto_chase_errors.loading_images_ac.background_main_menu_image) and
                    !(errors.auto_chase_errors.loading_images_ac.arrow_menu_image);
        }
        void move_selection_up_down(int num_of_moves)
        {
            ac_main_menu_option=LL::mod(ac_main_menu_option+num_of_moves,AC_MAIN_MENU_TOTAL_OPTIONS);
            _V_arrow.set_pos(AC_MAIN_MENU_OPTIONS_POS_X,
                        AC_MAIN_MENU_OPTIONS_POS_Y+(ac_main_menu_option*comic_long->get_size()));

        }
        void up()
        {
            move_selection_up_down(-1);
        }
        void down()
        {
            move_selection_up_down(1);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&_V_background);
            screen->draw(&_V_arrow);
            for(unsigned int i=0;i<AC_MAIN_MENU_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_options[i]));
            screen->draw(&_V_footnote);
            screen->draw(&_V_controls);
            screen->refresh();
        }
        void error()
        {
            if(errors.auto_chase_errors.loading_images_ac.background_main_menu_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    BACKGROUND_MAIN_MENU_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            if(errors.auto_chase_errors.loading_images_ac.arrow_menu_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    ARROW_MENU_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
};

void start_ac_main_menu()
{
    ACMainMenu ac_main_menu;
    if(!ac_main_menu.load_status())
        ac_main_menu.error();
    else
    {
        input->clear_key_status();
        input->clear_events();
        while(game_running)
        {
            input->get_event();
            if(input->get_display_status())
                game_running=false;
            if((*input)[MENU_UP])
            {
                ac_main_menu.up();
                (*input)[MENU_UP]=false;
            }
            if((*input)[MENU_DOWN])
            {
                ac_main_menu.down();
                (*input)[MENU_DOWN]=false;
            }
            if((*input)[MENU_CANCEL])
            {
                ac_main_menu_option=AC_MAIN_MENU_EXIT_GAME;
                break;
            }
            if((*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                ac_main_menu.draw();
        }
    }
}

#endif // INCLUDED_AC_MAIN_MENU_H
