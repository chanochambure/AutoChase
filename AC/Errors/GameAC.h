#ifndef INCLUDED_GAME_AC_ERRORS_H
#define INCLUDED_GAME_AC_ERRORS_H

struct GameErrorsAC
{
    bool create_key_control_status=false;
    bool create_player_status=false;
    bool create_enemies_status=false;
    unsigned int check(bool debug=false)
    {
        #ifdef DEBUG_OPTION
        if(debug)
            textlog->write_text("\t AUTO CHASE GAME ERRORS\n");
        #endif // DEBUG_OPTION
        unsigned int total_errors=0;
        if(create_key_control_status)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t \t ERROR CREATING GAME KEY CONTROL\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(create_player_status)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t \t ERROR CREATING PLAYER\n");
            #endif // DEBUG_OPTION
            ++total_errors;
        }
        if(create_enemies_status)
        {
            #ifdef DEBUG_OPTION
            if(debug)
                textlog->write_text("\t \t ERROR CREATING ENEMIES\n");
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

#endif // INCLUDED_GAME_AC_ERRORS_H
