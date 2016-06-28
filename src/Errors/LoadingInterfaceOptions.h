#ifndef INCLUDED_LOADING_INTERFACE_OPTIONS_ERRORS_H
#define INCLUDED_LOADING_INTERFACE_OPTIONS_ERRORS_H

struct LoadingInterfaceOptions
{
    bool loading_interface_options_file=false;
    bool bad_interface_options_lines=false;
    bool bad_decrypt_display=false;
    bool invalid_display_size=false;
    bool invalid_display_mode=false;
    bool incorrect_display_mode_display=false;
    bool bad_decrypt_audio_language=false;
    bool invalid_audio_number=false;
    bool invalid_language_option=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("LOADING INTERFACE OPTIONS\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(loading_interface_options_file)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR LOADING INTERFACE OPTIONS FILE - ");
                textlog->write_text(INTERFACE_OPTIONS_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(bad_interface_options_lines)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t MISS TOTAL LINES IN INTERFACE OPTIONS FILE \n");
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(bad_decrypt_display)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t MISS DATA - BAD DECRYPT DISPLAY SIZE AND TYPE\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(invalid_display_mode)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t NO VALID DISPLAY MODE\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(incorrect_display_mode_display)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t NO VALID DISPLAY FULLSCREEN WITH BAD DISPLAY SIZE\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(bad_decrypt_audio_language)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t MISS DATA - BAD DECRYPT AUDIO AND LANGUAGE\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(invalid_audio_number)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t NO VALID AUDIO VOLUME\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(invalid_language_option)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t NO VALID LANGUAGE OPTION\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("\n \t TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // DEBUG_OPTION
        return total_errors;
    }
};

#endif // INCLUDED_LOADING_INTERFACE_OPTIONS_ERRORS_H
