#ifndef INCLUDED_LOADING_AUDIOS_AC_ERRORS_H
#define INCLUDED_LOADING_AUDIOS_AC_ERRORS_H

struct LoadingAudiosAC
{
    bool ac_theme_audio=false;
    bool ac_game_audio=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("\t LOADING AUDIOS\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(ac_theme_audio)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING AC THEME AUDIO - ");
                textlog->write_text(AC_THEME_AUDIO_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(ac_game_audio)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING AC GAME AUDIO - ");
                textlog->write_text(AC_GAME_AUDIO_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("\n \t \t TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // DEBUG_OPTION
        return total_errors;
    }
};

#endif // INCLUDED_LOADING_AUDIOS_AC_ERRORS_H
