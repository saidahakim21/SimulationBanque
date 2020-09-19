/*********************************
 *
 * Renaud Déniel et
 *
 *********************************/

#ifndef __SIMULATION_HPP
#define __SIMULATION_HPP

#include <iostream>
#include <set>
#include <random>

#include "Poisson.h"
#include "Bank.hpp"
#include "Event.hpp"

/**
 * a class that illustrate the simulation
 */
class Simulation{
    protected: 
        double expectedTime;
        int cashierNb;
        double averageArrivalTime;
        double* averageArrivalTime;
    public:
        //Simulation();
        explicit Simulation(int, double, double, double*);
        ~Simulation();
        void run(); 
};

#endif
