
#ifndef __EVENT_HPP
#define __EVENT_HPP

#include <set>

using namespace std;

class Event {
protected:
    double time;

public:
    explicit Event(double);

    virtual void process();
    double getTime() const;
};

#endif
