#ifndef LL_LOGO_H_INCLUDED
#define LL_LOGO_H_INCLUDED

class LL_Logo
{
    private:
        LL_AL5::Video logo;
    public:
        LL_Logo()
        {
            logo.set_path(LL_LOGO_VIDEO_PATH);
            errors.loading_videos.ll_logo_video=!(logo.load());
        }
        bool load_status()
        {
            return !(errors.loading_videos.ll_logo_video);
        }
        void start()
        {
            if(load_status())
            {
                screen->set_real_size(logo.get_size_x(),logo.get_size_y());
                logo.start();
            }
        }
        bool status()
        {
            return logo.is_playing();
        }
        void draw()
        {
            screen->clear();
            screen->draw(&logo);
            screen->refresh();
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,LL_LOGO_VIDEO_PATH,ALLEGRO_MESSAGEBOX_WARN);
        }
        ~LL_Logo()
        {
            if(load_status())
                logo.stop();
            screen->set_real_size(_REALSIZEX_TITLE,_REALSIZEY_TITLE);
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
        while(exit_program and logo.status())
        {
            input->get_event();
            if(input->get_display_status())
                exit_program=false;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                logo.draw();
        }
    }
}

#endif // LL_LOGO_H_INCLUDED
