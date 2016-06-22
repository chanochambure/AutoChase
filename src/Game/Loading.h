#ifndef LOADING_H_INCLUDED
#define LOADING_H_INCLUDED

class Loader
{
    private:
        double FINAL_STATUS;
        double LOGO_STATUS;
        double TEXT_STATUS;
        double status;
        LL_AL5::Image logo;
        LL_AL5::Text load;
        LL::Chronometer timer;
    public:
        Loader()
        {
            FINAL_STATUS=_LOADER_TIME;
            LOGO_STATUS=FINAL_STATUS/3;
            TEXT_STATUS=2*(LOGO_STATUS);
            logo.set_path(LOGO_IMAGE_PATH);
            if(!(errors.loading_images.logo_image=!logo.load()))
            {
                logo.set_pos(_REALSIZEX-(logo.get_size_x()/2),_REALSIZEY-(logo.get_size_y()/2));
                logo.set_scale_x(0.5);
                logo.set_scale_y(0.5);
            }
            load.set_font(comic_16C);
            load=game.load;
            load.set_color(WHITE);
            load.set_flag(ALLEGRO_ALIGN_CENTER);
            load.set_pos((_REALSIZEX/2.0),(_REALSIZEY/2.0));
        }
        bool load_status()
        {
            return !(errors.loading_images.logo_image);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            if(status>LOGO_STATUS)
            {
                screen->draw(&logo,0);
                if(status>TEXT_STATUS)
                    screen->draw(&load,0);
            }
            screen->refresh();
        }
        void init_load()
        {
            input->clear_key_status();
            input->clear_events();
            timer.play();
            status=0;
            while(!exit_program and status<FINAL_STATUS)
            {
                status=timer.get_time();
                input->get_event();
                if(input->get_display_status())
                    exit_program=1;
                if(input->get_timer_event())
                    draw();
            }
            status=FINAL_STATUS;
            timer.stop();
        }
        void finish_load()
        {
            input->clear_key_status();
            input->clear_events();
            timer.play();
            status=FINAL_STATUS;
            while(!exit_program and status>0)
            {
                status=FINAL_STATUS-timer.get_time();
                if(input->get_event())
                {
                    if(input->get_display_status())
                        exit_program=1;
                    if(input->get_timer_event())
                        draw();
                }
            }
            status=0;
            timer.stop();
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
            show_native_message(*screen,game.error_text.title,game.error_text.header_file,LOGO_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            exit_program=1;
        }
};

Loader* loader=nullptr;

void init_loader()
{
    loader=new Loader();
    if(!(loader->load_status()))
        loader->error();
}

void destroy_loader(){if(loader)delete(loader);}

#endif // LOADING_H_INCLUDED
