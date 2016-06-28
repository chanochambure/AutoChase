#ifndef INCLUDED_GAME_LOADING_H
#define INCLUDED_GAME_LOADING_H

class Loader
{
    private:
        double status;
        LL_AL5::Image logo;
        LL_AL5::Text load;
        LL::Chronometer chrono;
    public:
        Loader()
        {
            logo.set_path(LOGO_IMAGE_PATH);
            if(!(errors.loading_images.logo_image=!logo.load()))
            {
                logo.set_pos(REAL_SIZE_X_TITLE-(logo.get_size_x()/2),REAL_SIZE_Y_TITLE-(logo.get_size_y()/2));
                logo.set_scale_x(0.5);
                logo.set_scale_y(0.5);
            }
            load.set_font(comic_small);
            load=game.load;
            load.set_color(WHITE);
            load.set_flag(ALLEGRO_ALIGN_CENTER);
            load.set_pos((REAL_SIZE_X_TITLE/2.0),(REAL_SIZE_Y_TITLE/2.0));
        }
        bool load_status()
        {
            return !(errors.loading_images.logo_image);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            if(status>LOADER_LOGO_STATUS)
            {
                screen->draw(&logo,false);
                if(status>LOADER_TEXT_STATUS)
                    screen->draw(&load,false);
            }
            screen->refresh();
        }
        void init_load()
        {
            input->clear_key_status();
            input->clear_events();
            chrono.play();
            status=0;
            while(game_running and status<LOADER_FINAL_STATUS)
            {
                status=chrono.get_time();
                input->get_event();
                if(input->get_display_status())
                    game_running=false;
                if(input->get_timer_event())
                    draw();
            }
            status=LOADER_FINAL_STATUS;
            chrono.stop();
        }
        void finish_load()
        {
            input->clear_key_status();
            input->clear_events();
            chrono.play();
            status=LOADER_FINAL_STATUS;
            while(game_running and status>0)
            {
                status=LOADER_FINAL_STATUS-chrono.get_time();
                if(input->get_event())
                {
                    if(input->get_display_status())
                        game_running=false;
                    if(input->get_timer_event())
                        draw();
                }
            }
            status=0;
            chrono.stop();
        }
        void init_message(string message)
        {
            load=message;
            init_load();
            load=game.load;
        }
        void finish_message(string message)
        {
            load=message;
            finish_load();
            load=game.load;
        }
        void error()
        {
            show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                LOGO_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
        }
};

Loader* loader=nullptr;

void init_loader()
{
    loader=new Loader();
    if(!(loader->load_status()))
        loader->error();
}

void destroy_loader()
{
    if(loader)
        delete(loader);
    loader=nullptr;
}

#endif // INCLUDED_GAME_LOADING_H
