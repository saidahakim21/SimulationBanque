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

/* Struct used to compare two events for the set of events *//*

struct EventComp {
    bool operator()(const Event* lhs, const Event* rhs) const  {
        */
/* Events are compared using their execution time *//*

        return (lhs->time() < rhs->time());
    }
};
*/

struct eventElement {
    Event *event;
    struct eventElement *next;
};

class SED
{
    protected:
        double time;
        struct eventElement *eventsList;
        
    public:
        explicit SED(double);
        virtual ~SED();

        virtual void start();
        void addEvent(Event*);
        double getTime();
};

#endif
