#ifndef INCLUDED_AC_ERRORS_H
#define INCLUDED_AC_ERRORS_H

//ERRORS

struct AutoChaseError
{
    //ERRORS
    //CHECK
    unsigned int check_all_game()
    {
        #ifdef GAME_DEBUG
        t_log->write("AUTO CHASE ERRORS\n");
        #endif // GAME_DEBUG
        #ifdef GAME_DEBUG
        bool debug=true;
        #else
        bool debug=false;
        #endif // GAME_DEBUG
        unsigned int total_errors=0;
        #ifdef GAME_DEBUG
        t_log->write("\n\t TOTAL ERRORS -> "+to_string(total_errors)+"\n");
        #endif // GAME_DEBUG
        return total_errors;
    }
};

#endif // INCLUDED_AC_ERRORS_H
