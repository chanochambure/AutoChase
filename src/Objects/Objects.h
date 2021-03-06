#ifndef INCLUDED_GAME_OBJECTS_H
#define INCLUDED_GAME_OBJECTS_H

//OBJECTS
#include "Colors.h"
#include "Encryptor.h"
#include "Mixer.h"
#include "Display.h"
#include "Timer.h"
#include "Input.h"
#include "Font.h"

void destroy_objects()
{
    destroy_fonts();
    destroy_input();
    destroy_timer();
    destroy_display();
    destroy_textlog();
}

void init_objects()
{
    init_input();
    init_textlog();
    #ifndef DEBUG_OPTION
        destroy_textlog();
    #endif // DEBUG_OPTION
    init_timer();
    init_display();
    input->register_timer(*timer);
    input->register_display(*screen);
    input->keyboard_on();
    init_fonts();
    mixer->set_volume(global_volume_option);
}

#endif // INCLUDED_GAME_OBJECTS_H
