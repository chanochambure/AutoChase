#ifndef INCLUDED_ARE_YOU_READY_AC_H
#define INCLUDED_ARE_YOU_READY_AC_H

class ACAreYouReady
{
    private:
        LL::Chronometer _V_chrono;
        LL_AL5::Color _V_background;
        LL_AL5::Text _V_message;
        bool _V_ready_message_set_status=true;
    public:
        ACAreYouReady()
        {
            if(ac_difficulty!=DIFFICULTY_HARD)
                _V_background=WHITE;
            else
                _V_background=BLACK;
            _V_message.set_color(!_V_background);
            _V_message.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_message.set_font(comic_long);
            _V_message.set_pos(REAL_SIZE_X_GAME/2,REAL_SIZE_Y_GAME/2);
            _V_message=game.autochase_text.are_you_ready.ready;
            _V_chrono.play();
        }
        bool status()
        {
            return _V_chrono.get_time()<AC_GO_TIME;
        }
        void draw()
        {
            screen->clear_to_color(_V_background);
            if(_V_ready_message_set_status and _V_chrono.get_time()>=AC_READY_TIME)
            {
                _V_ready_message_set_status=false;
                _V_message=game.autochase_text.are_you_ready.go;
            }
            screen->draw(&_V_message);
            screen->refresh();
        }
};

void start_are_you_ready()
{
    ACAreYouReady ac_are_you_ready;
    input->clear_key_status();
    input->clear_events();
    while(game_running and ac_are_you_ready.status())
    {
        input->get_event();
        if(input->get_display_status())
            game_running=false;
        if(input->get_timer_event())
            ac_are_you_ready.draw();
    }
    input->clear_key_status();
    input->clear_events();
}

#endif // INCLUDED_ARE_YOU_READY_AC_H
