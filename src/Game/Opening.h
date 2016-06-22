#ifndef GAME_OPENING_H_INCLUDED
#define GAME_OPENING_H_INCLUDED

class Opening
{
    private:
        LL_AL5::Video opening;
        double duration=0;
        LL::Chronometer timer;
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
                timer.play();
            }
        }
        bool status()
        {
            return (duration+0.5)>timer.get_time();
        }
        void draw()
        {
            duration=opening.get_video_position();
            screen->clear();
            screen->draw(&opening);
            screen->refresh();
        }
        void error()
        {
            #ifdef GAME_DEBUG
            show_native_message(*screen,game.error_text.title,game.error_text.header_file,OPENING_VIDEO_PATH,ALLEGRO_MESSAGEBOX_WARN);
            #else
            show_native_message(*screen,game.error_text.title,game.error_text.header_file,OPENING_VIDEO_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            exit_program=1;
            #endif // GAME_DEBUG
        }
        ~Opening()
        {
            if(load_status())
                opening.stop();
            timer.stop();
            screen->set_real_size(_REALSIZEX,_REALSIZEY);
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
        while(!exit_program and opening.status())
        {
            input->get_event();
            if(input->get_display_status())
                exit_program=1;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                opening.draw();
        }
    }
}

#endif // GAME_OPENING_H_INCLUDED
