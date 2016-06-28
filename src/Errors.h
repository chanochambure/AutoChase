#ifndef INCLUDED_ERRORS_H
#define INCLUDED_ERRORS_H

//LOG
#include "Objects/Log.h"

//ERRORS
#include "Errors/LoadingInterfaceOptions.h"
#include "Errors/InitializingFonts.h"
#include "Errors/LoadingImages.h"
#include "Errors/LoadingVideos.h"
#include "Errors/ModifyingInterfaceOptions.h"

#include "../AC/Errors.h"

//CONTROL ERRORS
struct Errors
{
    //ERRORS
    LoadingInterfaceOptions loading_interface_options;
    InitializingFonts initializing_fonts;
    LoadingImages loading_images;
    LoadingVideos loading_videos;
    ModifyingInterfaceOptions modifying_interface_options;
    AutoChaseError auto_chase_errors;
    //CHECK
    unsigned int check_all_system()
    {
        #ifdef DEBUG_OPTION
        textlog->write_text("ERRORS\n");
        #endif // DEBUG_OPTION
        #ifdef DEBUG_OPTION
        bool debug=true;
        #else
        bool debug=false;
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        total_errors+=loading_interface_options.check(debug);
        total_errors+=initializing_fonts.check(debug);
        total_errors+=loading_images.check(debug);
        total_errors+=loading_videos.check(debug);
        total_errors+=modifying_interface_options.check(debug);
        total_errors+=auto_chase_errors.check_all_game();
        #ifdef DEBUG_OPTION
        textlog->write_text("\n TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // DEBUG_OPTION
        return total_errors;
    }
};

Errors errors;

#endif // INCLUDED_ERRORS_H
