#ifndef TIMER_H
#define TIMER_H

#include <stdbool.h>
#include <stdint.h>

void timer_tick();
void timer_set(int i);
void timer_activate(int i);
bool timer_expired();
void deactivate_timer();
bool timer_deactivated();

#endif // TIMER_H
