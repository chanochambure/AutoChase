#ifndef INITIALIZING_FONTS_H_INCLUDED
#define INITIALIZING_FONTS_H_INCLUDED

struct InitializingFonts
{
    bool loading_comic_font=0;
    unsigned int check(bool debug=0)
    {
        #ifdef GAME_DEBUG
        if(debug)
            t_log->write_text("INITIALIZING FONTS\n");
        #endif // GAME_DEBUG
        unsigned int total_errors=0;
        if(loading_comic_font)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text("\t ERROR LOADING AGENCY FONT - ");
                t_log->write_text(COMIC_FONT_PATH);
                t_log->write_endl();
            }
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

#endif // INITIALIZING_FONTS_H_INCLUDED
