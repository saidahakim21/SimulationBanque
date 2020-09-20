
#include "Event.hpp"

#include <iostream>

/* Constructor of Event with params:
- time      time of the execution of the event
- simulation      pointer to the simulaiton
*/
Event::Event(double t, Simulation* simulation) {
    time = t;
    _simulation= simulation; 
}

/* Process of the event
Overridden by ClientArrival & Depart
*/
void Event::process() {
}

/* Returns the time of the event */
double Event::getTime() const {
    return time;
}
