#ifndef INCLUDED_EN_GAME_TEXT_H
#define INCLUDED_EN_GAME_TEXT_H

//#include "<GAME>/EN_text.h"

void load_EN_game_text()
{
    //ERRORS
    game.error_text.title="Error";
    game.error_text.header_file="File Not Found";
    game.error_text.header_internal="Internal Error";
    game.error_text.message_interface_options_internal_error="A variable has been"\
                                                             " corrupted in runtime.";
    //COMMON
    game.load="Loading...";
    #ifdef GAME_DEMO
    //DEMO
    game.demo_text.middle_text="Press ENTER to return to the game";
    #endif // GAME_DEMO
    //TITLE MENU
    game.title_menu.start_game="Press ENTER to start game";
    //MAIN MENU
    game.main_menu.init_game="Start Game";
    game.main_menu.options_game="Interface Options";
    game.main_menu.exit_game="Exit Game";
    game.main_menu.controls="\u21C5 : Browse -"\
                            " ESC : Exit -"\
                            " ENTER : Select";
        //INTERFACE OPTIONS MENU
        game.interface_options_menu.title="Interface Options";
        game.interface_options_menu.select_display_size="Screen Size";
            game.interface_options_menu.display_size_1="Full Size";
        game.interface_options_menu.select_display_type="Screen Type";
            game.interface_options_menu.display_type_1="Full Screen";
            game.interface_options_menu.display_type_2="Window";
        game.interface_options_menu.set_audio_volume="Volume";
        game.interface_options_menu.select_language="Language";
            game.interface_options_menu.language_EN="English";
            game.interface_options_menu.language_ES="Spanish";
            game.interface_options_menu.language_PR="Portuguese";
        game.interface_options_menu.controls="\u21C5 : Browse -"\
                                             " \u21C4 : Select -"\
                                             " ESC : Cancel -"\
                                             " ENTER : Apply and Save Changes";
//    load_EN_<GAME>_text();
}

#endif // INCLUDED_EN_GAME_TEXT_H
