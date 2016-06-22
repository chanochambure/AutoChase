#ifndef GAME_LOG_H_INCLUDED
#define GAME_LOG_H_INCLUDED

//DEBUGGER LOG
LL_AL5::TextLog* t_log=nullptr;

void init_log()
{
    t_log=new LL_AL5::TextLog;
    t_log->set_title("Text Log");
    t_log->open_textlog();
}

void destroy_log()
{
    if(t_log)
        delete(t_log);
    t_log=nullptr;
}

#endif // GAME_LOG_H_INCLUDED
