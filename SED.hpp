#ifndef __SED_HPP
#define __SED_HPP

#include <iostream>
#include <set>

#include "Event.hpp"

using namespace std;

class Event;

/* Struct used to compare two events for the set of events */
struct EventComp {
    bool operator()(const Event* lhs, const Event* rhs) const  {
        /* Events are compared using their execution time */
        return (lhs->getTime() < rhs->getTime());
    }
};

class SED {
protected:
    double time;

    set<Event*, EventComp> events;
    set<Event*, EventComp>::iterator eventIterator;

public:
    explicit SED(double);
    virtual ~SED();

    virtual void run();
    void addEvent(Event*);
    double getTime();
};

#endif
