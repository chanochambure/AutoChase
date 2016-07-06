#ifndef INCLUDED_GAME_INPUT_H
#define INCLUDED_GAME_INPUT_H

//Key Controls
LL_AL5::KeyControl* menu_key_control;

void init_key_control()
{
    menu_key_control=new LL_AL5::KeyControl;
    menu_key_control->add_key(MENU_LEFT,ALLEGRO_KEY_LEFT);
    menu_key_control->add_key(MENU_RIGHT,ALLEGRO_KEY_RIGHT);
    menu_key_control->add_key(MENU_UP,ALLEGRO_KEY_UP);
    menu_key_control->add_key(MENU_DOWN,ALLEGRO_KEY_DOWN);
    menu_key_control->add_key(MENU_CANCEL,ALLEGRO_KEY_ESCAPE);
    menu_key_control->add_key(MENU_SELECT,ALLEGRO_KEY_ENTER);
}

void destroy_key_control()
{
    if(menu_key_control)
        delete(menu_key_control);
    menu_key_control=nullptr;
}

//Input Object
LL_AL5::Input* input=nullptr;

void init_input()
{
    input=new LL_AL5::Input;
    input->keyboard_on();
    input->set_key_control(menu_key_control);
}

void destroy_input()
{
    if(input)
        delete(input);
    input=nullptr;
}

#endif // INCLUDED_GAME_INPUT_H
