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

//END GAME OPTIONS
#define AC_END_GAME_TOTAL_OPTIONS   2
#define END_NEW_GAME_OPTION         0
#define END_EXIT_GAME_OPTION        1

//MENU
//MAIN MENU
#define AC_MAIN_MENU_TOTAL_OPTIONS  4
#define AC_MAIN_MENU_PLAY_GAME      0
#define AC_MAIN_MENU_CONFIGURATION  1
#define AC_MAIN_MENU_CREDITS        2
#define AC_MAIN_MENU_EXIT_GAME      3

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

//CREDITS
#define TOTAL_CREDITS_LINES                     23
#define CREDIT_LINE_CREATED_BY                  7
#define CREDIT_LINE_MUSIC_BY                    10
#define CREDIT_LINE_DEVELOPER                   13
#define CREDIT_LINE_TESTER                      16
#define CREDIT_LINE_TESTER_WIN                  17
#define CREDIT_LINE_TESTER_MAC                  19
#define CREDIT_LINE_TESTER_LINUX                21

#define GAME_CREATOR                            "Christian Renato Benavides Castillo"
#define MUSIC_CREATOR                           "Christian Renato Benavides Castillo"
#define GAME_DEVELOPER                          "Christian Renato Benavides Castillo"
#define GAME_TESTER_WIN                         "Christian Renato Benavides Castillo"
#define GAME_TESTER_MAC                         "Jord\u00E1n Raji Lazo Cahua"
#define GAME_TESTER_LINUX                       "Sergio Alexis Cardenas Solis"

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

#define PLAYER_TOLERANCE                            4.0/5.0

//ENEMY
#define TOTAL_ENEMIES                               4

#define ENEMY_INI_POS_X                            680

#define ENEMY_EASY_MAX_SPEED                        5
#define ENEMY_NORMAL_MAX_SPEED                      6
#define ENEMY_HARD_MAX_SPEED                        7

//PATHS
#define CARS_SPRITE_PATH                            "Data/Image/Game/Cars/"
#define AUTO_SPRITE_PATH                            "Data/Image/Game/Cars/Auto/"
#define AC_CAR_SPRITE_PATH                          "Data/Image/Game/Cars/AutoChaseCar/"
#define FORMULA_SPRITE_PATH                         "Data/Image/Game/Cars/Formula/"
#define ENEMIES_PATH                                "Data/Image/Game/Enemies/"
//FORMATS
#define BMP_FORMAT                                  ".PNG"
//FILES
#define DATA_AC_PATH                                "Data/Save/data.acsf"
//IMAGES
#define BACKGROUND_MAIN_MENU_IMAGE_PATH             "Data/Image/Main Menu/background.png"
#define BACKGROUND_CREDITS_IMAGE_PATH               "Data/Image/Credits/background.png"
#define ARROW_MENU_IMAGE_PATH                       "Data/Image/arrow.png"
#define LEXRIS_LOGIC_LOGO_PATH                      "Data/Image/LL_Logo.png"
#define BACKGROUND_CONFIGRATION_MENU_IMAGE_PATH     "Data/Image/Configuration/background.png"
#define CAR_TYPE_AUTO_IMAGE_PATH                    "Data/Image/Configuration/Cars/Auto.PNG"
#define CAR_TYPE_AC_CAR_IMAGE_PATH                  "Data/Image/Configuration/Cars/AC_Car.PNG"
#define CAR_TYPE_FORMULA_IMAGE_PATH                 "Data/Image/Configuration/Cars/Formula.PNG"
#define AC_HUD_IMAGE_PATH                           "Data/Image/Game/hud.PNG"
#define AC_SCORE_IMAGE_PATH                         "Data/Image/Game/Score.PNG"
#define ENEMY_EASY_1_PATH_IMAGE                     "Data/Image/Game/Enemies/E1.PNG"
#define ENEMY_EASY_2_PATH_IMAGE                     "Data/Image/Game/Enemies/E2.PNG"
#define ENEMY_NORMAL_1_PATH_IMAGE                   "Data/Image/Game/Enemies/N1.PNG"
#define ENEMY_NORMAL_2_PATH_IMAGE                   "Data/Image/Game/Enemies/N2.PNG"
#define ENEMY_HARD_1_PATH_IMAGE                     "Data/Image/Game/Enemies/H1.PNG"
#define ENEMY_HARD_2_PATH_IMAGE                     "Data/Image/Game/Enemies/H2.PNG"
//AUDIO
#define AC_THEME_AUDIO_PATH                         "Data/Sound/Theme.WAV"
#define AC_GAME_AUDIO_PATH                          "Data/Sound/Game.WAV"

#endif // INCLUDED_AC_CONSTANTS_H
