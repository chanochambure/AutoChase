#ifndef GAME_TITLE_MENU_H_INCLUDED
#define GAME_TITLE_MENU_H_INCLUDED

#ifdef GAME_DEMO
#include "Demo.h"
#endif // GAME_DEMO

class TitleMenu
{
    private:
        LL_AL5::Image logo;
        LL_AL5::Text start_game;
        LL_AL5::Text footnote;
        #ifdef GAME_DEMO
        LL::Chronometer timer;
        #endif // GAME_DEMO
    public:
        TitleMenu()
        {
            logo.set_path(LOGO_IMAGE_PATH);
            if(!(errors.loading_images.logo_image=!logo.load()))
                logo.set_pos((REAL_SIZE_X_TITLE/2)-(logo.get_size_x()/2),100);
            start_game.set_font(comic_small);
            start_game=game.title_menu.start_game;
            start_game.set_color(WHITE);
            start_game.set_flag(ALLEGRO_ALIGN_CENTER);
            start_game.set_pos((REAL_SIZE_X_TITLE/2),500);
            footnote.set_font(comic_small);
            footnote=(game.organization+" - "+game.release_year);
            footnote.set_color(WHITE);
            footnote.set_flag(ALLEGRO_ALIGN_LEFT);
            footnote.set_pos(10,REAL_SIZE_Y_TITLE-30);
            #ifdef GAME_DEMO
            timer.clear();
            timer.play();
            #endif // GAME_DEMO
        }
        bool load_status()
        {
            return !(errors.loading_images.logo_image);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&logo);
            screen->draw(&start_game);
            screen->draw(&footnote);
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
            if(timer.get_time()>=GAME_DEMO_WAIT_TIME)
            {
                input->clear_key_status();
                input->clear_events();
                start_Demo();
                timer.stop();
                timer.clear();
                timer.play();
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
