#ifndef GAME_TIMER_H_INCLUDED
#define GAME_TIMER_H_INCLUDED

//Timer Object
LL_AL5::Timer* timer=nullptr;

void init_timer()
{
    //TIMER
        timer=new LL_AL5::Timer;
        timer->set_speed_seconds(_FPS);
        timer->create();
        timer->start();
}

void destroy_timer()
{
    if(timer)
        delete(timer);
    timer=nullptr;
}

#endif // GAME_TIMER_H_INCLUDED
