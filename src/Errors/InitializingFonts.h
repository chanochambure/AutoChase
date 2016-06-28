#ifndef INCLUDED_INITIALIZING_FONTS_ERRORS_H
#define INCLUDED_INITIALIZING_FONTS_ERRORS_H

struct InitializingFonts
{
    bool loading_comic_font=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("INITIALIZING FONTS\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(loading_comic_font)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR LOADING AGENCY FONT - ");
                textlog->write_text(COMIC_FONT_PATH);
                textlog->write_endl();
            }
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

#endif // INCLUDED_INITIALIZING_FONTS_ERRORS_H
