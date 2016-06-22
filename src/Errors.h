#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED

//LOG
#include "Objects/Log.h"

//ERRORS
#include "Errors/LoadingInterfaceOptions.h"
#include "Errors/InitializingFonts.h"
#include "Errors/LoadingImages.h"
#include "Errors/LoadingVideos.h"
#include "Errors/ModifyingInterfaceOptions.h"

//#include "<GAME>/Errors.h"

//CONTROL ERRORS
struct Errors
{
    //ERRORS
    LoadingInterfaceOptions loading_interface_options;
    InitializingFonts initializing_fonts;
    LoadingImages loading_images;
    LoadingVideos loading_videos;
    ModifyingInterfaceOptions modifying_interface_options;
//    <GAME>Error <GAME>;
    //CHECK
    unsigned int check_all_system()
    {
        #ifdef GAME_DEBUG
        t_log->write_text("ERRORS\n");
        #endif // GAME_DEBUG
        #ifdef GAME_DEBUG
        bool debug=1;
        #else
        bool debug=0;
        #endif // GAME_DEBUG
        unsigned int total_errors=0;
        total_errors+=loading_interface_options.check(debug);
        total_errors+=initializing_fonts.check(debug);
        total_errors+=loading_images.check(debug);
        total_errors+=loading_videos.check(debug);
        total_errors+=modifying_interface_options.check(debug);
//        total_errors+=<GAME>.check_all_game();
        #ifdef GAME_DEBUG
        t_log->write_text("\n TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // GAME_DEBUG
        return total_errors;
    }
};

Errors errors;

#endif // ERRORS_H_INCLUDED
