#ifndef LOADING_VIDEOS_H_INCLUDED
#define LOADING_VIDEOS_H_INCLUDED

struct LoadingVideos
{
    bool ll_logo_video=0;
    bool opening_video=0;
    #ifdef GAME_DEMO
    bool demo_video=0;
    #endif // GAME_DEMO
    unsigned int check(bool debug=0)
    {
        #ifdef GAME_DEBUG
        if(debug)
            t_log->write_text("LOADING VIDEOS\n");
        #endif // GAME_DEBUG
        unsigned int total_errors=0;
        if(ll_logo_video)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text("\t ERROR LOADING LEXRIS LOGIC LOGO VIDEO - ");
                t_log->write_text(LL_LOGO_VIDEO_PATH);
                t_log->write_endl();
            }
            #endif // GAME_DEBUG
            ++total_errors;
        }
        if(opening_video)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text(string("\t ERROR LOADING ")+GAME_NAME+" OPENING VIDEO - ");
                t_log->write_text(OPENING_VIDEO_PATH);
                t_log->write_endl();
            }
            #endif // GAME_DEBUG
            ++total_errors;
        }
        #ifdef GAME_DEMO
        if(demo_video)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text(string("\t ERROR LOADING ")+GAME_NAME+" DEMO VIDEO - ");
                t_log->write_text(DEMO_VIDEO_PATH);
                t_log->write_endl();
            }
            #endif // GAME_DEBUG
            ++total_errors;
        }
        #endif // GAME_DEMO
        #ifdef GAME_DEBUG
        if(debug)
            t_log->write_text("\n \t TOTAL ERRORS -> "+LL::to_string(total_errors)+"\n");
        #endif // GAME_DEBUG
        return total_errors;
    }
};

#endif // LOADING_VIDEOS_H_INCLUDED
