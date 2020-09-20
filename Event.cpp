
#include "Event.hpp"

#include <iostream>

/* Constructor of Event with params:
- time      time of the execution of the event
- simulation      pointer to the simulaiton
*/
Event::Event(double t, Simulation* s) {
    time = t;
    simulation= s;
}

/* Process of the event
Overridden by Arrival & Depart
*/
void Event::process() {
}

/* Returns the time of the event */
double Event::getTime() const {
    return time;
}
