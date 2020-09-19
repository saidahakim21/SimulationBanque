/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#include "DES.hpp"

/* Constructor of DES:
- start     starting time of the simulation
*/
DES::DES(double start) {
    _time = start;
}

DES::~DES() {
    _events.clear();
}

/* Overriden by Bank */
void DES::run() {
}

/* Add event to set of events */
void DES::addEvent(Event* e) {
    _events.insert(e);
}

/* Returns the current time of the simulation */
double DES::getTime() {
    return _time;
}
