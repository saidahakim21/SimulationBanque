/******************************
 * created by Abdelhakim SAID
 ******************************/

#ifndef __CLIENT_ARRIVAL_HPP
#define __CLIENT_ARRIVAL_HPP

#include <iostream>

#include "Poisson.h"
#include "Simulation.hpp"
#include "Client.hpp"
#include "Event.hpp"

class Simulation; 

/**
 * subclass of Event
 * a class that illustrate a new client arrival event.
 */
class Arrival: public Event {
    protected: 
        Simulation* simulation; 
    public:
        explicit Arrival(double, Simulation*);
        void process() override;
};

#endif
