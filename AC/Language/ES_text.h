#ifndef INCLUDED_ES_AC_GAME_TEXT_H
#define INCLUDED_ES_AC_GAME_TEXT_H

void load_ES_AC_text()
{
    //Main Menu
    game.autochase_text.main_menu.play_game="Iniciar una Partida";
    game.autochase_text.main_menu.configuration="Configuraci\u00F3n";
    game.autochase_text.main_menu.exit="Atr\u00E1s";
    game.autochase_text.main_menu.controls="\u21C5 : Navegar -"\
                                            " ESC : Atr\u00E1s -"\
                                            " ENTER : Seleccionar";
    //Configuration Menu
    game.autochase_text.configuration_menu.title="Configuraci\u00F3n";
    game.autochase_text.configuration_menu.car_type="Auto";
    game.autochase_text.configuration_menu.car_color="Color";
    game.autochase_text.configuration_menu.difficulty="Dificultad";
    game.autochase_text.configuration_menu.controls="\u21C4 : Cambiar -"\
                                                    "\u21C5 : Navegar -"\
                                                    " ESC : Atr\u00E1s";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_EASY]="F\u00E1cil";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_NORMAL]="Normal";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_HARD]="Dif\u00EDcil";
    game.autochase_text.configuration_menu.types[CAR_TYPE_AUTO]="Auto";
    game.autochase_text.configuration_menu.types[CAR_TYPE_AC_CAR]="Carro 'Auto Chase'";
    game.autochase_text.configuration_menu.types[CAR_TYPE_FORMULA]="F\u00F3rmula Uno";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_BLACK]="Negro";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_BLUE]="Azul";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_GREEN]="Verde";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_RED]="Rojo";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_WHITE]="Blanco";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_YELLOW]="Amarillo";
    game.autochase_text.configuration_menu.controls_options[AC_ARROWS_CONTROLS_OPTION]="Teclas de Flechas";
    game.autochase_text.configuration_menu.controls_options[AC_WASD_CONTROLS_OPTION]="Teclas WASD";
    //Are You Ready
    game.autochase_text.are_you_ready.ready="\u00BFListos?";
    game.autochase_text.are_you_ready.go="\u00A1Fuera!";
    //Game
    game.autochase_text.error_text.controls_option="Hubo un error interno al configurar los controles";
    game.autochase_text.error_text.create_player="Hubo un error interno al crear al jugador, verificar la existencia"\
                                                " de im\u00E1genes en el siguiente directorio: "\
                                                CARS_SPRITE_PATH;
    game.autochase_text.error_text.create_enemies="Hubo un error interno al crear a los enemigos, verficiar la"\
                                                " existencia de im\u00E1genes en el siguiente directorio: "\
                                                ENEMIES_PATH;
    game.autochase_text.game.score_label="Puntaje";
    game.autochase_text.game.record_label="R\u00E9cord";
    //Pause
    game.autochase_text.pause.pause_label="Pausa";
    game.autochase_text.pause.continue_option="Enter - Continuar Partida";
    game.autochase_text.pause.new_game_option="R - Nueva Partida";
    game.autochase_text.pause.exit_game_option="Esc - Salir de la Partida";
    //End Game
    game.autochase_text.end_game.end_game_label="Fin del Juego";
    game.autochase_text.end_game.new_game_option="Enter - Nueva Partida";
    game.autochase_text.end_game.exit_game_option="Esc - Salir de la Partida";
}

#endif // INCLUDED_ES_AC_GAME_TEXT_H
