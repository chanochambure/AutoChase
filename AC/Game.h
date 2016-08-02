#ifndef INCLUDED_AC_GAME_H
#define INCLUDED_AC_GAME_H

#include "AreYouReady.h"
#include "Pause.h"
#include "EndGame.h"

#include "Objects/Player.h"
#include "Objects/Score.h"
#include "Objects/Enemy.h"

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
        int _V_actual_score=0;
        bool _V_playing=true;
        bool _V_in_game=true;
        bool _V_finish_game=false;
        ACPlayer _V_player;
        ACScore _V_score;
        ACEnemy _V_enemies[TOTAL_ENEMIES];
        bool _V_up_status=false;
        bool _V_down_status=false;
        bool _V_left_status=false;
        bool _V_right_status=false;
    public:
        ACGame()
        {
            LL::random_generate_new_seed();
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
            errors.auto_chase_errors.game_errors_ac.create_player_status=!_V_player.create_sprite();
            _V_player.set_limits(PLAYER_LIMIT_POS_X_1,PLAYER_LIMIT_POS_X_2,
                                 PLAYER_LIMIT_POS_Y_1,PLAYER_LIMIT_POS_Y_2);
            errors.auto_chase_errors.loading_images_ac.ac_score_image=!_V_score.create_score();
            _V_score.set_limits(PLAYER_LIMIT_POS_X_1,PLAYER_LIMIT_POS_X_2,
                                PLAYER_LIMIT_POS_Y_1,PLAYER_LIMIT_POS_Y_2);
            int enemy_errors=0;
            for(unsigned int i=0;i<TOTAL_ENEMIES;++i)
            {
                switch(ac_difficulty)
                {
                    case DIFFICULTY_EASY:
                    {
                        _V_enemies[i].set_max_speed(ENEMY_EASY_MAX_SPEED*(i+1)/TOTAL_ENEMIES);
                        if(LL::mod(i,2)==0)
                            enemy_errors+=!_V_enemies[i].create_enemy(ENEMY_EASY_1_PATH_IMAGE);
                        else
                            enemy_errors+=!_V_enemies[i].create_enemy(ENEMY_EASY_2_PATH_IMAGE);
                        break;
                    }
                    case DIFFICULTY_NORMAL:
                    {
                        _V_enemies[i].set_max_speed(ENEMY_NORMAL_MAX_SPEED*(i+1)/TOTAL_ENEMIES);
                        if(LL::mod(i,2)==0)
                            enemy_errors+=!_V_enemies[i].create_enemy(ENEMY_NORMAL_1_PATH_IMAGE);
                        else
                            enemy_errors+=!_V_enemies[i].create_enemy(ENEMY_NORMAL_2_PATH_IMAGE);
                        break;
                    }
                    case DIFFICULTY_HARD:
                    {
                        _V_enemies[i].set_max_speed(ENEMY_HARD_MAX_SPEED*(i+1)/TOTAL_ENEMIES);
                        if(LL::mod(i,2)==0)
                            enemy_errors+=!_V_enemies[i].create_enemy(ENEMY_HARD_1_PATH_IMAGE);
                        else
                            enemy_errors+=!_V_enemies[i].create_enemy(ENEMY_HARD_2_PATH_IMAGE);
                        break;
                    }
                }
            }
            errors.auto_chase_errors.game_errors_ac.create_enemies_status=(0<enemy_errors);
        }
        bool load_status()
        {
            return !(errors.auto_chase_errors.loading_images_ac.ac_hud_image) and
                    !(errors.auto_chase_errors.game_errors_ac.create_player_status) and
                    !(errors.auto_chase_errors.game_errors_ac.create_enemies_status) and
                    !(errors.auto_chase_errors.loading_images_ac.ac_score_image);
        }
        bool status()
        {
            return _V_playing;
        }
        void initializing_data()
        {
            _V_in_game=true;
            _V_finish_game=false;
            _V_actual_score=0;
            _V_record_text.set_color(WHITE);
            _V_record_text=LL::to_string(ac_records[ac_difficulty]);
            _V_score_text.set_color(WHITE);
            _V_score_text=LL::to_string(_V_actual_score);
            _V_player.set_selection(RIGHT_PLAYER_SPRITE);
            _V_player.set_pos(PLAYER_INI_POS_X,PLAYER_INI_POS_Y);
            _V_score.generate_new_pos();
            for(unsigned int i=0;i<TOTAL_ENEMIES;++i)
                _V_enemies[i].set_pos(ENEMY_INI_POS_X,(i+1)*REAL_SIZE_Y_GAME/(TOTAL_ENEMIES+2));
        }
        void draw()
        {
            screen->clear_to_color(_V_background_color);
            screen->draw(&_V_hud);
            screen->draw(&_V_score_label);
            screen->draw(&_V_record_label);
            screen->draw(&_V_score_text);
            screen->draw(&_V_record_text);
            screen->draw(&_V_score);
            for(unsigned int i=0;i<TOTAL_ENEMIES;++i)
                screen->draw(&_V_enemies[i]);
            screen->draw(&_V_player);
            screen->refresh();
        }
        void error()
        {
            if(errors.auto_chase_errors.loading_images_ac.ac_hud_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    AC_HUD_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            if(errors.auto_chase_errors.game_errors_ac.create_player_status)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_internal,
                                    game.autochase_text.error_text.create_player,ALLEGRO_MESSAGEBOX_ERROR);
            if(errors.auto_chase_errors.loading_images_ac.ac_score_image)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                    AC_SCORE_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            if(errors.auto_chase_errors.game_errors_ac.create_enemies_status)
                LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_internal,
                                    game.autochase_text.error_text.create_enemies,ALLEGRO_MESSAGEBOX_ERROR);
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
        void set_up(bool up_status)
        {
            _V_up_status=up_status;
        }
        void set_down(bool down_status)
        {
            _V_down_status=down_status;
        }
        void set_left(bool left_status)
        {
            _V_left_status=left_status;
        }
        void set_right(bool right_status)
        {
            _V_right_status=right_status;
        }
        void move_world()
        {
            if(_V_right_status)
                _V_player.set_selection(RIGHT_PLAYER_SPRITE);
            else if(_V_left_status)
                _V_player.set_selection(LEFT_PLAYER_SPRITE);
            else if(_V_down_status)
                _V_player.set_selection(DOWN_PLAYER_SPRITE);
            else if(_V_up_status)
                _V_player.set_selection(UP_PLAYER_SPRITE);
            _V_player.move(_V_right_status-_V_left_status,_V_down_status-_V_up_status);
            if(LL::segment_collision(_V_player.get_pos_x()-_V_player.get_size_x()/2,
                                     _V_player.get_pos_x()+_V_player.get_size_x()/2,
                                     _V_score.get_pos_x()-_V_score.get_size_x()/2,
                                     _V_score.get_pos_x()+_V_score.get_size_x()/2))
            {
                if(LL::segment_collision(_V_player.get_pos_y()-_V_player.get_size_y()/2,
                                         _V_player.get_pos_y()+_V_player.get_size_y()/2,
                                         _V_score.get_pos_y()-_V_score.get_size_y()/2,
                                         _V_score.get_pos_y()+_V_score.get_size_y()/2))
                {
                    _V_score.generate_new_pos();
                    ++_V_actual_score;
                    if(ac_records[ac_difficulty]<_V_actual_score)
                    {
                        _V_record_text.set_color(RED);
                        _V_record_text=LL::to_string(_V_actual_score);
                    }
                    _V_score_text=LL::to_string(_V_actual_score);
                }
            }
            for(unsigned int i=0;i<TOTAL_ENEMIES;++i)
            {
                if(LL::mod(i,2))
                    _V_enemies[i].move(_V_player.get_pos_x(),_V_player.get_pos_y());
                else
                    _V_enemies[i].move(_V_score.get_pos_x(),_V_score.get_pos_y());
                if(LL::segment_collision(_V_player.get_pos_x()-_V_player.get_size_x()/2,
                                         _V_player.get_pos_x()+_V_player.get_size_x()/2,
                                         _V_enemies[i].get_pos_x()-_V_enemies[i].get_size_x()/2,
                                         _V_enemies[i].get_pos_x()+_V_enemies[i].get_size_x()/2))
                {
                    if(LL::segment_collision(_V_player.get_pos_y()-_V_player.get_size_y()/2,
                                             _V_player.get_pos_y()+_V_player.get_size_y()/2,
                                             _V_enemies[i].get_pos_y()-_V_enemies[i].get_size_y()/2,
                                             _V_enemies[i].get_pos_y()+_V_enemies[i].get_size_y()/2))
                    {
                        _V_in_game=false;
                        _V_finish_game=true;
                    }
                }
                if(LL::segment_collision(_V_score.get_pos_x()-_V_score.get_size_x()/2,
                                         _V_score.get_pos_x()+_V_score.get_size_x()/2,
                                         _V_enemies[i].get_pos_x()-_V_enemies[i].get_size_x()/2,
                                         _V_enemies[i].get_pos_x()+_V_enemies[i].get_size_x()/2))
                {
                    if(LL::segment_collision(_V_score.get_pos_y()-_V_score.get_size_y()/2,
                                             _V_score.get_pos_y()+_V_score.get_size_y()/2,
                                             _V_enemies[i].get_pos_y()-_V_enemies[i].get_size_y()/2,
                                             _V_enemies[i].get_pos_y()+_V_enemies[i].get_size_y()/2))
                    {
                        _V_score.generate_new_pos();
                    }
                }
            }
        }
        void save()
        {
            if(ac_records[ac_difficulty]<_V_actual_score)
            {
                ac_records[ac_difficulty]=_V_actual_score;
                save_data();
            }
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
                    ac_game.set_up((*input)[GAME_UP]);
                    ac_game.set_down((*input)[GAME_DOWN]);
                    ac_game.set_left((*input)[GAME_LEFT]);
                    ac_game.set_right((*input)[GAME_RIGHT]);
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
                    {
                        ac_game.move_world();
                        ac_game.draw();
                    }
                }
                if(ac_game.finish_game())
                {
                    ac_game.save();
                    switch(start_ac_end_game())
                    {
                        case END_EXIT_GAME_OPTION:
                        {
                            ac_game.exit();
                            break;
                        }
                    }
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
