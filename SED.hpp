#ifndef __SED_HPP
#define __SED_HPP

#include <iostream>
#include <set>

#include "Event.hpp"

using namespace std;

class Event;

/**
 * a struct used to compare two events by their starting time
 */
struct EventComp {
    bool operator()(const Event* e1, const Event* e2) const  {
        /* Events are compared using their execution time */
        return (e1->getTime() < e2->getTime());
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
