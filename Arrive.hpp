#ifndef __CLIENT_ARRIVAL_HPP
#define __CLIENT_ARRIVAL_HPP

#include <iostream>

#include "Poisson.h"
#include "Bank.hpp"
#include "Client.hpp"
#include "Event.hpp"

/**
 * a class of new client arrival, extends Event
 */
class Arrive: public Event {
public:
    explicit Arrive(double, Bank*);
    void process() override;
};

#endif
