#ifndef INCLUDED_AC_CONSTANTS_H
#define INCLUDED_AC_CONSTANTS_H

//DICTONARIES FOR ENCRYPTERS

//FILES VALUES
#define DATA_AC_TOTAL_DATA              2
#define DATA_AC_TOTAL_CONFIGURATION     3

//INPUT CONSTANTS
//KEYCONTROLS
#define GAME_TOTAL_CONTROLS     5
#define GAME_UP                 "U"
#define GAME_DOWN               "D"
#define GAME_LEFT               "L"
#define GAME_RIGHT              "R"
#define GAME_PAUSE              "P"

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

//MENU
//MAIN MENU
#define AC_MAIN_MENU_TOTAL_OPTIONS  3
#define AC_MAIN_MENU_PLAY_GAME      0
#define AC_MAIN_MENU_CONFIGURATION  1
#define AC_MAIN_MENU_EXIT_GAME      2

#define AC_MAIN_MENU_OPTIONS_POS_X  740
#define AC_MAIN_MENU_OPTIONS_POS_Y  150

//CONFIGURATION MENU
#define AC_CONFIGURATION_MENU_TOTAL_OPTIONS     3
#define AC_CONFIGURATION_MENU_CAR_TYPE          0
#define AC_CONFIGURATION_MENU_CAR_COLOR         1
#define AC_CONFIGURATION_MENU_DIFFICULTY        2

#define AC_CONFIGURATION_MENU_OPTIONS_POS_X     740
#define AC_CONFIGURATION_MENU_OPTIONS_POS_Y     180

#define AC_CONFIGURATION_MENU_DIFFICULTY_POS_X  650
#define AC_CONFIGURATION_MENU_DIFFICULTY_POS_Y  360

#define AC_CONFIGURATION_MENU_CAR_POS_X         250
#define AC_CONFIGURATION_MENU_CAR_POS_Y         400

#define AC_CONFIGURATION_MENU_DEMO_CAR_POS_X    20
#define AC_CONFIGURATION_MENU_DEMO_CAR_POS_Y    200

//PATHS
//DIRECTORIES
//FILES
#define DATA_AC_PATH                        "Data/Save/data.acsf"
//FONTS
//IMAGES
#define BACKGROUND_MAIN_MENU_IMAGE_PATH             "Data/Image/Main Menu/background.png"
#define ARROW_MENU_IMAGE_PATH                       "Data/Image/arrow.png"
#define BACKGROUND_CONFIGRATION_MENU_IMAGE_PATH     "Data/Image/Configuration/background.png"
#define CAR_TYPE_AUTO_IMAGE_PATH                    "Data/Image/Configuration/Cars/Auto.PNG"
#define CAR_TYPE_AC_CAR_IMAGE_PATH                  "Data/Image/Configuration/Cars/AC_Car.PNG"
#define CAR_TYPE_FORMULA_IMAGE_PATH                 "Data/Image/Configuration/Cars/Formula.PNG"
//VIDEO

#endif // INCLUDED_AC_CONSTANTS_H
