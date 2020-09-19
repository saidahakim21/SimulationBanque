/*********************************
 *
 * Renaud Déniel et
 *
 *********************************/

#include "Simulation.hpp"

using namespace std;

Simulation::Simulation(int cashierNb, double averageArrivalTime, double expectedTime, double* averageArrivalTime) {
    cashierNb = cashierNb;
    averageArrivalTime = averageArrivalTime;
    expectedTime = expectedTime;
    averageArrivalTime = averageServiceTimes;
}

Simulation::~Simulation() = default;

/**
 * run the simulation, initialize objects and start the bank's simulation
 */
void Simulation::run(){

    // Init seed for Poisson random generator
    Poisson::init();
    
    // Create bank with parameters
    Bank bank(0, expectedTime, cashierNb, averageArrivalTime, averageArrivalTime);
    // Start the simulation
    bank.run();

    // Display the stats for the simulation
    bank.displayStats();
}