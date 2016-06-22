#ifndef GAME_MAIN_MENU_H_INCLUDED
#define GAME_MAIN_MENU_H_INCLUDED

#include "InterfaceOptionsMenu.h"

int main_menu_option=_MAIN_MENU_INIT_GAME;

class MainMenu
{
    private:
        LL_AL5::Image logo;
        LL_AL5::Text options[_MAIN_MENU_TOTAL_OPTIONS];
        LL_AL5::Text footnote;
        LL_AL5::Text controls;
    public:
        MainMenu()
        {
            logo.set_path(LOGO_IMAGE_PATH);
            if(!(errors.loading_images.logo_image=!logo.load()))
                logo.set_pos((_REALSIZEX/2)-(logo.get_size_x()/2),100);
            for(unsigned int i=0;i<_MAIN_MENU_TOTAL_OPTIONS;++i)
            {
                options[i].set_font(comic_16C);
                options[i].set_color(WHITE);
                options[i].set_flag(ALLEGRO_ALIGN_CENTER);
                options[i].set_pos((_REALSIZEX/2),(2*_REALSIZEY/3)+(i*comic_16C->get_size()));
            }
            options[_MAIN_MENU_INIT_GAME]=game.main_menu.init_game;
            options[_MAIN_MENU_OPTIONS_GAME]=game.main_menu.options_game;
            options[_MAIN_MENU_EXIT_GAME]=game.main_menu.exit_game;
            options[main_menu_option].set_color(ORANGE);
            footnote.set_font(comic_16C);
            footnote=(game.organization+" - "+game.release_year);
            footnote.set_color(WHITE);
            footnote.set_flag(ALLEGRO_ALIGN_LEFT);
            footnote.set_pos(10,_REALSIZEY-30);
            controls.set_font(comic_16C);
            controls=game.main_menu.controls;
            controls.set_color(WHITE);
            controls.set_flag(ALLEGRO_ALIGN_RIGHT);
            controls.set_pos(_REALSIZEX-(comic_16C->get_size()*2),_REALSIZEY-(comic_16C->get_size()*2));
        }
        bool load_status()
        {
            return !(errors.loading_images.logo_image);
        }
        void up()
        {
            options[main_menu_option].set_color(WHITE);
            main_menu_option=LL::mod(main_menu_option-1,_MAIN_MENU_TOTAL_OPTIONS);
            options[main_menu_option].set_color(ORANGE);
        }
        void down()
        {
            options[main_menu_option].set_color(WHITE);
            main_menu_option=LL::mod(main_menu_option+1,_MAIN_MENU_TOTAL_OPTIONS);
            options[main_menu_option].set_color(ORANGE);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&logo);
            for(unsigned int i=0;i<_MAIN_MENU_TOTAL_OPTIONS;++i)
                screen->draw(&(options[i]));
            screen->draw(&footnote);
            screen->draw(&controls);
            screen->refresh();
        }
        void error()
        {
            show_native_message(*screen,game.error_text.title,game.error_text.header_file,LOGO_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            exit_program=1;
        }
};

void start_main_menu()
{
    MainMenu main_menu;
    if(!main_menu.load_status())
        main_menu.error();
    else
    {
        input->clear_key_status();
        input->clear_events();
        while(!exit_program)
        {
            input->get_event();
            if(input->get_display_status() or (*input)[MENU_CANCEL])
                exit_program=1;
            if((*input)[MENU_UP])
            {
                main_menu.up();
                (*input)[MENU_UP]=0;
            }
            if((*input)[MENU_DOWN])
            {
                main_menu.down();
                (*input)[MENU_DOWN]=0;
            }
            if((*input)[MENU_SELECT])
                return;
            if(input->get_timer_event())
                main_menu.draw();
        }
        main_menu_option=_MAIN_MENU_EXIT_GAME;
    }
}

#endif // GAME_MAIN_MENU_H_INCLUDED
