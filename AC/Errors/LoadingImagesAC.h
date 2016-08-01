#ifndef INCLUDED_LOADING_IMAGES_AC_ERRORS_H
#define INCLUDED_LOADING_IMAGES_AC_ERRORS_H

struct LoadingImagesAC
{
    bool background_main_menu_image=false;
    bool background_configuration_menu_image=false;
    bool arrow_menu_image=false;
    bool demo_car_image=false;
    bool ac_hud_image=false;
    bool ac_score_image=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("\t LOADING IMAGES\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(background_main_menu_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING BACKGROUND MAIN MENU IMAGE - ");
                textlog->write_text(BACKGROUND_MAIN_MENU_IMAGE_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(background_configuration_menu_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING BACKGROUND CONFIGURATION MENU IMAGE - ");
                textlog->write_text(BACKGROUND_CONFIGRATION_MENU_IMAGE_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(arrow_menu_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING ARROW MENU IMAGE - ");
                textlog->write_text(ARROW_MENU_IMAGE_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(demo_car_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t \t ERROR LOADING DEMO CAR IMAGE \n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(ac_hud_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING AC HUD GAME IMAGE - ");
                textlog->write_text(AC_HUD_IMAGE_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(ac_score_image)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING AC SCORE GAME IMAGE - ");
                textlog->write_text(AC_SCORE_IMAGE_PATH);
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

#endif // INCLUDED_LOADING_IMAGES_AC_ERRORS_H
