/*********************************
 *
 * Renaud Déniel et Vincent Monot
 *
 *********************************/

#include "Simulation.hpp"

using namespace std;

Simulation::Simulation(int cashierNb, double averageArrivalTime, double expectedTime, double* averageServiceTimes) {
    _cashierNb = cashierNb;
    _averageArrivalTime = averageArrivalTime;
    _expectedTime = expectedTime;
    _averageServiceTimes = averageServiceTimes;
}

Simulation::~Simulation() = default;

void Simulation::run(){

    // Init seed for Poisson random generator
    Poisson::init();
    
    // Create bank with parameters
    Bank bank(0, _expectedTime, _cashierNb, _averageArrivalTime, _averageServiceTimes);
    // Start the simulation
    bank.run();

    // Display the stats for the simulation
    bank.displayStats();
}