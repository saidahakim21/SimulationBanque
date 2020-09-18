/*********************************
 *
 * Vincent Monot
 *
 *********************************/

#ifndef __DES_HPP
#define __DES_HPP

#include <iostream>
#include <set>

#include "Event.hpp"

using namespace std;

class Event;

/* Struct used to compare two events for the set of events */
struct EventComp {
    bool operator()(const Event* lhs, const Event* rhs) const  {
        /* Events are compared using their execution time */
        return (lhs->time() < rhs->time());
    }
};

class DES {
protected:
    double _time;

    set<Event*, EventComp> _events;
    set<Event*, EventComp>::iterator _eventIterator;

public:
    explicit DES(double);
    virtual ~DES();

    virtual void run();
    void addEvent(Event*);
    double time();
};

#endif
