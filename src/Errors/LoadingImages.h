#ifndef INCLUDED_LOADING_IMAGES_ERRORS_H
#define INCLUDED_LOADING_IMAGES_ERRORS_H

struct LoadingImages
{
    bool logo_image=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("LOADING IMAGES\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(logo_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR LOADING LOGO IMAGE - ");
                textlog->write_text(LOGO_IMAGE_PATH);
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

#endif // INCLUDED_LOADING_IMAGES_ERRORS_H
