
#include "Event.hpp"

#include <iostream>

/**
 * constuctor for class Event
 * @param t time of the event happening
 * @param s an object of type Simulation
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
