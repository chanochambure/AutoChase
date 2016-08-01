#ifndef INCLUDED_AC_CONSTANTS_H
#define INCLUDED_AC_CONSTANTS_H

//FILES VALUES
#define DATA_AC_TOTAL_DATA              2
#define DATA_AC_TOTAL_CONFIGURATION     4

//INPUT CONSTANTS
//KEYCONTROLS
#define GAME_TOTAL_CONTROLS     7
#define GAME_UP                 "U"
#define GAME_DOWN               "D"
#define GAME_LEFT               "L"
#define GAME_RIGHT              "R"
#define GAME_PAUSE              "P"
#define GAME_RESTART            "N"
#define GAME_EXIT               "E"

//CONTROLS OPTIONS
#define TOTAL_CONTROLS_OPTIONS      2
#define AC_ARROWS_CONTROLS_OPTION   0
#define AC_WASD_CONTROLS_OPTION     1

//DIFFICULTY
#define TOTAL_DIFFICULTIES      3
#define DIFFICULTY_EASY         0
#define DIFFICULTY_NORMAL       1
#define DIFFICULTY_HARD         2
//CAR TYPES
#define CAR_TYPE_TOTAL_OPTIONS  3
#define CAR_TYPE_AUTO           0
#define CAR_TYPE_AC_CAR         1
#define CAR_TYPE_FORMULA        2
//CAR COLORS
#define CAR_COLOR_TOTAL_OPTIONS 6
#define CAR_COLOR_BLACK         0
#define CAR_COLOR_BLUE          1
#define CAR_COLOR_GREEN         2
#define CAR_COLOR_RED           3
#define CAR_COLOR_YELLOW        4
#define CAR_COLOR_WHITE         5

//ARE YOU READY TIMMING
#define AC_READY_TIME           1.5
#define AC_GO_TIME              2.0

//PAUSE OPTIONS
#define AC_PAUSE_TOTAL_OPTIONS  3
#define PAUSE_CONTINUE_OPTION   0
#define PAUSE_NEW_GAME_OPTION   1
#define PAUSE_EXIT_GAME_OPTION  2

//MENU
//MAIN MENU
#define AC_MAIN_MENU_TOTAL_OPTIONS  3
#define AC_MAIN_MENU_PLAY_GAME      0
#define AC_MAIN_MENU_CONFIGURATION  1
#define AC_MAIN_MENU_EXIT_GAME      2

#define AC_MAIN_MENU_OPTIONS_POS_X  740
#define AC_MAIN_MENU_OPTIONS_POS_Y  150

//CONFIGURATION MENU
#define AC_CONFIGURATION_MENU_TOTAL_OPTIONS     4
#define AC_CONFIGURATION_MENU_CAR_TYPE          0
#define AC_CONFIGURATION_MENU_CAR_COLOR         1
#define AC_CONFIGURATION_MENU_CONTROLS_OPTION   2
#define AC_CONFIGURATION_MENU_DIFFICULTY        3

#define AC_CONFIGURATION_MENU_OPTIONS_POS_X     740
#define AC_CONFIGURATION_MENU_OPTIONS_POS_Y     180

#define AC_CONFIGURATION_MENU_DIFFICULTY_POS_X  650
#define AC_CONFIGURATION_MENU_DIFFICULTY_POS_Y  365

#define AC_CONFIGURATION_MENU_CAR_POS_X         250
#define AC_CONFIGURATION_MENU_CAR_POS_Y         400

#define AC_CONFIGURATION_MENU_DEMO_CAR_POS_X    20
#define AC_CONFIGURATION_MENU_DEMO_CAR_POS_Y    200

//PLAYER
#define TOTAL_PLAYER_SPRITES                        4
#define DOWN_PLAYER_SPRITE                          0
#define UP_PLAYER_SPRITE                            1
#define RIGHT_PLAYER_SPRITE                         2
#define LEFT_PLAYER_SPRITE                          3

#define PLAYER_MAX_SPEED                            10

#define PLAYER_INI_POS_X                            30
#define PLAYER_INI_POS_Y                            30

#define PLAYER_LIMIT_POS_X_1                        10
#define PLAYER_LIMIT_POS_X_2                        691
#define PLAYER_LIMIT_POS_Y_1                        10
#define PLAYER_LIMIT_POS_Y_2                        591

//PATHS
#define CARS_SPRITE_PATH                            "Data/Image/Game/Cars/"
#define AUTO_SPRITE_PATH                            "Data/Image/Game/Cars/Auto/"
#define AC_CAR_SPRITE_PATH                          "Data/Image/Game/Cars/AutoChaseCar/"
#define FORMULA_SPRITE_PATH                         "Data/Image/Game/Cars/Formula/"
//FORMATS
#define BMP_FORMAT                                  ".PNG"
//FILES
#define DATA_AC_PATH                                "Data/Save/data.acsf"
//IMAGES
#define BACKGROUND_MAIN_MENU_IMAGE_PATH             "Data/Image/Main Menu/background.png"
#define ARROW_MENU_IMAGE_PATH                       "Data/Image/arrow.png"
#define BACKGROUND_CONFIGRATION_MENU_IMAGE_PATH     "Data/Image/Configuration/background.png"
#define CAR_TYPE_AUTO_IMAGE_PATH                    "Data/Image/Configuration/Cars/Auto.PNG"
#define CAR_TYPE_AC_CAR_IMAGE_PATH                  "Data/Image/Configuration/Cars/AC_Car.PNG"
#define CAR_TYPE_FORMULA_IMAGE_PATH                 "Data/Image/Configuration/Cars/Formula.PNG"
#define AC_HUD_IMAGE_PATH                           "Data/Image/Game/hud.PNG"
#define AC_SCORE_IMAGE_PATH                         "Data/Image/Game/Score.PNG"
//AUDIO
#define AC_THEME_AUDIO_PATH                         "Data/Sound/Theme.WAV"
//VIDEO

#endif // INCLUDED_AC_CONSTANTS_H
