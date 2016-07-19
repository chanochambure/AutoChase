#ifndef GAME_TITLE_MENU_H_INCLUDED
#define GAME_TITLE_MENU_H_INCLUDED

#ifdef GAME_DEMO
#include "Demo.h"
#endif // GAME_DEMO

class TitleMenu
{
    private:
        LL_AL5::Image _V_logo;
        LL_AL5::Text _V_start_game;
        LL_AL5::Text _V_footnote;
        #ifdef GAME_DEMO
        LL::Chronometer _V_chrono;
        #endif // GAME_DEMO
    public:
        TitleMenu()
        {
            _V_logo.set_path(LOGO_IMAGE_PATH);
            if(!(errors.loading_images.logo_image=!_V_logo.load()))
                _V_logo.set_pos((REAL_SIZE_X_TITLE/2)-(_V_logo.get_size_x()/2),100);
            _V_start_game.set_font(comic_small);
            _V_start_game=game.title_menu.start_game;
            _V_start_game.set_color(WHITE);
            _V_start_game.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_start_game.set_pos((REAL_SIZE_X_TITLE/2),500);
            _V_footnote.set_font(comic_small);
            _V_footnote=(game.organization+" - "+game.release_year);
            _V_footnote.set_color(WHITE);
            _V_footnote.set_flag(ALLEGRO_ALIGN_LEFT);
            _V_footnote.set_pos(10,REAL_SIZE_Y_TITLE-30);
            #ifdef GAME_DEMO
            _V_chrono.clear();
            _V_chrono.play();
            #endif // GAME_DEMO
        }
        bool load_status()
        {
            return !(errors.loading_images.logo_image);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&_V_logo);
            screen->draw(&_V_start_game);
            screen->draw(&_V_footnote);
            screen->refresh();
        }
        void error()
        {
            show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                LOGO_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
        #ifdef GAME_DEMO
        void demo_start()
        {
            if(_V_chrono.get_time()>=GAME_DEMO_WAIT_TIME)
            {
                input->clear_key_status();
                input->clear_events();
                start_Demo();
                _V_chrono.stop();
                _V_chrono.clear();
                _V_chrono.play();
                input->clear_key_status();
                input->clear_events();
            }
        }
        #endif // GAME_DEMO
};

bool start_title_menu()
{
    loader->init_load();
    TitleMenu title;
    if(!title.load_status())
        title.error();
    else
    {
        loader->finish_load();
        input->clear_key_status();
        input->clear_events();
        while(game_running)
        {
            #ifdef GAME_DEMO
            title.demo_start();
            #endif // GAME_DEMO
            if(input->get_event())
            {
                if(input->get_display_status() or (*input)[MENU_CANCEL])
                    game_running=false;
                if((*input)[MENU_SELECT])
                    return true;
                if(input->get_timer_event())
                    title.draw();
            }
        }
    }
    return false;
}

#endif // GAME_TITLE_MENU_H_INCLUDED
