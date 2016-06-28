#ifndef INCLUDED_PR_GAME_TEXT_H
#define INCLUDED_PR_GAME_TEXT_H

#include "../../AC/Language/PR_text.h"

void load_PR_game_text()
{
    //ERRORS
    game.error_text.title="Erro";
    game.error_text.header_file="File Not Found";
    game.error_text.header_internal="Erro Interno";
    game.error_text.message_interface_options_internal_error="Uma vari\u00E1vel foi corrompido"\
                                                             " em tempo de execu\u00E7\u00E3o.";
    //COMMON
    game.load="Carregando...";
    #ifdef GAME_DEMO
    //DEMO
    game.demo_text.middle_text="Pressione a tecla ENTER para voltar ao jogo";
    #endif // GAME_DEMO
    //TITLE MENU
    game.title_menu.start_game="Pressione a tecla ENTER para iniciar o jogo";
    //MAIN MENU
    game.main_menu.init_game="Iniciar o Jogo";
    game.main_menu.options_game="Op\u00E7\u00F5es de interface";
    game.main_menu.exit_game="Jogo Exit";
    game.main_menu.controls="\u21C5 : Navegar -"\
                            " ESC : Sair -"\
                            " ENTER : Selecionar";
        //INTERFACE OPTIONS MENU
        game.interface_options_menu.title="Op\u00E7\u00F5es de interface";
        game.interface_options_menu.select_display_size="Tamanho da Tela";
            game.interface_options_menu.display_size_1="Tamanho M\u00E1ximo";
        game.interface_options_menu.select_display_type="Tipo da Tela";
            game.interface_options_menu.display_type_1="Full Screen";
            game.interface_options_menu.display_type_2="Janela";
        game.interface_options_menu.set_audio_volume="Volume";
        game.interface_options_menu.select_language="L\u00EDngua";
            game.interface_options_menu.language_EN="Ingl\u00EAs";
            game.interface_options_menu.language_ES="Espanhol";
            game.interface_options_menu.language_PR="Portugu\u00EAs";
        game.interface_options_menu.controls="\u21C5 : Navegar -"\
                                             " \u21C4 : Selecionar -"\
                                             " ESC : Cancelar -"\
                                             " ENTER : Aplicar e em Salvar altera\u00E7\u00F5es";
    load_PR_AC_text();
}

#endif // INCLUDED_PR_GAME_TEXT_H
