#ifndef MODIFYING_INTERFACE_OPTIONS_H_INCLUDED
#define MODIFYING_INTERFACE_OPTIONS_H_INCLUDED

struct ModifyingInterfaceOptions
{
    bool invalid_display_size_option=0;
    bool invalid_display_type_option=0;
    unsigned int check(bool debug=0)
    {
        #ifdef GAME_DEBUG
        if(debug)
            t_log->write_text("MODIFYING INTERFACE OPTIONS\n");
        #endif // GAME_DEBUG
        unsigned int total_errors=0;
        if(invalid_display_size_option)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text("\t ERROR - INVALID DISPLAY SIZE OPTION");
                t_log->write_endl();
            }
            #endif // GAME_DEBUG
            ++total_errors;
        }
        if(invalid_display_type_option)
        {
            #ifdef GAME_DEBUG
            if(debug)
            {
                t_log->write_text("\t ERROR - INVALID DISPLAY TYPE OPTION");
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

#endif // MODIFYING_INTERFACE_OPTIONS_H_INCLUDED
