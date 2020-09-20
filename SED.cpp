/******************************
 * created by Yacine ZABAT
 ******************************/

#include "SED.hpp"

/**
 * constructor for class SED, Simulation of Discret Events
 * @param start
 */
SED::SED(double start) {
    time = start;
}

SED::~SED() {
    events.clear();
}

/**
 * start the simulation to be override
 */
void SED::run() {
}

/**
 * add a new Event into the simulation
 * @param e an object of type Event
 */
void SED::addEvent(Event* e) {
    events.insert(e);
}

/**
 * get the current time of the simulation
 * @return double
 */
double SED::getTime() {
    return time;
}
