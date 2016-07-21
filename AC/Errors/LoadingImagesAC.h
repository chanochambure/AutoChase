#ifndef INCLUDED_LOADING_IMAGES_AC_ERRORS_H
#define INCLUDED_LOADING_IMAGES_AC_ERRORS_H

struct LoadingImagesAC
{
    bool background_main_menu_image=false;
    bool arrow_main_menu_image=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("LOADING IMAGES\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(background_main_menu_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR LOADING BACKGROUND MAIN MENU IMAGE - ");
                textlog->write_text(BACKGROUND_MAIN_MENU_IMAGE_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(arrow_main_menu_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR LOADING ARROW MAIN MENU IMAGE - ");
                textlog->write_text(ARROW_MAIN_MENU_IMAGE_PATH);
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

#endif // INCLUDED_LOADING_IMAGES_AC_ERRORS_H
