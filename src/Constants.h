#ifndef CONSTANTS_INCLUDE_H_INCLUDED
#define CONSTANTS_INCLUDE_H_INCLUDED

//META
    #define GAME_NAME "<GAME NAME>"

//DICTIONARIES FOR ENCRYPTER
    #define DICTIONARY_GAME_FILES "1234567890$abcdefghijklmnopqrstuvwxyz"

//KEYS FOR ENCRYPTER
    #define _ENCRYPTER_DOC_KEY "gatito"
    #define _ENCRYPTER_ERIK_KEY "bloder"
    #define _ENCRYPTER_CHANO_KEY "587412369"
    #define _ENCRYPTER_CHECHO_KEY "sheylacorazon"
    #define _ENCRYPTER_CHUJU_KEY "sipiripipi"

//ENCRYPTER - DATA BY LINE
    #define _DISPLAY_OPTIONS_TOTAL_DATA 3
    #define _AUDIO_LANGUAGE_OPTIONS_TOTAL_DATA 2

//LANGUAGES
    #define _LANGUAGE_EN 0
    #define _LANGUAGE_ES 1
    #define _LANGUAGE_PR 2

//LOADING TIME
    #define _LOADER_TIME 0.9

//DISPLAY SIZE
    #define _DISPLAY_X_800      800
    #define _DISPLAY_Y_600      600
    #define _DISPLAY_X_640      640
    #define _DISPLAY_Y_480      480
    #define _REALSIZEX_TITLE    1250.0
    #define _REALSIZEY_TITLE    700.0
    #define REAL_SIZE_X_GAME    800.0
    #define REAL_SIZE_Y_GAME    600.0
//DISPLAY TYPE
    int _GAME_FULLSCREEN=ALLEGRO_FULLSCREEN_WINDOW;
    int _GAME_WINDOWED=ALLEGRO_WINDOWED;

//INPUT CONSTANTS
    //TIME
        #define _FPS 1.0/60
    //KEYCONTROLS
        #define MENU_LEFT     "L"
        #define MENU_RIGHT    "R"
        #define MENU_UP       "U"
        #define MENU_DOWN     "D"
        #define MENU_CANCEL   "E"
        #define MENU_SELECT   "S"

//MENU
    //MAIN MENU
        #define _MAIN_MENU_TOTAL_OPTIONS                                3
        #define _MAIN_MENU_INIT_GAME                                    0
        #define _MAIN_MENU_OPTIONS_GAME                                 1
        #define _MAIN_MENU_EXIT_GAME                                    2
    //INTERFACE OPTIONS MENU
        #define _INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS                   4
        #define _INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS           3
        #define _INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS           2
        #define _INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS               3
        #define _INTERFACE_OPTIONS_MENU_DISPLAY_SIZE                    0
        #define _INTERFACE_OPTIONS_MENU_DISPLAY_TYPE                    1
        #define _INTERFACE_OPTIONS_MENU_AUDIO_VOLUME                    2
        #define _INTERFACE_OPTIONS_MENU_LANGUAGE                        3

//PATHS
    //FILES
        #define INTERFACE_OPTIONS_PATH "Configuration/interface_options.acof"
    //FONTS
        #define COMIC_FONT_PATH "Fonts/comic.ttf"
    //IMAGES
        #define LOGO_IMAGE_PATH "Data/Image/Logo.png"
    //VIDEO
        #define LL_LOGO_VIDEO_PATH  "Data/Video/LL_Logo.ogv"
        #define OPENING_VIDEO_PATH  "Data/Video/Opening.ogv"
        #define DEMO_VIDEO_PATH     "Data/Video/Demo.ogv"

//FONTS SIZE
    #define FONT_SIZE_SMALL                         16
    #define FONT_SIZE_NORMAL                        24
    #define FONT_SIZE_LONG                          32

#endif // CONSTANTS_INCLUDE_H_INCLUDED
