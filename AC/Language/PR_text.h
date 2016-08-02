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
    game.autochase_text.configuration_menu.controls_options[AC_ARROWS_CONTROLS_OPTION]="Teclas de Setas";
    game.autochase_text.configuration_menu.controls_options[AC_WASD_CONTROLS_OPTION]="Teclas WASD";
    //Are You Ready
    game.autochase_text.are_you_ready.ready="Pronto?";
    game.autochase_text.are_you_ready.go="V\u00E1!";
    //Game
    game.autochase_text.error_text.controls_option="Houve um erro interno ao configurar os controles";
    game.autochase_text.error_text.create_player="Houve um erro interno criando o jogador, verificar a"\
                                                " exist\u00EAncia de imagens no seguinte diret\u00F3rio: "\
                                                CARS_SPRITE_PATH;
    game.autochase_text.error_text.create_enemies="Houve um erro interno criando inimigos, verificar a"\
                                                " exist\u00EAncia de imagens no seguinte diret\u00F3rio: "\
                                                ENEMIES_PATH;
    game.autochase_text.game.score_label="Ponta\u00E7\u00E3o";
    game.autochase_text.game.record_label="Recorde";
    //Pause
    game.autochase_text.pause.pause_label="Pausa";
    game.autochase_text.pause.continue_option="Enter - Continuar Jogo";
    game.autochase_text.pause.new_game_option="R - Novo Jogo";
    game.autochase_text.pause.exit_game_option="Esc - Deixar o Jogo";
    //End Game
    game.autochase_text.end_game.end_game_label="Fim do Jogo";
    game.autochase_text.end_game.new_game_option="Enter - Novo Jogo";
    game.autochase_text.end_game.exit_game_option="Esc - Deixar o Jogo";
}

#endif // INCLUDED_PR_AC_GAME_TEXT_H
