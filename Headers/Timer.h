#ifndef TIMER_CLASS
#define TIMER_CLASS
#include <Allegro5/allegro5>

class Timer
{
    Timer();
    double GetTime() const
    {
        al_get_time();
    }
};

#endif