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
Event::Event(double time, Bank* bank) {
    time = time;
    bank = bank;
}

/* Process of the event
Overridden by ClientArrival & CashierRelease
*/
void Event::process() {
}

/* Returns the time of the event */
double Event::time() const {
    return time;
}
