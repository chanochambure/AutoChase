#ifndef GAME_DEMO_H_INCLUDED
#define GAME_DEMO_H_INCLUDED

class Demo
{
    private:
        LL_AL5::Video _V_demo;
        LL_AL5::Text _V_middle;
    public:
        Demo()
        {
            _V_demo.set_path(DEMO_VIDEO_PATH);
            errors.loading_videos.demo_video=!(_V_demo.load());
        }
        bool load_status()
        {
            return !(errors.loading_videos.demo_video);
        }
        void start()
        {
            if(load_status())
            {
                screen->set_real_size(_V_demo.get_size_x(),_V_demo.get_size_y());
                _V_middle.set_font(comic_normal);
                _V_middle=game.demo_text.middle_text;
                _V_middle.set_pos(_V_demo.get_size_x()/2,_V_demo.get_size_y()/2);
                _V_middle.set_color(RED);
                _V_middle.set_flag(ALLEGRO_ALIGN_CENTER);
                _V_demo.start();
            }
        }
        bool status()
        {
            return _V_demo.is_playing();
        }
        void draw()
        {
            screen->clear();
            screen->draw(&_V_demo);
            screen->draw(&_V_middle);
            screen->refresh();
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                        DEMO_VIDEO_PATH,ALLEGRO_MESSAGEBOX_WARN);
        }
        ~Demo()
        {
            if(load_status())
                _V_demo.stop();
            screen->set_real_size(REAL_SIZE_X_TITLE,REAL_SIZE_Y_TITLE);
        }
};

void start_Demo()
{
    loader->init_load();
    Demo demo;
    if(!demo.load_status())
        demo.error();
    else
    {
        loader->finish_load();
        input->clear_key_status();
        input->clear_events();
        demo.start();
        while(game_running and demo.status())
        {
            input->get_event();
            if(input->get_display_status())
                game_running=false;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                demo.draw();
        }
    }
}

#endif // GAME_DEMO_H_INCLUDED
