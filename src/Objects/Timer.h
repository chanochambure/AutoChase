#ifndef INCLUDED_GAME_TIMER_H
#define INCLUDED_GAME_TIMER_H

//Timer Object
LL_AL5::Timer* timer=nullptr;

void init_timer()
{
    timer=new LL_AL5::Timer;
    timer->set_speed_seconds(FPS_OPTION);
    timer->create();
    timer->start();
}

void destroy_timer()
{
    if(timer)
        delete(timer);
    timer=nullptr;
}

#endif // INCLUDED_GAME_TIMER_H
