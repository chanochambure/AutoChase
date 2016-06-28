#ifndef INCLUDED_GAME_TEXTLOG_H
#define INCLUDED_GAME_TEXTLOG_H

//DEBUGGER LOG
LL_AL5::TextLog* textlog=nullptr;

void init_textlog()
{
    textlog=new LL_AL5::TextLog;
    textlog->set_title("TextLog");
    textlog->open_textlog();
}

void destroy_textlog()
{
    if(textlog)
        delete(textlog);
    textlog=nullptr;
}

#endif // INCLUDED_GAME_TEXTLOG_H
