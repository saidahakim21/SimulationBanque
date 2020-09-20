
#include "SED.hpp"

/* Constructor of SED:
- start     starting time of the simulation
*/
SED::SED(double start) {
    time = start;
}

SED::~SED() {
    events.clear();
}

/* Overriden by Bank */
void SED::run() {
}

/* Add event to set of events */
void SED::addEvent(Event* e) {
    events.insert(e);
}

/* Returns the current time of the simulation */
double SED::getTime() {
    return time;
}
