#ifndef INCLUDED_LOADING_DATA_AC_ERRORS_H
#define INCLUDED_LOADING_DATA_AC_ERRORS_H

struct LoadingDataAC
{
    bool loading_data_file=false;
    bool missing_data=false;
    bool missing_data_configuration=false;
    bool missing_data_records=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("\t LOADING DATA AC\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(loading_data_file)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR LOADING DATA AC FILE - ");
                textlog->write_text(DATA_AC_PATH);
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(missing_data)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR MISSING DATA");
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(missing_data_configuration)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR MISSING DATA CONFIGURATION");
                textlog->write_endl();
            }
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(missing_data_records)
        {
            #ifdef DEBUG_OPTION
            if(debug)
            {
                textlog->write_text("\t \t ERROR MISSING DATA RECORDS");
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

#endif // INCLUDED_LOADING_DATA_AC_ERRORS_H
