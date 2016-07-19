#ifndef GAME_MAIN_MENU_H_INCLUDED
#define GAME_MAIN_MENU_H_INCLUDED

#include "InterfaceOptionsMenu.h"

int main_menu_option=MAIN_MENU_INIT_GAME;

class MainMenu
{
    private:
        LL_AL5::Image _V_logo;
        LL_AL5::Text _V_options[MAIN_MENU_TOTAL_OPTIONS];
        LL_AL5::Text _V_footnote;
        LL_AL5::Text _V_controls;
    public:
        MainMenu()
        {
            _V_logo.set_path(LOGO_IMAGE_PATH);
            if(!(errors.loading_images.logo_image=!_V_logo.load()))
                _V_logo.set_pos((REAL_SIZE_X_TITLE/2)-(_V_logo.get_size_x()/2),100);
            for(unsigned int i=0;i<MAIN_MENU_TOTAL_OPTIONS;++i)
            {
                _V_options[i].set_font(comic_small);
                _V_options[i].set_color(WHITE);
                _V_options[i].set_flag(ALLEGRO_ALIGN_CENTER);
                _V_options[i].set_pos((REAL_SIZE_X_TITLE/2),(2*REAL_SIZE_Y_TITLE/3)+(i*comic_small->get_size()));
            }
            _V_options[MAIN_MENU_INIT_GAME]=game.main_menu.init_game;
            _V_options[MAIN_MENU_OPTIONS_GAME]=game.main_menu.options_game;
            _V_options[MAIN_MENU_EXIT_GAME]=game.main_menu.exit_game;
            _V_options[main_menu_option].set_color(ORANGE);
            _V_footnote.set_font(comic_small);
            _V_footnote=(game.organization+" - "+game.release_year);
            _V_footnote.set_color(WHITE);
            _V_footnote.set_flag(ALLEGRO_ALIGN_LEFT);
            _V_footnote.set_pos(10,REAL_SIZE_Y_TITLE-30);
            _V_controls.set_font(comic_small);
            _V_controls=game.main_menu.controls;
            _V_controls.set_color(WHITE);
            _V_controls.set_flag(ALLEGRO_ALIGN_RIGHT);
            _V_controls.set_pos(REAL_SIZE_X_TITLE-(comic_small->get_size()*2),
                             REAL_SIZE_Y_TITLE-(comic_small->get_size()*2));
        }
        bool load_status()
        {
            return !(errors.loading_images.logo_image);
        }
        void move_selection_up_down(int num_of_moves)
        {
            _V_options[main_menu_option].set_color(WHITE);
            main_menu_option=LL::mod(main_menu_option+num_of_moves,MAIN_MENU_TOTAL_OPTIONS);
            _V_options[main_menu_option].set_color(ORANGE);
        }
        void up()
        {
            move_selection_up_down(-1);
        }
        void down()
        {
            move_selection_up_down(1);
        }
        void draw()
        {
            screen->clear_to_color(BLACK);
            screen->draw(&_V_logo);
            for(unsigned int i=0;i<MAIN_MENU_TOTAL_OPTIONS;++i)
                screen->draw(&(_V_options[i]));
            screen->draw(&_V_footnote);
            screen->draw(&_V_controls);
            screen->refresh();
        }
        void error()
        {
            show_native_message(*screen,game.error_text.title,game.error_text.header_file,
                                LOGO_IMAGE_PATH,ALLEGRO_MESSAGEBOX_ERROR);
            game_running=false;
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
        while(game_running)
        {
            input->get_event();
            if(input->get_display_status() or (*input)[MENU_CANCEL])
                game_running=false;
            if((*input)[MENU_UP])
            {
                main_menu.up();
                (*input)[MENU_UP]=false;
            }
            if((*input)[MENU_DOWN])
            {
                main_menu.down();
                (*input)[MENU_DOWN]=false;
            }
            if((*input)[MENU_SELECT])
                return;
            if(input->get_timer_event())
                main_menu.draw();
        }
        main_menu_option=MAIN_MENU_EXIT_GAME;
    }
}

#endif // GAME_MAIN_MENU_H_INCLUDED
