#ifndef GAME_INPUT_H_INCLUDED
#define GAME_INPUT_H_INCLUDED

//Input Object
LL_AL5::Input* input=nullptr;

//Key Controls
LL_AL5::KeyControl* menu;

void init_input()
{
    //INPUT
        input=new LL_AL5::Input;
        input->keyboard_on();
        input->register_display(*screen);
        input->register_timer(*timer);
    //KEY CONTROL
        menu=new LL_AL5::KeyControl;
        menu->add_key(MENU_LEFT,ALLEGRO_KEY_LEFT);
        menu->add_key(MENU_RIGHT,ALLEGRO_KEY_RIGHT);
        menu->add_key(MENU_UP,ALLEGRO_KEY_UP);
        menu->add_key(MENU_DOWN,ALLEGRO_KEY_DOWN);
        menu->add_key(MENU_CANCEL,ALLEGRO_KEY_ESCAPE);
        menu->add_key(MENU_SELECT,ALLEGRO_KEY_ENTER);
        input->set_key_control(menu);
}

void destroy_input()
{
    if(menu)
        delete(menu);
    if(input)
        delete(input);
    input=nullptr;
    menu=nullptr;
}

#endif // GAME_INPUT_H_INCLUDED
