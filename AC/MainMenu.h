#ifndef AC_MAIN_MENU_H_INCLUDED
#define AC_MAIN_MENU_H_INCLUDED

int ac_main_menu_option=AC_MAIN_MENU_PLAY_GAME;

class ACMainMenu
{
    private:
    public:
        ACMainMenu()
        {
        }
        bool load_status()
        {
        }
        void move_selection_up_down(int num_of_moves)
        {
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
        }
        void error()
        {
        }
};

void start_ac_main_menu()
{
    ACMainMenu ac_main_menu;
}

#endif // AC_MAIN_MENU_H_INCLUDED
