#ifndef LOADING_INTERFACE_OPTION_H_INCLUDED
#define LOADING_INTERFACE_OPTION_H_INCLUDED

struct LoadingInterfaceOptions
{
    bool loading_interface_options_file=0;
    bool bad_decrypt_display=0;
    bool invalid_display_size=0;
    bool invalid_display_mode=0;
    bool bad_decrypt_audio_language=0;
    bool invalid_audio_number=0;
    bool invalid_language_option=0;
    unsigned int check(bool debug=0)
    {
        #ifdef GAME_DEBUG
        if(debug)
            t_log->write_text("LOADING INTERFACE OPTIONS\n");
        #endif // GAME_DEBUG
        unsigned int total_errors=0;
        if(loading_interface_options_file)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text("\t ERROR LOADING INTERFACE OPTIONS FILE - ");
                t_log->write_text(INTERFACE_OPTIONS_PATH);
                t_log->write_endl();
            }
            #endif // GAME_DEBUG
            ++total_errors;
        }
        if(bad_decrypt_display)
        {
            #ifdef GAME_DEBUG
            if(debug)
                t_log->write_text("\t MISS DATA - BAD DECRYPT DISPLAY SIZE AND TYPE\n");
            #endif // GAME_DEBUG
            ++total_errors;
        }
        if(invalid_display_mode)
        {
            #ifdef GAME_DEBUG
            if(debug)
                t_log->write_text("\t NO VALID DISPLAY MODE\n");
            #endif // GAME_DEBUG
            ++total_errors;
        }
        if(bad_decrypt_audio_language)
        {
            #ifdef GAME_DEBUG
            if(debug)
                t_log->write_text("\t MISS DATA - BAD DECRYPT AUDIO AND LANGUAGE\n");
            #endif // GAME_DEBUG
            ++total_errors;
        }
        if(invalid_audio_number)
        {
            #ifdef GAME_DEBUG
            if(debug)
                t_log->write_text("\t NO VALID AUDIO VOLUME\n");
            #endif // GAME_DEBUG
            ++total_errors;
        }
        if(invalid_language_option)
        {
            #ifdef GAME_DEBUG
            if(debug)
                t_log->write_text("\t NO VALID LANGUAGE OPTION\n");
            #endif // GAME_DEBUG
            ++total_errors;
        }
        #ifdef GAME_DEBUG
        if(debug)
            t_log->write_text("\n \t TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // GAME_DEBUG
        return total_errors;
    }
};

#endif // LOADING_INTERFACE_OPTION_H_INCLUDED
