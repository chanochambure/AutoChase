#ifndef INCLUDED_ES_GAME_TEXT_H
#define INCLUDED_ES_GAME_TEXT_H

#include "../../AC/Language/ES_text.h"

void load_ES_game_text()
{
    //ERRORS
    game.error_text.title="Error";
    game.error_text.header_file="No se encontro el Archivo: ";
    game.error_text.header_internal="Error Interno";
    game.error_text.message_interface_options_internal_error="Una variable se ha corrompido"\
                                                             " en tiempo de Ejecuci\u00F3n.";
    //COMMON
    game.load="Cargando...";
    #ifdef GAME_DEMO
    //DEMO
    game.demo_text.middle_text="Pulse ENTER para volver al juego";
    #endif // GAME_DEMO
    //TITLE MENU
    game.title_menu.start_game="Pulse ENTER para iniciar el juego";
    //MAIN MENU
    game.main_menu.init_game="Iniciar el Juego";
    game.main_menu.options_game="Opciones de Interfaz";
    game.main_menu.exit_game="Salir del Juego";
    game.main_menu.controls="\u21C5 : Navegar -"\
                            " ESC : Salir -"\
                            " ENTER : Seleccionar";
        //INTERFACE OPTIONS MENU
        game.interface_options_menu.title="Opciones de Interfaz";
        game.interface_options_menu.select_display_size="Tama\u00F1o de Pantalla";
            game.interface_options_menu.display_size_1="Tama\u00F1o M\u00E1ximo";
        game.interface_options_menu.select_display_type="Tipo de Pantalla";
            game.interface_options_menu.display_type_1="Pantalla Completa";
            game.interface_options_menu.display_type_2="Ventana";
        game.interface_options_menu.set_audio_volume="Volumen";
        game.interface_options_menu.select_language="Idioma";
            game.interface_options_menu.language_EN="Ingl\u00E9s";
            game.interface_options_menu.language_ES="Espa\u00F1ol";
            game.interface_options_menu.language_PR="Portugu\u00E9s";
        game.interface_options_menu.controls="\u21C5 : Navegar -"\
                                             " \u21C4 : Seleccionar -"\
                                             " ESC : Cancelar -"\
                                             " ENTER : Aplicar y Salvar Cambios";
    load_ES_AC_text();
}

#endif // INCLUDED_ES_GAME_TEXT_H
