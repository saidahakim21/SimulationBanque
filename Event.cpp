#include "Event.hpp"

#include <iostream>

/**
 * Constructor of Event
 * @param t
 * @param b
 */
Event::Event(double t, Bank* b) {
    time = t;
    bank = b;
}

/* Process of the event
Overridden by Arrive & Depart
*/
void Event::process() {
}

/* Returns the time of the event */
double Event::getTime() const {
    return time;
}
