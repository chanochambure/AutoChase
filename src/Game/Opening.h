#ifndef INCLUDED_GAME_OPENING_H
#define INCLUDED_GAME_OPENING_H

class Opening
{
    private:
        LL_AL5::Video _V_opening;
    public:
        Opening()
        {
            _V_opening.set_path(OPENING_VIDEO_PATH);
            errors.loading_videos.opening_video=!(_V_opening.load());
        }
        bool load_status()
        {
            return !(errors.loading_videos.opening_video);
        }
        void start()
        {
            if(load_status())
            {
                screen->set_real_size(_V_opening.get_size_x(),_V_opening.get_size_y());
                _V_opening.start();
            }
        }
        bool status()
        {
            return _V_opening.is_playing();
        }
        void draw()
        {
            screen->clear();
            screen->draw(&_V_opening);
            screen->refresh();
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                        OPENING_VIDEO_PATH,ALLEGRO_MESSAGEBOX_WARN);
        }
        ~Opening()
        {
            if(load_status())
                _V_opening.stop();
            screen->set_real_size(REAL_SIZE_X_TITLE,REAL_SIZE_Y_TITLE);
        }
};

void start_Opening()
{
    loader->init_load();
    Opening opening;
    if(!opening.load_status())
        opening.error();
    else
    {
        loader->finish_load();
        input->clear_key_status();
        input->clear_events();
        opening.start();
        while(game_running and opening.status())
        {
            input->get_event();
            if(input->get_display_status())
                game_running=false;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                opening.draw();
        }
    }
}

#endif // INCLUDED_GAME_OPENING_H
