#ifndef INCLUDED_AC_GAME_H
#define INCLUDED_AC_GAME_H

#include "AreYouReady.h"
#include "Pause.h"

bool create_key_control(LL_AL5::KeyControl* key_control)
{
    switch(ac_controls)
    {
        case AC_ARROWS_CONTROLS_OPTION:
        {
            key_control->add_key(GAME_UP,ALLEGRO_KEY_UP);
            key_control->add_key(GAME_LEFT,ALLEGRO_KEY_LEFT);
            key_control->add_key(GAME_DOWN,ALLEGRO_KEY_DOWN);
            key_control->add_key(GAME_RIGHT,ALLEGRO_KEY_RIGHT);
            key_control->add_key(GAME_PAUSE,ALLEGRO_KEY_ENTER);
            key_control->add_key(GAME_RESTART,ALLEGRO_KEY_R);
            key_control->add_key(GAME_EXIT,ALLEGRO_KEY_ESCAPE);
            break;
        }
        case AC_WASD_CONTROLS_OPTION:
        {
            key_control->add_key(GAME_UP,ALLEGRO_KEY_W);
            key_control->add_key(GAME_LEFT,ALLEGRO_KEY_A);
            key_control->add_key(GAME_DOWN,ALLEGRO_KEY_S);
            key_control->add_key(GAME_RIGHT,ALLEGRO_KEY_D);
            key_control->add_key(GAME_PAUSE,ALLEGRO_KEY_ENTER);
            key_control->add_key(GAME_RESTART,ALLEGRO_KEY_R);
            key_control->add_key(GAME_EXIT,ALLEGRO_KEY_ESCAPE);
            break;
        }
        default:
            return false;
    }
    return true;
}

class ACGame
{
    private:
        LL_AL5::Image _V_hud;
        LL_AL5::Color _V_background_color;
        LL_AL5::Text _V_score_label;
        LL_AL5::Text _V_score_text;
        LL_AL5::Text _V_record_label;
        LL_AL5::Text _V_record_text;
        unsigned int _V_score=0;
        bool _V_playing=true;
        bool _V_in_game=true;
        bool _V_finish_game=false;
    public:
        ACGame()
        {
            _V_hud.set_path(AC_HUD_IMAGE_PATH);
            errors.auto_chase_errors.loading_images_ac.ac_hud_image=!_V_hud.load();
            if(ac_difficulty!=DIFFICULTY_HARD)
                _V_background_color=WHITE;
            else
                _V_background_color=BLACK;
            _V_score_label.set_color(WHITE);
            _V_score_label.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_score_label.set_font(comic_normal);
            _V_score_label.set_pos(750,0);
            _V_score_label=game.autochase_text.game.score_label;
            _V_record_label.set_color(WHITE);
            _V_record_label.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_record_label.set_font(comic_long);
            _V_record_label.set_pos(750,425);
            _V_record_label=game.autochase_text.game.record_label;
            _V_score_text.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_score_text.set_font(comic_big);
            _V_score_text.set_pos(750,60);
            _V_record_text.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_record_text.set_font(comic_big);
            _V_record_text.set_pos(750,460);
        }
        bool load_status()
        {
            return !(errors.auto_chase_errors.loading_images_ac.ac_hud_image);
        }
        bool status()
        {
            return _V_playing;
        }
        void initializing_data()
        {
            _V_in_game=true;
            _V_finish_game=false;
            _V_score=0;
            _V_record_text.set_color(WHITE);
            _V_record_text=LL::to_string(ac_records[ac_difficulty]);
            _V_score_text.set_color(WHITE);
            _V_score_text=LL::to_string(_V_score);
        }
        void draw()
        {
            screen->clear_to_color(_V_background_color);
            screen->draw(&_V_hud);
            screen->draw(&_V_score_label);
            screen->draw(&_V_record_label);
            screen->draw(&_V_score_text);
            screen->draw(&_V_record_text);
            screen->refresh();
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                AC_HUD_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
        void exit()
        {
            _V_in_game=false;
            _V_playing=false;
        }
        void restart()
        {
            _V_in_game=false;
        }
        bool in_game()
        {
            return _V_in_game;
        }
        bool finish_game()
        {
            return _V_finish_game;
        }
};

void start_ac_game()
{
    ACGame ac_game;
    if(!ac_game.load_status())
        ac_game.error();
    else
    {
        input->clear_key_status();
        input->clear_events();
        LL_AL5::KeyControl game_key_control;
        if(!(errors.auto_chase_errors.game_errors_ac.create_key_control_status=!create_key_control(&game_key_control)))
        {
            input->set_key_control(&game_key_control);
            while(game_running and ac_game.status())
            {
                start_are_you_ready();
                ac_game.initializing_data();
                while(game_running and ac_game.in_game())
                {
                    input->get_event();
                    if(input->get_display_status())
                        game_running=false;
                    if((*input)[GAME_PAUSE])
                    {
                        switch(start_ac_pause())
                        {
                            case PAUSE_NEW_GAME_OPTION:
                            {
                                ac_game.restart();
                                break;
                            }
                            case PAUSE_EXIT_GAME_OPTION:
                            {
                                ac_game.exit();
                                break;
                            }
                        }
                    }
                    if(input->get_timer_event())
                        ac_game.draw();
                }
                if(ac_game.finish_game())
                {
                }
            }
            input->set_key_control(menu_key_control);
        }
        else
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_internal,
                                game.autochase_text.error_text.controls_option,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
    }
}

#endif // INCLUDED_AC_GAME_H
