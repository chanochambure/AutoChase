#ifndef INCLUDED_AC_CREDITS_H
#define INCLUDED_AC_CREDITS_H

class ACCredits
{
    private:
        LL_AL5::Image _V_background;
        LL_AL5::Image _V_logo;
        LL_AL5::Image _V_lexris_logic_logo;
        LL_AL5::Text _V_credit_line;
        LL_AL5::Type_pos _V_iterator;
        LL_AL5::Type_pos _V_position_x;
    public:
        ACCredits()
        {
            _V_position_x=REAL_SIZE_X_GAME/2;
            _V_background.set_path(BACKGROUND_CREDITS_IMAGE_PATH);
            errors.auto_chase_errors.loading_images_ac.background_credits_image=!_V_background.load();
            _V_logo.set_path(LOGO_IMAGE_PATH);
            errors.loading_images.logo_image=!_V_logo.load();
            _V_lexris_logic_logo.set_path(LEXRIS_LOGIC_LOGO_PATH);
            errors.auto_chase_errors.loading_images_ac.lexris_logic_image=!_V_lexris_logic_logo.load();
            _V_iterator=REAL_SIZE_Y_GAME+comic_long->get_size();
            _V_logo.set_anchor(0.5,0);
            _V_lexris_logic_logo.set_anchor(0.5,0);
            _V_logo.set_scale_x(0.8);
            _V_logo.set_scale_y(0.8);
            _V_credit_line.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_credit_line.set_color(BLACK_GRAY);
            _V_credit_line.set_font(comic_normal);
            _V_logo.set_pos(_V_position_x,_V_iterator);
            _V_credit_line.set_pos(_V_position_x,
                                   _V_iterator+_V_logo.get_size_y()*_V_logo.get_scale_y()+comic_long->get_size());
            _V_lexris_logic_logo.set_pos(_V_position_x,
                                         _V_credit_line.get_pos_y()+comic_long->get_size()*(TOTAL_CREDITS_LINES+3));
        }
        bool load_status()
        {
            return !(errors.auto_chase_errors.loading_images_ac.lexris_logic_image) and
                    !(errors.auto_chase_errors.loading_images_ac.background_credits_image) and
                    !(errors.loading_images.logo_image);
        }
        void move_selection_up_down(int num_of_moves)
        {
            if(_V_iterator<REAL_SIZE_Y_GAME+comic_long->get_size())
                _V_iterator+=num_of_moves;
        }
        void up()
        {
            move_selection_up_down(-3);
        }
        void down()
        {
            move_selection_up_down(3);
        }
        bool status()
        {
            return _V_lexris_logic_logo.get_pos_y()+_V_lexris_logic_logo.get_size_y()>-comic_long->get_size();
        }
        void draw()
        {
            --_V_iterator;
            _V_logo.set_pos_y(_V_iterator);
            _V_credit_line.set_pos_y(_V_iterator+_V_logo.get_size_y()*_V_logo.get_scale_y()+comic_long->get_size());
            _V_lexris_logic_logo.set_pos_y(_V_credit_line.get_pos_y()+comic_long->get_size()*(TOTAL_CREDITS_LINES+3));
            screen->clear_to_color(BLACK);
            screen->draw(&_V_background);
            screen->draw(&_V_logo);
            for(unsigned int i=0;i<TOTAL_CREDITS_LINES;i++)
            {
                if(_V_credit_line.get_pos_y()>REAL_SIZE_Y_GAME)
                    break;
                _V_credit_line=game.autochase_text.credits.credits[i];
                screen->draw(&_V_credit_line);
                _V_credit_line.set_pos_y(_V_credit_line.get_pos_y()+comic_long->get_size());
            }
            screen->draw(&_V_lexris_logic_logo);
            screen->refresh();
        }
        void error()
        {
            if(errors.auto_chase_errors.loading_images_ac.background_credits_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    BACKGROUND_CREDITS_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            if(errors.loading_images.logo_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    LOGO_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            if(errors.auto_chase_errors.loading_images_ac.lexris_logic_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    LEXRIS_LOGIC_LOGO_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
};

void start_ac_credits()
{
    ACCredits ac_credits;
    if(!ac_credits.load_status())
        ac_credits.error();
    else
    {
        input->clear_key_status();
        input->clear_events();
        while(game_running and ac_credits.status())
        {
            input->get_event();
            if(input->get_display_status())
                game_running=false;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
            {
                if((*input)[MENU_UP])
                    ac_credits.up();
                if((*input)[MENU_DOWN])
                    ac_credits.down();
                ac_credits.draw();
            }
        }
    }
}

#endif // INCLUDED_AC_CREDITS_H
