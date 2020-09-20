#ifndef __SIMULATION_HPP
#define __SIMULATION_HPP

#include <iostream>
#include <set>
#include <random>

#include "Poisson.h"
#include "Bank.hpp"
#include "Event.hpp"
#include "SED.hpp"

class Bank;

class Simulation: public SED {
    protected: 
        double expectedTime;
        int cashierNb;
        double averageArrivalTime;
        double* averageServiceTimes;
        Bank* bank;
    public:
        //Simulation();
        explicit Simulation(int, double, double, double*);
        ~Simulation();
        Bank* getBank(); 
        /**
         * Run simulation
         */
        void run(); 
        /**
         * displays the simulation statistics on console
         */
        void displayStatistics(); 
};

#endif
