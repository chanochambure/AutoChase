#ifndef GAME_DISPLAY_H_INCLUDED
#define GAME_DISPLAY_H_INCLUDED

//Screen Options
unsigned int _screen_size_x;
unsigned int _screen_size_y;
int _screen_mode=_GAME_FULLSCREEN;

void configure_display_options(LL_AL5::Type_display_size ss_X,LL_AL5::Type_display_size ss_Y,int mode)
{
    if((ss_X==LL_AL5::desktop_size_x and ss_Y==LL_AL5::desktop_size_y) or (ss_X==_DISPLAY_X_800 and ss_Y==_DISPLAY_Y_600) or (ss_X==_DISPLAY_X_640 and ss_Y==_DISPLAY_Y_480))
    {
        if(ss_X<=LL_AL5::desktop_size_x and ss_Y<=LL_AL5::desktop_size_y)
        {
            _screen_size_x=ss_X;
            _screen_size_y=ss_Y;
        }
        else
            errors.loading_interface_options.invalid_display_size=1;
    }
    else
        errors.loading_interface_options.invalid_display_size=1;
    if(mode==_GAME_FULLSCREEN)
    {
        if(ss_X==LL_AL5::desktop_size_x and ss_Y==LL_AL5::desktop_size_y)
            _screen_mode=mode;
        else
        {
            errors.loading_interface_options.incorrect_display_mode_display=true;
            _screen_mode=_GAME_WINDOWED;
        }
    }
    else if(mode==_GAME_WINDOWED)
        _screen_mode=mode;
    else
        errors.loading_interface_options.invalid_display_mode=1;

}

//Display Object
LL_AL5::Display* screen=nullptr;

void init_display()
{
    screen=new LL_AL5::Display(_screen_size_x,_screen_size_y,_REALSIZEX_TITLE,_REALSIZEY_TITLE);
    screen->set_flag(_screen_mode);
    screen->set_title(game.title);
    screen->hide_cursor();
}

void destroy_display(){if(screen)delete(screen);screen=nullptr;}

#endif // GAME_DISPLAY_H_INCLUDED
