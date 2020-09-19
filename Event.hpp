#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <set>

using namespace std;

class Bank;
/**
 * a class of an event, holds attributes about the object
 */
class Event {
protected:
    Bank* bank;
    double time;
public:
    explicit Event(double, Bank*);

    virtual void process();
    double getTime() const;
//    bool operator<(const Event&) const;
};

#endif
