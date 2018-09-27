#ifndef TIMER_CLASS
#define TIMER_CLASS
#include <allegro5/allegro5.h>

class Timer
{
    Timer();
    double GetTime() const
    {
        al_get_time();
    }
};

#endif