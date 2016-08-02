#ifndef INCLUDED_AC_ENDGAME_H
#define INCLUDED_AC_ENDGAME_H

class ACEndGame
{
    private:
        LL_AL5::Rectangle _V_end_game_block;
        LL_AL5::Rectangle _V_option_block;
        LL_AL5::Text _V_end_game_label;
        LL_AL5::Text _V_options[AC_END_GAME_TOTAL_OPTIONS];
    public:
        ACEndGame()
        {
            _V_end_game_block.set_filled_status(true);
            _V_end_game_block.set_color(BLACK_GRAY);
            _V_end_game_block.set_pos(40,500);
            _V_end_game_block.set_size_x(200);
            _V_end_game_block.set_size_y(60);
            _V_option_block.set_filled_status(true);
            _V_option_block.set_color(BLACK_GRAY);
            _V_option_block.set_pos(350,500);
            _V_option_block.set_size_x(200);
            _V_option_block.set_size_y(45);
            _V_end_game_label.set_font(comic_big);
            _V_end_game_label.set_color(BLACK);
            _V_end_game_label.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_end_game_label.set_pos(140,500);
            _V_end_game_label=game.autochase_text.end_game.end_game_label;
            for(unsigned int i=0;i<AC_END_GAME_TOTAL_OPTIONS;++i)
            {
                _V_options[i].set_font(comic_small);
                _V_options[i].set_color(BLACK);
                _V_options[i].set_flag(ALLEGRO_ALIGN_CENTER);
                _V_options[i].set_pos(450,505+(i*comic_small->get_size()));
            }
            _V_options[END_NEW_GAME_OPTION]=game.autochase_text.end_game.new_game_option;
            _V_options[END_EXIT_GAME_OPTION]=game.autochase_text.end_game.exit_game_option;
        }
        void draw()
        {
            screen->draw(&_V_end_game_block);
            screen->draw(&_V_option_block);
            screen->draw(&_V_end_game_label);
            for(unsigned int i=0;i<AC_END_GAME_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_options[i]));
            screen->refresh();
        }
};

int start_ac_end_game()
{
    ACEndGame ac_end_game;
    input->clear_key_status();
    input->clear_events();
    ac_end_game.draw();
    while(game_running)
    {
        input->get_event();
        if(input->get_display_status())
            game_running=false;
        if((*input)[GAME_PAUSE])
            break;
        if((*input)[GAME_EXIT])
            return END_EXIT_GAME_OPTION;
    }
    input->clear_key_status();
    input->clear_events();
    return END_NEW_GAME_OPTION;
}

#endif // INCLUDED_AC_ENDGAME_H
