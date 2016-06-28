#ifndef INCLUDED_MODIFYING_INTERFACE_OPTIONS_ERRORS_H
#define INCLUDED_MODIFYING_INTERFACE_OPTIONS_ERRORS_H

struct ModifyingInterfaceOptions
{
    bool invalid_display_size_option=false;
    bool invalid_display_type_option=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("MODIFYING INTERFACE OPTIONS\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(invalid_display_size_option)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR - INVALID DISPLAY SIZE OPTION");
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(invalid_display_type_option)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t ERROR - INVALID DISPLAY TYPE OPTION");
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

#endif // INCLUDED_MODIFYING_INTERFACE_OPTIONS_ERRORS_H
