#ifndef __SIMULATION_HPP
#define __SIMULATION_HPP

#include <iostream>
#include <set>
#include <random>

#include "Poisson.h"
#include "Bank.hpp"
#include "Event.hpp"
#include "DES.hpp"

class Bank;

class Simulation: public DES {
    protected: 
        double _expectedTime;
        int _cashierNb;
        double _averageArrivalTime;
        double* _averageServiceTimes;
        Bank* _bank;
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
