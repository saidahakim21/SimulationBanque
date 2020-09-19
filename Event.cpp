/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#include "Event.hpp"

#include <iostream>

/* Constructor of Event with params:
- time      time of the execution of the event
- bank      pointer to the bank
*/
Event::Event(double t, Bank* b) {
    time = t;
    bank = b;
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
