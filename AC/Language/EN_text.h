#ifndef INCLUDED_EN_AC_GAME_TEXT_H
#define INCLUDED_EN_AC_GAME_TEXT_H

void load_EN_AC_text()
{
    //Main Menu
    game.autochase_text.main_menu.play_game="Play a Game";
    game.autochase_text.main_menu.configuration="Configuration";
    game.autochase_text.main_menu.exit="Back";
    game.autochase_text.main_menu.controls="\u21C5 : Browse-"\
                                            " ESC : Back -"\
                                            " ENTER : Select";
    //Configuration Menu
    game.autochase_text.configuration_menu.title="Configuration";
    game.autochase_text.configuration_menu.car_type="Auto";
    game.autochase_text.configuration_menu.car_color="Color";
    game.autochase_text.configuration_menu.difficulty="Difficulty";
    game.autochase_text.configuration_menu.controls="\u21C4 : Change -"\
                                                    "\u21C5 : Browse -"\
                                                    " ESC : Back";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_EASY]="Easy";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_NORMAL]="Normal";
    game.autochase_text.configuration_menu.difficulties[DIFFICULTY_HARD]="Hard";
    game.autochase_text.configuration_menu.types[CAR_TYPE_AUTO]="Auto";
    game.autochase_text.configuration_menu.types[CAR_TYPE_AC_CAR]="'Auto Chase' Car";
    game.autochase_text.configuration_menu.types[CAR_TYPE_FORMULA]="Formula One";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_BLACK]="Black";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_BLUE]="Blue";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_GREEN]="Green";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_RED]="Red";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_WHITE]="White";
    game.autochase_text.configuration_menu.colors[CAR_COLOR_YELLOW]="Yellow";
    game.autochase_text.configuration_menu.controls_options[AC_ARROWS_CONTROLS_OPTION]="Arrows Keys";
    game.autochase_text.configuration_menu.controls_options[AC_WASD_CONTROLS_OPTION]="WASD Keys";
    //Are You Ready
    game.autochase_text.are_you_ready.ready="Ready?";
    game.autochase_text.are_you_ready.go="Go!";
    //Game
    game.autochase_text.error_text.controls_option="There was an internal error when setting the controls";
    game.autochase_text.error_text.create_player="There was an internal error creating the player, verify the"\
                                                " existence of images in the following directory: "\
                                                CARS_SPRITE_PATH;
    game.autochase_text.game.score_label="Score";
    game.autochase_text.game.record_label="Record";
    //Pause
    game.autochase_text.pause.pause_label="Pause";
    game.autochase_text.pause.continue_option="Enter - Continue Game";
    game.autochase_text.pause.new_game_option="R - New Game";
    game.autochase_text.pause.exit_game_option="Esc - Exit Game";
}

#endif // INCLUDED_EN_AC_GAME_TEXT_H
