#ifndef EVENTS_H
#define EVENTS_H

#include "orokorrak.h"

int key_state[4];

void event_listener(SDL_Event *event, int *quit);

#endif