#ifndef GAME_OPENING_H_INCLUDED
#define GAME_OPENING_H_INCLUDED

class Opening
{
    private:
        LL_AL5::Video opening;
    public:
        Opening()
        {
            opening.set_path(OPENING_VIDEO_PATH);
            errors.loading_videos.opening_video=!(opening.load());
        }
        bool load_status()
        {
            return !(errors.loading_videos.opening_video);
        }
        void start()
        {
            if(load_status())
            {
                screen->set_real_size(opening.get_size_x(),opening.get_size_y());
                opening.start();
            }
        }
        bool status()
        {
            return opening.is_playing();
        }
        void draw()
        {
            screen->clear();
            screen->draw(&opening);
            screen->refresh();
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,OPENING_VIDEO_PATH,ALLEGRO_MESSAGEBOX_WARN);
        }
        ~Opening()
        {
            if(load_status())
                opening.stop();
            screen->set_real_size(_REALSIZEX_TITLE,_REALSIZEY_TITLE);
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
        while(exit_program and opening.status())
        {
            input->get_event();
            if(input->get_display_status())
                exit_program=false;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                opening.draw();
        }
    }
}

#endif // GAME_OPENING_H_INCLUDED
