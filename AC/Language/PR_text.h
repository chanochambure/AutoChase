#ifndef INCLUDED_PR_AC_GAME_TEXT_H
#define INCLUDED_PR_AC_GAME_TEXT_H

void load_PR_AC_text()
{
    //Main Menu
    game.autochase_text.main_menu.play_game="Jogar um Jogo";
    game.autochase_text.main_menu.configuration="Configura\u00E7\u00E3o";
    game.autochase_text.main_menu.exit="De Volta";
    game.autochase_text.main_menu.controls="\u21C5 : Navegar -"\
                                            " ESC : De Volta -"\
                                            " ENTER : Selecionar";
    //Configuration Menu
    game.autochase_text.configuration_menu.title="Configura\u00E7\u00E3o";
    game.autochase_text.configuration_menu.car_type="Auto";
    game.autochase_text.configuration_menu.car_color="Cor";
    game.autochase_text.configuration_menu.difficulty="Dificuldade";
    game.autochase_text.configuration_menu.controls="\u21C4 : Mudan\u00E7a -"\
                                                    "\u21C5 : Navegar -"\
                                                    " ESC : De Volta";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_EASY]="F\u00E1cil";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_NORMAL]="Normal";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_HARD]="Dif\u00EDcil";
    game.autochase_text.configuration_menu.types[CAR_TYPE_AUTO]="Auto";
    game.autochase_text.configuration_menu.types[CAR_TYPE_AC_CAR]="Carro 'Auto Chase'";
    game.autochase_text.configuration_menu.types[CAR_TYPE_FORMULA]="F\u00F3rmula Um";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_BLACK]="Preta";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_BLUE]="Azul";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_GREEN]="Verde";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_RED]="Vermelho";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_WHITE]="Branco";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_YELLOW]="Amarela";
}

#endif // INCLUDED_PR_AC_GAME_TEXT_H
