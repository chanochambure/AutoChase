#ifndef INCLUDED_AC_PAUSE_H
#define INCLUDED_AC_PAUSE_H

class ACPause
{
    private:
        LL_AL5::Rectangle _V_pause_block;
        LL_AL5::Rectangle _V_option_block;
        LL_AL5::Text _V_pause_label;
        LL_AL5::Text _V_options[AC_PAUSE_TOTAL_OPTIONS];
    public:
        ACPause()
        {
            _V_pause_block.set_filled_status(true);
            _V_pause_block.set_color(BLACK_GRAY);
            _V_pause_block.set_pos(50,500);
            _V_pause_block.set_size_x(180);
            _V_pause_block.set_size_y(60);
            _V_option_block.set_filled_status(true);
            _V_option_block.set_color(BLACK_GRAY);
            _V_option_block.set_pos(350,500);
            _V_option_block.set_size_x(200);
            _V_option_block.set_size_y(70);
            _V_pause_label.set_font(comic_long);
            _V_pause_label.set_color(BLACK);
            _V_pause_label.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_pause_label.set_pos(140,500);
            _V_pause_label=game.autochase_text.pause.pause_label;
            for(unsigned int i=0;i<AC_PAUSE_TOTAL_OPTIONS;++i)
            {
                _V_options[i].set_font(comic_small);
                _V_options[i].set_color(BLACK);
                _V_options[i].set_flag(ALLEGRO_ALIGN_CENTER);
                _V_options[i].set_pos(450,505+(i*comic_small->get_size()));
            }
            _V_options[PAUSE_CONTINUE_OPTION]=game.autochase_text.pause.continue_option;
            _V_options[PAUSE_NEW_GAME_OPTION]=game.autochase_text.pause.new_game_option;
            _V_options[PAUSE_EXIT_GAME_OPTION]=game.autochase_text.pause.exit_game_option;
        }
        void draw()
        {
            screen->draw(&_V_pause_block);
            screen->draw(&_V_option_block);
            screen->draw(&_V_pause_label);
            for(unsigned int i=0;i<AC_PAUSE_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_options[i]));
            screen->refresh();
        }
};

int start_ac_pause()
{
    ACPause ac_pause;
    input->clear_key_status();
    input->clear_events();
    ac_pause.draw();
    while(game_running)
    {
        input->get_event();
        if(input->get_display_status())
            game_running=false;
        if((*input)[GAME_PAUSE])
            break;
        if((*input)[GAME_EXIT])
            return PAUSE_EXIT_GAME_OPTION;
        if((*input)[GAME_RESTART])
            return PAUSE_NEW_GAME_OPTION;
    }
    input->clear_key_status();
    input->clear_events();
    return PAUSE_CONTINUE_OPTION;
}

#endif // INCLUDED_AC_PAUSE_H
