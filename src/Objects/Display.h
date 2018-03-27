#ifndef INCLUDED_GAME_DISPLAY_H
#define INCLUDED_GAME_DISPLAY_H

//Screen Options
unsigned int global_screen_option_size_x;
unsigned int global_screen_option_size_y;
int global_screen_mode_option=SCREEN_FULLSCREEN_OPTION;

void configure_display_options(LL_AL5::Type_display_size new_screen_size_x,
                               LL_AL5::Type_display_size new_screen_size_y,
                               int mode)
{
    if((new_screen_size_x==LL_AL5::desktop_size_x and new_screen_size_y==LL_AL5::desktop_size_y) or
       (new_screen_size_x==SCREEN_X_800 and new_screen_size_y==SCREEN_Y_600) or
       (new_screen_size_x==SCREEN_X_640 and new_screen_size_y==SCREEN_Y_480))
    {
        if(new_screen_size_x<=LL_AL5::desktop_size_x and new_screen_size_y<=LL_AL5::desktop_size_y)
        {
            global_screen_option_size_x=new_screen_size_x;
            global_screen_option_size_y=new_screen_size_y;
        }
        else
            errors.loading_interface_options.invalid_display_size=true;
    }
    else
        errors.loading_interface_options.invalid_display_size=true;
    if(mode==SCREEN_FULLSCREEN_OPTION)
    {
        if(new_screen_size_x==LL_AL5::desktop_size_x and new_screen_size_y==LL_AL5::desktop_size_y)
            global_screen_mode_option=mode;
        else
        {
            errors.loading_interface_options.incorrect_display_mode_display=true;
            global_screen_mode_option=SCREEN_WINDOWED_OPTION;
        }
    }
    else if(mode==SCREEN_WINDOWED_OPTION)
        global_screen_mode_option=mode;
    else
        errors.loading_interface_options.invalid_display_mode=true;

}

//Display Object
LL_AL5::Display* screen=nullptr;

void init_display()
{
    screen=new LL_AL5::Display(global_screen_option_size_x,global_screen_option_size_y,
                               REAL_SIZE_X_TITLE,REAL_SIZE_Y_TITLE);
    screen->set_display_mode(global_screen_mode_option);
    screen->set_title(game.title);
    screen->create();
    screen->hide_cursor();
}

void destroy_display()
{
    if(screen)
    {
        screen->destroy();
        delete(screen);
    }
    screen=nullptr;
}

#endif // INCLUDED_GAME_DISPLAY_H
