

#ifndef __SED_HPP
#define __SED_HPP

#include <iostream>
#include <set>

#include "Event.hpp"

using namespace std;

class Event;

/**
 * struct holds a comparator for Two events
 */
struct EventComp {
    bool operator()(const Event* e1, const Event* e2) const  {
        /* Events are compared using their execution time */
        return (e1->getTime() < e2->getTime());
    }
};

class SED {
protected:
    double _time;
    /// a Set of Event objects
    set<Event*, EventComp> events;
    /// an iterator to iterate over the simulation events in a chronological way
    set<Event*, EventComp>::iterator eventIterator;

public:
    explicit SED(double);
    virtual ~SED();

    virtual void run();
    /**
     * add a new Event object to the list of events of the simulation
     */
    void addEvent(Event*);
    /**
     * getter for current time of simulation
     * @return double
     */
    double getTime();
};

#endif
