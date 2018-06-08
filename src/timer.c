#include "timer.h"

static int timer;

void timer_tick() {
    if (timer > 0)
        timer--;
}

// ~10 ticks per second, don't set it deactivated
void timer_set(int i) {
    if(!timer_deactivated())
        timer = i;
}

void timer_activate(int i) {
    timer = i;
}

bool timer_expired() {
    // if expired set it into deactivated state
    if(timer == 0) {
        
        deactivate_timer();
        return true;
    }
    else return false;
}

void deactivate_timer() {
    timer = -1;
}

bool timer_deactivated() {
    return timer < 0;
}
