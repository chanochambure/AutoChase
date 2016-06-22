#ifndef LOADING_IMAGES_H_INCLUDED
#define LOADING_IMAGES_H_INCLUDED

struct LoadingImages
{
    bool logo_image=0;
    unsigned int check(bool debug=0)
    {
        #ifdef GAME_DEBUG
        if(debug)
            t_log->write_text("LOADING IMAGES\n");
        #endif // GAME_DEBUG
        unsigned int total_errors=0;
        if(logo_image)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text("\t ERROR LOADING LOGO IMAGE - ");
                t_log->write_text(LOGO_IMAGE_PATH);
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

#endif // LOADING_IMAGES_H_INCLUDED
