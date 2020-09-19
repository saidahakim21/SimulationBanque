/*********************************
 *
 * Renaud Déniel et Vincent Monot
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

class Simulation{
    protected: 
        double _expectedTime;
        int _cashierNb;
        double _averageArrivalTime;
        double* _averageServiceTimes;
    public:
        //Simulation();
        explicit Simulation(int, double, double, double*);
        ~Simulation();
        void run(); 
};

#endif
