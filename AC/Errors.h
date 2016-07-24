#ifndef INCLUDED_AC_ERRORS_H
#define INCLUDED_AC_ERRORS_H

//ERRORS
#include "Errors/LoadingDataAC.h"
#include "Errors/LoadingImagesAC.h"
#include "Errors/LoadingAudiosAC.h"

struct AutoChaseError
{
    //ERRORS
    LoadingDataAC loading_data_ac;
    LoadingImagesAC loading_images_ac;
    LoadingAudiosAC loading_audios_ac;
    //CHECK
    unsigned int check_all_game()
    {
        #ifdef DEBUG_OPTION
        textlog->write_text("AUTO CHASE ERRORS\n");
        #endif // DEBUG_OPTION
        #ifdef DEBUG_OPTION
        bool debug=true;
        #else
        bool debug=false;
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        total_errors+=loading_data_ac.check(debug);
        total_errors+=loading_images_ac.check(debug);
        total_errors+=loading_audios_ac.check(debug);
        #ifdef DEBUG_OPTION
        textlog->write_text("\n\t TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // DEBUG_OPTION
        return total_errors;
    }
};

#endif // INCLUDED_AC_ERRORS_H
