
#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <set>

using namespace std;

class Simulation;

class Event {
protected:
    double time;
    Simulation* _simulation;     

public:
    explicit Event(double, Simulation*);

    virtual void process();
    double getTime() const;
};

#endif
