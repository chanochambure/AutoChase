#ifndef INCLUDED_LL_LOGO_H
#define INCLUDED_LL_LOGO_H

class LL_Logo
{
    private:
        LL_AL5::Video _V_logo;
    public:
        LL_Logo()
        {
            _V_logo.set_path(LL_LOGO_VIDEO_PATH);
            errors.loading_videos.ll_logo_video=!(_V_logo.load());
        }
        bool load_status()
        {
            return !(errors.loading_videos.ll_logo_video);
        }
        void start()
        {
            if(load_status())
            {
                screen->set_real_size(_V_logo.get_size_x(),_V_logo.get_size_y());
                _V_logo.start();
            }
        }
        bool status()
        {
            return _V_logo.is_playing();
        }
        void draw()
        {
            screen->clear();
            screen->draw(&_V_logo);
            screen->refresh();
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                        LL_LOGO_VIDEO_PATH,ALLEGRO_MESSAGEBOX_WARN);
        }
        ~LL_Logo()
        {
            if(load_status())
                _V_logo.stop();
            screen->set_real_size(REAL_SIZE_X_TITLE,REAL_SIZE_Y_TITLE);
        }
};

void start_LL_Logo()
{
    loader->init_load();
    LL_Logo logo;
    if(!logo.load_status())
        logo.error();
    else
    {
        loader->finish_load();
        input->clear_key_status();
        input->clear_events();
        logo.start();
        while(game_running and logo.status())
        {
            input->get_event();
            if(input->get_display_status())
                game_running=false;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                logo.draw();
        }
    }
}

#endif // INCLUDED_LL_LOGO_H
