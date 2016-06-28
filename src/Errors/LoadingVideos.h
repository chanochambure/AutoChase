#ifndef INCLUDED_LOADING_VIDEOS_ERRORS_H
#define INCLUDED_LOADING_VIDEOS_ERRORS_H

struct LoadingVideos
{
    bool ll_logo_video=false;
    bool opening_video=false;
    #ifdef GAME_DEMO
    bool demo_video=false;
    #endif // GAME_DEMO
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("LOADING VIDEOS\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(ll_logo_video)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR LOADING LEXRIS LOGIC LOGO VIDEO - ");
                textlog->write_text(LL_LOGO_VIDEO_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(opening_video)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text(string("\t ERROR LOADING ")+GAME_NAME+" OPENING VIDEO - ");
                textlog->write_text(OPENING_VIDEO_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        #ifdef GAME_DEMO
        if(demo_video)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text(string("\t ERROR LOADING ")+GAME_NAME+" DEMO VIDEO - ");
                textlog->write_text(DEMO_VIDEO_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        #endif // GAME_DEMO
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("\n \t TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // DEBUG_OPTION
        return total_errors;
    }
};

#endif // INCLUDED_LOADING_VIDEOS_ERRORS_H
