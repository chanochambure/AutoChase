#ifndef INCLUDED_CONSTANTS_H
#define INCLUDED_CONSTANTS_H

//META
#define GAME_NAME           "Auto Chase"
#define GAME_COMPANY        "LexRis Logic"
#define GAME_YEAR           "2016"

//DICTIONARIES FOR ENCRYPTER
#define DICTIONARY_GAME_FILES   "1234567890$abcdefghijklmnopqrstuvwxyz"

//KEYS FOR ENCRYPTER
#define KEY_ENCRYPTER_DOC       "gatito"
#define KEY_ENCRYPTER_ERIK      "bloder"
#define KEY_ENCRYPTER_CHANO     "587412369"
#define KEY_ENCRYPTER_CHECHO    "sheylacorazon"
#define KEY_ENCRYPTER_CHUJU     "sipiripipi"
#define KEY_ENCRYPTER_RAJI      "soyunchucha"

//FILES VALUES
#define INTERFACE_OPTIONS_FILE_TOTAL_LINES      2
#define SCREEN_OPTIONS_TOTAL_DATA               3
#define AUDIO_LANGUAGE_OPTIONS_TOTAL_DATA       2

//LANGUAGES
#define TOTAL_LANGUAGES         3
#define LANGUAGE_EN             0
#define LANGUAGE_ES             1
#define LANGUAGE_PR             2

//AUDIO OPTIONS
#define MAX_VOLUME              20.0
#define NORMAL_VOLUME           10.0

//LOADING OPTIONS
#define LOADER_LOGO_STATUS      0.3
#define LOADER_TEXT_STATUS      0.7
#define LOADER_FINAL_STATUS     0.9

//DISPLAY SIZE
#define SCREEN_X_800        800
#define SCREEN_Y_600        600
#define SCREEN_X_640        640
#define SCREEN_Y_480        480
#define REAL_SIZE_X_TITLE   1250.0
#define REAL_SIZE_Y_TITLE   700.0
#define REAL_SIZE_X_GAME    800.0
#define REAL_SIZE_Y_GAME    600.0
//DISPLAY TYPE
const int SCREEN_FULLSCREEN_OPTION=ALLEGRO_FULLSCREEN_WINDOW;
const int SCREEN_WINDOWED_OPTION=ALLEGRO_WINDOWED;

//INPUT CONSTANTS
//TIME
#define FPS_OPTION 1.0/60
//KEYCONTROLS
#define MENU_LEFT     "L"
#define MENU_RIGHT    "R"
#define MENU_UP       "U"
#define MENU_DOWN     "D"
#define MENU_CANCEL   "E"
#define MENU_SELECT   "S"

//MENU
//MAIN MENU
#define MAIN_MENU_TOTAL_OPTIONS                                 3
#define MAIN_MENU_INIT_GAME                                     0
#define MAIN_MENU_OPTIONS_GAME                                  1
#define MAIN_MENU_EXIT_GAME                                     2
//INTERFACE OPTIONS MENU
#define INTERFACE_OPTIONS_MENU_TOTAL_OPTIONS                    4
#define INTERFACE_OPTIONS_DISPLAY_SIZE_TOTAL_OPTIONS            3
#define INTERFACE_OPTIONS_DISPLAY_TYPE_TOTAL_OPTIONS            2
#define INTERFACE_OPTIONS_LANGUAGE_TOTAL_OPTIONS                3
#define INTERFACE_OPTIONS_MENU_DISPLAY_SIZE                     0
#define INTERFACE_OPTIONS_MENU_DISPLAY_TYPE                     1
#define INTERFACE_OPTIONS_MENU_AUDIO_VOLUME                     2
#define INTERFACE_OPTIONS_MENU_LANGUAGE                         3

//PATHS
//FILES
#define INTERFACE_OPTIONS_PATH              "Configuration/interface_options.acof"
//FONTS
#define COMIC_FONT_PATH                     "Fonts/comic.ttf"
//IMAGES
#define LOGO_IMAGE_PATH                     "Data/Image/Logo.png"
//VIDEO
#define LL_LOGO_VIDEO_PATH                  "Data/Video/LL_Logo.ogv"
#define OPENING_VIDEO_PATH                  "Data/Video/Opening.ogv"
#define DEMO_VIDEO_PATH                     "Data/Video/Demo.ogv"

//FONTS SIZE
#define FONT_SIZE_SMALL                         16
#define FONT_SIZE_NORMAL                        24
#define FONT_SIZE_LONG                          32
#define FONT_SIZE_BIG                           48

#endif // INCLUDED_CONSTANTS_H
