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
}

#endif // INCLUDED_EN_AC_GAME_TEXT_H
