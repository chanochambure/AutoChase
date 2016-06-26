#ifndef GAME_DEMO_H_INCLUDED
#define GAME_DEMO_H_INCLUDED

class Demo
{
    private:
        LL_AL5::Video demo;
        LL_AL5::Text middle;
    public:
        Demo()
        {
            demo.set_path(DEMO_VIDEO_PATH);
            errors.loading_videos.demo_video=!(demo.load());
        }
        bool load_status()
        {
            return !(errors.loading_videos.demo_video);
        }
        void start()
        {
            if(load_status())
            {
                screen->set_real_size(demo.get_size_x(),demo.get_size_y());
                middle.set_font(comic_normal);
                middle=game.demo_text.middle_text;
                middle.set_pos(demo.get_size_x()/2,demo.get_size_y()/2);
                middle.set_color(RED);
                middle.set_flag(ALLEGRO_ALIGN_CENTER);
                demo.start();
            }
        }
        bool status()
        {
            return demo.is_playing();
        }
        void draw()
        {
            screen->clear();
            screen->draw(&demo);
            screen->draw(&middle);
            screen->refresh();
        }
        void error()
        {
            LL_AL5::show_native_message(*screen,game.error_text.title,game.error_text.header_file,DEMO_VIDEO_PATH,ALLEGRO_MESSAGEBOX_WARN);
        }
        ~Demo()
        {
            if(load_status())
                demo.stop();
            screen->set_real_size(_REALSIZEX_TITLE,_REALSIZEY_TITLE);
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
        while(exit_program and demo.status())
        {
            input->get_event();
            if(input->get_display_status())
                exit_program=false;
            if((*input)[MENU_CANCEL] or (*input)[MENU_SELECT])
                break;
            if(input->get_timer_event())
                demo.draw();
        }
    }
}

#endif // GAME_DEMO_H_INCLUDED
