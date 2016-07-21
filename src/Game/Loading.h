#ifndef INCLUDED_GAME_LOADING_H
#define INCLUDED_GAME_LOADING_H

class Loader
{
    private:
        double _V_status;
        LL_AL5::Image _V_logo;
        LL_AL5::Text _V_load_message;
        LL::Chronometer _V_chrono;
    public:
        Loader()
        {
            _V_logo.set_path(LOGO_IMAGE_PATH);
            if(!(errors.loading_images.logo_image=!_V_logo.load()))
            {
                _V_logo.set_pos(REAL_SIZE_X_TITLE-(_V_logo.get_size_x()/2),REAL_SIZE_Y_TITLE-(_V_logo.get_size_y()/2));
                _V_logo.set_scale_x(0.5);
                _V_logo.set_scale_y(0.5);
            }
            _V_load_message.set_font(comic_small);
            _V_load_message=game.load;
            _V_load_message.set_color(WHITE);
            _V_load_message.set_flag(ALLEGRO_ALIGN_CENTER);
            _V_load_message.set_pos((REAL_SIZE_X_TITLE/2.0),(REAL_SIZE_Y_TITLE/2.0));
        }
        bool load_status()
        {
            return !(errors.loading_images.logo_image);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            if(_V_status>LOADER_LOGO_STATUS)
            {
                screen->draw(&_V_logo,false);
                if(_V_status>LOADER_TEXT_STATUS)
                    screen->draw(&_V_load_message,false);
            }
            screen->refresh();
        }
        void init_load()
        {
            input->clear_key_status();
            input->clear_events();
            _V_chrono.play();
            _V_status=0;
            while(game_running and _V_status<LOADER_FINAL_STATUS)
            {
                _V_status=_V_chrono.get_time();
                input->get_event();
                if(input->get_display_status())
                    game_running=false;
                if(input->get_timer_event())
                    draw();
            }
            _V_status=LOADER_FINAL_STATUS;
            _V_chrono.stop();
        }
        void finish_load()
        {
            input->clear_key_status();
            input->clear_events();
            _V_chrono.play();
            _V_status=LOADER_FINAL_STATUS;
            while(game_running and _V_status>0)
            {
                _V_status=LOADER_FINAL_STATUS-_V_chrono.get_time();
                if(input->get_event())
                {
                    if(input->get_display_status())
                        game_running=false;
                    if(input->get_timer_event())
                        draw();
                }
            }
            _V_status=0;
            _V_chrono.stop();
        }
        void init_message(string message)
        {
            _V_load_message=message;
            init_load();
            _V_load_message=game.load;
        }
        void finish_message(string message)
        {
            _V_load_message=message;
            finish_load();
            _V_load_message=game.load;
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
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
