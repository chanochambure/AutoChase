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
}

#endif // INCLUDED_ES_AC_GAME_TEXT_H
